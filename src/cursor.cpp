/*
 * cursor.cpp
 *
 * Last modified: <2014/01/30 16:39:34 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "cursor.hpp"
#include "pointer.hpp"

using namespace swo;

Cursor::Cursor() {
}

Cursor::Cursor(const String& name) {
	Image::load(name, IMAGE_CURSOR);
}

Cursor::~Cursor() {
}

Cursor& Cursor::set(const String& name) {
	Image::load(name, IMAGE_CURSOR);
	return *this;
}

HCURSOR Cursor::getHandle() const {
	return pointer_cast<HCURSOR>(handle);
}
