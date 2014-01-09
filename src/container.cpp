/*
 * container.cpp
 *
 * Last modified: <2014/01/09 15:23:31 +0900> By Zumida
 */
#include "container.hpp"

namespace swo {
	inline namespace control {

		Container::Container() : EventListener() {}

		Container::Container(Control& parent) : EventListener(parent) {}

		Container::~Container() {
			while (!childs.empty()) {
				Control* child = childs.back();
				childs.pop_back();
				delete child;
			}
		}

		void Container::addChild(Control& child) {
			childs.push_back(&child);
			child.setParent(this);
		}

		void Container::removeChild(Control& child) {
			childs.remove(&child);
			child.setParent(nullptr);
		}

		void Container::renew(void) {
			update();

			HWND handle = getHandle();
			if (handle != nullptr) {
				::DestroyWindow(handle);
				resetHandle();
			}

			for (Control* child : childs) {
				child->resetHandle();
			}

			refresh();
		}

		void Container::refresh(void) {
			Control::refresh();

			childs.sort();
			for (Control* child : childs) {
				child->refresh();
			}
		}
	};
};
