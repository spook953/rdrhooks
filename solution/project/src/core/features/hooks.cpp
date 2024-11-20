#include "../../rdr2/rdr2.hpp"

MAKE_HOOK(
	hlthHealthComponent_SetHitPoints,
	sigs::hlthHealthComponent_SetHitPoints.get(),
	void,
	rdr2::hlthHealthComponent *thisptr, float param_1, bool param_2, bool param_3, rdr2::hlthMsgInjure *param_4)
{
	//player invincibility
	if (thisptr && thisptr->GetActor() == rdr2::GetPlayerActor()) {
		return;
	}

	CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4);
}

MAKE_HOOK(
	weapWeapon_OnFireProjectile,
	sigs::weapWeapon_OnFireProjectile.get(),
	void,
	rdr2::weapWeapon *thisptr, rdr2::weapProjectileInfo *proj_info)
{
	//infinite ammo
	if (rdr2::sagPlayer *const plr{ rdr2::GetPlayer() })
	{
		if (thisptr && thisptr == plr->GetActiveWeapon(true))
		{
			const float pre_call_ammo_in_clip{ thisptr->GetAmmoInClip() };

			CALL_ORIGINAL(thisptr, proj_info);

			thisptr->GetAmmoInClip() = pre_call_ammo_in_clip;

			return;
		}
	}

	CALL_ORIGINAL(thisptr, proj_info);
}

MAKE_HOOK(
	weapWeapon_SomeShotDelayFunc,
	sigs::weapWeapon_SomeShotDelayFunc.get(),
	float,
	rdr2::weapWeapon *thisptr)
{
	//no shot delay
	if (rdr2::sagPlayer *const plr{ rdr2::GetPlayer() })
	{
		if (thisptr && thisptr == plr->GetActiveWeapon(true)) {
			return -0.42f;
		}
	}

	return CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	sagShellDerived_Update,
	sigs::sagShellDerived_Update.get(),
	void,
	void *thisptr)
{
	//TODO: find a more appropriate function for this
	//NOTE: sagShellDerived::Update is a big game update function
	//force weapon to auto fire
	if (rdr2::sagPlayer *const plr{ rdr2::GetPlayer() })
	{
		if (rdr2::weapWeapon *const wep{ plr->GetActiveWeapon(true) })
		{
			const int og_auto_fire{ wep->GetAutoFire() };

			wep->GetAutoFire() = 1;

			CALL_ORIGINAL(thisptr);

			wep->GetAutoFire() = og_auto_fire;

			return;
		}
	}

	CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	CameraViewport_UnknownFunc,
	sigs::CameraViewport_UnknownFunc.get(),
	void,
	rdr2::CameraViewport *thisptr)
{
	CALL_ORIGINAL(thisptr);

	//fov override
	thisptr->m_Fov += 20.0f;
}