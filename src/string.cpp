/*
 * string.cpp
 *
 * Last modified: <2014/01/07 17:39:52 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "string.hpp"
#include <windows.h>
#include <cstring>

namespace swo {
	inline namespace string {

	String toString(char *str) {
		String result;

#if defined(UNICODE) || defined(_UNICODE)
		int len = ::MultiByteToWideChar(CP_THREAD_ACP, 0, str, -1, nullptr, 0);
		WCHAR* wstr = new WCHAR[len];

		::MultiByteToWideChar(CP_THREAD_ACP, 0, str, (int)::strlen(str)+1, wstr, len);

		result = wstr;
		delete wstr;

#else
/*
		size_t len ::_tcslen(str) + 1;

		TCHAR* tstr = new TCHAR[len];
		::wcscpy_s(tstr, len * sizeof(TCHAR), str);

		result = tstr;
		delete tstr;
*/
		result = str;
#endif

		return result;
	}

	String empty;
	};
};
