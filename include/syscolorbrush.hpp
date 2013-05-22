/*
 * syscolorbrush.hpp
 *
 * Last modified: <2013/05/22 07:11:29 +0900> By Zumida
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
		int getIndex(void) const;
		void trash(void);
	};

};

#endif
