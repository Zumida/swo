/*
 * control.cpp
 *
 * Last modified: <2014/01/09 15:02:49 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "control.hpp"
#include <algorithm>

namespace swo {
	inline namespace control {

		/*
		 * コンストラクタ
		 *
		 * プライベート変数を初期化する。
		 */
		Control::Control() {
			initialize();
		}

		Control::Control(Control& parent) {
			initialize();
			setParent(&parent);
		}

		/*
		 * デストラクタ
		 *
		 * 内部管理のオブジェクトを解放する。
		 */
		Control::~Control() {
			if (getHandle() != nullptr) {
				::DestroyWindow(getHandle());
				setHandle(nullptr);
			}
		}

		void Control::initialize(void) {
			handle      = nullptr;
			parent      = nullptr;

			rect.left   = 0;
			rect.top    = 0;
			rect.width  = 0;
			rect.height = 0;
			background  = nullptr;
			cursor      = nullptr;

			tab         = 0;
			visible     = false;
			updated     = true;
			terminated  = false;
		}

		void Control::resetHandle(void) {
			this->handle = nullptr;
		}

		void Control::setHandle(HWND handle) {
			this->handle = handle;
		}

		HWND Control::getHandle(void) const {
			return handle;
		}

		void Control::setAttributes(HWND handle) {
			UINT uFlags = SWP_SHOWWINDOW
				| SWP_DRAWFRAME
					| SWP_NOZORDER
						| SWP_SHOWWINDOW
				| (visible ? SWP_SHOWWINDOW: SWP_HIDEWINDOW);

			::SetWindowPos(handle, nullptr,
						   rect.left, rect.top,
						   rect.width, rect.height,
						   uFlags);
		}

		void Control::renew(void) {
			update();

			HWND handle = getHandle();
			if (handle != nullptr) {
				::DestroyWindow(handle);
				setHandle(nullptr);
			}

			refresh();
		}

		void Control::update(void) {
			updated = true;
		}

		void Control::refresh(void) {
			updated = false;

			HWND handle = getHandle();
			if (handle == nullptr) {
				handle = createHandle();
				setHandle(handle);
			}

			setAttributes(handle);
		}

		void Control::terminate(void) {
			terminated = true;
		}

		Control* Control::getParent(void) {
			return parent;
		}

		void Control::setParent(Control* parent) {
			this->parent = parent;
			update();
		}

		void Control::show(void) {
			visible = true;
			refresh();

			HWND hWnd = getHandle();
			if (hWnd != nullptr) {
				::ShowWindow(hWnd, SW_SHOW);
				::UpdateWindow(hWnd);
			}
		}

		void Control::hide(void) {
			visible = false;

			HWND hWnd = getHandle();
			if (hWnd != nullptr) {
				::ShowWindow(hWnd, SW_HIDE);
				::UpdateWindow(hWnd);
			}
		}

		void Control::setRect(const WindowRect& rect) {
			this->rect = rect;
			update();
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
			return control != nullptr && this->tab < control->tab;
		};
	};
};
