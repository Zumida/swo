/*
 * string.hpp
 *
 * Last modified: <2014/01/25 01:52:32 +0900> By Zumida
 */
#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include "swoconfig.hpp"
#include <tchar.h>
#include <clocale>
#include <string>
#include <sstream>
#include <iostream>
#include <list>

#if defined(UNICODE) || defined(_UNICODE)
# define tout std::wcout
# define tin  std::wcin
# define terr std::wcerr
# define tlog std::wclog
#else
# define tout std::cout
# define tin  std::cin
# define terr std::cerr
# define tlog std::clog
#endif

#define Stdout tout
#define Stdin  tin
#define Stderr terr
#define Stdlog tlog

namespace swo {
	inline namespace string {

		using tstring = std::basic_string<TCHAR>;
		using tstringstream = std::basic_stringstream<TCHAR>;
		using tostringstream = std::basic_ostringstream<TCHAR>;
		using tistringstream = std::basic_istringstream<TCHAR>;

		using String = tstring;
		using StringStream = tstringstream;
		using OutputStringStream = tostringstream;
		using InputStringStream = tistringstream;

		extern String valueOf(const char *str);
		extern String replaceAll(const String& str,
								 const String& find, const String& replace);
		extern String empty;

		using StringList = std::list<String>;
	};
};

#endif
