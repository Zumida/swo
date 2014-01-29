/*
 * logger.hpp
 *
 * Last modified: <2014/01/29 19:12:33 +0900> By Zumida
 */
#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"
#include "exception.hpp"

namespace swo {
	inline namespace log {
		extern void debugLog(const char* file, const int line,
						  const char* func, const String& msg);
		extern void infoLog(const char* file, const int line,
						 const char* func, const String& msg);
		extern void warningLog(const char* file, const int line,
						 const char* func, const String& msg);
		extern void errorLog(const char* file, const int line,
						  const char* func, const String& msg);
		extern void exceptionLog(const char* file, const int line,
								 const char* func, const std::exception& e);
		extern void exceptionLog(const char* file, const int line,
								 const char* func,
								 const swo::exception::Exception& e);
	};
};

#define LOG_D(m)  swo::log::debugLog(__FILE__,__LINE__,__func__,m)
#define LOG_I(m)  swo::log::infoLog(__FILE__,__LINE__,__func__,m)
#define LOG_W(m)  swo::log::warningLog(__FILE__,__LINE__,__func__,m)
#define LOG_E(m)  swo::log::errorLog(__FILE__,__LINE__,__func__,m)
#define LOG_EX(e) swo::log::exceptionLog(__FILE__,__LINE__,__func__,e)

#endif
