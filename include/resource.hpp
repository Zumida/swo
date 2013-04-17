/*
 * resource.hpp
 *
 * Last modified: <2013/04/17 12:38:03 +0900> By Zumida
 */
#ifndef RESOURCE_HPP_INCLUDED
#define RESOURCE_HPP_INCLUDED

#if defined(__MINGW32__)
# ifdef MAKEINTRESOURCEA
#   undef  MAKEINTRESOURCEA
# endif
# ifdef MAKEINTRESOURCEW
#   undef  MAKEINTRESOURCEW
# endif
#define MAKEINTRESOURCEA(i)  ((LPSTR)((ULONG_PTR)(i)))
#define MAKEINTRESOURCEW(i)  ((LPWSTR)((ULONG_PTR)(i)))
#endif

#endif
