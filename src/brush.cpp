/*
 * brush.cpp
 *
 * Last modified: <2013/04/17 14:05:12 +0900> By Zumida
 */
#include "brush.hpp"

using namespace swo;

Brush::Brush() {
}

Brush::~Brush() {
}

HBRUSH Brush::getBrush(void) {
	return (HBRUSH)getHandle();
}
