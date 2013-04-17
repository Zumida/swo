/*
 * treeview.hpp
 *
 * Last modified: <2013/04/17 12:36:30 +0900> By Zumida
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
