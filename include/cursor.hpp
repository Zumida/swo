/*
 * cursor.hpp
 *
 * Last modified: <2013/03/27 14:30:11 +0900> By Zumida
 */
#ifndef CURSOR_HPP_INCLUDED
#define CURSOR_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Cursor : public Image {
	private:

	public:
		Cursor();
		Cursor(const String& cursorName);
		virtual ~Cursor();

		HCURSOR getHandle(void) const;
	};

};

#endif
