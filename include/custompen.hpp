/*
 * custompen.hpp
 *
 * Last modified: <2013/05/13 18:04:40 +0900> By Zumida
 */
#ifndef CUSTOMPEN_HPP_INCLUDED
#define CUSTOMPEN_HPP_INCLUDED

#include "pen.hpp"

namespace swo {

	class CustomPen : public Pen {
	protected:
		int style;
		int width;
		COLORREF color;

		void refresh(void);

	public:
		CustomPen();
		CustomPen(const int style, const int width, const COLORREF color);
		~CustomPen();

		Pen& set(const int style, const int width, const COLORREF color);
	};

};

#endif
