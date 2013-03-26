/*
 * menu.hpp
 *
 * Last modified: <2013/03/26 17:37:32 +0900> By Zumida
 */
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "object.hpp"

namespace swo {

	class MenuItem : public Object {
	private:
		MENUITEMINFO mii;

	public:
		MenuItem();
		virtual ~MenuItem();

		

		MENUITEMINFO& getInfo(void) const;
	};

	class Menu : public Object {
	private:
		HMENU handle;

	public:
		Menu();
		virtual ~Menu();

		HMENU getHandle(void) const;
		void add(MenuItem& item);
	};

};

#endif
