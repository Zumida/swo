/*
 * stockbrush.cpp
 *
 * Last modified: <2013/04/02 09:47:43 +0900> By Zumida
 */

#include "stockbrush.hpp"

using namespace swo;

StockBrush::StockBrush(int stock) {
	this->stock = stock;
}

void StockBrush::select(void) {
	handle = (HBRUSH)::GetStockObject(stock);
}
