/*
 * icon.hpp
 *
 * Last modified: <2013/05/06 16:02:12 +0900> By Zumida
 */
#ifndef ICON_HPP_INCLUDED
#define ICON_HPP_INCLUDED

#include "image.hpp"

namespace swo {

	class Icon : public Image {
	public:
		Icon();
		Icon(const String& name);
		~Icon();

		Icon& set(const String& name);
		HICON getHandle(void) const;

		const static class Icon appStarting;
		const static class Icon arrow;
		const static class Icon cross;
		const static class Icon hand;
		const static class Icon help;
		const static class Icon ibeam;
		const static class Icon no;
		const static class Icon sizeAll;
		const static class Icon sizeNESW;
		const static class Icon sizeNS;
		const static class Icon sizeNWSE;
		const static class Icon sizeWE;
		const static class Icon uparrow;
		const static class Icon wait;
	};

};

#endif
