/*
 * pointer.hpp
 *
 * Last modified: <2013/05/07 12:24:25 +0900> By Zumida
 */
#ifndef POINTER_HPP_INCLUDED
#define POINTER_HPP_INCLUDED

namespace swo {
	template <class T>
	inline T pointer_cast(void* p) {
		return static_cast<T>(p);
	}
};

#endif
