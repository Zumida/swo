/*
 * icon.cpp
 *
 * Last modified: <2013/04/09 18:49:38 +0900> By Zumida
 */

#include "icon.hpp"

using namespace swo;

Icon::Icon() {
	load(IDI_APPLICATION, IMAGE_ICON);
}

Icon::Icon(const String& iconName) {
	load(iconName, IMAGE_ICON);
}

Icon::~Icon() {
}

HICON Icon::getHandle(void) const {
	return (HICON)handle;
}
