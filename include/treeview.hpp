/*
 * treeview.hpp
 *
 * Last modified: <2014/01/30 16:41:22 +0900> By Zumida
 */
#ifndef TREEVIEW_HPP_INCLUDED
#define TREEVIEW_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class TreeView : public Control {
	protected:
		bool vscroll;
		bool hscroll;
		HWND createHandle();

	public:
		TreeView();
		~TreeView();
	};

};

#endif
