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