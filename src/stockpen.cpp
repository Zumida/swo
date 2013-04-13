/*
 * stockpen.cpp
 *
 * Last modified: <2013/04/13 21:10:07 +0900> By Zumida
 */
#include "stockpen.hpp"

using namespace swo;

StockPen::StockPen() {
	this->stock = 0;
}

StockPen::StockPen(int stock) {
	this->stock = stock;
}

StockPen::~StockPen() {
}

Pen& StockPen::set(int stock) {
	this->stock = stock;
	return *this;
}

HGDIOBJ StockPen::getHandle(void) {
	if (handle == NULL) handle = ::GetStockObject(stock);
	return handle;
}
