/*
 * windowclass.hpp
 *
 * Last modified: <2013/04/17 12:36:17 +0900> By Zumida
 */
#ifndef WINDOWCLASS_HPP_INCLUDED
#define WINDOWCLASS_HPP_INCLUDED

#include "eventlistener.hpp"
#include "icon.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "menu.hpp"

namespace swo {

	typedef LRESULT CALLBACK (*FuncWndProc)(HWND, UINT, WPARAM, LPARAM);

	class WindowClass : public Object {
	private:
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

		void setClassName(const String& className);
		void setIcon(const Icon& icon);
		void setSmallIcon(const Icon& smallIcon);
		void setCursor(const Cursor& cursor);
		void setBackground(const Brush& background);
		void setMenuName(const String& menuName);
		void setWndProc(const FuncWndProc wndProc);

		static void add(class WindowClass& wndClass);
		static class WindowClass* find(const String& className);
	};

};

#endif
