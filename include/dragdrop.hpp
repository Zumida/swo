/*
 * dragdrop.hpp
 *
 * Last modified: <2013/03/22 11:30:28 +0900> By Zumida
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
