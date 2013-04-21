/*
 * control.hpp
 *
 * Last modified: <2013/04/22 00:30:39 +0900> By Zumida
 */
#ifndef CONTROL_HPP_INCLUDED
#define CONTROL_HPP_INCLUDED

#include <list>
#include "eventlistener.hpp"

namespace swo {

	typedef std::list<class Control*> Controls;

	class Control : public EventListener {
	private:
		Control* parent;
		Controls childs;

		int tab;
		bool visible;
		bool updated;
		bool terminated;

		void initialize(void);
		void refresh(bool isOwner);

	protected:
		int exStyle;

		virtual HWND createHandle(void) = 0;
		virtual void resetAttribute(void) = 0;

	public:
		Control();
		Control(Control* parent);
		~Control();

		void renew(void);
		void update(void);
		void refresh(void);
		void terminate(void);

		Control* getParent(void);
		void setParent(Control* parent);
		Controls* getChilds(void);
		void addChild(Control* child);
		void removeChild(Control* child);

		void show(void);
		void hide(void);

		int getTab(void) const;
		void setTab(int tab);

		bool isUpdated(void) const;
		bool isTerminated(void) const;

		void setExStyle(const int exStyle);
		int getExStyle(void) const;

		bool operator < (const Control* control);
	};

};

#endif
