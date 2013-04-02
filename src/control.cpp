/*
 * control.cpp
 *
 * Last modified: <2013/04/11 07:02:13 +0900> By Zumida
 */
#include "control.hpp"
#include <algorithm>

using namespace swo;

/*
 * コンストラクタ
 *
 * プライベート変数を初期化する。
 */
Control::Control() {
	initialize();
}

Control::Control(Control* parent) {
	initialize();
	setParent(parent);
}

/*
 * デストラクタ
 *
 * 内部管理のオブジェクトを解放する。
 */
Control::~Control() {
	if (parent != NULL) {
		parent->removeChild(this);
		parent = NULL;
	}

	while (!childs.empty()) {
		Control* child = childs.back();
		childs.pop_back();
		delete child;
	}

	if (getHandle() != NULL) {
		DestroyWindow(getHandle());
		setHandle(NULL);
	}
}

void Control::initialize(void) {
	updated = true;
	parent = NULL;
	childs.clear();
}

void Control::update(void) {
	updated = true;
}

void Control::sync(bool isOwner) {
	if (updated) {
		updated = false;
		childs.sort();

		HWND handle = getHandle();
		if (handle != NULL && isOwner) ::DestroyWindow(handle);

		handle = createHandle();
		setHandle(handle);
	}

	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->sync(false);
	}
}

void Control::refresh(bool isOwner) {
	updated = false;
	childs.sort();

	HWND handle = getHandle();
	if (handle != NULL && isOwner) ::DestroyWindow(handle);

	tout << "createHandle()" << std::endl;
	handle = createHandle();
	tout << "handle=" << handle << std::endl;
	setHandle(handle);

	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->refresh(false);
	}
}

void Control::sync() {
	sync(true);
}

void Control::refresh() {
	refresh(true);
}

Control* Control::getParent(void) {
	return parent;
}

void Control::setParent(Control* parent) {
	if (this->parent != parent) {
		if (this->parent != NULL) {
			this->parent->removeChild(this);
		}
		this->parent = parent;
		if (this->parent != NULL) {
			this->parent->addChild(this);
		}
	}
}

void Control::addChild(Control* child) {
	childs.push_back(child);
}

void Control::removeChild(Control* child) {
	childs.remove(child);
}

void Control::show(void) {
	visible = true;
	sync();

	HWND hWnd = getHandle();
	if (hWnd != NULL) {
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);
	}
}

void Control::hide(void) {
	visible = false;

	HWND hWnd = getHandle();
	if (hWnd != NULL) {
		ShowWindow(hWnd, SW_HIDE);
		UpdateWindow(hWnd);
	}
}

int Control::getTab(void) {
	return tab;
}

void Control::setTab(int tab) {
	this->tab = tab;
	update();
}

bool Control::hasBorder(void) {
	return border;
}

void Control::setBorder(bool border) {
	this->border = border;
	update();
}

bool Control::operator < (const Control* control) {
	return control != NULL && this->tab < control->tab;
};
