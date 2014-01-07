/*
 * menu.cpp
 *
 * Last modified: <2014/01/07 14:26:10 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "menu.hpp"

using namespace swo;

Menu::Menu() {
	handle = nullptr;
}

Menu::~Menu() {
}

HMENU Menu::getHandle(void) const {
	return handle;
}

void Menu::add(const MenuItem& item) {
	if (handle == nullptr) {
		handle = CreateMenu();
	}
	if (handle != nullptr) {
		InsertMenuItem(handle, item.getId(), FALSE, &item.getInfo());
	}
}

void Menu::add(const int index, const MenuItem& item) {
	if (handle == nullptr) {
		handle = CreateMenu();
	}
	if (handle != nullptr) {
		InsertMenuItem(handle, index, TRUE, &item.getInfo());
	}
}

const Menu Menu::empty;
