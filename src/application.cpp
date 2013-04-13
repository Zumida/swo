/*
 * application.cpp
 *
 * Last modified: <2013/04/13 22:02:36 +0900> By Zumida
 */
#include "define.hpp"
#include "application.hpp"
#include "windowclass.hpp"
#include "syscolorbrush.hpp"

using namespace swo;

Application::Application() {
	if (WindowClass::find(WINDOW_CLASSNAME) == NULL) {
		WindowClass& wc = createObject<WindowClass>();
		Brush& bs = createObject<SysColorBrush>().set(0);

		wc.setClassName(WINDOW_CLASSNAME);
		wc.setBackground(bs);
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
