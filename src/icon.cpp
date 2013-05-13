/*
 * icon.cpp
 *
 * Last modified: <2013/05/13 18:16:06 +0900> By Zumida
 */
#include "icon.hpp"
#include "pointer.hpp"

using namespace swo;

Icon::Icon() {
}

Icon::Icon(const String& name) {
	Image::load(name, IMAGE_ICON);
}

Icon::~Icon() {
}

Icon& Icon::set(const String& name) {
	Image::load(name, IMAGE_ICON);
	return *this;
}

HICON Icon::getHandle(void) const {
	return pointer_cast<HICON>(handle);
}
