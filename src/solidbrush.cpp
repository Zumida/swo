/*
 * solidbrush.cpp
 *
 * Last modified: <2013/04/13 01:10:50 +0900> By Zumida
 */
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

HGDIOBJ SolidBrush::getHandle(void) {
	if (handle == NULL) handle = ::CreateSolidBrush(color);
	return handle;
}
