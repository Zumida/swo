/*
 * solidbrush.hpp
 *
 * Last modified: <2013/04/02 07:02:14 +0900> By Zumida
 */
#ifndef SOLIDBRUSH_HPP_INCLUDED
#define SOLIDBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SolidBrush : public Brush {
	protected:
		COLORREF color;

	public:
		SolidBrush(COLORREF color);
		SolidBrush(int r, int g, int b);
		virtual ~SolidBrush();

		virtual void select(void);
		virtual void trash(void);
	};

};

#endif
