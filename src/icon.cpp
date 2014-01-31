/*
 * icon.cpp
 *
 * Last modified: <2014/01/31 16:57:59 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "icon.hpp"
#include "pointer.hpp"

namespace swo {
	inline namespace image {

		Icon::Icon() {}

		Icon::Icon(const String& name) {
			Image::load(name, IMAGE_ICON);
		}

		Icon::~Icon() {}

		Icon& Icon::set(const String& name) {
			Image::load(name, IMAGE_ICON);
			return *this;
		}

		const HICON Icon::getHandle() const {
			return pointer_cast<HICON>(handle);
		}
	};
};
