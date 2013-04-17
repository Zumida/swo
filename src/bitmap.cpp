/*
 * bitmap.cpp
 *
 * Last modified: <2013/04/17 14:05:16 +0900> By Zumida
 */
#include "bitmap.hpp"

using namespace swo;

Bitmap::Bitmap() {
}

Bitmap::Bitmap(const String& name) {
	Image::load(name, IMAGE_BITMAP);
}

Bitmap::~Bitmap() {
}

Bitmap& Bitmap::set(const String& name) {
	Image::load(name, IMAGE_BITMAP);
	return *this;
}

HBITMAP Bitmap::getHandle(void) const {
	return handle;
}

const Bitmap Bitmap::empty;
