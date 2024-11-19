#pragma once

#include "base.hpp"

#include "camCamera.hpp"
#include "camCameraChannel.hpp"
#include "CameraViewport.hpp"
#include "eCameraChannelEnum.hpp"
#include "gohCameraFactory.hpp"

namespace rdr2
{
	class camManager
	{
	public:
		void EndDeathScreenCamera()
		{
			sigs::camManager_EndDeathScreenCamera.call<void>(this);
		}

		void PostInit()
		{
			sigs::camManager_PostInit.call<void>(this);
		}

		void RemoveCameraOnChannel(eCameraChannelEnum param_1, camCamera *param_2)
		{
			sigs::camManager_RemoveCameraOnChannel.call<void>(this, param_1, param_2);
		}

		void Update()
		{
			sigs::camManager_Update.call<void>(this);
		}

	public:
		camCameraChannel *GetCameraChannel()
		{
			return *reinterpret_cast<camCameraChannel **>(reinterpret_cast<uintptr_t>(this) + 0x8);
		}

		gohCameraFactory *GetCameraFactory()
		{
			return *reinterpret_cast<gohCameraFactory **>(reinterpret_cast<uintptr_t>(this) + 0x50);
		}

		CameraViewport *GetCameraViewport()
		{
			//cba to convert to c++ casts
			return (CameraViewport *)(*((uintptr_t *)*((uintptr_t *)this + 0x4) + 0x42));
		}
	};
}