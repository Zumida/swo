/*
 * image.hpp
 *
 * Last modified: <2014/01/31 16:53:07 +0900> By Zumida
 */
#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include "object.hpp"

namespace swo {
	inline namespace image {

		class Image : public Object {
		protected:
			HANDLE handle;
			int type;

		public:
			Image();
			Image(const class Image& image);
			~Image();

			void load(const String& name, const int type);
			void load(const TCHAR* id, const int type);
			const HANDLE getHandle() const;

			const static class Image empty;
		};
	};
};

#endif
