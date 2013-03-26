/*
 * menu.cpp
 *
 * Last modified: <2013/03/26 12:48:48 +0900> By Zumida
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
