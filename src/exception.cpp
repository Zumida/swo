/*
 * exception.cpp
 *
 * Last modified: <2014/01/25 13:48:25 +0900> By Zumida
 */
#include "exception.hpp"
#include <typeinfo>
#include <cxxabi.h>
#include <sstream>

namespace swo {
	inline namespace exception {
		Exception::Exception(const String& message, const Exception* cause)
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

		const String Exception::getDetail() const {
			StringStream ss;

			ss << what() << L":" << message;

			if (cause != nullptr) {
				ss << L"\ncause " << cause->getMessage();
			}

			return ss.str();
		}
	};
};
