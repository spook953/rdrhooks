#pragma once

#include "base.hpp"

#include "sagGuid.hpp"

namespace rdr2
{
	class sagLayout
	{
	public:
		bool DestroyActor(sagGuid param_1, bool param_2)
		{
			return sigs::sagLayout_DestroyActor.call<bool>(this, param_1, param_2);
		}
	};
}