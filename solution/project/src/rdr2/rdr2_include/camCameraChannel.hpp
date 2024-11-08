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
		void RemoveCamera(camCamera *param_1);
		void PushCamera(camCamera *param_1, camCameraTransitionBase *param_2, camCameraTransitionBase *param_3);
		void Update();
		CameraViewport *GetCameraViewport();
		gohDofSettings *GetDofSettings();
		TransitionCamera *GetTransitionCamera();
	};
}