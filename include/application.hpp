/*
 * application.hpp
 *
 * Last modified: <2013/04/09 18:56:47 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class Application : public Object {
	private:
		Objects objects;

	protected:

	public:
		Application();
		virtual ~Application();

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
