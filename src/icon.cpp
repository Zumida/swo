/*
 * icon.cpp
 *
 * Last modified: <2013/03/27 15:23:33 +0900> By Zumida
 */

#include "icon.hpp"
#include "resource.hpp"

using namespace swo;

Icon::Icon() {
	Load(IDI_APPLICATION, IMAGE_ICON);
}

Icon::Icon(const String& iconName) {
	Load(iconName, IMAGE_ICON);
}

Icon::~Icon() {
}

HICON Icon::getHandle(void) const {
	return (HICON)handle;
}
