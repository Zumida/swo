/*
 * stockbrush.cpp
 *
 * Last modified: <2013/05/13 18:20:28 +0900> By Zumida
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

void StockBrush::refresh(void) {
	handle = ::GetStockObject(stock);
}

void StockBrush::trash(void) {
	handle = NULL;
}
