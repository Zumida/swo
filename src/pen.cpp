/*
 * pen.cpp
 *
 * Last modified: <2013/04/12 20:48:46 +0900> By Zumida
 */
#include "pen.hpp"

using namespace swo;

Pen::Pen() {
}

Pen::~Pen() {
}

HPEN Pen::getPen(void) {
	return (HPEN)getHandle();
}
