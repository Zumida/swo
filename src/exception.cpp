/*
 * exception.cpp
 *
 * Last modified: <2014/01/29 17:30:34 +0900> By Zumida
 */
#include "exception.hpp"
#include <typeinfo>
#include <cxxabi.h>
#include <sstream>

namespace swo {
	inline namespace exception {
		Exception::Exception(const String& message)
			: message(message), cause(nullptr), clone(false) {}

		Exception::Exception(const String& message, const Exception& cause)
			: message(message), cause(new Exception(cause)), clone(false) {}

		Exception::Exception(const Exception& cause)
			: message(cause.message), cause(nullptr), clone(true), name(cause.what()) {}

		Exception::~Exception() {
			if (cause != nullptr) {
				delete cause;
				cause = nullptr;
			}
		}

		const String& Exception::getMessage() const {
			return message;
		}

		const Exception* Exception::getCause() const {
			return cause;
		}

		const char* Exception::what() const throw() {
			if (clone) {
				return name.c_str();
			} else {
				const std::type_info& id_p = typeid(*this);
				int status;
				return abi::__cxa_demangle(id_p.name(), 0, 0, &status);
			}
		}

		const String Exception::getDetail() const {
			StringStream ss;

			ss << what() << L": " << message;

			if (cause != nullptr) {
				ss << L"\ncause " << cause->getDetail();
			}

			return ss.str();
		}
	};
};
