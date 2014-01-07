/*
 * solidbrush.cpp
 *
 * Last modified: <2014/01/07 14:26:42 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "solidbrush.hpp"

using namespace swo;

SolidBrush::SolidBrush() {
	this->color = 0;
}

SolidBrush::SolidBrush(COLORREF color) {
	this->color = color;
}

SolidBrush::~SolidBrush() {
}

Brush& SolidBrush::set(COLORREF color) {
	this->color = color;
	return *this;
}

void SolidBrush::refresh(void) {
	handle = ::CreateSolidBrush(color);
}
