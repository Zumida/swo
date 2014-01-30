/*
 * bitmap.hpp
 *
 * Last modified: <2014/01/30 16:39:10 +0900> By Zumida
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
		HBITMAP getHandle() const;

		const static class Bitmap empty;
	};

};

#endif
