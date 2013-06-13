/*
 * application.cpp
 *
 * Last modified: <2013/06/14 06:23:55 +0900> By Zumida
 */
#include "application.hpp"

using namespace swo;

Application::Application() {
}

Application::~Application() {
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

int Application::run(void) {

	// メッセージループ
	MSG msg;
	for (;;) {
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

	// 登録されたコントロールを破棄
	while (!controls.empty()) {
		Control* control = controls.back();
		controls.pop_back();
		delete control;
	}

	// 登録されたオブジェクトを破棄
	while (!objects.empty()) {
		Object* object = objects.back();
		objects.pop_back();
		delete object;
	}

	return static_cast<int>(msg.wParam);
}

Application Application::instance;

Application& Application::getInstance(void) {
	return instance;
}
