/*
 * imagelist.hpp
 *
 * Last modified: <2014/01/08 10:15:39 +0900> By Zumida
 */
#ifndef IMAGELIST_HPP_INCLUDED
#define IMAGELIST_HPP_INCLUDED

#include "object.hpp"
#include <commctrl.h>

namespace swo {

	class ImageList : public Object {
	protected:
		HIMAGELIST handle;

	public:
		ImageList();
		~ImageList();

		void addIcon();
	};

};

#endif
