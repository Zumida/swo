/*
 * menuitem.cpp
 *
 * Last modified: <2014/01/30 16:40:32 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "menuitem.hpp"

namespace swo {
	inline namespace menu {

		MenuItem::MenuItem()
		: info{sizeof(Info)}, subMenu(&Menu::empty),
		checkedImage(&Bitmap::empty), uncheckedImage(&Bitmap::empty),
		image(&Bitmap::empty), text(empty) {}

		MenuItem::~MenuItem() {}

		MenuItem& MenuItem::setType(const MenuItem::Type type) {
			info.fType &= ~(MFT_MENUBARBREAK
							| MFT_MENUBREAK
							| MFT_RADIOCHECK
							| MFT_SEPARATOR);

			switch (type) {
			case Type::MenuBarBreak:
				info.fType |= MFT_MENUBARBREAK;
				break;
			case Type::MenuBreak:
				info.fType |= MFT_MENUBREAK;
				break;
			case Type::RadioCheck:
				info.fType |= MFT_RADIOCHECK;
				break;
			case Type::Separator:
				info.fType |= MFT_SEPARATOR;
				break;
			default:
				break;
			}

			return *this;
		}

		MenuItem::Type MenuItem::getType() const {
			MenuItem::Type type;

			if (info.fType & MFT_MENUBARBREAK)    type = Type::MenuBarBreak;
			else if (info.fType & MFT_MENUBREAK)  type = Type::MenuBreak;
			else if (info.fType & MFT_RADIOCHECK) type = Type::RadioCheck;
			else if (info.fType & MFT_SEPARATOR)  type = Type::Separator;
			else                                  type = Type::Normal;

			return type;
		}

		MenuItem& MenuItem::setAlign(const MenuItem::Align align) {
			if (align == Align::Right)
				info.fType |= MFT_RIGHTJUSTIFY;
			else
				info.fType &= ~MFT_RIGHTJUSTIFY;
			return *this;
		}

		MenuItem::Align MenuItem::getAlign() const {
			return (info.fType & MFT_RIGHTJUSTIFY)?
				Align::Right: Align::Left;
		}

		MenuItem& MenuItem::setState(const MenuItem::State& state) {
			info.fState &= ~(MFS_CHECKED|MFS_DEFAULT|MFS_DISABLED|MFS_HILITE);

			if (state.isChecked  ) info.fState |= MFS_CHECKED;
			if (state.isDefault  ) info.fState |= MFS_DEFAULT;
			if (state.isDisabled ) info.fState |= MFS_DISABLED;
			if (state.isHighLight) info.fState |= MFS_HILITE;

			return *this;
		}

		MenuItem::State MenuItem::getState() const {
			MenuItem::State state;

			state.isChecked   = (info.fState & MFS_CHECKED )? true: false;
			state.isDefault   = (info.fState & MFS_DEFAULT )? true: false;
			state.isDisabled  = (info.fState & MFS_DISABLED)? true: false;
			state.isHighLight = (info.fState & MFS_HILITE  )? true: false;

			return state;
		}

		MenuItem& MenuItem::setId(const int id) {
			info.wID = id;
			if (id != 0)
				info.fMask |=  MIIM_ID;
			else
				info.fMask &= ~MIIM_ID;
			return *this;
		}

		int MenuItem::getId() const {
			return info.wID;
		}

		MenuItem& MenuItem::setSubMenu(const class Menu& subMenu) {
			this->subMenu = &subMenu;
			info.hSubMenu = subMenu.getHandle();
			if (info.hSubMenu != nullptr)
				info.fMask |=  MIIM_SUBMENU;
			else
				info.fMask &= ~MIIM_SUBMENU;
			return *this;
		}

		Menu& MenuItem::getSubMenu() const {
			return *const_cast<Menu*>(subMenu);
		}

		MenuItem& MenuItem::setCheckedImage(const Bitmap& bmp) {
			this->checkedImage = &bmp;
			info.hbmpChecked = bmp.getHandle();
			if (info.hbmpChecked != nullptr && info.hbmpUnchecked != nullptr)
				info.fMask |=  MIIM_CHECKMARKS;
			else
				info.fMask &= ~MIIM_CHECKMARKS;
			return *this;
		}

		Bitmap& MenuItem::getCheckedImage(const Bitmap& bmp) const {
			return *const_cast<Bitmap*>(checkedImage);
		}

		MenuItem& MenuItem::setUncheckedImage(const Bitmap& bmp) {
			this->uncheckedImage = &bmp;
			info.hbmpUnchecked = bmp.getHandle();
			if (info.hbmpChecked != nullptr && info.hbmpUnchecked != nullptr)
				info.fMask |=  MIIM_CHECKMARKS;
			else
				info.fMask &= ~MIIM_CHECKMARKS;
			return *this;
		}

		Bitmap& MenuItem::getUncheckedImage(const Bitmap& bmp) const {
			return *const_cast<Bitmap*>(uncheckedImage);
		}

		MenuItem& MenuItem::setData(const int data) {
			info.dwItemData = data;
			info.fMask |= MIIM_DATA;
			return *this;
		}

		int MenuItem::getData() const {
			return info.dwItemData;
		}

		MenuItem& MenuItem::setText(const String& text) {
			this->text = text;
			if (this->text.empty()) {
				info.dwTypeData = nullptr;
				info.fMask &= ~MIIM_STRING;
			} else {
				info.dwTypeData = (LPWSTR)this->text.c_str();
				info.fMask |=  MIIM_STRING;
			}
			return *this;
		}

		const String& MenuItem::getText() const {
			return text;
		}

		MenuItem& MenuItem::setImage(const Bitmap& bmp) {
#if (_WIN32_WINNT >= 0x0500)
			image = &bmp;
			info.hbmpItem = bmp.getHandle();
			if (info.hbmpItem == nullptr)
				info.fMask &= ~MIIM_BITMAP;
			else
				info.fMask |=  MIIM_BITMAP;
#endif
			return *this;
		}

		Bitmap& MenuItem::getImage() const {
			return *const_cast<Bitmap*>(image);
		}

		const MenuItem::Info& MenuItem::getInfo() const {
			return info;
		}
	};
};
