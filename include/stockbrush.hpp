/*
 * stockbrush.hpp
 *
 * Last modified: <2013/04/02 09:36:52 +0900> By Zumida
 */
#ifndef STOCKBRUSH_HPP_INCLUDED
#define STOCKBRUSH_HPP_INCLUDED

#include "brush.hpp"

namespace swo {

	class StockBrush : public Brush {
	protected:
		int stock;

	public:
		StockBrush(int stock);

		virtual void select(void);
	};

};

#endif
