/*
 * patternbrush.cpp
 *
 * Last modified: <2013/04/02 09:46:13 +0900> By Zumida
 */

#include "patternbrush.hpp"

using namespace swo;

PatternBrush::PatternBrush(const Bitmap& bmp) {
	this->bmp = const_cast<Bitmap*>(&bmp);
}

PatternBrush::~PatternBrush() {
	trash();
}

void PatternBrush::select(void) {
	handle = ::CreatePatternBrush(bmp->getHandle());
}
