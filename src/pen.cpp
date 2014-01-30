/*
 * pen.cpp
 *
 * Last modified: <2014/01/30 16:40:50 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "pen.hpp"
#include "pointer.hpp"

using namespace swo;

Pen::Pen() {
}

Pen::~Pen() {
}

HPEN Pen::getHandle() {
	return pointer_cast<HPEN>(GdiObject::getHandle());
}
