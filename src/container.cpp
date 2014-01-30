/*
 * container.cpp
 *
 * Last modified: <2014/01/30 16:39:22 +0900> By Zumida
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

		void Container::renew() {
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

		void Container::refresh() {
			Control::refresh();

			childs.sort();
			for (Control* child : childs) {
				child->refresh();
			}
		}
	};
};
