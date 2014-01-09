/*
 * runner.cpp
 *
 * Last modified: <2014/01/10 02:31:38 +0900> By Zumida
 */
#include "application.hpp"
#include "runner.hpp"

namespace swo {
	inline namespace core {

		Runner::Runner() {
			Application::setRunner(this);
		}
	};
};
