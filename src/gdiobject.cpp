/*
 * gdiobject.cpp
 *
 * Last modified: <2014/01/30 16:40:00 +0900> By Zumida
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

HGDIOBJ GdiObject::getHandle() {
	if (handle == nullptr) refresh();
	return handle;
}

void GdiObject::trash() {
	if (handle != nullptr) ::DeleteObject(handle);
	handle = nullptr;
}
