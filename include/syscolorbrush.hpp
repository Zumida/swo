/*
 * syscolorbrush.hpp
 *
 * Last modified: <2013/05/13 18:09:33 +0900> By Zumida
 */
#ifndef SYSCOLORBRUSH_HPP_INCLUDED
#define SYSCOLORBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SysColorBrush : public Brush {
	protected:
		int index;

		void refresh(void);

	public:
		SysColorBrush();
		SysColorBrush(const int index);
		~SysColorBrush();

		Brush& set(const int index);
		void trash(void);
	};

};

#endif
