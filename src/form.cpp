/*
 * form.cpp
 *
 * Last modified: <2013/09/02 23:31:39 +0900> By Zumida
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

void Form::setClassName(const String& className) {
	this->className = className;
}

String& Form::getClassName(void) {
	return className;
}

void Form::setStyle(const int style) {
	this->style = style;
}

int Form::getStyle(void) const {
	return style;
}

void Form::setExStyle(const int exStyle) {
	this->exStyle = exStyle;
}

int Form::getExStyle(void) const {
	return exStyle;
}

void Form::setText(const String& text) {
	this->text = text;
}

String& Form::getText(void) {
	return text;
}

void Form::setIcon(const Icon& icon) {
	this->icon = const_cast<Icon*>(&icon);
}

Icon& Form::getIcon(void) {
	return *icon;
}

void Form::setMenu(const Menu& menu) {
	this->menu = const_cast<Menu*>(&menu);
}

Menu& Form::getMenu(void) {
	return *menu;
}

void Form::setAcceptFiles(const bool enabled) {
}
bool Form::isAcceptFiles(void) const {
	return false;
}
void Form::setAppWindow(const bool enabled) {
}
bool Form::isAppWindow(void) const {
	return false;
}
void Form::setControlParent(const bool enabled) {
}
bool Form::isControlParent(void) const {
	return false;
}
void Form::setFormType(const FormType formType) {
}
Form::FormType Form::getFormType(void) const {
	return DialogModalFrame;
}
void Form::setMdiChild(const bool enabled) {
}
bool Form::isMdiChild(void) const {
	return false;
}
void Form::setNoActivate(const bool enabled) {
}
bool Form::isNoActivate(void) const {
	return false;
}
void Form::setTopMost(const bool enabled) {
}
bool Form::isTopMost(void) {
	return false;
}
void Form::setTransparent(const bool enabled) {
}
bool Form::isTransparent(void) {
	return false;
}

void Form::setActiveWindow(void) {
}
void Form::setForegroundWindow(void) {
}

Form& Form::create(void) {
	return Instance::create<Form>();
}

Form& Form::create(Control& parent) {
	return Instance::create<Form>(parent);
}
