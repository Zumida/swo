/*
 * pen.cpp
 *
 * Last modified: <2014/01/07 14:26:33 +0900> By Zumida
 */
#include "swoconfig.hpp"
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
