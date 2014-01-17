/*
 * logger.hpp
 *
 * Last modified: <2014/01/17 23:46:35 +0900> By Zumida
 */
#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"

namespace swo {
	inline namespace log {
		extern void debug(const char* file, const int line,
						  const char* func, const String& msg);
		extern void info(const char* file, const int line,
						 const char* func, const String& msg);
		extern void warn(const char* file, const int line,
						 const char* func, const String& msg);
		extern void error(const char* file, const int line,
						  const char* func, const String& msg);
		extern void exception(const char* file, const int line,
							  const char* func, const std::exception& e);
	};
};

#define LOG_D(m)  swo::log::debug(__FILE__,__LINE__,__func__,m)
#define LOG_I(m)  swo::log::info(__FILE__,__LINE__,__func__,m)
#define LOG_W(m)  swo::log::warn(__FILE__,__LINE__,__func__,m)
#define LOG_E(m)  swo::log::error(__FILE__,__LINE__,__func__,m)
#define LOG_EX(e) swo::log::exception(__FILE__,__LINE__,__func__,e)

#endif
