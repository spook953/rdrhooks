#include "rdrActorTracker.hpp"

void rdr2::rdrActorTracker::EndTrack(sagActor *param_1)
{
	sigs::rdrActorTracker_EndTrack.call<void>(this, param_1);
}