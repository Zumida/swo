/*
 * form.hpp
 *
 * Last modified: <2013/08/21 03:18:51 +0900> By Zumida
 */
#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED

#include "eventlistener.hpp"
#include "icon.hpp"
#include "menu.hpp"

namespace swo {
	class Form : public EventListener {
	protected:
		String className;
		int style;
		int exStyle;
		String text;
		Icon* icon;
		Menu* menu;

		void initialize(void);
		HWND createHandle(void);
		bool onDestroy(void);

	public:
		enum FormType {
			DialogModalFrame,
			OverLappedWindow,
			PaletteWindow,
			ToolWindow
		};

		enum WindowOrder {
			Normal,
			Bottom,
			Top,
			TopMost
		};

		Form();
		Form(Control* parent);
		~Form();

		void setClassName(const String& className);
		String& getClassName(void);

		void setStyle(const int style);
		int getStyle(void) const;
		void setExStyle(const int exStyle);
		int getExStyle(void) const;

		void setText(const String& text);
		String& getText(void);
		void setIcon(const Icon& icon);
		Icon& getIcon(void);
		void setMenu(const Menu& menu);
		Menu& getMenu(void);

		void setAcceptFiles(const bool enabled=true);
		bool isAcceptFiles(void) const;
		void setAppWindow(const bool enabled=true);
		bool isAppWindow(void) const;
		void setControlParent(const bool enabled=true);
		bool isControlParent(void) const;
		void setFormType(const FormType formType);
		FormType getFormType(void) const;
		void setMdiChild(const bool enabled=true);
		bool isMdiChild(void) const;
		void setNoActivate(const bool enabled=true);
		bool isNoActivate(void) const;
		void setTopMost(const bool enabled=true);
		bool isTopMost(void);
		void setTransparent(const bool enabled=true);
		bool isTransparent(void);

		void setActiveWindow(void);
		void setForegroundWindow(void);

		static Form& create(void);
		static Form& create(Control& parent);
	};

};

#endif
