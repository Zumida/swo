/*
 * canvas.hpp
 *
 * Last modified: <2013/04/17 12:43:05 +0900> By Zumida
 */
#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "object.hpp"
#include "rect.hpp"

namespace swo {

	class Canvas : public Object {
	private:
		HWND hWnd;
		HDC hDc;
		PAINTSTRUCT ps;

	public:
		Canvas(HWND hWnd);
		~Canvas();

		const HDC getDc(void) const;
		const Rect& getRect(void) const;

		void beginPaint(void);
		void endPaint(void);
	};

};

#endif
