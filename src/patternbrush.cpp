/*
 * patternbrush.cpp
 *
 * Last modified: <2014/01/30 16:40:44 +0900> By Zumida
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

void PatternBrush::refresh() {
	handle = ::CreatePatternBrush(bmp->getHandle());
}
