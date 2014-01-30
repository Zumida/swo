/*
 * gdiobject.hpp
 *
 * Last modified: <2014/01/30 16:40:02 +0900> By Zumida
 */
#ifndef GDIOBJECT_HPP_INCLUDED
#define GDIOBJECT_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class GdiObject : public Object {
	protected:
		HGDIOBJ handle;

	public:
		GdiObject();
		~GdiObject();

		HGDIOBJ getHandle();
		virtual void refresh() = 0;
		virtual void trash();
	};

};

#endif
