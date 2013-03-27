/*
 * icon.hpp
 *
 * Last modified: <2013/03/27 15:19:43 +0900> By Zumida
 */
#ifndef ICON_HPP_INCLUDED
#define ICON_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Icon : public Image {
	private:

	public:
		Icon();
		Icon(const String& iconName);
		virtual ~Icon();

		HICON getHandle(void) const;
	};

};

#endif
