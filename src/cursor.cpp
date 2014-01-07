/*
 * cursor.cpp
 *
 * Last modified: <2014/01/07 14:25:25 +0900> By Zumida
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

HCURSOR Cursor::getHandle(void) const {
	return pointer_cast<HCURSOR>(handle);
}
