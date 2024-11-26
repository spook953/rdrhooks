#pragma once

#include "base.hpp"

#include "CameraViewport.hpp"
#include "gohGUID.hpp"

namespace rdr2
{
	class camCamera
	{
	public:
		bool GetCollisionTarget(gohGUID *param_1, Vector3 *param_2)
		{
			return sigs::camCamera_GetCollisionTarget.call<bool>(this, param_1, param_2);
		}

		void InitCameraSettingsFromCamera(camCamera *param_1)
		{
			sigs::camCamera_InitCameraSettingsFromCamera.call<void>(this, param_1);
		}

		void ProcessShake()
		{
			sigs::camCamera_ProcessShake.call<void>(this);
		}

		void Reset()
		{
			sigs::camCamera_Reset.call<void>(this);
		}

		void ShakeCameraRandom(float param_1, Vector3 *param_2, Vector3 *param_3, float param_4, float param_5)
		{
			sigs::camCamera_ShakeCameraRandom.call<void>(this, param_1, param_2, param_3, param_4, param_5);
		}

		void Update()
		{
			sigs::camCamera_Update.call<void>(this);
		}

		void GetTargetPoint(Vector3 &param_1, bool param_2)
		{
			sigs::camCamera_GetTargetPoint.call<void, camCamera *, Vector3 &, bool>(this, param_1, param_2);
		}
	};
}