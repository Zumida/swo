/*
 * exception.cpp
 *
 * Last modified: <2014/01/24 06:59:20 +0900> By Zumida
 */
#include "exception.hpp"
#include <typeinfo>
#include <cxxabi.h>

namespace swo {
	inline namespace core {
		Exception::Exception(const String& message, const class Exception* cause=nullptr)
			: message(message), cause(cause) {}

		Exception::~Exception() {}

		const String& Exception::getMessage() const {
			return message;
		}

		const Exception* Exception::getCause() const {
			return cause;
		}

		const char* Exception::what() const throw() {
			const std::type_info & id_p = typeid(*this);
			int status;
			return abi::__cxa_demangle(id_p.name(), 0, 0, &status);
		}
	};
};
