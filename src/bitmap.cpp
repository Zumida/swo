/*
 * bitmap.cpp
 *
 * Last modified: <2014/02/17 23:25:21 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include "bitmap.hpp"
#include "pointer.hpp"

namespace swo {
	inline namespace image {

		Bitmap::Bitmap() {
		}

		Bitmap::Bitmap(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_BITMAP);
		}

		Bitmap::~Bitmap() {
		}

		Bitmap& Bitmap::set(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_BITMAP);
			return *this;
		}

		HBITMAP Bitmap::getHandle() const {
			return pointer_cast<HBITMAP>(handle);
		}

		const Bitmap Bitmap::empty;
	};
};
