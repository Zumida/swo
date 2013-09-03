/*
 * form.cpp
 *
 * Last modified: <2013/09/04 02:04:43 +0900> By Zumida
 */
#include "define.hpp"
#include "form.hpp"
#include "application.hpp"
#include "windowclass.hpp"
#include "syscursor.hpp"
#include "syscolorbrush.hpp"
#include "instance.hpp"

using namespace swo;

Form::Form() {
	initialize();
}

Form::Form(Control* parent) {
	initialize();
	setParent(parent);
}

Form::~Form() {
}

void Form::initialize(void) {
	if (WindowClass::find(WINDOW_CLASSNAME) == NULL) {
		WindowClass& wc = WindowClass::create();

		wc.setClassName(WINDOW_CLASSNAME)
			.setCursor(SysCursor::Arrow)
				.setBackground(SysColorBrush::create(COLOR_WINDOW))
					.setWndProc(Application::WndProc);

		WindowClass::add(wc);
	}

	className   = WINDOW_CLASSNAME;
	rect.left   = WINDOW_X;
	rect.top    = WINDOW_Y;
	rect.width  = WINDOW_WIDTH;
	rect.height = WINDOW_HEIGHT;
	icon        = NULL;
	menu        = NULL;
	style       = WS_OVERLAPPEDWINDOW;
	exStyle     = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
}

HWND Form::createHandle(void) {
	HWND hparent = (getParent() != NULL)? getParent()->getHandle(): HWND_DESKTOP;
	HMENU hmenu = (menu != NULL)? menu->getHandle(): NULL;

	// ウィンドウを作成する
	HWND hwnd = CreateWindowEx(
		exStyle,
		className.c_str(),       // ウィンドウクラス名
		text.c_str(),            // タイトルバーに表示する文字列
		style,                   // ウィンドウの種類
		rect.left,               // ウィンドウを表示する位置（X座標）
		rect.top,                // ウィンドウを表示する位置（Y座標）
		rect.width,              // ウィンドウの幅
		rect.height,             // ウィンドウの高さ
		hparent,                 // 親ウィンドウのウィンドウハンドル
		hmenu,                   // メニューハンドル
		::GetModuleHandle(NULL), // インスタンスハンドル
		NULL                     // その他の作成データ
		);

	return hwnd;
}

bool Form::onDestroy(void) {
	if (getParent() == NULL) {
		::PostQuitMessage(0);
		return true;
	} else {
		return false;
	}
}

Form& Form::setClassName(const String& className) {
	this->className = className;
	return *this;
}

String& Form::getClassName(void) {
	return className;
}

Form& Form::setStyle(const int style) {
	this->style = style;
	return *this;
}

int Form::getStyle(void) const {
	return style;
}

Form& Form::setExStyle(const int exStyle) {
	this->exStyle = exStyle;
	return *this;
}

int Form::getExStyle(void) const {
	return exStyle;
}

Form& Form::setText(const String& text) {
	this->text = text;
	return *this;
}

String& Form::getText(void) {
	return text;
}

Form& Form::setIcon(const Icon& icon) {
	this->icon = const_cast<Icon*>(&icon);
	return *this;
}

Icon& Form::getIcon(void) {
	return *icon;
}

Form& Form::setMenu(const Menu& menu) {
	this->menu = const_cast<Menu*>(&menu);
	return *this;
}

Menu& Form::getMenu(void) {
	return *menu;
}

Form& Form::setAcceptFiles(const bool enabled) {
	if (enabled)
		exStyle |= WS_EX_ACCEPTFILES;
	else
		exStyle &= ~WS_EX_ACCEPTFILES;
	return *this;
}
bool Form::isAcceptFiles(void) const {
	return ((exStyle & WS_EX_ACCEPTFILES) != 0);
}
Form& Form::setAppWindow(const bool enabled) {
	return *this;
}
bool Form::isAppWindow(void) const {
	return false;
}
Form& Form::setControlParent(const bool enabled) {
	return *this;
}
bool Form::isControlParent(void) const {
	return false;
}
Form& Form::setFormType(const FormType formType) {
	return *this;
}
Form::FormType Form::getFormType(void) const {
	return DialogModalFrame;
}
Form& Form::setMdiChild(const bool enabled) {
	return *this;
}
bool Form::isMdiChild(void) const {
	return false;
}
Form& Form::setNoActivate(const bool enabled) {
	return *this;
}
bool Form::isNoActivate(void) const {
	return false;
}
Form& Form::setTopMost(const bool enabled) {
	return *this;
}
bool Form::isTopMost(void) {
	return false;
}
Form& Form::setTransparent(const bool enabled) {
	return *this;
}
bool Form::isTransparent(void) {
	return false;
}

Form& Form::setActiveWindow(void) {
	return *this;
}
Form& Form::setForegroundWindow(void) {
	return *this;
}

Form& Form::setParent(Control* parent) {
	Control::setParent(parent);
	return *this;
}

Form& Form::addChild(Control* child) {
	Control::addChild(child);
	return *this;
}

Form& Form::removeChild(Control* child) {
	Control::removeChild(child);
	return *this;
}

Form& Form::setRect(const WindowRect& rect) {
	Control::setRect(rect);
	return *this;
}

Form& Form::setBackground(const Brush& brush) {
	Control::setBackground(brush);
	return *this;
}

Form& Form::setCursor(const Cursor& cursor) {
	Control::setCursor(cursor);
	return *this;
}

Form& Form::setTab(int tab) {
	Control::setTab(tab);
	return *this;
}

Form& Form::create(void) {
	return Instance::create<Form>();
}

Form& Form::create(Control& parent) {
	return Instance::create<Form>(parent);
}
