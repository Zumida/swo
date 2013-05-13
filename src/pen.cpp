/*
 * pen.cpp
 *
 * Last modified: <2013/05/13 18:19:45 +0900> By Zumida
 */
#include "pen.hpp"
#include "pointer.hpp"

using namespace swo;

Pen::Pen() {
}

Pen::~Pen() {
}

HPEN Pen::getHandle(void) {
	return pointer_cast<HPEN>(GdiObject::getHandle());
}
