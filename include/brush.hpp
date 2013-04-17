/*
 * brush.hpp
 *
 * Last modified: <2013/04/17 12:43:14 +0900> By Zumida
 */
#ifndef BRUSH_HPP_INCLUDED
#define BRUSH_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Brush : public GdiObject {
	public:
		Brush();
		~Brush();

		HBRUSH getBrush(void);
	};

};

#endif
