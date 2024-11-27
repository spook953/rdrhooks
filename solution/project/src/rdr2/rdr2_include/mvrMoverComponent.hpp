#pragma once

#include "base.hpp"

#include "phInst.hpp"
#include "Vector3.hpp"

namespace rdr2
{
	class mvrMoverComponent
	{
	public:
		phInst *GetPhysicsInst()
		{
			return *reinterpret_cast<phInst **>(reinterpret_cast<uintptr_t>(this) + 0x20);
		}

		Vector3 GetVelocity()
		{
			return *reinterpret_cast<Vector3 *>(reinterpret_cast<uintptr_t>(this) + 0x7C0);
		}
	};
}