#pragma once

#include "base.hpp"

namespace rdr2
{
	class camCameraTransitionBase
	{
	public:
		bool ComputeCollision(CameraViewport *param_1, CameraViewport *param_2, CameraViewport *param_3)
		{
			return sigs::camCameraTransitionBase_ComputeCollision.call<bool>(this, param_1, param_2, param_3);
		}

		void Start()
		{
			sigs::camCameraTransitionBase_Start.call<void>(this);
		}
	};
}