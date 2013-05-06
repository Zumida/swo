/*
 * sysicon.cpp
 *
 * Last modified: <2013/05/07 06:32:24 +0900> By Zumida
 */
#include "sysicon.hpp"

using namespace swo;

SysIcon::SysIcon(const TCHAR* idc) {
	Image::load(idc, IMAGE_ICON);
}

SysIcon::~SysIcon() {
}

const SysIcon SysIcon::AppStarting(IDC_APPSTARTING);
const SysIcon SysIcon::Arrow(IDC_ARROW);
const SysIcon SysIcon::Cross(IDC_CROSS);
const SysIcon SysIcon::Hand(IDC_HAND);
const SysIcon SysIcon::Help(IDC_HELP);
const SysIcon SysIcon::IBeam(IDC_IBEAM);
const SysIcon SysIcon::No(IDC_NO);
const SysIcon SysIcon::SizeAll(IDC_SIZEALL);
const SysIcon SysIcon::SizeNESW(IDC_SIZENESW);
const SysIcon SysIcon::SizeNS(IDC_SIZENS);
const SysIcon SysIcon::SizeNWSE(IDC_SIZENWSE);
const SysIcon SysIcon::SizeWE(IDC_SIZEWE);
const SysIcon SysIcon::Uparrow(IDC_UPARROW);
const SysIcon SysIcon::Wait(IDC_WAIT);
