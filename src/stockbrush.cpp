/*
 * stockbrush.cpp
 *
 * Last modified: <2013/04/13 21:08:30 +0900> By Zumida
 */
#include "stockbrush.hpp"

using namespace swo;

StockBrush::StockBrush() {
	this->stock = 0;
}

StockBrush::StockBrush(int stock) {
	this->stock = stock;
}

StockBrush::~StockBrush() {
}

Brush& StockBrush::set(int stock) {
	this->stock = stock;
	return *this;
}

HGDIOBJ StockBrush::getHandle(void) {
	if (handle == NULL) handle = ::GetStockObject(stock);
	return handle;
}

void StockBrush::trash(void) {
	handle = NULL;
}
