/*
 * application.cpp
 *
 * Last modified: <2013/04/11 09:09:47 +0900> By Zumida
 */
#include "define.hpp"
#include "application.hpp"
#include "windowclass.hpp"

using namespace swo;

Application::Application() {
	if (WindowClass::find(WINDOW_CLASSNAME) == NULL) {
		WindowClass& wc = createObject<WindowClass>();
		wc.setClassName(WINDOW_CLASSNAME);
		wc.setWndProc(EventListener::WndProc);
		WindowClass::add(wc);
	}
}

Application::~Application() {
	while (!objects.empty()) {
		Object* object = objects.back();
		objects.pop_back();
		delete object;
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
