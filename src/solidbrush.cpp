/*
 * solidbrush.cpp
 *
 * Last modified: <2013/05/13 18:20:05 +0900> By Zumida
 */
#include "solidbrush.hpp"

using namespace swo;

SolidBrush::SolidBrush() {
	this->color = 0;
}

SolidBrush::SolidBrush(COLORREF color) {
	this->color = color;
}

SolidBrush::~SolidBrush() {
}

Brush& SolidBrush::set(COLORREF color) {
	this->color = color;
	return *this;
}

void SolidBrush::refresh(void) {
	handle = ::CreateSolidBrush(color);
}
