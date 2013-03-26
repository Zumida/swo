/*
 * object.cpp
 *
 * Last modified: <2013/03/21 09:49:19 +0900> By Zumida
 */

#include "object.hpp"

#include <typeinfo>
#include <cxxabi.h>

using namespace swo;

Object::Object() {
}

Object::~Object() {
}

String Object::getName(void) {
	const std::type_info & id_p = typeid(*this);
	int status;

	return swo::toString(abi::__cxa_demangle(id_p.name(), 0, 0, &status));
}

String Object::toString(void) {
	StringStream ss;

	ss << this << _T("@") << getName() << std::endl;

	return ss.str();
}
