/*
 * hatchbrush.hpp
 *
 * Last modified: <2013/04/12 22:04:20 +0900> By Zumida
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
		HatchBrush();
		HatchBrush(const int style, const COLORREF color);
		~HatchBrush();

		Brush& set(const int style, const COLORREF color);
		HGDIOBJ getHandle(void);
	};

};

#endif
