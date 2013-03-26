/*
 * cursor.cpp
 *
 * Last modified: <2013/03/25 18:31:13 +0900> By Zumida
 */

#include "cursor.hpp"
#include "resource.hpp"

using namespace swo;

Cursor::Cursor() {
	handle = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_CURSOR,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

Cursor::Cursor(String cursorName) {
	handle = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(cursorName.c_str()), IMAGE_CURSOR,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

Cursor::Cursor(const Cursor& cursor) {
	handle = cursor.handle;
}

Cursor::~Cursor() {
}

HCURSOR Cursor::getHandle(void) const {
	return handle;
}
