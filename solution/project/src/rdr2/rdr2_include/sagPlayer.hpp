#pragma once

#include "base.hpp"

#include "eState.hpp"
#include "weapWeapon.hpp"

namespace rdr2
{
	class sagPlayer
	{
	public:
		bool CanSniperZoom(bool param_1);
		weapWeapon *GetActiveWeapon(bool param_1);
		bool CanQuickPickActivate();
		void UpdateJumpHotspot();
		void ChangeState(eState param_1);
	};
}