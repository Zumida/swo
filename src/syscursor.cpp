/*
 * syscursor.cpp
 *
 * Last modified: <2014/02/17 23:15:53 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "syscursor.hpp"

namespace swo {
	inline namespace image {

		SysCursor::SysCursor(const TCHAR* idc) {
			Image::load(nullptr, idc, IMAGE_CURSOR);
		}

		SysCursor::~SysCursor() {
		}

		const SysCursor SysCursor::AppStarting(IDC_APPSTARTING);
		const SysCursor SysCursor::Arrow(IDC_ARROW);
		const SysCursor SysCursor::Cross(IDC_CROSS);
		const SysCursor SysCursor::Hand(IDC_HAND);
		const SysCursor SysCursor::Help(IDC_HELP);
		const SysCursor SysCursor::IBeam(IDC_IBEAM);
		const SysCursor SysCursor::No(IDC_NO);
		const SysCursor SysCursor::SizeAll(IDC_SIZEALL);
		const SysCursor SysCursor::SizeNESW(IDC_SIZENESW);
		const SysCursor SysCursor::SizeNS(IDC_SIZENS);
		const SysCursor SysCursor::SizeNWSE(IDC_SIZENWSE);
		const SysCursor SysCursor::SizeWE(IDC_SIZEWE);
		const SysCursor SysCursor::Uparrow(IDC_UPARROW);
		const SysCursor SysCursor::Wait(IDC_WAIT);
	};
};
