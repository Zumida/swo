/*
 * exception.hpp
 *
 * Last modified: <2014/01/24 07:01:31 +0900> By Zumida
 */
#ifndef EXCEPTION_HPP_INCLUDED
#define EXCEPTION_HPP_INCLUDED

#include "string.hpp"

namespace swo {
	inline namespace core {
		class Exception : public std::exception {
		private:
			String message;
			const Exception* cause;
		public:
			Exception(const String& message, const Exception* cause=nullptr);
			virtual ~Exception();
			const String& getMessage() const;
			const Exception* getCause() const;
			const char* what() const throw();
		};
	};
};

#endif
