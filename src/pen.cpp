/*
 * pen.cpp
 *
 * Last modified: <2013/04/17 14:03:10 +0900> By Zumida
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
