#include "sagPlayer.hpp"

bool rdr2::sagPlayer::CanSniperZoom(bool param_1)
{
	return sigs::sagPlayer_CanSniperZoom.call<bool>(this, param_1);
}

rdr2::weapWeapon *rdr2::sagPlayer::GetActiveWeapon(bool param_1)
{
	return sigs::sagPlayer_GetActiveWeapon.call<weapWeapon *>(this, param_1);
}

bool rdr2::sagPlayer::CanQuickPickActivate()
{
	return sigs::sagPlayer_CanQuickPickActivate.call<bool>(this);
}

void rdr2::sagPlayer::UpdateJumpHotspot()
{
	sigs::sagPlayer_UpdateJumpHotspot.call<void>(this);
}

void rdr2::sagPlayer::ChangeState(eState param_1)
{
	sigs::sagPlayer_ChangeState.call<void>(this, param_1);
}

void rdr2::sagPlayer::SetDeadEyeDueling(bool param_1, bool param_2)
{
	sigs::sagPlayer_SetDeadEyeDueling.call<void>(this, param_1, param_2);
}

void rdr2::sagPlayer::HandleFallThrough(mvrMoverComponent *param_1)
{
	sigs::sagPlayer_HandleFallThrough.call<void>(this, param_1);
}

void rdr2::sagPlayer::UpdateWpnRadialSelectInput()
{
	sigs::sagPlayer_UpdateWpnRadialSelectInput.call<void>(this);
}

void rdr2::sagPlayer::UpdateReticle(animAnimatorComponent *param_1)
{
	sigs::sagPlayer_UpdateReticle.call<void>(this, param_1);
}

void rdr2::sagPlayer::Update(eState param_1)
{
	sigs::sagPlayer_Update.call<void>(this, param_1);
}

void rdr2::sagPlayer::StorePlayerData()
{
	sigs::sagPlayer_StorePlayerData.call<void>(this);
}

void rdr2::sagPlayer::PostCameraUpdate()
{
	sigs::sagPlayer_PostCameraUpdate.call<void>(this);
}

void rdr2::sagPlayer::UpdateHudReticles(animAnimatorComponent *param_1, tgtReticleComponent *param_2, invInventoryComponent *param_3)
{
	sigs::sagPlayer_UpdateHudReticles.call<void>(this, param_1, param_2, param_3);
}

bool rdr2::sagPlayer::CanDrawWeaponOfType(invWeaponType *param_1)
{
	return sigs::sagPlayer_CanDrawWeaponOfType.call<bool>(this, param_1);
}

void rdr2::sagPlayer::UpdateTargeting(invInventoryComponent *param_1)
{
	sigs::sagPlayer_UpdateTargeting.call<void>(this, param_1);
}

void rdr2::sagPlayer::UpdateStateVehicle()
{
	sigs::sagPlayer_UpdateStateVehicle.call<void>(this);
}

void rdr2::sagPlayer::EndDeadEyeCommon()
{
	sigs::sagPlayer_EndDeadEyeCommon.call<void>(this);
}

void rdr2::sagPlayer::CancelDeadeye()
{
	sigs::sagPlayer_CancelDeadeye.call<void>(this);
}

void rdr2::sagPlayer::UpdateAttackInput(invInventoryComponent *param_1)
{
	sigs::sagPlayer_UpdateAttackInput.call<void>(this, param_1);
}

void rdr2::sagPlayer::UpdateWeaponSpecialMove(WeaponSpecialRequest param_1)
{
	sigs::sagPlayer_UpdateWeaponSpecialMove.call<void>(this, param_1);
}

void rdr2::sagPlayer::ResetData()
{
	sigs::sagPlayer_ResetData.call<void>(this);
}

void rdr2::sagPlayer::UpdateStateHorse()
{
	sigs::sagPlayer_UpdateStateHorse.call<void>(this);
}

void rdr2::sagPlayer::UpdateInput()
{
	sigs::sagPlayer_UpdateInput.call<void>(this);
}

void rdr2::sagPlayer::UpdateZoomState()
{
	sigs::sagPlayer_UpdateZoomState.call<void>(this);
}

void rdr2::sagPlayer::UpdateFoot()
{
	sigs::sagPlayer_UpdateFoot.call<void>(this);
}

void rdr2::sagPlayer::IncrementStat(eCodeSideStatistics param_1, eCodeSideStatistics param_2)
{
	sigs::sagPlayer_IncrementStat.call<void>(this, param_1, param_2);
}

void rdr2::sagPlayer::UpdateState(eState param_1)
{
	sigs::sagPlayer_UpdateState.call<void>(this, param_1);
}

void rdr2::sagPlayer::UpdateWeaponSelection(int param_1)
{
	sigs::sagPlayer_UpdateWeaponSelection.call<void>(this, param_1);
}