#include "features/aim/aim.hpp"
#include "features/esp/esp.hpp"

MAKE_HOOK(
	GameWndProc,
	sigs::GameWndProc.get(),
	LONG,
	HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	ImGui_ImplWin32_WndProcHandler(wnd, msg, wparam, lparam);

	Input::wndproc(msg, wparam, lparam);

	return CALL_ORIGINAL(wnd, msg, wparam, lparam);
}

MAKE_HOOK(
	CDXGISwapChain_Present,
	mem::findVirtual(sigs::IDXGISwapChain_ptr.rcast<IDXGISwapChain *>(), 8).get(),
	HRESULT,
	IDXGISwapChain *thisptr, UINT SyncInterval, UINT Flags)
{
	Input::start();

	if (Renderer::start())
	{
		ESP::run();

		Renderer::end();
	}

	Input::end();

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

MAKE_HOOK(
	camCamera_ProcessShake,
	sigs::camCamera_ProcessShake.get(),
	void,
	rdr2::camCamera *thisptr)
{
	if (cfg::visuals_no_cam_shake) {
		return;
	}

	CALL_ORIGINAL(thisptr);
}

//this is more accurate im pretty sure..
//but it has an annoying down flick after aim stops aiming
//WTF!!
//MAKE_HOOK(
//	camCMXCameraActions_Roam_Camera_ComputeFollowMatrix,
//	sigs::camCMXCameraActions_Roam_Camera_ComputeFollowMatrix.get(),
//	void,
//	rdr2::Roam_Camera *thisptr, const rdr2::Vector3 &param_1, float param_2, bool param_3, rdr2::Matrix44 &param_4)
//{
//	rdr2::Vector3 aim_angles{};
//
//	if (Aim::run(aim_angles)) {
//		return CALL_ORIGINAL(thisptr, aim_angles, param_2, param_3, param_4);
//	}
//
//	CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4);
//}

MAKE_HOOK(
	camCMXCameraActions_Roam_Camera_UpdateFollowBehavior,
	sigs::camCMXCameraActions_Roam_Camera_UpdateFollowBehavior.get(),
	void,
	rdr2::Roam_Camera *thisptr)
{
	rdr2::Vector3 aim_angles{};

	if (Aim::run(aim_angles))
	{
		rdr2::Matrix44 aim_matrix{};

		thisptr->ComputeFollowMatrix({ aim_angles.x - 0.051f, aim_angles.y, 0.0f }, 0.0f, false, aim_matrix);
		thisptr->GetVelocity() = {};

		CALL_ORIGINAL(thisptr);

		thisptr->GetMatrix1() = aim_matrix;

		return;
	}

	CALL_ORIGINAL(thisptr);
}

MAKE_HOOK(
	SomeInputFuncOrSomething,
	sigs::SomeInputFuncOrSomething.get(),
	bool,
	void *thisptr)
{
	const bool result{ CALL_ORIGINAL(thisptr) };

	Aim::processAttack(thisptr);

	return result;
}

MAKE_HOOK(
	projProjectile_Launch,
	sigs::projProjectile_Launch.get(),
	void,
	rdr2::projProjectile *thisptr, rdr2::Matrix34 *param_1, int param_2, rdr2::Vector3 *param_3, rdr2::sagGuid param_4,
	rdr2::Vector3 *param_5, bool param_6, bool param_7, float param_8, rdr2::Vector3 *param_9)
{
	if (cfg::misc_no_weapon_spread)
	{
		if (rdr2::sagActor *const plr{ rdr2::global::GetPlayerActor() })
		{
			if (param_4 == plr->GetSagGUID()) {
				param_7 = true;
			}
		}
	}

	CALL_ORIGINAL(thisptr, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}