/*
 * image.hpp
 *
 * Last modified: <2014/02/18 01:19:33 +0900> By Zumida
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

			void load(const HINSTANCE hInstance, const int id, const int type);
			void load(const HINSTANCE hInstance, const String& name, const int type);
			void load(const HINSTANCE hInstance, const TCHAR* idc, const int type);
			const HANDLE getHandle() const;

			const static class Image empty;
		};
	};
};

#endif
