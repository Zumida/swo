/*
 * stockpen.cpp
 *
 * Last modified: <2014/01/30 16:41:06 +0900> By Zumida
 */
#include "swoconfig.hpp"
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

void StockPen::refresh() {
	handle = ::GetStockObject(stock);
}
