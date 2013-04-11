/*
 * application.cpp
 *
 * Last modified: <2013/04/03 01:34:25 +0900> By Zumida
 */

#include "application.hpp"

using namespace swo;

Application::Application() {
}

Application::~Application() {
	while (!objects.empty()) {
		delete *objects.end();
		objects.pop_back();
	}
}

void Application::add(Object* object) {
	objects.push_back(object);
}

void Application::remove(Object* object) {
	objects.remove(object);
	delete object;
}

int Application::run(void) {

	// メッセージループ
	MSG msg;
	for (;;) {
		int result = GetMessage(&msg, NULL, 0, 0);

		// メッセージ取得失敗、終了メッセージ受信時はループ終了
		if (result == 0 || result == -1) break;

		// メッセージを処理する
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}
