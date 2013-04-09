/*
 * bitmap.cpp
 *
 * Last modified: <2013/04/09 18:50:33 +0900> By Zumida
 */

#include "bitmap.hpp"

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
