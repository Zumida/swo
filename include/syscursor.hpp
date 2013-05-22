/*
 * syscursor.hpp
 *
 * Last modified: <2013/05/22 06:49:49 +0900> By Zumida
 */
#ifndef SYSCURSOR_HPP_INCLUDED
#define SYSCURSOR_HPP_INCLUDED

#include "cursor.hpp"

namespace swo {

	class SysCursor : public Cursor {
	public:
		SysCursor(const TCHAR* idc);
		~SysCursor();

		const static class SysCursor AppStarting;
		const static class SysCursor Arrow;
		const static class SysCursor Cross;
		const static class SysCursor Hand;
		const static class SysCursor Help;
		const static class SysCursor IBeam;
		const static class SysCursor No;
		const static class SysCursor SizeAll;
		const static class SysCursor SizeNESW;
		const static class SysCursor SizeNS;
		const static class SysCursor SizeNWSE;
		const static class SysCursor SizeWE;
		const static class SysCursor Uparrow;
		const static class SysCursor Wait;
	};

};

#endif
