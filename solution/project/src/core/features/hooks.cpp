#include "../../sdk/sdk.hpp"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
		Draw::line({ 300.0f, 349.0f }, { 789.0f, 457.0f }, { 90, 70, 200, 255 });

		Draw::rect({ 200.0f, 200.0f }, { 50.0f, 50.0f }, { 20, 160, 70, 255 });
		Draw::rectFilled({ 400.0f, 100.0f }, { 150.0f, 70.0f }, { 20, 160, 70, 255 });

		Draw::circle({ 200.0f, 500.0f }, 20.0f, { 50, 100, 100, 255 });
		Draw::circleFilled({ 250.0f, 550.0f }, 30.0f, { 100, 20, 150, 255 });

		Draw::text({ 300.0f, 200.0f }, "hello :D", { 200, 200, 200, 255 });
		Draw::textOutlined({ 300.0f, 220.0f }, "whatsup", { 20, 220, 50, 255 }, Draw::CENTERX);

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
	thisptr->m_Fov += 10.0f;
}