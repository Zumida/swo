/*
 * windowclass.cpp
 *
 * Last modified: <2013/04/09 21:27:47 +0900> By Zumida
 */
#include <map>
#include "windowclass.hpp"
#include "resource.hpp"

using namespace swo;

typedef std::map<String, class WindowClass> WndClassMap;

static WndClassMap wndClassMap;

WindowClass::WindowClass() {
	icon        = NULL;
	smallIcon   = NULL;
	cursor      = NULL;
	background  = NULL;
	wndProc     = NULL;
}

WindowClass::~WindowClass() {
}

void WindowClass::setClassName(const String& className) {
	this->className = className;
}

void WindowClass::setIcon(const Icon& icon) {
	this->icon = const_cast<Icon*>(&icon);
}

void WindowClass::setSmallIcon(const Icon& smallIcon) {
	this->smallIcon = const_cast<Icon*>(&smallIcon);
}

void WindowClass::setCursor(const Cursor& cursor) {
	this->cursor = const_cast<Cursor*>(&cursor);
}

void WindowClass::setBackground(const Brush& background) {
	this->background = const_cast<Brush*>(&background);
}

void WindowClass::setWndProc(const FuncWndProc wndProc) {
	this->wndProc = wndProc;
}

void WindowClass::add(class WindowClass& wndClass) {
	WNDCLASSEX wc = {0};

	// ウィンドウクラスの情報を設定
	wc.cbSize = sizeof(wc);                 // 構造体サイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;     // スタイル
	wc.lpfnWndProc = wndClass.wndProc;      // ウィンドウプロシージャ
	wc.cbClsExtra = 0;                      // 拡張情報１
	wc.cbWndExtra = 0;                      // 拡張情報２
	wc.hInstance = ::GetModuleHandle(NULL); // インスタンスハンドル
	wc.lpszClassName = wndClass.className.c_str(); // ウィンドウクラス名

	// アイコン
	if (wndClass.icon != NULL)
		wc.hIcon = wndClass.icon->getHandle();

	// 小アイコン
	if (wndClass.smallIcon != NULL)
		wc.hIconSm = wndClass.smallIcon->getHandle();

	// マウスカーソル
	if (wndClass.cursor != NULL)
		wc.hCursor = wndClass.cursor->getHandle();

	// ウィンドウ背景
	if (wndClass.background != NULL)
		wc.hbrBackground = wndClass.background->getBrush();

	// メニュー名
	if (!wndClass.menuName.empty())
		wc.lpszMenuName  = wndClass.menuName.c_str();

	// ウィンドウクラスを登録する
	if (RegisterClassEx(&wc) != 0) {
		wndClassMap.insert(std::make_pair(wndClass.className, wndClass));
	}
}

class WindowClass* WindowClass::find(const String& className) {
	WndClassMap::iterator it = wndClassMap.find(className);

	return (it == wndClassMap.end())? NULL: &it->second;
}
