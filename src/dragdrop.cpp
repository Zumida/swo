/*
 * dragdrop.cpp
 *
 * Last modified: <2014/01/30 16:39:46 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "dragdrop.hpp"

using namespace swo;

DragDrop::DragDrop(HDROP hDrop) {
	::DragQueryPoint(hDrop, &point);

	UINT n = ::DragQueryFile(hDrop, -1, nullptr, 0);
	for (UINT i = 0; i < n; i++) {
		UINT l = ::DragQueryFile(hDrop, i, nullptr, 0);
		TCHAR str[l];

		::DragQueryFile(hDrop, i, str, l);
		files.push_back(str);
	}

	//::DragFinish(hDrop);
}

DragDrop::~DragDrop() {
}

const StringList& DragDrop::getFiles() const {
	return files;
}

const Point& DragDrop::getPoint() const {
	return point;
}

