/*
 * solidbrush.hpp
 *
 * Last modified: <2013/04/17 12:37:35 +0900> By Zumida
 */
#ifndef SOLIDBRUSH_HPP_INCLUDED
#define SOLIDBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SolidBrush : public Brush {
	protected:
		COLORREF color;

	public:
		SolidBrush();
		SolidBrush(const COLORREF color);
		~SolidBrush();

		Brush& set(const COLORREF color);
		HGDIOBJ getHandle(void);
	};

};

#endif
