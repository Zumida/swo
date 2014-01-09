/*
 * object.hpp
 *
 * Last modified: <2014/01/09 11:58:31 +0900> By Zumida
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"

#include <list>
#include <windows.h>

namespace swo {
	inline namespace core {

		class Object {
		public:
			Object();
			virtual ~Object();

			String getClassName(void);
			virtual String toString(void);
		};

		using ObjectPtrList = std::list<Object*>;
	};
};

#endif
