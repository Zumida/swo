/*
 * brush.cpp
 *
 * Last modified: <2014/01/30 16:39:12 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "brush.hpp"
#include "pointer.hpp"

using namespace swo;

Brush::Brush() {
}

Brush::~Brush() {
}

HBRUSH Brush::getHandle() {
	return pointer_cast<HBRUSH>(GdiObject::getHandle());
}
