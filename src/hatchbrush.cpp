/*
 * hatchbrush.cpp
 *
 * Last modified: <2013/04/02 09:36:29 +0900> By Zumida
 */

#include "hatchbrush.hpp"

using namespace swo;

HatchBrush::HatchBrush(int style, COLORREF color) {
	this->style = style;
	this->color = color;
}

HatchBrush::HatchBrush(int style, int r, int g, int b) {
	this->style = style;
	this->color = RGB(r, g, b);
}

HatchBrush::~HatchBrush() {
	trash();
}

void HatchBrush::select(void) {
	handle = ::CreateHatchBrush(style, color);
}
