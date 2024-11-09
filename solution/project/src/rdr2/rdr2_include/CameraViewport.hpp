#pragma once

#include "base.hpp"

#include "grcViewport.hpp"
#include "Matrix34.hpp"

namespace rdr2
{
	class CameraViewport
	{
	public:
		void SetCameraMatrix(Matrix34 *param_1)
		{
			sigs::CameraViewport_SetCameraMatrix.call<void>(this, param_1);
		}

		grcViewport *GetViewport()
		{
			return *reinterpret_cast<grcViewport **>(reinterpret_cast<uintptr_t>(this) + 0x150);
		}
	};
}