/*
 * runner.hpp
 *
 * Last modified: <2014/01/10 14:21:19 +0900> By Zumida
 */
#ifndef RUNNER_HPP_INCLUDED
#define RUNNER_HPP_INCLUDED

#include "object.hpp"

namespace swo {
	inline namespace core {
		class Runner : public Object {
		public:
			virtual void run() = 0;
		};
	};
};

#endif
