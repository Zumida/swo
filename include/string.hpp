/*
 * string.hpp
 *
 * Last modified: <2013/04/17 12:37:05 +0900> By Zumida
 */
#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include <locale.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <iostream>

namespace swo {

	typedef std::basic_string<TCHAR>        tstring;
	typedef std::basic_stringstream<TCHAR>  tstringstream;
	typedef std::basic_ostringstream<TCHAR> tostringstream;
	typedef std::basic_istringstream<TCHAR> tistringstream;

	typedef tstring         String;
	typedef tstringstream   StringStream;
	typedef tostringstream  OutputStringStream;
	typedef tistringstream  InputStringStream;

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

#define StdOut tout
#define StdIn  tin
#define StdErr terr
#define StdLog tlog

	extern String toString(char *str);
	extern String empty;

};

#endif
