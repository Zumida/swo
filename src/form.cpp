/*
 * form.cpp
 *
 * Last modified: <2013/03/26 10:46:24 +0900> By Zumida
 */

#include "form.hpp"
#include "resource.hpp"

using namespace swo;

// 定数
#define WINDOW_WIDTH  (400)		// ウィンドウの幅
#define WINDOW_HEIGHT (300)		// ウィンドウの高さ
#define WINDOW_X ((GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH ) / 2)
#define WINDOW_Y ((GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT) / 2)


static Icon defaultIcon;
static Cursor defaultCursor;

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
	icon   = NULL;
	cursor = NULL;
}

HWND Form::createHandle(void) {
	WNDCLASSEX wc;

	if (icon   == NULL) icon   = &defaultIcon;
	if (cursor == NULL) cursor = &defaultCursor;

	// ウィンドウクラスの情報を設定
	wc.cbSize = sizeof(wc);                 // 構造体サイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;     // スタイル
	wc.lpfnWndProc = WndProc;               // ウィンドウプロシージャ
	wc.cbClsExtra = 0;                      // 拡張情報１
	wc.cbWndExtra = 0;                      // 拡張情報２
	wc.hInstance = ::GetModuleHandle(NULL); // インスタンスハンドル
	wc.hIcon   = icon->getHandle();         // アイコン
	wc.hIconSm = wc.hIcon;                  // 小アイコン
	wc.hCursor = cursor->getHandle();       // マウスカーソル
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ウィンドウ背景
	wc.lpszMenuName  = NULL;                // メニュー名
	wc.lpszClassName = _T("Default Class Name");// ウィンドウクラス名

	// ウィンドウクラスを登録する
	if (RegisterClassEx(&wc) == 0) {
		return NULL;

	} else {
		// ウィンドウを作成する
		return CreateWindow(
			wc.lpszClassName,      // ウィンドウクラス名
			_T("Sample Program"),  // タイトルバーに表示する文字列
			WS_OVERLAPPEDWINDOW,   // ウィンドウの種類
			WINDOW_X,              // ウィンドウを表示する位置（X座標）
			WINDOW_Y,              // ウィンドウを表示する位置（Y座標）
			WINDOW_WIDTH,          // ウィンドウの幅
			WINDOW_HEIGHT,         // ウィンドウの高さ
			NULL,                  // 親ウィンドウのウィンドウハンドル
			NULL,                  // メニューハンドル
			wc.hInstance,          // インスタンスハンドル
			NULL                   // その他の作成データ
		);
	}
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
	this->icon = &icon;
}

void Form::setCursor(const Cursor& cursor) {
	this->cursor = &cursor;
}
