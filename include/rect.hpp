/*
 * rect.hpp
 *
 * Last modified: <2014/01/08 09:55:21 +0900> By Zumida
 */
#ifndef RECT_HPP_INCLUDED
#define RECT_HPP_INCLUDED

#include <windows.h>

namespace swo {
	inline namespace util {
		using Rect = RECT;

		struct WindowRect {
			int left;
			int top;
			int width;
			int height;
		};
	};
};

#endif
