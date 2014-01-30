/*
 * container.hpp
 *
 * Last modified: <2014/01/30 16:39:25 +0900> By Zumida
 */
#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include "EventListener.hpp"

namespace swo {
	inline namespace control {
		class Container : public EventListener {
		protected:
			ControlPtrList childs;

		public:
			Container();
			Container(Control& parent);
			~Container();

			ControlPtrList& getChilds();
			void addChild(Control& child);
			void removeChild(Control& child);

			void renew();
			void refresh();
		};
	};
};

#endif
