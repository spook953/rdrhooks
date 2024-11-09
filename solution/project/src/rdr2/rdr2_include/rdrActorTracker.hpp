#pragma once

#include "base.hpp"

#include "sagActor.hpp"

namespace rdr2
{
	class rdrActorTracker
	{
	public:
		void EndTrack(sagActor *param_1)
		{
			sigs::rdrActorTracker_EndTrack.call<void>(this, param_1);
		}
	};
}