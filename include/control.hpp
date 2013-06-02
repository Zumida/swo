/*
 * control.hpp
 *
 * Last modified: <2013/06/03 01:46:34 +0900> By Zumida
 */
#ifndef CONTROL_HPP_INCLUDED
#define CONTROL_HPP_INCLUDED

#include <list>
#include "object.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "rect.hpp"

namespace swo {

	typedef std::list<class Control*> Controls;

	class Control : public Object {
	private:
		HWND handle;

	protected:
		Control* parent;
		Controls childs;

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
		Control(Control* parent);
		~Control();

		HWND getHandle(void) const;

		void renew(void);
		void update(void);
		void refresh(void);
		void terminate(void);

		void show(void);
		void hide(void);

		Control* getParent(void);
		void setParent(Control* parent);
		Controls* getChilds(void);
		void addChild(Control* child);
		void removeChild(Control* child);

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

};

#endif
