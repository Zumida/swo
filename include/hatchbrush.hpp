/*
 * hatchbrush.hpp
 *
 * Last modified: <2013/05/13 18:05:13 +0900> By Zumida
 */
#ifndef HATCHBRUSH_HPP_INCLUDED
#define HATCHBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class HatchBrush : public Brush {
	protected:
		int style;
		COLORREF color;

		void refresh(void);

	public:
		HatchBrush();
		HatchBrush(const int style, const COLORREF color);
		~HatchBrush();

		Brush& set(const int style, const COLORREF color);
	};

};

#endif
