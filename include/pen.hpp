/*
 * pen.hpp
 *
 * Last modified: <2013/05/13 18:07:23 +0900> By Zumida
 */
#ifndef PEN_HPP_INCLUDED
#define PEN_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Pen : public GdiObject {
	public:
		Pen();
		~Pen();

		HPEN getHandle(void);
	};

};

#endif
