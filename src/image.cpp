/*
 * image.cpp
 *
 * Last modified: <2013/05/06 21:57:11 +0900> By Zumida
 */
#include "image.hpp"
#include "resource.hpp"

using namespace swo;

Image::Image() {
	type   = 0;
	handle = NULL;
}

Image::Image(const class Image& image) {
	type   = image.type;
	handle = image.handle;
}

Image::~Image() {
}

void Image::load(const String& name, const int type) {
	this->type   = type;
	this->handle = LoadImage(
		NULL, MAKEINTRESOURCE(name.c_str()), type,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

void Image::load(const TCHAR* id, const int type) {
	this->type   = type;
	this->handle = LoadImage(
		NULL, id, type,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

HANDLE Image::getHandle(void) const {
	return handle;
}
