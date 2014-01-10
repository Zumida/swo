/*
 * menuitem.hpp
 *
 * Last modified: <2014/01/10 16:29:44 +0900> By Zumida
 */
#ifndef MENUITEM_HPP_INCLUDED
#define MENUITEM_HPP_INCLUDED

#include "object.hpp"
#include "menu.hpp"
#include "bitmap.hpp"

namespace swo {
	inline namespace menu {

		class MenuItem : public Object {
		public:
			using Info = MENUITEMINFO;

			enum class Type {
				Normal,
				MenuBarBreak,
				MenuBreak,
				RadioCheck,
				Separator,
			};

			enum class Align {
				Left,
				Right,
			};

			struct State {
				bool isChecked;
				bool isDefault;
				bool isDisabled;
				bool isHighLight;
			};

		protected:
			Info info;
			const class Menu *subMenu;
			const Bitmap *checkedImage;
			const Bitmap *uncheckedImage;
			const Bitmap *image;
			String text;

		public:
			MenuItem();
			~MenuItem();

			MenuItem& setType(const Type type);
			Type getType(void) const;

			MenuItem& setAlign(const Align align);
			Align getAlign(void) const;

			MenuItem& setState(const State& state);
			State getState(void) const;

			MenuItem& setId(const int id);
			int getId(void) const;

			MenuItem& setSubMenu(const class Menu& subMenu);
			class Menu& getSubMenu(void) const;

			MenuItem& setCheckedImage(const Bitmap& bmp);
			Bitmap& getCheckedImage(const Bitmap& bmp) const;

			MenuItem& setUncheckedImage(const Bitmap& bmp);
			Bitmap& getUncheckedImage(const Bitmap& bmp) const;

			MenuItem& setData(const int data);
			int getData(void) const;

			MenuItem& setText(const String& text);
			const String& getText(void) const;

			MenuItem& setImage(const Bitmap& bmp);
			Bitmap& getImage(void) const;

			const Info& getInfo(void) const;
		};
	};
};
#endif
