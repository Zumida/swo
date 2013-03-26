/*
 * rootcontrol.cpp
 *
 * Last modified: <2013/03/21 09:48:27 +0900> By Zumida
 */

#include "rootcontrol.hpp"

using namespace swo;

RootControl::RootControl() : Control() {
}

RootControl::RootControl(HWND root) {
	this->root = root;
}

HWND RootControl::createHandle(void) {
	return this->root;
}
