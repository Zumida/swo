/*
 * stockpen.hpp
 *
 * Last modified: <2013/05/13 18:09:17 +0900> By Zumida
 */
#ifndef STOCKPEN_HPP_INCLUDED
#define STOCKPEN_HPP_INCLUDED

#include "pen.hpp"

namespace swo {

	class StockPen : public Pen {
	protected:
		int stock;

		void refresh(void);

	public:
		StockPen();
		StockPen(const int stock);
		~StockPen();

		Pen& set(const int stock);
	};

};

#endif
