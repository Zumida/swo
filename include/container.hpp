/*
 * container.hpp
 *
 * Last modified: <2013/10/20 16:05:06 +0900> By Zumida
 */
#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include "EventListener.hpp"
#include <list>

namespace swo {

	typedef std::list<class Control*> Controls;

	class Container : public EventListener {
	protected:
		Controls childs;

	public:
		Container();
		Container(Control& parent);
		~Container();

		Controls& getChilds(void);
		void addChild(Control& child);
		void removeChild(Control& child);

		void renew(void);
		void refresh(void);
	};
};

#endif
