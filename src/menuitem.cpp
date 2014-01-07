/*
 * menuitem.cpp
 *
 * Last modified: <2014/01/07 18:03:03 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "menuitem.hpp"

using namespace swo;

MenuItem::MenuItem() {
	MENUITEMINFO d = {sizeof(MENUITEMINFO)};
	mii = d;

	subMenu = &Menu::empty;
	checkedImage = &Bitmap::empty;
	uncheckedImage = &Bitmap::empty;
	image = &Bitmap::empty;
	text = empty;
}

MenuItem::~MenuItem() {
}

void MenuItem::setType(const MenuItem::Type type) {
	mii.fType &=
		~(MFT_MENUBARBREAK|MFT_MENUBREAK|MFT_RADIOCHECK|MFT_SEPARATOR);

	switch (type) {
	case Type::MenuBarBreak:
		mii.fType |= MFT_MENUBARBREAK;
		break;
	case Type::MenuBreak:
		mii.fType |= MFT_MENUBREAK;
		break;
	case Type::RadioCheck:
		mii.fType |= MFT_RADIOCHECK;
		break;
	case Type::Separator:
		mii.fType |= MFT_SEPARATOR;
		break;
	default:
		break;
	}
}

MenuItem::Type MenuItem::getType(void) const {
	MenuItem::Type type;

	if (mii.fType & MFT_MENUBARBREAK)    type = Type::MenuBarBreak;
	else if (mii.fType & MFT_MENUBREAK)  type = Type::MenuBreak;
	else if (mii.fType & MFT_RADIOCHECK) type = Type::RadioCheck;
	else if (mii.fType & MFT_SEPARATOR)  type = Type::Separator;
	else                                 type = Type::Normal;

	return type;
}

void MenuItem::setAlign(const MenuItemAlign align) {
	if (align == Right)
		mii.fType |= MFT_RIGHTJUSTIFY;
	else
		mii.fType &= ~MFT_RIGHTJUSTIFY;
}

MenuItemAlign MenuItem::getAlign(void) const {
	return (mii.fType & MFT_RIGHTJUSTIFY)? Right: Left;
}

void MenuItem::setState(const MenuItemState& state) {
	mii.fState &= ~(MFS_CHECKED|MFS_DEFAULT|MFS_DISABLED|MFS_HILITE);

	if (state.isChecked  ) mii.fState |= MFS_CHECKED;
	if (state.isDefault  ) mii.fState |= MFS_DEFAULT;
	if (state.isDisabled ) mii.fState |= MFS_DISABLED;
	if (state.isHighLight) mii.fState |= MFS_HILITE;
}

MenuItemState MenuItem::getState(void) const {
	MenuItemState state;

	state.isChecked   = (mii.fState & MFS_CHECKED )? true: false;
	state.isDefault   = (mii.fState & MFS_DEFAULT )? true: false;
	state.isDisabled  = (mii.fState & MFS_DISABLED)? true: false;
	state.isHighLight = (mii.fState & MFS_HILITE  )? true: false;

	return state;
}

void MenuItem::setId(const int id) {
	mii.wID = id;
	if (id != 0)
		mii.fMask |=  MIIM_ID;
	else
		mii.fMask &= ~MIIM_ID;
}

int MenuItem::getId(void) const {
	return mii.wID;
}

void MenuItem::setSubMenu(const class Menu& subMenu) {
	this->subMenu = &subMenu;
	mii.hSubMenu = subMenu.getHandle();
	if (mii.hSubMenu != nullptr)
		mii.fMask |=  MIIM_SUBMENU;
	else
		mii.fMask &= ~MIIM_SUBMENU;
}

Menu& MenuItem::getSubMenu(void) const {
	return *const_cast<Menu*>(subMenu);
}

void MenuItem::setCheckedImage(const Bitmap& bmp) {
	this->checkedImage = &bmp;
	mii.hbmpChecked = bmp.getHandle();
	if (mii.hbmpChecked != nullptr && mii.hbmpUnchecked != nullptr)
		mii.fMask |=  MIIM_CHECKMARKS;
	else
		mii.fMask &= ~MIIM_CHECKMARKS;
}

Bitmap& MenuItem::getCheckedImage(const Bitmap& bmp) const {
	return *const_cast<Bitmap*>(checkedImage);
}

void MenuItem::setUncheckedImage(const Bitmap& bmp) {
	this->uncheckedImage = &bmp;
	mii.hbmpUnchecked = bmp.getHandle();
	if (mii.hbmpChecked != nullptr && mii.hbmpUnchecked != nullptr)
		mii.fMask |=  MIIM_CHECKMARKS;
	else
		mii.fMask &= ~MIIM_CHECKMARKS;
}

Bitmap& MenuItem::getUncheckedImage(const Bitmap& bmp) const {
	return *const_cast<Bitmap*>(uncheckedImage);
}

void MenuItem::setData(const int data) {
	mii.dwItemData = data;
	mii.fMask |= MIIM_DATA;
}

int MenuItem::getData(void) const {
	return mii.dwItemData;
}

void MenuItem::setText(const String& text) {
	this->text = text;
	if (!this->text.empty()) {
		mii.dwTypeData = (LPWSTR)this->text.c_str();
		mii.fMask |=  MIIM_STRING;
	} else {
		mii.dwTypeData = nullptr;
		mii.fMask &= ~MIIM_STRING;
	}
}

const String& MenuItem::getText(void) const {
	return text;
}

void MenuItem::setImage(const Bitmap& bmp) {
#if (_WIN32_WINNT >= 0x0500)
	image = &bmp;
	mii.hbmpItem = bmp.getHandle();
	if (mii.hbmpItem != nullptr)
		mii.fMask |=  MIIM_BITMAP;
	else
		mii.fMask &= ~MIIM_BITMAP;
#endif
}

Bitmap& MenuItem::getImage(void) const {
	return *const_cast<Bitmap*>(image);
}

const MENUITEMINFO& MenuItem::getInfo(void) const {
	return mii;
}
