/*
 * stockbrush.hpp
 *
 * Last modified: <2013/04/02 06:59:48 +0900> By Zumida
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
		virtual void trash(void);
	};

};

#endif
