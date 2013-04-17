/*
 * syscolorbrush.cpp
 *
 * Last modified: <2013/04/17 13:52:39 +0900> By Zumida
 */
#include "syscolorbrush.hpp"

using namespace swo;

SysColorBrush::SysColorBrush() {
	index = 0;
}

SysColorBrush::SysColorBrush(const int index) {
	this->index = index;
}

SysColorBrush::~SysColorBrush() {
}

Brush& SysColorBrush::set(const int index) {
	this->index = index;
	return *this;
}

HGDIOBJ SysColorBrush::getHandle(void) {
	if (handle == NULL) handle = ::GetSysColorBrush(index);
	return handle;
}

void SysColorBrush::trash(void) {
	handle = NULL;
}
