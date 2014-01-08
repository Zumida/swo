/*
 * gdiobject.hpp
 *
 * Last modified: <2014/01/08 09:50:01 +0900> By Zumida
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
