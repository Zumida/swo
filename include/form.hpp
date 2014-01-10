/*
 * form.hpp
 *
 * Last modified: <2014/01/10 15:36:42 +0900> By Zumida
 */
#ifndef FORM_HPP_INCLUDED
#define FORM_HPP_INCLUDED

#include "container.hpp"
#include "icon.hpp"
#include "menu.hpp"

namespace swo {
	inline namespace container {

		class Form : public Container {
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
			Form(Control& parent);
			~Form();

			Form& setClassName(const String& className);
			String& getClassName(void);

			Form& setStyle(const int style);
			int getStyle(void) const;
			Form& setExStyle(const int exStyle);
			int getExStyle(void) const;

			Form& setText(const String& text);
			String& getText(void);
			Form& setIcon(const Icon& icon);
			Icon& getIcon(void);
			Form& setMenu(const Menu& menu);
			Menu& getMenu(void);

			Form& setAcceptFiles(const bool enabled=true);
			bool isAcceptFiles(void) const;
			Form& setAppWindow(const bool enabled=true);
			bool isAppWindow(void) const;
			Form& setControlParent(const bool enabled=true);
			bool isControlParent(void) const;
			Form& setFormType(const FormType formType);
			FormType getFormType(void) const;
			Form& setMdiChild(const bool enabled=true);
			bool isMdiChild(void) const;
			Form& setNoActivate(const bool enabled=true);
			bool isNoActivate(void) const;
			Form& setTopMost(const bool enabled=true);
			bool isTopMost(void);
			Form& setTransparent(const bool enabled=true);
			bool isTransparent(void);

			Form& setActiveWindow(void);
			Form& setForegroundWindow(void);

			Form& setParent(Control* parent);
			Form& addChild(Control& child);
			Form& removeChild(Control& child);
			Form& setRect(const WindowRect& rect);
			Form& setBackground(const Brush& brush);
			Form& setCursor(const Cursor& cursor);
			Form& setTab(int tab);

			static Form& create(void);
			static Form& create(Control& parent);
		};
	};
};

#endif
