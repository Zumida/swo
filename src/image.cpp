/*
 * image.cpp
 *
 * Last modified: <2014/02/18 01:19:28 +0900> By Zumida
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

		void Image::load(const HINSTANCE hInstance, int id, const int type) {
			this->type   = type;
			this->handle = ::LoadImage(
				hInstance, MAKEINTRESOURCE(id), type,
				0, 0, LR_DEFAULTSIZE | LR_SHARED);
		}

		void Image::load(const HINSTANCE hInstance, const String& name, const int type) {
			this->type   = type;
			this->handle = ::LoadImage(
				hInstance, name.c_str(), type,
				0, 0, LR_DEFAULTSIZE | LR_SHARED);
		}

		void Image::load(const HINSTANCE hInstance, const TCHAR* idc, const int type) {
			this->type   = type;
			this->handle = ::LoadImage(
				hInstance, idc, type,
				0, 0, LR_DEFAULTSIZE | LR_SHARED);
		}

		const HANDLE Image::getHandle() const {
			return handle;
		}
	};
};
