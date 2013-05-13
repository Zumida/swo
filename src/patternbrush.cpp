/*
 * patternbrush.cpp
 *
 * Last modified: <2013/05/13 18:16:49 +0900> By Zumida
 */
#include "patternbrush.hpp"

using namespace swo;

PatternBrush::PatternBrush() {
	bmp = NULL;
}

PatternBrush::PatternBrush(const Bitmap& bmp) {
	this->bmp = const_cast<Bitmap*>(&bmp);
}

PatternBrush::~PatternBrush() {
}

Brush& PatternBrush::set(const Bitmap& bmp) {
	this->bmp = const_cast<Bitmap*>(&bmp);
	return *this;
}

void PatternBrush::refresh(void) {
	handle = ::CreatePatternBrush(bmp->getHandle());
}
