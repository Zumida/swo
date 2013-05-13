/*
 * syscolorbrush.cpp
 *
 * Last modified: <2013/05/13 18:21:10 +0900> By Zumida
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

void SysColorBrush::refresh(void) {
	handle = ::GetSysColorBrush(index);
}

void SysColorBrush::trash(void) {
	handle = NULL;
}
