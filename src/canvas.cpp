/*
 * canvas.cpp
 *
 * Last modified: <2013/04/02 19:10:04 +0900> By Zumida
 */

#include "canvas.hpp"

using namespace swo;

Canvas::Canvas(HWND hWnd) {
	this->hWnd = hWnd;
	this->hDc = NULL;
}

Canvas::~Canvas() {
	endPaint();
}

const HDC Canvas::getDc(void) const {
	return hDc;
}

const Rect& Canvas::getRect(void) const {
	return ps.rcPaint;
}

void Canvas::beginPaint(void) {
	hDc = BeginPaint(hWnd , &ps);
}

void Canvas::endPaint(void) {
	if (hDc != NULL) {
		EndPaint(hWnd , &ps);
		hDc = NULL;
	}
}

