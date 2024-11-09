#pragma once

#include "base.hpp"

#include "ActionContext.hpp"

namespace rdr2
{
	class ConditionMoverNotOnGround
	{
	public:
		bool Match(ActionContext *param_1)
		{
			return sigs::ConditionMoverNotOnGround_Match.call<bool>(this, param_1);
		}
	};
}