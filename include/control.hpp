/*
 * control.hpp
 *
 * Last modified: <2014/01/30 16:39:31 +0900> By Zumida
 */
#ifndef CONTROL_HPP_INCLUDED
#define CONTROL_HPP_INCLUDED

#include "swoconfig.hpp"
#include "object.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "rect.hpp"

namespace swo {
	inline namespace control {

		class Control : public Object {
		private:
			HWND handle;

		protected:
			Control* parent;

			WindowRect rect;
			Brush* background;
			Cursor* cursor;

			int tab;
			bool visible;
			bool updated;
			bool terminated;

			void initialize();

			virtual HWND createHandle() = 0;
			virtual void setHandle(HWND handle);
			virtual void setAttributes(HWND handle);

		public:
			Control();
			Control(Control& parent);
			~Control();

			HWND getHandle() const;
			void resetHandle();

			virtual void renew();
			virtual void update();
			virtual void refresh();
			virtual void terminate();

			virtual void show();
			virtual void hide();

			Control* getParent();
			void setParent(Control* parent);

			void setRect(const WindowRect& rect);
			WindowRect& getRect();
			void setBackground(const Brush& brush);
			Brush& getBackground();
			void setCursor(const Cursor& cursor);
			Cursor& getCursor();

			void setTab(int tab);
			int getTab() const;

			bool isUpdated() const;
			bool isTerminated() const;

			bool operator < (const Control* control);
		};

		using ControlPtrList = std::list<class Control*>;
	};
};

#endif
