/*
 * object.cpp
 *
 * Last modified: <2013/04/17 14:03:54 +0900> By Zumida
 */
#include "object.hpp"

#include <typeinfo>
#include <cxxabi.h>

using namespace swo;

Object::Object() {
}

Object::~Object() {
}

String Object::getClassName(void) {
	const std::type_info & id_p = typeid(*this);
	int status;

	return swo::toString(abi::__cxa_demangle(id_p.name(), 0, 0, &status));
}

String Object::toString(void) {
	StringStream ss;

	ss << this << _T("@") << getClassName() << std::endl;

	return ss.str();
}
