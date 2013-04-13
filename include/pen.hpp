/*
 * pen.hpp
 *
 * Last modified: <2013/04/12 22:25:48 +0900> By Zumida
 */
#ifndef PEN_HPP_INCLUDED
#define PEN_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Pen : public GdiObject {
	public:
		Pen();
		~Pen();

		HPEN getPen(void);
	};

};

#endif
