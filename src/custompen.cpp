/*
 * custompen.cpp
 *
 * Last modified: <2014/01/07 14:25:30 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

void CustomPen::refresh(void) {
	handle = ::CreatePen(style, width, color);
}

Pen& CustomPen::set(const int style, const int width, const COLORREF color) {
	this->style = style;
	this->width = width;
	this->color = color;
	return *this;
}
