/*
 * form.hpp
 *
 * Last modified: <2013/04/23 01:38:42 +0900> By Zumida
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

		void setAcceptFiles(const bool enabled=true);
		void setAppWindow(const bool enabled=true);
		void setControlParent(const bool enabled=true);
		void setFormType(const FormType formType);
		void setMdiChild(const bool enabled=true);
		void setNoActivate(const bool enabled=true);
		void setTopMost(const bool enabled=true);
		void setTransparent(const bool enabled=true);
		
		void setSwpFlags(const int swpFlags);

		void setActiveWindow(void);
		void setForegroundWindow(void);
	};

};

#endif
