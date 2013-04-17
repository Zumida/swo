/*
 * control.hpp
 *
 * Last modified: <2013/04/17 12:41:16 +0900> By Zumida
 */
#ifndef CONTROL_HPP_INCLUDED
#define CONTROL_HPP_INCLUDED

#include <list>
#include "eventlistener.hpp"

namespace swo {

	typedef std::list<class Control*> Controls;

	enum ControlEdge {
		Nothing,
		Client,
		Static,
		Window,
		ClientWindow,
		ClientStatic,
		WindowStatic,
		ClientWindowStatic
	};

	class Control : public EventListener {
	private:
		Control* parent;
		Controls childs;

		int tab;
		bool visible;
		bool border;
		bool updated;
		bool terminated;

		void initialize(void);
		void refresh(bool isOwner);

	protected:
		ControlEdge edge;

		virtual HWND createHandle(void) = 0;
		virtual void reset(void);

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

		bool hasBorder(void) const;
		void setBorder(bool border);

		bool isUpdated(void) const;
		bool isTerminated(void) const;

		void setControlParent(const bool enabled);
		void setControlEdge(const ControlEdge edge);

		bool operator < (const Control* control);
	};

};

#endif
