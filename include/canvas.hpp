/*
 * canvas.hpp
 *
 * Last modified: <2013/03/22 16:28:07 +0900> By Zumida
 */
#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "object.hpp"
#include "rect.hpp"

namespace swo {

	class Canvas : public Object {
	private:
		HDC hDc;
		Rect rect;

	public:
		Canvas(HDC hDc, HWND hWnd);
		Canvas(HDC hDc, const Rect& rect);
		~Canvas();

		const HDC getDc(void) const;
		Rect& getRect(void);
	};

};

#endif
