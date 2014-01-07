/*
 * application.cpp
 *
 * Last modified: <2014/01/07 14:23:42 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include <windows.h>

using namespace swo;

Application Application::instance;

Application::Application() {
	// 各フィールドの初期化
	status = BOOT;
	terminated = false;
	result = 0;
}

Application::~Application() {
}

Application& Application::getInstance(void) {
	return instance;
}

void Application::boot(void) {
	// コマンドライン引数の取得

	int argc = 0;
	WCHAR **argv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);

	if (argv != nullptr) {
		for (int i = 0; i < argc; ++i) {
			arguments.push_back(argv[i]);
		}
		::GlobalFree(argv);
	}

	status = INITIALIZE;
}

void Application::run(void) {
	status = RUN;

	// メッセージループ
	MSG msg;
	while (!isTerminated()) {
		// 更新予約コントロールを更新
		for (Controls::iterator it = controls.begin();
			 it != controls.end(); ) {
			Control* c = *it;
			if (c->isTerminated()) {
				it = controls.erase(it);
				delete c;
				continue;
			}
			if (c->isUpdated()) {
				c->refresh();
			}
			it++;
		}

		// メッセージ取得失敗、終了メッセージ受信時はループ終了
		int result = GetMessage(&msg, nullptr, 0, 0);
		if (result == 0 || result == -1) break;

		// メッセージを処理する
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (!isTerminated()) this->result = static_cast<int>(msg.wParam);
}

void Application::finalize(void) {

	status = FINALIZE;

	try {
		// 登録されたコントロールを破棄
		while (!controls.empty()) {
			Control* control = controls.back();
			controls.pop_back();
			delete control;
		}

	} catch (const std::exception &e) {
		Stderr << "Catch a std::exception! : " << e.what() << std::endl;

	} catch (...) {
		Stderr << "Catch an unexpected exception!" << std::endl;
	}

	try {
		// 登録されたオブジェクトを破棄
		while (!objects.empty()) {
			Object* object = objects.back();
			objects.pop_back();
			delete object;
		}

	} catch (const std::exception &e) {
		Stderr << "Catch a std::exception! : " << e.what() << std::endl;

	} catch (...) {
		Stderr << "Catch an unexpected exception!" << std::endl;
	}
}

void Application::terminate(int result) {
	Application& app = getInstance();
	app.result = result;
	app.terminated = true;
	::PostQuitMessage(result);
}

StringList& Application::getArguments(void) {
	return arguments;
}

int Application::getResult(void) const {
	return result;
}

Application::Status Application::getStatus(void) const {
	return status;
}

bool Application::isRunning(void) const {
	return (status == RUN);
}

bool Application::isTerminated(void) const {
	return terminated;
}

void Application::add(Object* object) {
	Control* control = dynamic_cast<Control*>(object);

	if (control != nullptr) {
		controls.push_back(control);
	} else {
		objects.push_back(object);
	}
}

void Application::remove(Object* object) {
	Control* control = dynamic_cast<Control*>(object);

	if (control != nullptr) {
		controls.remove(control);
		delete control;
	} else {
		objects.remove(object);
		delete object;
	}
}

void Application::addListener(const HWND hWnd, const EventListener* listener) {
	WndMap& map = getInstance().wndMap;

	map.insert(std::make_pair(const_cast<HWND>(hWnd),
							  const_cast<EventListener*>(listener)));
}

void Application::removeListener(HWND hWnd) {
	getInstance().wndMap.erase(hWnd);
}

EventListener* Application::findListener(HWND hWnd) {
	Application& app = getInstance();

	if (app.status != RUN) {
		return nullptr;
	} else {
		WndMap& map = app.wndMap;
		WndMap::iterator it = map.find(hWnd);
		return (it == map.end())? nullptr: it->second;
	}
}

LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	EventListener* listener = findListener(hWnd);
	if (listener != nullptr && listener->wndproc(msg, wp, lp)) return 0;
	return ::DefWindowProc(hWnd, msg, wp, lp);
}
