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
		camCamera *GetCamera()
		{
			return *reinterpret_cast<camCamera **>(reinterpret_cast<uintptr_t>(this) + 0x38);
		}

		camCameraChannel *GetCameraChannel()
		{
			return *reinterpret_cast<camCameraChannel **>(reinterpret_cast<uintptr_t>(this) + 0x8);
		}

		CameraViewport *GetCameraViewport()
		{
			return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x38); //same as GetCamera?
		}

		gohCameraFactory *GetCameraFactory()
		{
			return *reinterpret_cast<gohCameraFactory **>(reinterpret_cast<uintptr_t>(this) + 0x50);
		}
	};
}