/*
 * object.hpp
 *
 * Last modified: <2014/01/08 09:51:27 +0900> By Zumida
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"

#include <list>
#include <windows.h>

namespace swo {

	class Object {
	public:
		Object();
		virtual ~Object();

		String getClassName(void);
		virtual String toString(void);
	};

	using Objects = std::list<Object*>;
};

#endif
