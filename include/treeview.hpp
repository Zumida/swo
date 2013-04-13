/*
 * treeview.hpp
 *
 * Last modified: <2013/04/13 21:12:05 +0900> By Zumida
 */
#ifndef TREEVIEW_HPP_INCLUDED
#define TREEVIEW_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class TreeView : public Control {
	private:
		bool vscroll;
		bool hscroll;

	protected:
		HWND createHandle(void);

	public:
		TreeView();
		~TreeView();
	};

};

#endif
