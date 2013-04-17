/*
 * dragdrop.hpp
 *
 * Last modified: <2013/04/17 12:40:31 +0900> By Zumida
 */
#ifndef DRAGDROP_HPP_INCLUDED
#define DRAGDROP_HPP_INCLUDED

#include "object.hpp"
#include "stringlist.hpp"
#include "point.hpp"

namespace swo {

	class DragDrop : public Object {
	private:
		StringList files;
		Point point;

	public:
		DragDrop(HDROP hDrop);
		~DragDrop();

		const StringList& getFiles(void) const;
		const Point& getPoint(void) const;
	};

};

#endif
