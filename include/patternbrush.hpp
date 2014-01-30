/*
 * patternbrush.hpp
 *
 * Last modified: <2014/01/30 16:40:47 +0900> By Zumida
 */
#ifndef PATTERNBRUSH_HPP_INCLUDED
#define PATTERNBRUSH_HPP_INCLUDED

#include "brush.hpp"
#include "bitmap.hpp"

namespace swo {

	class PatternBrush : public Brush {
	protected:
		Bitmap* bmp;

		void refresh();

	public:
		PatternBrush();
		PatternBrush(const Bitmap& bmp);
		~PatternBrush();

		Brush& set(const Bitmap& bmp);
	};

};

#endif
