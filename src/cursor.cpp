/*
 * cursor.cpp
 *
 * Last modified: <2013/04/09 18:50:13 +0900> By Zumida
 */

#include "cursor.hpp"

using namespace swo;

Cursor::Cursor() {
	load(IDC_ARROW, IMAGE_CURSOR);
}

Cursor::Cursor(const String& cursorName) {
	load(cursorName, IMAGE_CURSOR);
}

Cursor::~Cursor() {
}

HCURSOR Cursor::getHandle(void) const {
	return (HCURSOR)handle;
}
