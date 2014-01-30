/*
 * instance.cpp
 *
 * Last modified: <2014/01/30 16:40:20 +0900> By Zumida
 */
#include "instance.hpp"

namespace swo {
	inline namespace core {
		ObjectPtrList Instance::objects;
		ControlPtrList Instance::controls;

		void Instance::add(Object* object) {
			Control* control = dynamic_cast<Control*>(object);

			if (control != nullptr) {
				controls.push_back(control);
			} else {
				objects.push_back(object);
			}
		}

		void Instance::remove(Object* object) {
			Control* control = dynamic_cast<Control*>(object);

			if (control != nullptr) {
				controls.remove(control);
				delete control;
			} else {
				objects.remove(object);
				delete object;
			}
		}

		void Instance::discard() {
			// 登録されたコントロールを破棄
			while (!controls.empty()) {
				Control* control = controls.back();
				controls.pop_back();

				try {
					delete control;
				} catch (const std::exception &e) {
					Stderr << "Catch a std::exception! : "
						<< e.what() << std::endl;
				} catch (...) {
					Stderr << "Catch an unexpected exception!"
						<< std::endl;
				}
			}

			// 登録されたオブジェクトを破棄
			while (!objects.empty()) {
				Object* object = objects.back();
				objects.pop_back();

				try {
					delete object;
				} catch (const std::exception &e) {
					Stderr << "Catch a std::exception! : "
						<< e.what() << std::endl;
				} catch (...) {
					Stderr << "Catch an unexpected exception!"
						<< std::endl;
				}
			}
		}

		void Instance::discard(const Object& object) {
			Object *obj = const_cast<Object*>(&object);
			remove(obj);
		}

		ControlPtrList& Instance::getControls() {
			return controls;
		}
	};
};
