/*
 * image.cpp
 *
 * Last modified: <2013/04/12 22:22:57 +0900> By Zumida
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

HANDLE Image::getHandle(void) const {
	return handle;
}
