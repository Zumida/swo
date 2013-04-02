/*
 * solidbrush.cpp
 *
 * Last modified: <2013/04/02 09:40:41 +0900> By Zumida
 */

#include "solidbrush.hpp"

using namespace swo;

SolidBrush::SolidBrush(COLORREF color) {
	this->color = color;
}

SolidBrush::SolidBrush(int r, int g, int b) {
	this->color = RGB(r, g, b);
}

SolidBrush::~SolidBrush() {
	trash();
}

void SolidBrush::select(void) {
	handle = ::CreateSolidBrush(color);
}
