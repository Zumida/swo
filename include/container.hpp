/*
 * container.hpp
 *
 * Last modified: <2014/01/09 14:08:12 +0900> By Zumida
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

			ControlPtrList& getChilds(void);
			void addChild(Control& child);
			void removeChild(Control& child);

			void renew(void);
			void refresh(void);
		};
	};
};

#endif
