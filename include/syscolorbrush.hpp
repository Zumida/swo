/*
 * syscolorbrush.hpp
 *
 * Last modified: <2013/04/12 22:40:25 +0900> By Zumida
 */
#ifndef SYSCOLORBRUSH_HPP_INCLUDED
#define SYSCOLORBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SysColorBrush : public Brush {
	protected:
		int index;

	public:
		SysColorBrush();
		SysColorBrush(const int index);
		~SysColorBrush();

		Brush& set(const int index);
		HGDIOBJ getHandle(void);
		void trash(void);
	};

};

#endif