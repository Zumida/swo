/*
 * canvas.hpp
 *
 * Last modified: <2014/01/30 16:39:20 +0900> By Zumida
 */
#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "object.hpp"
#include "rect.hpp"

namespace swo {

	class Canvas : public Object {
	protected:
		HWND hWnd;
		HDC hDc;
		PAINTSTRUCT ps;

	public:
		Canvas(HWND hWnd);
		~Canvas();

		const HDC getDc() const;
		const Rect& getRect() const;

		void beginPaint();
		void endPaint();
	};

};

#endif
