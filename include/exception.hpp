/*
 * exception.hpp
 *
 * Last modified: <2014/01/25 13:48:31 +0900> By Zumida
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
			const Exception *cause;
		public:
			Exception(const String& message,
					  const Exception* cause=nullptr);
			virtual ~Exception();
			const String& getMessage() const;
			const Exception* getCause() const;
			const char* what() const throw();
			const String getDetail() const;
		};
	};
};

#endif
