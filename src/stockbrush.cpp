/*
 * stockbrush.cpp
 *
 * Last modified: <2014/01/07 14:26:46 +0900> By Zumida
 */
#include "swoconfig.hpp"
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
	handle = nullptr;
}
