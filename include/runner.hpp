/*
 * runner.hpp
 *
 * Last modified: <2014/01/09 18:34:58 +0900> By Zumida
 */
#ifndef RUNNER_HPP_INCLUDED
#define RUNNER_HPP_INCLUDED

#include "object.hpp"

namespace swo {
	inline namespace core {
		struct Runner : public Object {
			virtual void run() = 0;
		};
	};
};

#endif
