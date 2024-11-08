#include "aniRide.hpp"

void rdr2::aniRide::FastDismount(bool param_1, bool param_2)
{
	sigs::aniRide_FastDismount.call<void>(param_1, param_2);
}