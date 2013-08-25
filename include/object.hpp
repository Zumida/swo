/*
 * object.hpp
 *
 * Last modified: <2013/08/21 02:24:53 +0900> By Zumida
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "define.hpp"
#include "string.hpp"
#include <list>
#include <windows.h>
#include <commctrl.h>

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
