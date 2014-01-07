/*
 * swomain.hpp
 *
 * Last modified: <2014/01/07 14:12:44 +0900> By Zumida
 */
#ifndef SWOMAIN_HPP_INCLUDED
#define SWOMAIN_HPP_INCLUDED

#include "swoconfig.hpp"
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
