#pragma once

#include "base.hpp"

namespace rdr2
{
	class CameraShakeFactory
	{
	public:
		void ReturnCameraShake(camCameraShakeBase **param_1)
		{
			sigs::CameraShakeFactory_ReturnCameraShake.call<void>(this, param_1);
		}
	};
}