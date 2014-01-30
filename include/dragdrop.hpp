/*
 * dragdrop.hpp
 *
 * Last modified: <2014/01/30 16:39:49 +0900> By Zumida
 */
#ifndef DRAGDROP_HPP_INCLUDED
#define DRAGDROP_HPP_INCLUDED

#include "object.hpp"
#include "point.hpp"

namespace swo {

	class DragDrop : public Object {
	protected:
		StringList files;
		Point point;

	public:
		DragDrop(HDROP hDrop);
		~DragDrop();

		const StringList& getFiles() const;
		const Point& getPoint() const;
	};

};

#endif
