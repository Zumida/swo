/*
 * syscolorbrush.cpp
 *
 * Last modified: <2013/08/28 01:42:23 +0900> By Zumida
 */
#include "syscolorbrush.hpp"
#include "instance.hpp"

using namespace swo;

SysColorBrush::SysColorBrush() {
	index = 0;
}

SysColorBrush::~SysColorBrush() {
}

SysColorBrush& SysColorBrush::set(const int index) {
	this->index = index;
	return *this;
}

int SysColorBrush::getIndex(void) const {
	return index;
}

void SysColorBrush::refresh(void) {
	handle = ::GetSysColorBrush(index);
}

void SysColorBrush::trash(void) {
	handle = NULL;
}

SysColorBrush& SysColorBrush::create(const int index) {
	return Instance::create<SysColorBrush>().set(index);
}
