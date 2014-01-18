/*
 * uri.cpp
 *
 * Last modified: <2014/01/18 16:39:50 +0900> By Zumida
 */
#include "string.hpp"
//#include <regex>

namespace swo {
	inline namespace uri {

		String basename(const String& uri) {
			String p = replaceAll(uri, L"\\", L"/");
			return p.substr(p.find_last_of(L'/') + 1);
		}

		String filename(const String& uri) {
			String b = basename(uri);
			auto e = b.find_last_of(L'.');
			return (e < 0)? b: b.substr(0, e);
		}

		String extname(const String& uri) {
			auto i = uri.find_last_of(L'.');
			return (i < 0)? string::empty: uri.substr(i + 1);
		}
	};
};
