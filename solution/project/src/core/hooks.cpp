#include "features/esp/esp.hpp"

MAKE_HOOK(
	GameWndProc,
	sigs::GameWndProc.get(),
	LONG,
	HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	ImGui_ImplWin32_WndProcHandler(wnd, msg, wparam, lparam);

	return CALL_ORIGINAL(wnd, msg, wparam, lparam);
}

MAKE_HOOK(
	CDXGISwapChain_Present,
	mem::findVirtual(sigs::IDXGISwapChain_ptr.rcast<IDXGISwapChain *>(), 8).get(),
	HRESULT,
	IDXGISwapChain *thisptr, UINT SyncInterval, UINT Flags)
{
	if (Renderer::start())
	{
		ESP::run();
		
		Renderer::end();
	}

	return CALL_ORIGINAL(thisptr, SyncInterval, Flags);
}

MAKE_HOOK(
	CDXGISwapChain_ResizeBuffers,
	mem::findVirtual(sigs::IDXGISwapChain_ptr.rcast<IDXGISwapChain *>(), 13).get(),
	HRESULT,
	IDXGISwapChain *thisptr, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	Renderer::uninit();

	const HRESULT result{ CALL_ORIGINAL(thisptr, BufferCount, Width, Height, NewFormat, SwapChainFlags) };

	Renderer::init();

	return result;
}

MAKE_HOOK(
	hlthHealthComponent_SetHitPoints,
	sigs::hlthHealthComponent_SetHitPoints.get(),
	void,
	rdr2::hlthHealthComponent *thisptr, float param_1, bool param_2, bool param_3, rdr2::hlthMsgInjure *param_4)
{
	if (cfg::misc_god_mode)
	{
		if (thisptr && thisptr->GetActor() == rdr2::global::GetPlayerActor()) {
			return;
		}
	}

	CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4);
}

MAKE_HOOK(
	weapWeapon_OnFireProjectile,
	sigs::weapWeapon_OnFireProjectile.get(),
	void,
	rdr2::weapWeapon *thisptr, rdr2::weapProjectileInfo *proj_info)
{
	if (cfg::misc_no_ammo_drain)
	{
		if (rdr2::sagPlayer *const plr{ rdr2::global::GetPlayer() })
		{
			if (thisptr && thisptr == plr->GetActiveWeapon(true))
			{
				const float pre_call_ammo_in_clip{ thisptr->GetAmmoInClip() };

				CALL_ORIGINAL(thisptr, proj_info);

				thisptr->GetAmmoInClip() = pre_call_ammo_in_clip;

				return;
			}
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
	if (cfg::misc_no_shot_delay)
	{
		if (rdr2::sagPlayer *const plr{ rdr2::global::GetPlayer() })
		{
			if (thisptr && thisptr == plr->GetActiveWeapon(true)) {
				return -0.42f;
			}
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
	if (cfg::misc_force_auto_fire)
	{
		if (rdr2::sagPlayer *const plr{ rdr2::global::GetPlayer() })
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

	if (cfg::visuals_fov_override_active) {
		thisptr->m_Fov += cfg::visuals_fov_override_val;
	}
}