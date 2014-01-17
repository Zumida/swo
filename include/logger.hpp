/*
 * logger.hpp
 *
 * Last modified: <2014/01/17 17:29:00 +0900> By Zumida
 */
#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"

namespace swo {
	inline namespace log {
		class Log {
		public:
			Log() = delete;
			~Log() = delete;

			static void debug(const char* file, const int line,
							  const char* func, const String& msg);
			static void info(const char* file, const int line,
							 const char* func, const String& msg);
			static void warn(const char* file, const int line,
							 const char* func, const String& msg);
			static void error(const char* file, const int line,
							  const char* func, const String& msg);
			static void exception(const char* file, const int line,
								  const char* func, const std::exception& e);
		};
	};
};

#define LOG_D(m)  swo::log::Log::debug(__FILE__,__LINE__,__func__,m)
#define LOG_I(m)  swo::log::Log::info(__FILE__,__LINE__,__func__,m)
#define LOG_W(m)  swo::log::Log::warn(__FILE__,__LINE__,__func__,m)
#define LOG_E(m)  swo::log::Log::error(__FILE__,__LINE__,__func__,m)
#define LOG_EX(e) swo::log::Log::exception(__FILE__,__LINE__,__func__,e)

#endif
