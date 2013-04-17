/*
 * icon.cpp
 *
 * Last modified: <2013/04/17 14:04:24 +0900> By Zumida
 */
#include "icon.hpp"

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
	return (HICON)handle;
}
