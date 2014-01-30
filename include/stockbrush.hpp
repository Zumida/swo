/*
 * stockbrush.hpp
 *
 * Last modified: <2014/01/30 16:41:04 +0900> By Zumida
 */
#ifndef STOCKBRUSH_HPP_INCLUDED
#define STOCKBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class StockBrush : public Brush {
	protected:
		int stock;

		void refresh();

	public:
		StockBrush();
		StockBrush(const int stock);
		~StockBrush();

		Brush& set(const int stock);
		void trash();
	};

};

#endif
