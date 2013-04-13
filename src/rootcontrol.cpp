/*
 * rootcontrol.cpp
 *
 * Last modified: <2013/04/12 07:14:22 +0900> By Zumida
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
