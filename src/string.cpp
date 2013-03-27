/*
 * string.cpp
 *
 * Last modified: <2013/03/27 20:12:38 +0900> By Zumida
 */

#include "string.hpp"
#include <windows.h>
#include <string.h>

namespace swo {

	String toString(char *str) {
		String result;

#if defined(UNICODE) || defined(_UNICODE)
		int len = ::MultiByteToWideChar(CP_THREAD_ACP, 0, str, -1, NULL, 0);
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
