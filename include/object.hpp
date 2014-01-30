/*
 * object.hpp
 *
 * Last modified: <2014/01/30 16:40:42 +0900> By Zumida
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

			String getClassName();
			virtual String toString();
		};

		using ObjectPtrList = std::list<Object*>;
	};
};

#endif
