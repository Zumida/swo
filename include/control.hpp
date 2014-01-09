/*
 * control.hpp
 *
 * Last modified: <2014/01/09 12:33:54 +0900> By Zumida
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

			void initialize(void);

			virtual HWND createHandle(void) = 0;
			virtual void setHandle(HWND handle);
			virtual void setAttributes(HWND handle);

		public:
			Control();
			Control(Control& parent);
			~Control();

			HWND getHandle(void) const;
			void resetHandle(void);

			virtual void renew(void);
			virtual void update(void);
			virtual void refresh(void);
			virtual void terminate(void);

			virtual void show(void);
			virtual void hide(void);

			Control* getParent(void);
			void setParent(Control* parent);

			void setRect(const WindowRect& rect);
			WindowRect& getRect(void);
			void setBackground(const Brush& brush);
			Brush& getBackground(void);
			void setCursor(const Cursor& cursor);
			Cursor& getCursor(void);

			void setTab(int tab);
			int getTab(void) const;

			bool isUpdated(void) const;
			bool isTerminated(void) const;

			bool operator < (const Control* control);
		};

		using ControlPtrList = std::list<class Control*>;
	};
};

#endif
