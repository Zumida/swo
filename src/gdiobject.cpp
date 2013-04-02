/*
 * gdiobject.cpp
 *
 * Last modified: <2013/04/02 19:07:37 +0900> By Zumida
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
