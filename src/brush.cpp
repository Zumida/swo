/*
 * brush.cpp
 *
 * Last modified: <2014/01/07 14:24:39 +0900> By Zumida
 */
#include "swoconfig.hpp"
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
