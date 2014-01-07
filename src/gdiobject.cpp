/*
 * gdiobject.cpp
 *
 * Last modified: <2014/01/07 14:25:49 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "gdiobject.hpp"

using namespace swo;

GdiObject::GdiObject() {
	handle = nullptr;
}

GdiObject::~GdiObject() {
	trash();
}

HGDIOBJ GdiObject::getHandle(void) {
	if (handle == nullptr) refresh();
	return handle;
}

void GdiObject::trash(void) {
	if (handle != nullptr) ::DeleteObject(handle);
	handle = nullptr;
}
