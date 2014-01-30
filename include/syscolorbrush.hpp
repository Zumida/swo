/*
 * syscolorbrush.hpp
 *
 * Last modified: <2014/01/30 16:41:15 +0900> By Zumida
 */
#ifndef SYSCOLORBRUSH_HPP_INCLUDED
#define SYSCOLORBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SysColorBrush : public Brush {
	protected:
		int index;

		void refresh();

	public:
		SysColorBrush();
		~SysColorBrush();

		SysColorBrush& set(const int index);
		int getIndex() const;
		void trash();

		static SysColorBrush& create(const int index);
	};

};

#endif
