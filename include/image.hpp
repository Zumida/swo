/*
 * image.hpp
 *
 * Last modified: <2013/05/06 21:56:11 +0900> By Zumida
 */
#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include "object.hpp"

namespace swo {

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
		HANDLE getHandle(void) const;

		const static class Image empty;
	};

};

#endif
