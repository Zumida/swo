/*
 * pen.hpp
 *
 * Last modified: <2013/04/17 12:38:33 +0900> By Zumida
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
