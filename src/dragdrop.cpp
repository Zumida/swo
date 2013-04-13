/*
 * dragdrop.cpp
 *
 * Last modified: <2013/04/12 07:14:07 +0900> By Zumida
 */
#include "dragdrop.hpp"

using namespace swo;

DragDrop::DragDrop(HDROP hDrop) {
	::DragQueryPoint(hDrop, &point);

	UINT n = ::DragQueryFile(hDrop, -1, NULL, 0);
	for (UINT i = 0; i < n; i++) {
		UINT l = ::DragQueryFile(hDrop, i, NULL, 0);
		TCHAR str[l];

		::DragQueryFile(hDrop, i, str, l);
		files.push_back(str);
	}

	//::DragFinish(hDrop);
}

DragDrop::~DragDrop() {
}

const StringList& DragDrop::getFiles(void) const {
	return files;
}

const Point& DragDrop::getPoint(void) const {
	return point;
}

