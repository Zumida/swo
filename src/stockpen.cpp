/*
 * stockpen.cpp
 *
 * Last modified: <2013/05/13 18:20:47 +0900> By Zumida
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

void StockPen::refresh(void) {
	handle = ::GetStockObject(stock);
}
