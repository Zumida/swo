/*
 * gdiobject.cpp
 *
 * Last modified: <2013/04/17 14:04:33 +0900> By Zumida
 */
#include "gdiobject.hpp"

using namespace swo;

GdiObject::GdiObject() {
	handle = NULL;
}

GdiObject::~GdiObject() {
	trash();
}

void GdiObject::trash(void) {
	if (handle != NULL) ::DeleteObject(handle);
	handle = NULL;
}
