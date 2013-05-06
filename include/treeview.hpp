/*
 * treeview.hpp
 *
 * Last modified: <2013/05/07 07:16:34 +0900> By Zumida
 */
#ifndef TREEVIEW_HPP_INCLUDED
#define TREEVIEW_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class TreeView : public Control {
	protected:
		bool vscroll;
		bool hscroll;
		HWND createHandle(void);

	public:
		TreeView();
		~TreeView();
	};

};

#endif
