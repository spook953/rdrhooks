#pragma once

#include "base.hpp"

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix44.hpp"

namespace rdr2
{
	class Roam_Camera
	{
	public:
		void ComputeFollowMatrix(const Vector3 &param_1, float param_2, bool param_3, Matrix44 &param_4)
		{
			sigs::camCMXCameraActions_Roam_Camera_ComputeFollowMatrix.call<void, void *, const Vector3 &, float, bool, Matrix44 &>
				(this, param_1, param_2, param_3, param_4);
		}

	public:
		Vector2 &GetVelocity()
		{
			return *reinterpret_cast<Vector2 *>(reinterpret_cast<uintptr_t>(this) + 0x3E0);
		}

		Matrix44 &GetMatrix1()
		{
			return *reinterpret_cast<Matrix44 *>(reinterpret_cast<uintptr_t>(this) + 0x490);
		}

		Matrix44 &GetMatrix2()
		{
			return *reinterpret_cast<Matrix44 *>(reinterpret_cast<uintptr_t>(this) + 0x4D0);
		}
	};
}