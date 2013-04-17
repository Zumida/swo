/*
 * bitmap.hpp
 *
 * Last modified: <2013/04/17 12:43:26 +0900> By Zumida
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
		Bitmap(const String& name);
		~Bitmap();

		Bitmap& set(const String& name);
		HBITMAP getHandle(void) const;

		const static class Bitmap empty;
	};

};

#endif
