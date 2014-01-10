/*
 * menu.cpp
 *
 * Last modified: <2014/01/10 16:29:16 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "menu.hpp"

namespace swo {
	inline namespace menu {

		Menu::Menu() : handle(nullptr) {}

		Menu::~Menu() {}

		Menu::Handle Menu::getHandle(void) const {
			return handle;
		}

		Menu& Menu::add(const MenuItem& item) {
			if (handle == nullptr) {
				handle = ::CreateMenu();
			}
			if (handle != nullptr) {
				::InsertMenuItem(
					handle, item.getId(), FALSE, &item.getInfo());
			}
			return *this;
		}

		Menu& Menu::add(const int index, const MenuItem& item) {
			if (handle == nullptr) {
				handle = ::CreateMenu();
			}
			if (handle != nullptr) {
				::InsertMenuItem(handle, index, TRUE, &item.getInfo());
			}
			return *this;
		}

		const Menu Menu::empty;
	};
};
