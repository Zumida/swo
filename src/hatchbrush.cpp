/*
 * hatchbrush.cpp
 *
 * Last modified: <2013/04/17 14:04:29 +0900> By Zumida
 */
#include "hatchbrush.hpp"

using namespace swo;

HatchBrush::HatchBrush() {
	this->style = 0;
	this->color = 0;
}

HatchBrush::HatchBrush(const int style, const COLORREF color) {
	this->style = style;
	this->color = color;
}

HatchBrush::~HatchBrush() {
}

Brush& HatchBrush::set(const int style, const COLORREF color) {
	this->style = style;
	this->color = color;
	return *this;
}

HGDIOBJ HatchBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreateHatchBrush(style, color);
	return handle;
}
