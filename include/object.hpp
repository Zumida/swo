/*
 * object.hpp
 *
 * Last modified: <2013/05/06 22:17:35 +0900> By Zumida
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <list>
#include <windows.h>
#include <commctrl.h>
#include "string.hpp"

namespace swo {

	typedef std::list<class Object*> Objects;

	class Object {
	public:
		Object();
		virtual ~Object();

		String getClassName(void);
		virtual String toString(void);
	};

};

#endif
