/*
 * logger.cpp
 *
 * Last modified: <2014/01/17 17:37:49 +0900> By Zumida
 */
#include "logger.hpp"

namespace swo {
	inline namespace log {
		void Log::debug(const char* file, const int line,
						const char* func, const String& msg) {

			Stdlog << L"[DEBUG] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void Log::info(const char* file, const int line,
					   const char* func, const String& msg) {

			Stdlog << L"[INFO] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void Log::warn(const char* file, const int line,
					   const char* func, const String& msg) {

			Stdlog << L"[WARN] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void Log::error(const char* file, const int line,
						const char* func, const String& msg) {

			Stdlog << L"[ERROR] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void Log::exception(const char* file, const int line,
							const char* func, const std::exception& e) {

			Stdlog << L"[EXCEPTION] "
				<< func << L"(" << file << L":" << line << L") - "
				<< e.what() << std::endl;
		}
	};
};
