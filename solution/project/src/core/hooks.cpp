#include "../rdr2/rdr2.hpp"

MAKE_HOOK(
	hlthHealthComponent_SetHitPoints,
	sigs::hlthHealthComponent_SetHitPoints.get(),
	void,
	rdr2::hlthHealthComponent *thisptr, float param_1, bool param_2, bool param_3, rdr2::hlthMsgInjure *param_4)
{
	//CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4);
}

MAKE_HOOK(
	weapWeapon_OnFireProjectile,
	sigs::weapWeapon_OnFireProjectile.get(),
	void,
	rdr2::weapWeapon *thisptr, rdr2::weapProjectileInfo *proj_info)
{
	thisptr->GetAutoFire() = 1;

	const float pre_call_ammo_in_clip{ thisptr->GetAmmoInClip() };

	CALL_ORIGINAL(thisptr, proj_info);

	thisptr->GetAmmoInClip() = pre_call_ammo_in_clip;
}

MAKE_HOOK(
	weapWeapon_GetReloadTimeScale, //unconfirmed name
	sigs::weapWeapon_GetReloadTimeScale.get(),
	float,
	rdr2::weapWeapon *thisptr)
{
	return -1000.0f;
}