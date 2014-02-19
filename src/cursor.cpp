/*
 * cursor.cpp
 *
 * Last modified: <2014/02/17 23:23:31 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include "cursor.hpp"
#include "pointer.hpp"

namespace swo {
	inline namespace image {

		Cursor::Cursor() {
		}

		Cursor::Cursor(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_CURSOR);
		}

		Cursor::~Cursor() {
		}

		Cursor& Cursor::set(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_CURSOR);
			return *this;
		}

		HCURSOR Cursor::getHandle() const {
			return pointer_cast<HCURSOR>(handle);
		}
	};
};
