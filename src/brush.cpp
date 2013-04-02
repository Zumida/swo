/*
 * brush.cpp
 *
 * Last modified: <2013/04/02 18:14:06 +0900> By Zumida
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
