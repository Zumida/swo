/*
 * custompen.cpp
 *
 * Last modified: <2013/04/02 18:08:16 +0900> By Zumida
 */

#include "custompen.hpp"

using namespace swo;

CustomPen::CustomPen(int style, int width, COLORREF color) {
	this->style = style;
	this->width = width;
	this->color = color;
}

CustomPen::CustomPen(int style, int width, int r, int g, int b) {
	this->style = style;
	this->width = width;
	this->color = RGB(r, g, b);
}

CustomPen::~CustomPen() {
}

HGDIOBJ CustomPen::getHandle(void) {
	if (handle == NULL) handle = ::CreatePen(style, width, color);
	return handle;
}
