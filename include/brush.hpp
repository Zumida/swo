/*
 * brush.hpp
 *
 * Last modified: <2013/04/02 07:06:53 +0900> By Zumida
 */
#ifndef BRUSH_HPP_INCLUDED
#define BRUSH_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class Brush : public Object {
	protected:
		HBRUSH handle;

	public:
		Brush();
		virtual ~Brush();

		virtual void select(void);
		virtual void trash(void);

		HBRUSH getHandle(void) const;
	};

};

#endif
