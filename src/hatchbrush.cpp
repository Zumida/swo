/*
 * hatchbrush.cpp
 *
 * Last modified: <2013/04/02 18:22:33 +0900> By Zumida
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
}

HGDIOBJ HatchBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreateHatchBrush(style, color);
	return handle;
}
