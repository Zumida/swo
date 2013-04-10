/*
 * form.cpp
 *
 * Last modified: <2013/04/10 23:06:50 +0900> By Zumida
 */
#include "form.hpp"
#include "resource.hpp"

using namespace swo;

// 定数
#define WINDOW_WIDTH  (400)		// ウィンドウの幅
#define WINDOW_HEIGHT (300)		// ウィンドウの高さ
#define WINDOW_X ((GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH ) / 2)
#define WINDOW_Y ((GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT) / 2)

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
	icon        = NULL;
	cursor      = NULL;
	background  = NULL;
	menu        = NULL;
	rect.left   = WINDOW_X;
	rect.top    = WINDOW_Y;
	rect.width  = WINDOW_WIDTH;
	rect.height = WINDOW_HEIGHT;
}

HWND Form::createHandle(void) {
	HWND hparent = (getParent() != NULL)? getParent()->getHandle(): NULL;
	HMENU hmenu = (menu != NULL)? menu->getHandle(): NULL;

	// ウィンドウを作成する
	// TODO : CreateWindowEx()
	HWND hwnd = CreateWindow(
		className.c_str(),       // ウィンドウクラス名
		text.c_str(),            // タイトルバーに表示する文字列
		WS_OVERLAPPEDWINDOW,     // ウィンドウの種類
		rect.left,               // ウィンドウを表示する位置（X座標）
		rect.top,                // ウィンドウを表示する位置（Y座標）
		rect.width,              // ウィンドウの幅
		rect.height,             // ウィンドウの高さ
		hparent,                 // 親ウィンドウのウィンドウハンドル
		hmenu,                   // メニューハンドル
		::GetModuleHandle(NULL), // インスタンスハンドル
		NULL                     // その他の作成データ
		);

	// TODO : アイコン他の設定

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

void Form::setIcon(const Icon& icon) {
	this->icon = const_cast<Icon*>(&icon);
}

void Form::setCursor(const Cursor& cursor) {
	this->cursor = const_cast<Cursor*>(&cursor);
}
