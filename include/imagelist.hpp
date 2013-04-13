/*
 * imagelist.hpp
 *
 * Last modified: <2013/04/12 22:23:18 +0900> By Zumida
 */
#ifndef IMAGELIST_HPP_INCLUDED
#define IMAGELIST_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class ImageList : public Object {
	private:
		HIMAGELIST handle;

	public:
		ImageList();
		~ImageList();

		void addIcon();
	};

};

#endif
