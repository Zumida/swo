/*
 * icon.cpp
 *
 * Last modified: <2013/03/25 18:15:42 +0900> By Zumida
 */

#include "icon.hpp"
#include "resource.hpp"

using namespace swo;

Icon::Icon() {
	handle = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

Icon::Icon(String iconName) {
	handle = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(iconName.c_str()), IMAGE_ICON,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

Icon::Icon(const Icon& icon) {
	handle = icon.handle;
}

Icon::~Icon() {
}

HICON Icon::getHandle(void) const {
	return handle;
}
