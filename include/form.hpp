/*
 * form.hpp
 *
 * Last modified: <2014/01/31 16:31:07 +0900> By Zumida
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
			Icon* smallIcon;
			Menu* menu;

			HWND createHandle();
			void setAttributes(HWND handle);
			bool onDestroy();

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
			const String& getClassName() const;

			Form& setStyle(const int style);
			int getStyle() const;
			Form& setExStyle(const int exStyle);
			int getExStyle() const;

			Form& setText(const String& text);
			const String& getText() const;
			Form& setIcon(const Icon& icon);
			const Icon& getIcon() const;
			Form& setSmallIcon(const Icon& icon);
			const Icon& getSmallIcon() const;
			Form& setMenu(const Menu& menu);
			const Menu& getMenu() const;

			Form& setAcceptFiles(const bool enabled=true);
			bool isAcceptFiles() const;
			Form& setAppWindow(const bool enabled=true);
			bool isAppWindow() const;
			Form& setControlParent(const bool enabled=true);
			bool isControlParent() const;
			Form& setFormType(const FormType formType);
			FormType getFormType() const;
			Form& setMdiChild(const bool enabled=true);
			bool isMdiChild() const;
			Form& setNoActivate(const bool enabled=true);
			bool isNoActivate() const;
			Form& setTopMost(const bool enabled=true);
			bool isTopMost();
			Form& setTransparent(const bool enabled=true);
			bool isTransparent();

			Form& setActiveWindow();
			Form& setForegroundWindow();

			Form& setParent(Control* parent);
			Form& addChild(Control& child);
			Form& removeChild(Control& child);
			Form& setRect(const WindowRect& rect);
			Form& setBackground(const Brush& brush);
			Form& setCursor(const Cursor& cursor);
			Form& setTab(int tab);

			static Form& create();
			static Form& create(Control& parent);
		};
	};
};

#endif
