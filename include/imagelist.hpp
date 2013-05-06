/*
 * imagelist.hpp
 *
 * Last modified: <2013/05/06 22:16:20 +0900> By Zumida
 */
#ifndef IMAGELIST_HPP_INCLUDED
#define IMAGELIST_HPP_INCLUDED

#include "object.hpp"

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
