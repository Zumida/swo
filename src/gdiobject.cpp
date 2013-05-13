/*
 * gdiobject.cpp
 *
 * Last modified: <2013/05/13 18:02:31 +0900> By Zumida
 */
#include "gdiobject.hpp"

using namespace swo;

GdiObject::GdiObject() {
	handle = NULL;
}

GdiObject::~GdiObject() {
	trash();
}

HGDIOBJ GdiObject::getHandle(void) {
	if (handle == NULL) refresh();
	return handle;
}

void GdiObject::trash(void) {
	if (handle != NULL) ::DeleteObject(handle);
	handle = NULL;
}
