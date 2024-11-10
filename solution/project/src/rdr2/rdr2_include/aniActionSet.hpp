#pragma once

#include "base.hpp"

#include "aniActionSetData.hpp"
#include "animAnimatorComponent.hpp"

namespace rdr2
{
	class aniActionSet
	{
	public:
		void Init(animAnimatorComponent *param_1, aniActionSetData *param_2)
		{
			sigs::aniActionSet_Init.call<void>(this, param_1, param_2);
		}

		void Shutdown(bool param_1)
		{
			sigs::aniActionSet_Shutdown.call<void>(this, param_1);
		}
	};
}