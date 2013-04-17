/*
 * patternbrush.cpp
 *
 * Last modified: <2013/04/17 14:03:48 +0900> By Zumida
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
