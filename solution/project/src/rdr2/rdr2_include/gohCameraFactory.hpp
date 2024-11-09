#pragma once

#include "base.hpp"

#include "gohCamera.hpp"

namespace rdr2
{
	class gohCameraFactory
	{
	public:
		gohCamera *const GetCamera(const int cam_type)
		{
			return sigs::gohCameraFactory_GetCamera.call<gohCamera *>(this, cam_type);
		}
	};
}