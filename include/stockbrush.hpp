/*
 * stockbrush.hpp
 *
 * Last modified: <2013/04/17 12:37:24 +0900> By Zumida
 */
#ifndef STOCKBRUSH_HPP_INCLUDED
#define STOCKBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class StockBrush : public Brush {
	protected:
		int stock;

	public:
		StockBrush();
		StockBrush(const int stock);
		~StockBrush();

		Brush& set(const int stock);
		HGDIOBJ getHandle(void);
		void trash(void);
	};

};

#endif
