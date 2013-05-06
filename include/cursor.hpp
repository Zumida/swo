/*
 * cursor.hpp
 *
 * Last modified: <2013/05/06 01:08:14 +0900> By Zumida
 */
#ifndef CURSOR_HPP_INCLUDED
#define CURSOR_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Cursor : public Image {
	public:
		Cursor();
		Cursor(const String& name);
		~Cursor();

		Cursor& set(const String& name);
		HCURSOR getHandle(void) const;
	};

};

#endif
