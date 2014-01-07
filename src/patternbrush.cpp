/*
 * patternbrush.cpp
 *
 * Last modified: <2014/01/07 14:26:29 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "patternbrush.hpp"

using namespace swo;

PatternBrush::PatternBrush() {
	bmp = nullptr;
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
