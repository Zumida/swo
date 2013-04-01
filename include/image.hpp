/*
 * image.hpp
 *
 * Last modified: <2013/04/02 00:52:55 +0900> By Zumida
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
		virtual ~Image();

		void load(const String& name, const int type);
		HANDLE getHandle(void) const;

		const static class Image empty;
	};

};

#endif
