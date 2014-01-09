/*
 * string.cpp
 *
 * Last modified: <2014/01/09 11:53:25 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "string.hpp"
#include <windows.h>

namespace swo {
	inline namespace string {

		String valueOf(char *str) {
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

		String empty;
	};
};
