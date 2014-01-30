/*
 * form.cpp
 *
 * Last modified: <2014/01/30 16:38:55 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "form.hpp"
#include "application.hpp"
#include "windowclass.hpp"
#include "syscursor.hpp"
#include "syscolorbrush.hpp"
#include "instance.hpp"

#define WINDOW_WIDTH  (400)		// ウィンドウの幅
#define WINDOW_HEIGHT (300)		// ウィンドウの高さ
#define WINDOW_X ((GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH ) / 2)
#define WINDOW_Y ((GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT) / 2)
#define WINDOW_CLASSNAME L"SWO Form Class"

namespace swo {
	inline namespace container {

		Form::Form() : Container() {
			initialize();
		}

		Form::Form(Control& parent) : Container(parent) {
			initialize();
		}

		Form::~Form() {
		}

		void Form::initialize() {
			if (WindowClass::find(WINDOW_CLASSNAME) == nullptr) {
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
			icon        = nullptr;
			menu        = nullptr;
			style       = WS_OVERLAPPEDWINDOW;
			exStyle     = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
		}

		HWND Form::createHandle() {
			HWND hparent = (getParent() != nullptr)? getParent()->getHandle(): HWND_DESKTOP;
			HMENU hmenu = (menu != nullptr)? menu->getHandle(): nullptr;

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
				::GetModuleHandle(nullptr), // インスタンスハンドル
				nullptr                     // その他の作成データ
				);

			return hwnd;
		}

		bool Form::onDestroy() {
			if (getParent() == nullptr) {
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

		String& Form::getClassName() {
			return className;
		}

		Form& Form::setStyle(const int style) {
			this->style = style;
			return *this;
		}

		int Form::getStyle() const {
			return style;
		}

		Form& Form::setExStyle(const int exStyle) {
			this->exStyle = exStyle;
			return *this;
		}

		int Form::getExStyle() const {
			return exStyle;
		}

		Form& Form::setText(const String& text) {
			this->text = text;
			return *this;
		}

		String& Form::getText() {
			return text;
		}

		Form& Form::setIcon(const Icon& icon) {
			this->icon = const_cast<Icon*>(&icon);
			return *this;
		}

		Icon& Form::getIcon() {
			return *icon;
		}

		Form& Form::setMenu(const Menu& menu) {
			this->menu = const_cast<Menu*>(&menu);
			return *this;
		}

		Menu& Form::getMenu() {
			return *menu;
		}

		Form& Form::setAcceptFiles(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_ACCEPTFILES;
			else
				exStyle &= ~WS_EX_ACCEPTFILES;
			return *this;
		}

		bool Form::isAcceptFiles() const {
			return ((exStyle & WS_EX_ACCEPTFILES) != 0);
		}

		Form& Form::setAppWindow(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_APPWINDOW;
			else
				exStyle &= ~WS_EX_APPWINDOW;
			return *this;
		}

		bool Form::isAppWindow() const {
			return ((exStyle & WS_EX_APPWINDOW) != 0);
		}

		Form& Form::setControlParent(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_CONTROLPARENT;
			else
				exStyle &= ~WS_EX_CONTROLPARENT;
			return *this;
		}

		bool Form::isControlParent() const {
			return ((exStyle & WS_EX_CONTROLPARENT) != 0);
		}

		Form& Form::setFormType(const FormType formType) {
			exStyle &= ~(WS_EX_DLGMODALFRAME
						 |WS_EX_OVERLAPPEDWINDOW
						 |WS_EX_PALETTEWINDOW
						 |WS_EX_TOOLWINDOW);

			switch (formType) {
			default:
			case DialogModalFrame:
				exStyle |= WS_EX_DLGMODALFRAME;
				break;
			case OverLappedWindow:
				exStyle |= WS_EX_OVERLAPPEDWINDOW;
				break;
			case PaletteWindow:
				exStyle |= WS_EX_PALETTEWINDOW;
				break;
			case ToolWindow:
				exStyle |= WS_EX_TOOLWINDOW;
				break;
			}
			return *this;
		}

		Form::FormType Form::getFormType() const {
			FormType formType;

			if ((exStyle & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME)
				formType = DialogModalFrame;
			else if ((exStyle & WS_EX_OVERLAPPEDWINDOW) == WS_EX_OVERLAPPEDWINDOW)
				formType = OverLappedWindow;
			else if ((exStyle & WS_EX_PALETTEWINDOW) == WS_EX_PALETTEWINDOW)
				formType = PaletteWindow;
			else if ((exStyle & WS_EX_TOOLWINDOW) == WS_EX_TOOLWINDOW)
				formType = ToolWindow;
			else
				formType = DialogModalFrame;

			return formType;
		}

		Form& Form::setMdiChild(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_MDICHILD;
			else
				exStyle &= ~WS_EX_MDICHILD;
			return *this;
		}

		bool Form::isMdiChild() const {
			return ((exStyle & WS_EX_MDICHILD) != 0);
		}

		Form& Form::setNoActivate(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_NOACTIVATE;
			else
				exStyle &= ~WS_EX_NOACTIVATE;
			return *this;
		}

		bool Form::isNoActivate() const {
			return ((exStyle & WS_EX_NOACTIVATE) != 0);
		}

		Form& Form::setTopMost(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_TOPMOST;
			else
				exStyle &= ~WS_EX_TOPMOST;
			return *this;
		}

		bool Form::isTopMost() {
			return ((exStyle & WS_EX_TOPMOST) != 0);
		}

		Form& Form::setTransparent(const bool enabled) {
			if (enabled)
				exStyle |= WS_EX_TRANSPARENT;
			else
				exStyle &= ~WS_EX_TRANSPARENT;
			return *this;
		}

		bool Form::isTransparent() {
			return ((exStyle & WS_EX_TRANSPARENT) != 0);
		}

		Form& Form::setActiveWindow() {
			::SetActiveWindow(getHandle());
			return *this;
		}

		Form& Form::setForegroundWindow() {
			::SetForegroundWindow(getHandle());
			return *this;
		}

		Form& Form::setParent(Control* parent) {
			Control::setParent(parent);
			return *this;
		}

		Form& Form::addChild(Control& child) {
			Container::addChild(child);
			return *this;
		}

		Form& Form::removeChild(Control& child) {
			Container::removeChild(child);
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

		Form& Form::create() {
			return Instance::create<Form>();
		}

		Form& Form::create(Control& parent) {
			return Instance::create<Form>(parent);
		}
	};
};
