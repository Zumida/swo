/*
 * uri.hpp
 *
 * Last modified: <2014/01/18 15:51:03 +0900> By Zumida
 */
#ifndef URI_HPP_INCLUDED
#define URI_HPP_INCLUDED

#include "swoconfig.hpp"
#include "string.hpp"

namespace swo {
	inline namespace uri {

		extern String basename(const String& uri);
		extern String filename(const String& uri);
		extern String extname(const String& uri);
	};
};

#endif
