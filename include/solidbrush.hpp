/*
 * solidbrush.hpp
 *
 * Last modified: <2014/01/30 16:40:59 +0900> By Zumida
 */
#ifndef SOLIDBRUSH_HPP_INCLUDED
#define SOLIDBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SolidBrush : public Brush {
	protected:
		COLORREF color;

		void refresh();

	public:
		SolidBrush();
		SolidBrush(const COLORREF color);
		~SolidBrush();

		Brush& set(const COLORREF color);
	};

};

#endif
