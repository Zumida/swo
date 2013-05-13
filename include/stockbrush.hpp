/*
 * stockbrush.hpp
 *
 * Last modified: <2013/05/13 18:08:52 +0900> By Zumida
 */
#ifndef STOCKBRUSH_HPP_INCLUDED
#define STOCKBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class StockBrush : public Brush {
	protected:
		int stock;

		void refresh(void);

	public:
		StockBrush();
		StockBrush(const int stock);
		~StockBrush();

		Brush& set(const int stock);
		void trash(void);
	};

};

#endif
