#pragma once

#include "camCamera.hpp"
#include "camCameraTransitionBase.hpp"

namespace rdr2
{
	class camCameraChannel
	{
	public:
		void RemoveCamera(camCamera *param_1);
		void PushCamera(camCamera *param_1, camCameraTransitionBase *param_2, camCameraTransitionBase *param_3);
	};
}