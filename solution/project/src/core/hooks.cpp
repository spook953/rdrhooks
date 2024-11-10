#include "../rdr2/rdr2.hpp"

MAKE_HOOK(
	hlthHealthComponent_SetHitPoints,
	sigs::hlthHealthComponent_SetHitPoints.get(),
	void,
	rdr2::hlthHealthComponent *thisptr, float param_1, bool param_2, bool param_3, rdr2::hlthMsgInjure *param_4)
{
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
	if (rdr2::ActorHasWeapon(rdr2::GetPlayerActor(), thisptr))
	{
		const float pre_call_ammo_in_clip{ thisptr->GetAmmoInClip() };

		CALL_ORIGINAL(thisptr, proj_info);

		thisptr->GetAmmoInClip() = pre_call_ammo_in_clip;

		return;
	}

	CALL_ORIGINAL(thisptr, proj_info);
}

MAKE_HOOK(
	weapWeapon_GetReloadTimeScale, //unconfirmed name, possibly inlined on switch release
	sigs::weapWeapon_GetReloadTimeScale.get(),
	float,
	rdr2::weapWeapon *thisptr)
{
	if (rdr2::ActorHasWeapon(rdr2::GetPlayerActor(), thisptr)) {
		return -1000.0f;
	}

	return CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	sagShellDerived_Update,
	sigs::sagShellDerived_Update.get(),
	void,
	void *thisptr)
{
	//terrible way of applying auto fire on weapons temporarily
	//until i find out how to get sagPlayer

	class AutoFireHelper final
	{
	private:
		rdr2::weapWeapon *m_weapon{};
		int m_og_auto_fire{};
	
	public:
		AutoFireHelper(rdr2::weapWeapon *const weapon, const int og_auto_fire) {
			m_weapon = weapon;
			m_og_auto_fire = og_auto_fire;
		}

	public:
		void apply()
		{
			if (m_weapon) {
				m_weapon->GetAutoFire() = 1;
			}
		}

		void restore()
		{
			if (m_weapon) {
				m_weapon->GetAutoFire() = m_og_auto_fire;
			}
		}
	};

	std::vector<AutoFireHelper> auto_fire_helper{};

	if (rdr2::sagActor *const plr{ rdr2::GetPlayerActor() })
	{
		for (int n{}; n < 16; n++)
		{
			if (rdr2::weapWeapon *const plr_wep{ rdr2::FindWeaponFromActor(plr, n, nullptr) }) {
				auto_fire_helper.push_back(AutoFireHelper{ plr_wep, plr_wep->GetAutoFire() });
			}
		}
	}

	for (AutoFireHelper &afh : auto_fire_helper) {
		afh.apply();
	}

	CALL_ORIGINAL(thisptr);

	for (AutoFireHelper &afh : auto_fire_helper) {
		afh.restore();
	}
}