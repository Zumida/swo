/*
 * menu.cpp
 *
 * Last modified: <2013/04/11 06:28:14 +0900> By Zumida
 */

#include "menu.hpp"

using namespace swo;

Menu::Menu() {
	handle = NULL;
}

Menu::~Menu() {
}

HMENU Menu::getHandle(void) const {
	return handle;
}

void Menu::add(const MenuItem& item) {
	if (handle == NULL) {
		handle = CreateMenu();
	}
	if (handle != NULL) {
		InsertMenuItem(handle, item.getId(), FALSE, &item.getInfo());
	}
}

void Menu::add(const int index, const MenuItem& item) {
	if (handle == NULL) {
		handle = CreateMenu();
	}
	if (handle != NULL) {
		InsertMenuItem(handle, index, TRUE, &item.getInfo());
	}
}

const Menu Menu::empty;
