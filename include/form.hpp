/*
 * form.hpp
 *
 * Last modified: <2013/03/26 12:48:32 +0900> By Zumida
 */
#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED

#include "control.hpp"
#include "icon.hpp"
#include "cursor.hpp"
#include "menu.hpp"

namespace swo {

	typedef std::map<String, WNDCLASSEX> WndClassMap;

	class Form : public Control {
	private:
		const Icon *icon;
		const Cursor *cursor;
		int background;
		String menuName;
		String className;
		String text;
		Rect rect;
		const Menu *menu;

		void initialize(void);

	protected:
		HWND createHandle(void);
		bool onDestroy(void);

		static WNDCLASSEX& getWndClass(const String& className);

	public:
		Form();
		Form(Control* parent);
		virtual ~Form();

		void setIcon(const Icon& icon);
		void setCursor(const Cursor& cursor);
		void setBackground(const int brush);
		void setMenuName(const String& menuName);
		void setClassName(const String& className);
		void setText(const String& text);
		void setRect(const Rect& rect);
		void setMenu(const Menu& menu);
	};

};

#endif
