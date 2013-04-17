/*
 * form.hpp
 *
 * Last modified: <2013/04/18 02:20:35 +0900> By Zumida
 */
#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED

#include "control.hpp"
#include "icon.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "menu.hpp"

namespace swo {
	enum FormType {
		DialogModalFrame,
		OverLappedWindow,
		PaletteWindow,
		ToolWindow
	};

	class Form : public Control {
	private:
		String className;
		String text;
		WindowRect rect;
		Icon* icon;
		Cursor* cursor;
		Brush* background;
		Menu* menu;

		void initialize(void);

	protected:
		HWND createHandle(void);
		void resetAttribute(void);
		bool onDestroy(void);

	public:
		Form();
		Form(Control* parent);
		~Form();

		void setIcon(const Icon& icon);
		void setCursor(const Cursor& cursor);
		void setBackground(const Brush& brush);
		void setClassName(const String& className);
		void setText(const String& text);
		void setRect(const WindowRect& rect);
		void setMenu(const Menu& menu);

		void setAcceptFiles(const bool enabled);
		void setAppWindow(const bool enabled);
		void setFormType(const FormType formType);
		void setMdiChild(const bool enabled);
		void setActivate(const bool enabled);
		void setTopMost(const bool enabled);
		void setTransparent(const bool enabled);
	};

};

#endif
