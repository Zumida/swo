/*
 * stockpen.hpp
 *
 * Last modified: <2013/04/02 18:12:09 +0900> By Zumida
 */
#ifndef STOCKPEN_HPP_INCLUDED
#define STOCKPEN_HPP_INCLUDED

#include "pen.hpp"

namespace swo {

	class StockPen : public Pen {
	protected:
		int stock;

	public:
		StockPen(int stock);
		virtual ~StockPen();

		virtual HGDIOBJ getHandle(void);
	};

};

#endif
