/*
 * instance.hpp
 *
 * Last modified: <2013/08/28 01:16:11 +0900> By Zumida
 */
#ifndef INSTANCE_HPP_INCLUDED
#define INSTANCE_HPP_INCLUDED

#include "application.hpp"

namespace swo {

	class Instance {
	private:
		Instance();
		~Instance();

	public:
		template<typename T> static T& create(void) {
			T *obj = new T();
			Application::getInstance().add(obj);
			return *obj;
		}

		template<typename T> static T& create(Control& parent) {
			T *obj = new T(&parent);
			Application::getInstance().add(obj);
			return *obj;
		}

		static void discard(const Object& object) {
			Object *obj = const_cast<Object*>(&object);
			Application::getInstance().remove(obj);
		}
	};
};

#endif
