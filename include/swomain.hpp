/*
 * swomain.hpp
 *
 * Last modified: <2013/08/22 21:42:52 +0900> By Zumida
 */
#ifndef SWOMAIN_HPP_INCLUDED
#define SWOMAIN_HPP_INCLUDED

#include "define.hpp"
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR pCmdLine, int showCmd);
int main(const int argc, const char* argv[]);

#ifdef __cplusplus
}
#endif

#endif
