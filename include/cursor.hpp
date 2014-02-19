/*
 * cursor.hpp
 *
 * Last modified: <2014/02/17 23:18:53 +0900> By Zumida
 */
#ifndef CURSOR_HPP_INCLUDED
#define CURSOR_HPP_INCLUDED

#include "image.hpp"

namespace swo {
	inline namespace image {

		class Cursor : public Image {
		public:
			Cursor();
			Cursor(const String& name);
			~Cursor();

			Cursor& set(const String& name);
			HCURSOR getHandle() const;
		};
	};
};

#endif
