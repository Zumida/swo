/*
 * cursor.cpp
 *
 * Last modified: <2013/03/27 15:08:46 +0900> By Zumida
 */

#include "cursor.hpp"
#include "resource.hpp"

using namespace swo;

Cursor::Cursor() {
	Load(IDC_ARROW, IMAGE_CURSOR);
}

Cursor::Cursor(const String& cursorName) {
	Load(cursorName, IMAGE_CURSOR);
}

Cursor::~Cursor() {
}

HCURSOR Cursor::getHandle(void) const {
	return (HCURSOR)handle;
}
