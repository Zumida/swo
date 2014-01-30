/*
 * menu.hpp
 *
 * Last modified: <2014/01/30 16:40:29 +0900> By Zumida
 */
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "object.hpp"
#include "menuitem.hpp"

namespace swo {
	inline namespace menu {

		class Menu : public Object {
		public:
			using Handle = HMENU;

		protected:
			Handle handle;

		public:
			Menu();
			~Menu();

			Handle getHandle() const;
			Menu& add(const class MenuItem& item);
			Menu& add(const int index, const class MenuItem& item);

			const static class Menu empty;
		};
	};
};

#endif
