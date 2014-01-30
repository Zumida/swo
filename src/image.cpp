/*
 * image.cpp
 *
 * Last modified: <2014/01/30 16:40:15 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "image.hpp"
#include "resource.hpp"

using namespace swo;

Image::Image() {
	type   = 0;
	handle = nullptr;
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
		nullptr, MAKEINTRESOURCE(name.c_str()), type,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

void Image::load(const TCHAR* id, const int type) {
	this->type   = type;
	this->handle = LoadImage(
		nullptr, id, type,
		0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

HANDLE Image::getHandle() const {
	return handle;
}
