/*
 * cursor.cpp
 *
 * Last modified: <2013/04/12 23:54:52 +0900> By Zumida
 */
#include "cursor.hpp"

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
	return (HCURSOR)handle;
}
