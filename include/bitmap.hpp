/*
 * bitmap.hpp
 *
 * Last modified: <2014/02/17 23:24:33 +0900> By Zumida
 */
#ifndef BITMAP_HPP_INCLUDED
#define BITMAP_HPP_INCLUDED

#include "image.hpp"

namespace swo {
	inline namespace image {

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
};

#endif
