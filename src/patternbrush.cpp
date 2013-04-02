/*
 * patternbrush.cpp
 *
 * Last modified: <2013/04/02 18:21:03 +0900> By Zumida
 */

#include "patternbrush.hpp"

using namespace swo;

PatternBrush::PatternBrush(const Bitmap& bmp) {
	this->bmp = const_cast<Bitmap*>(&bmp);
}

PatternBrush::~PatternBrush() {
}

HGDIOBJ PatternBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreatePatternBrush(bmp->getHandle());
	return handle;
}
