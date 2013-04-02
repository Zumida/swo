/*
 * brush.hpp
 *
 * Last modified: <2013/04/02 18:13:53 +0900> By Zumida
 */
#ifndef BRUSH_HPP_INCLUDED
#define BRUSH_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Brush : public GdiObject {
	public:
		Brush();
		virtual ~Brush();

		HBRUSH getBrush(void);
	};

};

#endif
