#pragma once

#include "base.hpp"

#include "Vector3.hpp"

namespace rdr2
{
	class gohCameraTarget
	{
	public:
		bool GetPosition(Vector3 *param_1, bool param_2)
		{
			return sigs::gohCameraTarget_GetPosition.call<bool>(this, param_1, param_2);
		}
	};
}