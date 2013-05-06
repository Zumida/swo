/*
 * sysicon.hpp
 *
 * Last modified: <2013/05/07 06:39:09 +0900> By Zumida
 */
#ifndef SYSICON_HPP_INCLUDED
#define SYSICON_HPP_INCLUDED

#include "icon.hpp"

namespace swo {

	class SysIcon : public Icon {
	public:
		SysIcon(const TCHAR* idc);
		~SysIcon();

		const static class SysIcon AppStarting;
		const static class SysIcon Arrow;
		const static class SysIcon Cross;
		const static class SysIcon Hand;
		const static class SysIcon Help;
		const static class SysIcon IBeam;
		const static class SysIcon No;
		const static class SysIcon SizeAll;
		const static class SysIcon SizeNESW;
		const static class SysIcon SizeNS;
		const static class SysIcon SizeNWSE;
		const static class SysIcon SizeWE;
		const static class SysIcon Uparrow;
		const static class SysIcon Wait;
	};

};

#endif
