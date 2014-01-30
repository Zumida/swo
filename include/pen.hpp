/*
 * pen.hpp
 *
 * Last modified: <2014/01/30 16:40:53 +0900> By Zumida
 */
#ifndef PEN_HPP_INCLUDED
#define PEN_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Pen : public GdiObject {
	public:
		Pen();
		~Pen();

		HPEN getHandle();
	};

};

#endif
