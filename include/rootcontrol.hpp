/*
 * rootcontrol.hpp
 *
 * Last modified: <2013/03/21 09:39:10 +0900> By Zumida
 */
#ifndef ROOTCONTROL_HPP_INCLUDED
#define ROOTCONTROL_HPP_INCLUDED

#include "control.hpp"

namespace swo {

	class RootControl : public Control {
	private:
		HWND root;

		RootControl();

	protected:
		HWND createHandle(void);

	public:
		RootControl(HWND root);
	};

};

#endif
