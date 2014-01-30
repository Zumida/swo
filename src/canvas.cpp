/*
 * canvas.cpp
 *
 * Last modified: <2014/01/30 16:39:17 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "canvas.hpp"

using namespace swo;

Canvas::Canvas(HWND hWnd) : hWnd(hWnd), hDc(nullptr) {}

Canvas::~Canvas() {
	endPaint();
}

const HDC Canvas::getDc() const {
	return hDc;
}

const Rect& Canvas::getRect() const {
	return ps.rcPaint;
}

void Canvas::beginPaint() {
	hDc = ::BeginPaint(hWnd , &ps);
}

void Canvas::endPaint() {
	if (hDc != nullptr) {
		::EndPaint(hWnd , &ps);
		hDc = nullptr;
	}
}

