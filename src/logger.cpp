/*
 * logger.cpp
 *
 * Last modified: <2014/01/17 23:47:08 +0900> By Zumida
 */
#include "logger.hpp"

namespace swo {
	inline namespace log {
		void debug(const char* file, const int line,
						const char* func, const String& msg) {

			Stdlog << L"[DEBUG] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void info(const char* file, const int line,
					   const char* func, const String& msg) {

			Stdlog << L"[INFO] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void warn(const char* file, const int line,
					   const char* func, const String& msg) {

			Stdlog << L"[WARN] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void error(const char* file, const int line,
						const char* func, const String& msg) {

			Stdlog << L"[ERROR] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void exception(const char* file, const int line,
							const char* func, const std::exception& e) {

			Stdlog << L"[EXCEPTION] "
				<< func << L"(" << file << L":" << line << L") - "
				<< e.what() << std::endl;
		}
	};
};
