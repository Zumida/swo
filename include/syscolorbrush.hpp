/*
 * syscolorbrush.hpp
 *
 * Last modified: <2013/08/28 02:21:34 +0900> By Zumida
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
		~SysColorBrush();

		SysColorBrush& set(const int index);
		int getIndex(void) const;
		void trash(void);

		static SysColorBrush& create(const int index);
	};

};

#endif
