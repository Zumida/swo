/*
 * cursor.hpp
 *
 * Last modified: <2014/01/30 16:39:39 +0900> By Zumida
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
		HCURSOR getHandle() const;
	};

};

#endif
