#pragma once

#include "base.hpp"

#include "camCamera.hpp"
#include "camCameraChannel.hpp"
#include "CameraViewport.hpp"
#include "gohCameraFactory.hpp"

namespace rdr2
{
	class camManager
	{
	public:
		camCamera *GetCamera();
		camCameraChannel *GetCameraChannel();
		CameraViewport *GetCameraViewport();
		gohCameraFactory *GetCameraFactory();
	};
}