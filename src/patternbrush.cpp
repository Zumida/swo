/*
 * patternbrush.cpp
 *
 * Last modified: <2013/04/13 01:07:26 +0900> By Zumida
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

HGDIOBJ PatternBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreatePatternBrush(bmp->getHandle());
	return handle;
}
