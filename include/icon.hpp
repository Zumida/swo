/*
 * icon.hpp
 *
 * Last modified: <2013/03/25 18:15:15 +0900> By Zumida
 */
#ifndef ICON_HPP_INCLUDED
#define ICON_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class Icon : public Object {
	private:
		HICON handle;

	public:
		Icon();
		Icon(String iconName);
		Icon(const Icon& icon);
		virtual ~Icon();

		HICON getHandle(void) const;
	};

};

#endif
