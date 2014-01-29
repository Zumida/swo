/*
 * exception.hpp
 *
 * Last modified: <2014/01/29 17:33:46 +0900> By Zumida
 */
#ifndef EXCEPTION_HPP_INCLUDED
#define EXCEPTION_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"
#include <exception>

namespace swo {
	inline namespace exception {
		class Exception : public std::exception {
		private:
			const String message;
			const Exception* cause;
			const bool clone;
			const std::string name;
		public:
			Exception(const String& message);
			Exception(const String& message, const Exception& cause);
			Exception(const Exception& cause);
			virtual ~Exception();
			const String& getMessage() const;
			const Exception* getCause() const;
			const char* what() const throw();
			const String getDetail() const;
		};
	};
};

#endif
