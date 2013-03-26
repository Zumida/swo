/*
 * cursor.hpp
 *
 * Last modified: <2013/03/25 18:31:23 +0900> By Zumida
 */
#ifndef CURSOR_HPP_INCLUDED
#define CURSOR_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class Cursor : public Object {
	private:
		HCURSOR handle;

	public:
		Cursor();
		Cursor(String cursorName);
		Cursor(const Cursor& cursor);
		virtual ~Cursor();

		HCURSOR getHandle(void) const;
	};

};

#endif
