/*
 * bitmap.cpp
 *
 * Last modified: <2013/03/27 15:22:13 +0900> By Zumida
 */

#include "bitmap.hpp"
#include "resource.hpp"

using namespace swo;

Bitmap::Bitmap() {
}

Bitmap::Bitmap(const String& bitmapName) {
	Load(bitmapName, IMAGE_BITMAP);
}

Bitmap::~Bitmap() {
}

HBITMAP Bitmap::getHandle(void) const {
	return handle;
}
