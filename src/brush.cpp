/*
 * brush.cpp
 *
 * Last modified: <2013/04/02 09:21:16 +0900> By Zumida
 */

#include "brush.hpp"

using namespace swo;

Brush::Brush() {
	handle = NULL;
}

Brush::~Brush() {
}

void Brush::trash(void) {
	if (handle != NULL) ::DeleteObject(handle);
	handle = NULL;
}

HBRUSH Brush::getHandle(void) const {
	return handle;
}
