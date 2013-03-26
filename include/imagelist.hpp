/*
 * imagelist.hpp
 *
 * Last modified: <2013/03/21 09:37:22 +0900> By Zumida
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
		virtual ~ImageList();

		void addIcon();
	};

};

#endif
