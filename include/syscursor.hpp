/*
 * syscursor.hpp
 *
 * Last modified: <2014/02/17 22:00:13 +0900> By Zumida
 */
#ifndef SYSCURSOR_HPP_INCLUDED
#define SYSCURSOR_HPP_INCLUDED

#include "cursor.hpp"

namespace swo {
	inline namespace image {

		class SysCursor : public Cursor {
		private:
			SysCursor(const TCHAR* idc);
			~SysCursor();

		public:
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
};

#endif
