/*
 * control.hpp
 *
 * Last modified: <2013/04/12 22:00:35 +0900> By Zumida
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
		bool border;
		bool updated;

		void initialize(void);
		void sync(bool isOwner);
		void refresh(bool isOwner);

	protected:
		virtual HWND createHandle(void) = 0;

	public:
		Control();
		Control(Control* parent);
		~Control();

		void update(void);
		void sync(void);
		void refresh(void);

		Control* getParent(void);
		void setParent(Control* parent);
		Controls* getChilds(void);
		void addChild(Control* child);
		void removeChild(Control* child);

		void show(void);
		void hide(void);

		int getTab(void);
		void setTab(int tab);

		bool hasBorder(void);
		void setBorder(bool border);

		bool operator < (const Control* control);
	};

};

#endif
