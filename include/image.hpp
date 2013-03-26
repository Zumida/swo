/*
 * image.hpp
 *
 * Last modified: <2013/03/21 09:36:32 +0900> By Zumida
 */
#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class Image : public Object {
	private:
		HANDLE handle;

	public:
		Image();
		virtual ~Image();


	};

};

#endif
