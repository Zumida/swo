/*
 * application.hpp
 *
 * Last modified: <2013/05/03 21:01:00 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class Application : public Object {
	protected:
		Objects objects;

	public:
		Application();
		~Application();

		int run(void);

		void add(Object* object);
		void remove(Object* object);

		template<typename T> T& createObject(void) {
			T *obj = new T();
			add(obj);
			return *obj;
		}

		template<typename T> T& createObject(Control& parent) {
			T *obj = new T(&parent);
			add(obj);
			return *obj;
		}
	};

};

#endif
