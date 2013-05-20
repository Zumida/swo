/*
 * control.cpp
 *
 * Last modified: <2013/05/21 00:12:12 +0900> By Zumida
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
	parent      = NULL;
	childs.clear();

	rect.left   = 0;
	rect.top    = 0;
	rect.width  = 0;
	rect.height = 0;
	background  = NULL;
	cursor      = NULL;

	tab         = 0;
	visible     = false;
	updated     = true;
	terminated  = false;
}

void Control::setAttributes(HWND handle) {
	UINT uFlags = SWP_SHOWWINDOW|SWP_DRAWFRAME|SWP_NOZORDER|SWP_SHOWWINDOW
		| (visible ? SWP_SHOWWINDOW: SWP_HIDEWINDOW);

	::SetWindowPos(handle, NULL,
				   rect.left, rect.top,
				   rect.width, rect.height,
				   uFlags);

	
}

void Control::renew(void) {
	update();

	HWND handle = getHandle();
	if (handle != NULL) {
		::DestroyWindow(handle);
		setHandle(NULL);
	}

	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->setHandle(NULL);
	}

	refresh();
}

void Control::update(void) {
	updated = true;
}

void Control::refresh(void) {
	updated = false;

	HWND handle = getHandle();
	if (handle == NULL) {
		handle = createHandle();
		setHandle(handle);
	}

	setAttributes(handle);

	childs.sort();
	for (Controls::iterator it = childs.begin();
		 it != childs.end();
		 it++) {

		(*it)->refresh();
	}
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

void Control::setRect(const WindowRect& rect) {
	this->rect = rect;
}

WindowRect& Control::getRect(void) {
	return rect;
}

void Control::setBackground(const Brush& brush) {
	this->background = const_cast<Brush*>(&brush);
	update();
}

Brush& Control::getBackground(void) {
	return *background;
}

void Control::setCursor(const Cursor& cursor) {
	this->cursor = const_cast<Cursor*>(&cursor);
	update();
}

Cursor& Control::getCursor(void) {
	return *cursor;
}

void Control::setTab(int tab) {
	this->tab = tab;
	update();
}

int Control::getTab(void) const {
	return tab;
}

bool Control::isUpdated(void) const {
	return updated;
}

bool Control::isTerminated(void) const {
	return terminated;
}

bool Control::operator < (const Control* control) {
	return control != NULL && this->tab < control->tab;
};
