/*
 * logger.cpp
 *
 * Last modified: <2014/01/29 19:13:18 +0900> By Zumida
 */
#include "logger.hpp"

namespace swo {
	inline namespace log {
		void debugLog(const char* file, const int line,
					  const char* func, const String& msg) {

			Stdlog << L"[DEBUG] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void infoLog(const char* file, const int line,
					 const char* func, const String& msg) {

			Stdlog << L"[INFO] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void warningLog(const char* file, const int line,
						const char* func, const String& msg) {

			Stdlog << L"[WARN] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void errorLog(const char* file, const int line,
					  const char* func, const String& msg) {

			Stdlog << L"[ERROR] "
				<< func << L"(" << file << L":" << line << L") - "
				<< msg << std::endl;
		}

		void exceptionLog(const char* file, const int line,
						  const char* func, const std::exception& e) {

			Stdlog << L"[EXCEPTION] "
				<< func << L"(" << file << L":" << line << L") - "
				<< e.what() << std::endl;
		}

		void exceptionLog(const char* file, const int line,
						  const char* func,
						  const swo::exception::Exception& e) {

			Stdlog << L"[EXCEPTION] "
				<< func << L"(" << file << L":" << line << L") - "
				<< e.getDetail() << std::endl;
		}
	};
};
