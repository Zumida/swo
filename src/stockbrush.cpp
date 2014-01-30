/*
 * stockbrush.cpp
 *
 * Last modified: <2014/01/30 16:41:01 +0900> By Zumida
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

void StockBrush::refresh() {
	handle = ::GetStockObject(stock);
}

void StockBrush::trash() {
	handle = nullptr;
}
