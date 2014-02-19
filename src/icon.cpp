/*
 * icon.cpp
 *
 * Last modified: <2014/02/19 22:34:23 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include "icon.hpp"
#include "pointer.hpp"

namespace swo {
	inline namespace image {

		Icon::Icon() {}

		Icon::Icon(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_ICON);
		}

		Icon::~Icon() {}

		Icon& Icon::set(const String& name) {
			Image::load(Application::getInstance().getHandle(), name, IMAGE_ICON);
			return *this;
		}

		Icon& Icon::set(const int id) {
			Image::load(Application::getInstance().getHandle(), id, IMAGE_ICON);
			return *this;
		}

		const HICON Icon::getHandle() const {
			return pointer_cast<HICON>(handle);
		}
	};
};
