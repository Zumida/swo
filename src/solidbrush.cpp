/*
 * solidbrush.cpp
 *
 * Last modified: <2014/01/30 16:40:57 +0900> By Zumida
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

void SolidBrush::refresh() {
	handle = ::CreateSolidBrush(color);
}
