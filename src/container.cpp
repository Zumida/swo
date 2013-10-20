/*
 * container.cpp
 *
 * Last modified: <2013/10/20 16:16:50 +0900> By Zumida
 */
#include "container.hpp"

using namespace swo;

Container::Container() : EventListener() {
}

Container::Container(Control& parent) : EventListener(parent) {
}

Container::~Container() {
	while (!childs.empty()) {
		Control* child = childs.back();
		childs.pop_back();
		delete child;
	}
}

void Container::addChild(Control& child) {
	childs.push_back(&child);
	child.setParent(this);
}

void Container::removeChild(Control& child) {
	childs.remove(&child);
	child.setParent(NULL);
}

void Container::renew(void) {
	update();

	HWND handle = getHandle();
	if (handle != NULL) {
		::DestroyWindow(handle);
		resetHandle();
	}

	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->resetHandle();
	}

	refresh();
}

void Container::refresh(void) {
	Control::refresh();

	childs.sort();
	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->refresh();
	}
}
