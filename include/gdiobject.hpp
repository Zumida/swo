/*
 * gdiobject.hpp
 *
 * Last modified: <2013/04/02 19:08:59 +0900> By Zumida
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
		virtual ~GdiObject();

		virtual HGDIOBJ getHandle(void) = 0;
		virtual void trash(void);
	};

};

#endif
