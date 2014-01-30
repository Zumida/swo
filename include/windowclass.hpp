/*
 * windowclass.hpp
 *
 * Last modified: <2014/01/30 19:54:00 +0900> By Zumida
 */
#ifndef WINDOWCLASS_HPP_INCLUDED
#define WINDOWCLASS_HPP_INCLUDED

#include "eventlistener.hpp"
#include "icon.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "menu.hpp"
#include "exception.hpp"

namespace swo {
	inline namespace window {

		using FuncWndProc = LRESULT CALLBACK (*)(HWND, UINT, WPARAM, LPARAM);

		class WindowClass : public Object {
		public:
			class ExistsClassException : public swo::exception::Exception {
			public:
				ExistsClassException(const String& className);
			};

			class RegisterClassException : public swo::exception::Exception {
			public:
				RegisterClassException(const String& className);
			};

		protected:
			String className;
			String menuName;
			Icon* icon;
			Icon* smallIcon;
			Cursor* cursor;
			Brush* background;
			FuncWndProc wndProc;

		public:
			WindowClass();
			~WindowClass();

			WindowClass& setClassName(const String& className);
			WindowClass& setIcon(const Icon& icon);
			WindowClass& setSmallIcon(const Icon& smallIcon);
			WindowClass& setCursor(const Cursor& cursor);
			WindowClass& setBackground(const Brush& background);
			WindowClass& setMenuName(const String& menuName);
			WindowClass& setWndProc(const FuncWndProc wndProc);

			static void add(class WindowClass& wndClass);
			static WindowClass* find(const String& className);
			static WindowClass& create();
		};
	};
};

#endif
