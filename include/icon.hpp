/*
 * icon.hpp
 *
 * Last modified: <2013/04/12 22:06:46 +0900> By Zumida
 */
#ifndef ICON_HPP_INCLUDED
#define ICON_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Icon : public Image {
	private:

	public:
		Icon();
		Icon(const String& name);
		~Icon();

		Icon& set(const String& name);
		HICON getHandle(void) const;
	};

};

#endif
