#pragma once

#include "base.hpp"

#include "grcViewport.hpp"

namespace rdr2
{
	class CameraViewport
	{
	public:
		void SetCameraMatrix(rage::Matrix34 *param_1);
		grcViewport *GetViewport();
	};
}