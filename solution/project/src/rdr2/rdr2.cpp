#include "rdr2.hpp"

rdr2::sagActor *rdr2::GetPlayerActor()
{
	return sigs::GetPlayerActor.call<sagActor *>();
}

rdr2::weapWeapon *rdr2::FindWeaponFromActor(sagActor *param_1, int param_2, AmmoComponent **param_3)
{
	return sigs::FindWeaponFromActor.call<weapWeapon *>(param_1, param_2, param_3);
}

rdr2::camManager *rdr2::GetCamManager()
{
	return sigs::camManager_sm_Instance.rcast<camManager *>();
}

bool rdr2::ActorHasWeapon(sagActor *const actor, weapWeapon *const weapon)
{
	if (!actor || !weapon) {
		return false;
	}

	constexpr int max_it{ 20 }; //magic number for now

	for (int n{}; n < max_it; n++)
	{
		if (FindWeaponFromActor(actor, n, nullptr) == weapon) {
			return true;
		}
	}

	return false;
}