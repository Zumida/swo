/*
 * patternbrush.hpp
 *
 * Last modified: <2013/04/02 09:42:16 +0900> By Zumida
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
		PatternBrush(const Bitmap& bmp);
		virtual ~PatternBrush();

		virtual void select(void);
	};

};

#endif