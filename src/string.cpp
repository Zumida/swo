/*
 * string.cpp
 *
 * Last modified: <2014/01/30 17:29:48 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "string.hpp"
#include <windows.h>

namespace swo {
	inline namespace string {

		String valueOf(const char *str) {
			String result;

#if defined(UNICODE) || defined(_UNICODE)
			int len = ::MultiByteToWideChar(CP_THREAD_ACP, 0, str, -1, nullptr, 0);
			WCHAR* wstr = new WCHAR[len];
			::MultiByteToWideChar(CP_THREAD_ACP, 0, str, (int)::strlen(str)+1, wstr, len);
			result = wstr;
			delete wstr;

#else
			result = str;
#endif

			return result;
		}

		String valueOf(const int value) {
			StringStream ss;
			ss << value;
			return ss.str();
		}

		String valueOf(const double value) {
			StringStream ss;
			ss << value;
			return ss.str();
		}

		String replaceAll(const String& str,
						  const String& find, const String& replace) {
			String s(str);

			for(std::string::size_type pos(s.find(find));
				pos != std::string::npos;
				pos = s.find(find, pos + replace.length())) {

				s.replace(pos, find.length(), replace);
			}

			return s;
		}

		String empty;
	};
};
