#pragma once

#include "base.hpp"

#include "grcViewport.hpp"
#include "Matrix34.hpp"

namespace rdr2
{
	class CameraViewport
	{
	public:
		void SetCameraMatrix(rdr2::Matrix34 *param_1)
		{
			sigs::CameraViewport_SetCameraMatrix.call<void>(this, param_1);
		}

		rdr2::grcViewport *GetViewport()
		{
			return *reinterpret_cast<grcViewport **>(reinterpret_cast<uintptr_t>(this) + 0x150);
		}
	};
}