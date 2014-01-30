/*
 * hatchbrush.hpp
 *
 * Last modified: <2014/01/30 16:40:06 +0900> By Zumida
 */
#ifndef HATCHBRUSH_HPP_INCLUDED
#define HATCHBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class HatchBrush : public Brush {
	protected:
		int style;
		COLORREF color;

		void refresh();

	public:
		HatchBrush();
		HatchBrush(const int style, const COLORREF color);
		~HatchBrush();

		Brush& set(const int style, const COLORREF color);
	};

};

#endif
