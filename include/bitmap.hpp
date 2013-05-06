/*
 * bitmap.hpp
 *
 * Last modified: <2013/05/03 21:18:21 +0900> By Zumida
 */
#ifndef BITMAP_HPP_INCLUDED
#define BITMAP_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Bitmap : public Image {
	public:
		Bitmap();
		Bitmap(const String& name);
		~Bitmap();

		Bitmap& set(const String& name);
		HBITMAP getHandle(void) const;

		const static class Bitmap empty;
	};

};

#endif
