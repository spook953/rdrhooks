#pragma once

#include "base.hpp"

#include "eTransitionType.hpp"

namespace rdr2
{
	class camCameraTransitionFactory
	{
	public:
		static void ReleaseTransition(camCameraTransitionBase **param_1, int a2 /* 2 args? */)
		{
			sigs::camCameraTransitionFactory_ReleaseTransition.call<void>(param_1, a2);
		}

		static void *GetTransition(eTransitionType param_1)
		{
			return sigs::camCameraTransitionFactory_GetTransition.call<void *>(param_1);
		}
	};
}