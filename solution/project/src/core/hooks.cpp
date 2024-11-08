#include "../rdr2/rdr2.hpp"

MAKE_HOOK(
	hlthHealthComponent_SetHitPoints,
	mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 0F 2E C7").fixRip().get(),
	void,
	rdr2::hlthHealthComponent *thisptr, float param_1, bool param_2, bool param_3, rdr2::hlthMsgInjure *param_4)
{
	//CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4);
}

MAKE_HOOK(
	weapWeapon_OnFireProjectile,
	mem::findBytes("RDR.exe", "48 89 54 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 44 0F B7 41 ?").get(),
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
	mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 33 F6 0F 2F F0").fixRip().get(),
	float,
	rdr2::weapWeapon *thisptr)
{
	return -1000.0f;
}

//MAKE_HOOK(
//	sagShellDerived_Update,
//	mem::findBytes("RDR.exe", "40 55 53 56 57 41 54 41 55 41 56 48 8D AC 24 ? ? ? ?").get(),
//	void,
//	void *rcx)
//{
//	CALL_ORIGINAL(rcx);
//}

//MAKE_HOOK(
//	rage_scrThread_Run,
//	mem::findBytes("RDR.exe", "89 54 24 10 55 53 57 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44 8B 79 10").get(),
//	void,
//	void *rcx, int a1)
//{
//	CALL_ORIGINAL(rcx, a1);
//}

//MAKE_HOOK(
//	ConditionMoverNotOnGround_Match,
//	mem::findBytes("RDR.exe", "48 83 EC 28 48 83 7A ? ? 4C 8B C9").get(),
//	bool,
//	void *rcx, void *a2)
//{
//	return false;
//}