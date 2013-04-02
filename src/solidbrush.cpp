/*
 * solidbrush.cpp
 *
 * Last modified: <2013/04/02 18:20:02 +0900> By Zumida
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
}

HGDIOBJ SolidBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreateSolidBrush(color);
	return handle;
}
