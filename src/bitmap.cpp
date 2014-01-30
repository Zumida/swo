/*
 * bitmap.cpp
 *
 * Last modified: <2014/01/30 16:39:07 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "bitmap.hpp"
#include "pointer.hpp"

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

HBITMAP Bitmap::getHandle() const {
	return pointer_cast<HBITMAP>(handle);
}

const Bitmap Bitmap::empty;
