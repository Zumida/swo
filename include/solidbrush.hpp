/*
 * solidbrush.hpp
 *
 * Last modified: <2013/05/13 18:07:53 +0900> By Zumida
 */
#ifndef SOLIDBRUSH_HPP_INCLUDED
#define SOLIDBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class SolidBrush : public Brush {
	protected:
		COLORREF color;

		void refresh(void);

	public:
		SolidBrush();
		SolidBrush(const COLORREF color);
		~SolidBrush();

		Brush& set(const COLORREF color);
	};

};

#endif
