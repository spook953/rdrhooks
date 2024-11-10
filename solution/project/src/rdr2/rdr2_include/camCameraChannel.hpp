#pragma once

#include "base.hpp"

#include "camCamera.hpp"
#include "camCameraTransitionBase.hpp"
#include "CameraViewport.hpp"
#include "gohDofSettings.hpp"
#include "TransitionCamera.hpp"

namespace rdr2
{
	class camCameraChannel
	{
	public:
		void RemoveCamera(camCamera *param_1)
		{
			sigs::camCameraChannel_RemoveCamera.call<void>(this, param_1);
		}

		void PushCamera(camCamera *param_1, camCameraTransitionBase *param_2, camCameraTransitionBase *param_3)
		{
			sigs::camCameraChannel_PushCamera.call<void>(this, param_1, param_2, param_3);
		}

		void Update()
		{
			sigs::camCameraChannel_Update.call<void>(this);
		}

	public:
		static void ReleaseTransitionCamera(TransitionCamera **param_1)
		{
			sigs::camCameraChannel_ReleaseTransitionCamera.call<void>(param_1);
		}

	public:
		CameraViewport *GetCameraViewport()
		{
			return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x40);
		}

		gohDofSettings *GetDofSettings()
		{
			return *reinterpret_cast<gohDofSettings **>(reinterpret_cast<uintptr_t>(this) + 0x610);
		}

		TransitionCamera *GetTransitionCamera()
		{
			return *reinterpret_cast<TransitionCamera **>(reinterpret_cast<uintptr_t>(this) + 0x18);
		}
	};
}