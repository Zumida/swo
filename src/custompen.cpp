/*
 * custompen.cpp
 *
 * Last modified: <2013/04/17 14:04:56 +0900> By Zumida
 */
#include "custompen.hpp"

using namespace swo;

CustomPen::CustomPen() {
	this->style = 0;
	this->width = 0;
	this->color = 0;
}

CustomPen::CustomPen(const int style, const int width, const COLORREF color) {
	this->style = style;
	this->width = width;
	this->color = color;
}

CustomPen::~CustomPen() {
}

HGDIOBJ CustomPen::getHandle(void) {
	if (handle == NULL) handle = ::CreatePen(style, width, color);
	return handle;
}

Pen& CustomPen::set(const int style, const int width, const COLORREF color) {
	this->style = style;
	this->width = width;
	this->color = color;
	return *this;
}
