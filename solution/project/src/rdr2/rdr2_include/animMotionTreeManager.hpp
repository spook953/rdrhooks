#pragma once

#include "base.hpp"

#include "crClip.hpp"
#include "crFrameFilter.hpp"

namespace rdr2
{
	class animMotionTreeManager
	{
	public:
		bool ScheduleAnimation(crClip *param_1, bool param_2, float param_3, float param_4, float param_5, crFrameFilter *param_6, float param_7, bool param_8)
		{
			return sigs::animMotionTreeManager_ScheduleAnimation.call<bool>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
		}

		void Shutdown()
		{
			sigs::animMotionTreeManager_Shutdown.call<void>(this);
		}
	};
}