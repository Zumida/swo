/*
 * pen.hpp
 *
 * Last modified: <2013/04/02 18:10:37 +0900> By Zumida
 */
#ifndef PEN_HPP_INCLUDED
#define PEN_HPP_INCLUDED

#include "gdiobject.hpp"

namespace swo {

	class Pen : public GdiObject {
	public:
		Pen();
		virtual ~Pen();

		HPEN getPen(void);
	};

};

#endif
