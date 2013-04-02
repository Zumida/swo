/*
 * hatchbrush.hpp
 *
 * Last modified: <2013/04/02 18:21:26 +0900> By Zumida
 */
#ifndef HATCHBRUSH_HPP_INCLUDED
#define HATCHBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class HatchBrush : public Brush {
	protected:
		int style;
		COLORREF color;

	public:
		HatchBrush(int style, COLORREF color);
		HatchBrush(int style, int r, int g, int b);
		virtual ~HatchBrush();

		virtual HGDIOBJ getHandle(void);
	};

};

#endif
