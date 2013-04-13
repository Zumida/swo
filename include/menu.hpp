/*
 * menu.hpp
 *
 * Last modified: <2013/04/12 22:23:35 +0900> By Zumida
 */
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "object.hpp"
#include "menuitem.hpp"

namespace swo {

	class Menu : public Object {
	private:
		HMENU handle;

	public:
		Menu();
		~Menu();

		HMENU getHandle(void) const;
		void add(const class MenuItem& item);
		void add(const int index, const class MenuItem& item);

		const static class Menu empty;
	};

};

#endif
