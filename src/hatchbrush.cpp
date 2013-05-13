/*
 * hatchbrush.cpp
 *
 * Last modified: <2013/05/13 18:15:27 +0900> By Zumida
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

void HatchBrush::refresh(void) {
	handle = ::CreateHatchBrush(style, color);
}
