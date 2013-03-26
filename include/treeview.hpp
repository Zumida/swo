/*
 * treeview.hpp
 *
 * Last modified: <2013/03/21 09:39:56 +0900> By Zumida
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
		virtual ~TreeView();
	};

};

#endif
