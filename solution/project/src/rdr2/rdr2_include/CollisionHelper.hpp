#pragma once

#include "base.hpp"

#include "CameraViewport.hpp"

namespace rdr2
{
	class CollisionHelper
	{
	public:
		bool PerformCollision(float param_1, CameraViewport *param_2, CameraViewport *param_3, CameraViewport *param_4)
		{
			return sigs::CollisionHelper_PerformCollision.call<bool>(this, param_1, param_2, param_3, param_4);
		}
	};
}