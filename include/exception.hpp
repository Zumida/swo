/*
 * exception.hpp
 *
 * Last modified: <2014/01/23 06:46:24 +0900> By Zumida
 */
#ifndef EXCEPTION_HPP_INCLUDED
#define EXCEPTION_HPP_INCLUDED

#include "string.hpp"

namespace swo {
	inline namespace core {
		class Exception : public std::exception {
		private:
			String message;
		public:
			Exception(const String& message, const class Exception& cause=empty);
			const String& getMessage(void) const;
			const Exception& getCause(void) const;
			const char* what() const throw();

			static class Exception empty;
		};
	};
};

#endif
