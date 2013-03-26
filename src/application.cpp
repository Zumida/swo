/*
 * application.cpp
 *
 * Last modified: <2013/03/25 13:47:09 +0900> By Zumida
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

	// ���b�Z�[�W���[�v
	MSG msg;
	for (;;) {
		int result = GetMessage(&msg, NULL, 0, 0);

		if (result == 0 || result == -1) break;

		// ���b�Z�[�W����������
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}
