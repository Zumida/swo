/*
 * windowclass.cpp
 *
 * Last modified: <2014/01/30 16:41:25 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "windowclass.hpp"
#include "instance.hpp"
#include "syscolorbrush.hpp"
#include <map>

using namespace swo;

typedef std::map<String, class WindowClass*> WndClassMap;

static WndClassMap wndClassMap;

WindowClass::WindowClass() {
	icon        = nullptr;
	smallIcon   = nullptr;
	cursor      = nullptr;
	background  = nullptr;
	wndProc     = nullptr;
}

WindowClass::~WindowClass() {
	if (!className.empty()) {
		UnregisterClass(className.c_str(), ::GetModuleHandle(nullptr));
	}
}

WindowClass& WindowClass::setClassName(const String& className) {
	this->className = className;
	return *this;
}

WindowClass& WindowClass::setIcon(const Icon& icon) {
	this->icon = const_cast<Icon*>(&icon);
	return *this;
}

WindowClass& WindowClass::setSmallIcon(const Icon& smallIcon) {
	this->smallIcon = const_cast<Icon*>(&smallIcon);
	return *this;
}

WindowClass& WindowClass::setCursor(const Cursor& cursor) {
	this->cursor = const_cast<Cursor*>(&cursor);
	return *this;
}

WindowClass& WindowClass::setBackground(const Brush& background) {
	this->background = const_cast<Brush*>(&background);
	return *this;
}

WindowClass& WindowClass::setWndProc(const FuncWndProc wndProc) {
	this->wndProc = wndProc;
	return *this;
}

void WindowClass::add(class WindowClass& wndClass) {
	WNDCLASSEX wc = {0};

	// ウィンドウクラスの情報を設定
	wc.cbSize = sizeof(wc);                 // 構造体サイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;     // スタイル
	wc.lpfnWndProc = wndClass.wndProc;      // ウィンドウプロシージャ
	wc.cbClsExtra = 0;                      // 拡張情報１
	wc.cbWndExtra = 0;                      // 拡張情報２
	wc.hInstance = ::GetModuleHandle(nullptr); // インスタンスハンドル
	wc.lpszClassName = wndClass.className.c_str(); // ウィンドウクラス名

	// アイコン
	if (wndClass.icon != nullptr)
		wc.hIcon = wndClass.icon->getHandle();

	// 小アイコン
	if (wndClass.smallIcon != nullptr)
		wc.hIconSm = wndClass.smallIcon->getHandle();
	if (wc.hIconSm == nullptr) wc.hIconSm = wc.hIcon;

	// マウスカーソル
	if (wndClass.cursor != nullptr)
		wc.hCursor = wndClass.cursor->getHandle();

	// ウィンドウ背景
	if (wndClass.background != nullptr) {
		SysColorBrush* sb = dynamic_cast<SysColorBrush*>(wndClass.background);
		if (sb != nullptr) {
			wc.hbrBackground = (HBRUSH)(sb->getIndex() + 1);
		} else {
			wc.hbrBackground = wndClass.background->getHandle();
		}
	}

	// メニュー名
	if (!wndClass.menuName.empty())
		wc.lpszMenuName  = wndClass.menuName.c_str();

	// ウィンドウクラスを登録する
	if (RegisterClassEx(&wc) != 0) {
		wndClassMap.insert(std::make_pair(wndClass.className, &wndClass));
	}
}

WindowClass* WindowClass::find(const String& className) {
	WndClassMap::iterator it = wndClassMap.find(className);
	return (it == wndClassMap.end())? nullptr: it->second;
}

WindowClass& WindowClass::create() {
	return Instance::create<WindowClass>();
}
