#pragma once

#include "base.hpp"

namespace rdr2
{
	class aActorTypeManager
	{
	public:
		int64_t GetType(const char *param_1)
		{
			return sigs::aActorTypeManager_GetType.call<int64_t>(this, param_1);
		}
	};
}