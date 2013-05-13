/*
 * brush.cpp
 *
 * Last modified: <2013/05/13 18:12:12 +0900> By Zumida
 */
#include "brush.hpp"
#include "pointer.hpp"

using namespace swo;

Brush::Brush() {
}

Brush::~Brush() {
}

HBRUSH Brush::getHandle(void) {
	return pointer_cast<HBRUSH>(GdiObject::getHandle());
}
