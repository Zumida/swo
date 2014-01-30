/*
 * hatchbrush.cpp
 *
 * Last modified: <2014/01/30 16:40:04 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

void HatchBrush::refresh() {
	handle = ::CreateHatchBrush(style, color);
}
