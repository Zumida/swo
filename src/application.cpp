/*
 * application.cpp
 *
 * Last modified: <2013/08/25 08:59:10 +0900> By Zumida
 */
#include "application.hpp"
#include <windows.h>

using namespace swo;

Application::Application() {
	// 各フィールドの初期化
	running = false;
	terminated = false;
	result = 0;
}

Application::~Application() {
}

void Application::initialize(void) {

	// コマンドライン引数の取得
	int argc = 0;
	WCHAR **argv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);

	if (argv != NULL) {
		for (int i = 0; i < argc; ++i) {
			arguments.push_back(argv[i]);
		}
		::GlobalFree(argv);
	}
}

void Application::finalize(void) {

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
	this->result = result;
}

StringList& Application::getArguments(void) {
	return arguments;
}

int Application::getResult(void) const {
	return result;
}

bool Application::isRunning(void) const {
	return running;
}

bool Application::isTerminated(void) const {
	return terminated;
}

void Application::add(Object* object) {
	Control* control = dynamic_cast<Control*>(object);

	if (control != NULL) {
		controls.push_back(control);
	} else {
		objects.push_back(object);
	}
}

void Application::remove(Object* object) {
	Control* control = dynamic_cast<Control*>(object);

	if (control != NULL) {
		controls.remove(control);
		delete control;
	} else {
		objects.remove(object);
		delete object;
	}
}

void Application::run(void) {

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
		int result = GetMessage(&msg, NULL, 0, 0);
		if (result == 0 || result == -1) break;

		// メッセージを処理する
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (!isTerminated()) this->result = static_cast<int>(msg.wParam);
}

Application Application::instance;

Application& Application::getInstance(void) {
	return instance;
}
