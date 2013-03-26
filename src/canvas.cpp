/*
 * canvas.cpp
 *
 * Last modified: <2013/03/22 16:28:54 +0900> By Zumida
 */

#include "canvas.hpp"

using namespace swo;

Canvas::Canvas(HDC hDc, HWND hWnd) {
	this->hDc = hDc;
	if (hWnd != NULL) {
		::GetClientRect(hWnd , &rect);
	}
}

Canvas::Canvas(HDC hDc, const Rect& rect) {
	this->hDc = hDc;
	this->rect = rect;
}

Canvas::~Canvas() {
}

const HDC Canvas::getDc(void) const {
	return hDc;
}

Rect& Canvas::getRect(void) {
	return rect;
}
