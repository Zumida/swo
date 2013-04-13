/*
 * stockpen.hpp
 *
 * Last modified: <2013/04/12 22:39:46 +0900> By Zumida
 */
#ifndef STOCKPEN_HPP_INCLUDED
#define STOCKPEN_HPP_INCLUDED

#include "pen.hpp"

namespace swo {

	class StockPen : public Pen {
	protected:
		int stock;

	public:
		StockPen();
		StockPen(const int stock);
		~StockPen();

		Pen& set(const int stock);
		HGDIOBJ getHandle(void);
	};

};

#endif
