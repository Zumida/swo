/*
 * stockpen.hpp
 *
 * Last modified: <2014/01/30 16:41:08 +0900> By Zumida
 */
#ifndef STOCKPEN_HPP_INCLUDED
#define STOCKPEN_HPP_INCLUDED

#include "pen.hpp"

namespace swo {

	class StockPen : public Pen {
	protected:
		int stock;

		void refresh();

	public:
		StockPen();
		StockPen(const int stock);
		~StockPen();

		Pen& set(const int stock);
	};

};

#endif
