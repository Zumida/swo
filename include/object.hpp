/*
 * object.hpp
 *
 * Last modified: <2014/01/07 17:35:35 +0900> By Zumida
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "swoconfig.hpp"
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
