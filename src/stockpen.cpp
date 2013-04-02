/*
 * stockpen.cpp
 *
 * Last modified: <2013/04/02 18:12:51 +0900> By Zumida
 */

#include "stockpen.hpp"

using namespace swo;

StockPen::StockPen(int stock) {
	this->stock = stock;
}

StockPen::~StockPen() {
}

HGDIOBJ StockPen::getHandle(void) {
	if (handle == NULL) handle = ::GetStockObject(stock);
	return handle;
}
