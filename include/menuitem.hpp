/*
 * menuitem.hpp
 *
 * Last modified: <2014/01/30 16:40:35 +0900> By Zumida
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
			Type getType() const;

			MenuItem& setAlign(const Align align);
			Align getAlign() const;

			MenuItem& setState(const State& state);
			State getState() const;

			MenuItem& setId(const int id);
			int getId() const;

			MenuItem& setSubMenu(const class Menu& subMenu);
			class Menu& getSubMenu() const;

			MenuItem& setCheckedImage(const Bitmap& bmp);
			Bitmap& getCheckedImage(const Bitmap& bmp) const;

			MenuItem& setUncheckedImage(const Bitmap& bmp);
			Bitmap& getUncheckedImage(const Bitmap& bmp) const;

			MenuItem& setData(const int data);
			int getData() const;

			MenuItem& setText(const String& text);
			const String& getText() const;

			MenuItem& setImage(const Bitmap& bmp);
			Bitmap& getImage() const;

			const Info& getInfo() const;
		};
	};
};
#endif
