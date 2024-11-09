#pragma once

#include "base.hpp"

#include "crFrameFilter.hpp"

namespace rdr2
{
	class crFrame
	{
	public:
		void Set(crFrame *param_1, crFrameFilter *param_2)
		{
			sigs::crFrame_Set.call<void>(this, param_1, param_2);
		}
	};
}