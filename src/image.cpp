/*
 * image.cpp
 *
 * Last modified: <2014/01/31 16:50:23 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "image.hpp"
#include "resource.hpp"

namespace swo {
	inline namespace image {

		Image::Image()
			: handle(nullptr), type(0) {}

		Image::Image(const class Image& image)
			: handle(image.handle), type(image.type) {}

		Image::~Image() {}

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

		const HANDLE Image::getHandle() const {
			return handle;
		}
	};
};
