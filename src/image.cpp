/*
 * image.cpp
 *
 * Last modified: <2013/03/27 15:05:32 +0900> By Zumida
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

void Image::Load(const String& imageName, const int type) {
	this->type   = type;
	this->handle = LoadImage(
		NULL, MAKEINTRESOURCE(imageName.c_str()), type,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

HANDLE Image::getHandle(void) const {
	return handle;
}
