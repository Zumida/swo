/*
 * control.cpp
 *
 * Last modified: <2013/04/22 00:36:34 +0900> By Zumida
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
		::DestroyWindow(getHandle());
		setHandle(NULL);
	}
}

void Control::initialize(void) {
	terminated = false;
	updated = true;
	parent = NULL;
	exStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
	childs.clear();
}

void Control::renew(void) {
	updated = true;

	if (getHandle() != NULL) {
		::DestroyWindow(getHandle());
		setHandle(NULL);
	}
}

void Control::update(void) {
	updated = true;
}

void Control::refresh(bool isOwner) {
	updated = false;

	HWND handle = getHandle();
	if (handle != NULL && isOwner) {
		::DestroyWindow(handle);
		handle = NULL;
	}

	if (handle == NULL) {
		handle = createHandle();
		setHandle(handle);
	}

	resetAttribute();

	childs.sort();
	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->refresh(false);
	}
}

void Control::refresh() {
	refresh(true);
}

void Control::terminate(void) {
	terminated = true;
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
	refresh();

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

int Control::getTab(void) const {
	return tab;
}

void Control::setTab(int tab) {
	this->tab = tab;
	update();
}

bool Control::isUpdated(void) const {
	return updated;
}

bool Control::isTerminated(void) const {
	return terminated;
}

void Control::setExStyle(const int exStyle) {
	this->exStyle = exStyle;
}

int Control::getExStyle(void) const {
	return exStyle;
}

bool Control::operator < (const Control* control) {
	return control != NULL && this->tab < control->tab;
};
