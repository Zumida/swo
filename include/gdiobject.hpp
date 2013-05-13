/*
 * gdiobject.hpp
 *
 * Last modified: <2013/05/13 18:00:15 +0900> By Zumida
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

		HGDIOBJ getHandle(void);
		virtual void refresh(void) = 0;
		virtual void trash(void);
	};

};

#endif
