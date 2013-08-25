/*
 * instance.hpp
 *
 * Last modified: <2013/08/21 03:27:14 +0900> By Zumida
 */
#ifndef INSTANCE_HPP_INCLUDED
#define INSTANCE_HPP_INCLUDED

#include "application.hpp"

namespace swo {

	template<typename T> T& createInstance(void) {
		T *obj = new T();
		Application::getInstance().add(obj);
		return *obj;
	}

	template<typename T> T& createInstance(Control& parent) {
		T *obj = new T(&parent);
		Application::getInstance().add(obj);
		return *obj;
	}

};

#endif
