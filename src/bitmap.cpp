/*
 * bitmap.cpp
 *
 * Last modified: <2013/05/03 21:47:33 +0900> By Zumida
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
	return (HBITMAP)handle;
}

const Bitmap Bitmap::empty;
