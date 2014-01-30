/*
 * icon.cpp
 *
 * Last modified: <2014/01/30 16:40:09 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

HICON Icon::getHandle() const {
	return pointer_cast<HICON>(handle);
}
