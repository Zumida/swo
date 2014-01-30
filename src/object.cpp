/*
 * object.cpp
 *
 * Last modified: <2014/01/30 16:40:39 +0900> By Zumida
 */
#include "object.hpp"

#include <typeinfo>
#include <cxxabi.h>

namespace swo {
	inline namespace core {

		Object::Object() {}

		Object::~Object() {}

		String Object::getClassName() {
			const std::type_info & id_p = typeid(*this);
			int status;

			return swo::string::valueOf(
				abi::__cxa_demangle(id_p.name(), 0, 0, &status));
		}

		String Object::toString() {
			StringStream ss;

			ss << this << L"@" << getClassName();

			return ss.str();
		}
	};
};
