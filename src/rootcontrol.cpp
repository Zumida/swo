/*
 * rootcontrol.cpp
 *
 * Last modified: <2014/01/07 14:26:38 +0900> By Zumida
 */
#include "swoconfig.hpp"
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
