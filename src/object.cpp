/*
 * object.cpp
 *
 * Last modified: <2014/01/07 19:20:43 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

	return swo::string::valueOf(
		abi::__cxa_demangle(id_p.name(), 0, 0, &status));
}

String Object::toString(void) {
	StringStream ss;

	ss << this << L"@" << getClassName() << std::endl;

	return ss.str();
}
