#pragma once

#include "base.hpp"

#include "Matrix44.hpp"

namespace rdr2
{
	class grcViewport
	{
	public:
		void SetCameraMtx(Matrix34 *param_1)
		{
			sigs::grcViewport_SetCameraMtx.call<void>(this, param_1);
		}

		Matrix44 *ComputeFullCompositeMtx()
		{
			return sigs::grcViewport_ComputeFullCompositeMtx.call<Matrix44 *>(this);
		}
	};
}