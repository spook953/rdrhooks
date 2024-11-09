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
		rdr2::camCamera *GetCamera()
		{
			return *reinterpret_cast<camCamera **>(reinterpret_cast<uintptr_t>(this) + 0x38);
		}

		rdr2::camCameraChannel *GetCameraChannel()
		{
			return *reinterpret_cast<camCameraChannel **>(reinterpret_cast<uintptr_t>(this) + 0x8);
		}

		rdr2::CameraViewport *GetCameraViewport()
		{
			return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x38); //same as GetCamera?
		}

		rdr2::gohCameraFactory *GetCameraFactory()
		{
			return *reinterpret_cast<gohCameraFactory **>(reinterpret_cast<uintptr_t>(this) + 0x50);
		}
	};
}