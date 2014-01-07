/*
 * canvas.cpp
 *
 * Last modified: <2014/01/07 17:23:18 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "canvas.hpp"

using namespace swo;

Canvas::Canvas(HWND hWnd) : hWnd(hWnd), hDc(nullptr) {}

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
	hDc = ::BeginPaint(hWnd , &ps);
}

void Canvas::endPaint(void) {
	if (hDc != nullptr) {
		::EndPaint(hWnd , &ps);
		hDc = nullptr;
	}
}

