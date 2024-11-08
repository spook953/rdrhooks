#pragma once

#include "base.hpp"

#include "gohCamera.hpp"

namespace rdr2
{
	class gohCameraFactory
	{
	public:
		gohCamera *const GetCamera(const int cam_type);
	};
}