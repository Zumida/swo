/*
 * point.hpp
 *
 * Last modified: <2014/01/08 09:54:51 +0900> By Zumida
 */
#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include "swoconfig.hpp"
#include <windows.h>

namespace swo {
	inline namespace util {
		using Point = POINT;
		using ShortPoint = POINTS;
		using WindowPos = WINDOWPOS;
	};
};

#endif
