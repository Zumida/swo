/*
 * rect.hpp
 *
 * Last modified: <2013/04/09 02:04:35 +0900> By Zumida
 */
#ifndef RECT_HPP_INCLUDED
#define RECT_HPP_INCLUDED

#include <windef.h>

namespace swo {

	typedef RECT Rect;

	typedef struct WindowRect {
		int left;
		int top;
		int width;
		int height;
	} WindowRect;

};

#endif
