/*
 * patternbrush.hpp
 *
 * Last modified: <2013/04/13 01:06:27 +0900> By Zumida
 */
#ifndef PATTERNBRUSH_HPP_INCLUDED
#define PATTERNBRUSH_HPP_INCLUDED

#include "brush.hpp"
#include "bitmap.hpp"

namespace swo {

	class PatternBrush : public Brush {
	protected:
		Bitmap* bmp;

	public:
		PatternBrush();
		PatternBrush(const Bitmap& bmp);
		~PatternBrush();

		Brush& set(const Bitmap& bmp);
		HGDIOBJ getHandle(void);
	};

};

#endif
