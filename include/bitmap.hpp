/*
 * bitmap.hpp
 *
 * Last modified: <2013/03/27 16:53:34 +0900> By Zumida
 */
#ifndef BITMAP_HPP_INCLUDED
#define BITMAP_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Bitmap : public Image {
	private:
		HBITMAP handle;

	public:
		Bitmap();
		Bitmap(const String& bitmapName);
		virtual ~Bitmap();

		HBITMAP getHandle(void) const;

		const static class Bitmap empty;
	};

};

#endif
