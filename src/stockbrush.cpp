/*
 * stockbrush.cpp
 *
 * Last modified: <2013/04/02 18:16:23 +0900> By Zumida
 */

#include "stockbrush.hpp"

using namespace swo;

StockBrush::StockBrush(int stock) {
	this->stock = stock;
}

StockBrush::~StockBrush() {
}

HGDIOBJ StockBrush::getHandle(void) {
	if (handle == NULL) handle = ::GetStockObject(stock);
	return handle;
}
