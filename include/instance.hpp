/*
 * instance.hpp
 *
 * Last modified: <2014/01/30 16:40:22 +0900> By Zumida
 */
#ifndef INSTANCE_HPP_INCLUDED
#define INSTANCE_HPP_INCLUDED

#include "swoconfig.hpp"
#include "control.hpp"

namespace swo {
	inline namespace core {

		class Instance {
		private:
			static ObjectPtrList objects;
			static ControlPtrList controls;

			static void add(Object* object);
			static void remove(Object* object);

		public:
			Instance() = delete;
			~Instance() = delete;

			template<typename T> static T& create() {
				T *obj = new T();
				add(obj);
				return *obj;
			}

			template<typename T> static T& create(Control& parent) {
				T *obj = new T(parent);
				add(obj);
				return *obj;
			}

			static void discard();
			static void discard(const Object& object);
			static ControlPtrList& getControls();
		};
	};
};

#endif
