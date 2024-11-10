#pragma once

#include "base.hpp"

#include "Matrix34.hpp"

namespace rdr2
{
	class grcViewport
	{
	public:
		void SetCameraMtx(Matrix34 *param_1)
		{
			sigs::grcViewport_SetCameraMtx.call<void>(this, param_1);
		}
	};
}