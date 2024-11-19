#pragma once

#include "base.hpp"

#include "gohCamera.hpp"

namespace rdr2
{
	class gohCameraFactory
	{
	public:
		gohCameraFactory *GetCamera(eCameraType cam_type)
		{
			return sigs::gohCameraFactory_GetCamera.call<gohCameraFactory *>(this, cam_type);
		}
	};
}