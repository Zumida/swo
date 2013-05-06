/*
 * menuitem.hpp
 *
 * Last modified: <2013/05/06 22:17:23 +0900> By Zumida
 */
#ifndef MENUITEM_HPP_INCLUDED
#define MENUITEM_HPP_INCLUDED

#include "object.hpp"
#include "menu.hpp"
#include "bitmap.hpp"

namespace swo {

	enum MenuItemType {
		Normal,
		MenuBarBreak,
		MenuBreak,
		RadioCheck,
		Separator,
	};

	enum MenuItemAlign {
		Left,
		Right,
	};

	struct MenuItemState {
		bool isChecked;
		bool isDefault;
		bool isDisabled;
		bool isHighLight;
	};

	class MenuItem : public Object {
	protected:
		MENUITEMINFO mii;
		const class Menu *subMenu;
		const Bitmap *checkedImage;
		const Bitmap *uncheckedImage;
		const Bitmap *image;
		String text;

	public:
		MenuItem();
		~MenuItem();

		void setType(const MenuItemType type);
		MenuItemType getType(void) const;

		void setAlign(const MenuItemAlign align);
		MenuItemAlign getAlign(void) const;

		void setState(const MenuItemState& state);
		MenuItemState getState(void) const;

		void setId(const int id);
		int getId(void) const;

		void setSubMenu(const class Menu& subMenu);
		class Menu& getSubMenu(void) const;

		void setCheckedImage(const Bitmap& bmp);
		Bitmap& getCheckedImage(const Bitmap& bmp) const;

		void setUncheckedImage(const Bitmap& bmp);
		Bitmap& getUncheckedImage(const Bitmap& bmp) const;

		void setData(const int data);
		int getData(void) const;

		void setText(const String& text);
		const String& getText(void) const;

		void setImage(const Bitmap& bmp);
		Bitmap& getImage(void) const;

		const MENUITEMINFO& getInfo(void) const;
	};

};
#endif
