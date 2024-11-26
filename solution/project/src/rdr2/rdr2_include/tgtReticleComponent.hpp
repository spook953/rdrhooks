#pragma once

#include "base.hpp"

namespace rdr2
{
	class sagActor;

	class tgtReticleComponent
	{
	public:
		void SetTargetPoint(const Vector3 &v)
		{
			*reinterpret_cast<rdr2::Vector3 *>(reinterpret_cast<uintptr_t>(this) + 0x3810) = v;
		}

		sagActor *GetActor()
		{
			return *reinterpret_cast<sagActor **>(reinterpret_cast<uintptr_t>(this) + 0x10);
		}
	};
}