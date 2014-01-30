/*
 * syscolorbrush.cpp
 *
 * Last modified: <2014/01/30 16:41:13 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

int SysColorBrush::getIndex() const {
	return index;
}

void SysColorBrush::refresh() {
	handle = ::GetSysColorBrush(index);
}

void SysColorBrush::trash() {
	handle = nullptr;
}

SysColorBrush& SysColorBrush::create(const int index) {
	return Instance::create<SysColorBrush>().set(index);
}
