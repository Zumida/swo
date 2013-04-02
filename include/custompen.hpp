/*
 * custompen.hpp
 *
 * Last modified: <2013/04/02 18:09:17 +0900> By Zumida
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

	public:
		CustomPen(int style, int width, COLORREF color);
		CustomPen(int style, int width, int r, int g, int b);
		virtual ~CustomPen();

		virtual HGDIOBJ getHandle(void);
	};

};

#endif
