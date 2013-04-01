/*
 * bitmap.cpp
 *
 * Last modified: <2013/04/02 00:53:36 +0900> By Zumida
 */

#include "bitmap.hpp"
#include "resource.hpp"

using namespace swo;

Bitmap::Bitmap() {
}

Bitmap::Bitmap(const String& bitmapName) {
	load(bitmapName, IMAGE_BITMAP);
}

Bitmap::~Bitmap() {
}

HBITMAP Bitmap::getHandle(void) const {
	return handle;
}
