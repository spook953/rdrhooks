#pragma once

#include "base.hpp"

#include "phInst.hpp"

namespace rdr2
{
	class mvrMoverComponent
	{
	public:
		phInst *GetPhysicsInst()
		{
			return *reinterpret_cast<phInst **>(reinterpret_cast<uintptr_t>(this) + 0x20);
		}
	};
}