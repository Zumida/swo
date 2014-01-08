/*
 * brush.hpp
 *
 * Last modified: <2014/01/08 09:47:11 +0900> By Zumida
 */
#ifndef BRUSH_HPP_INCLUDED
#define BRUSH_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Brush : public GdiObject {
	public:
		Brush();
		~Brush();

		HBRUSH getHandle(void);
	};

};

#endif
