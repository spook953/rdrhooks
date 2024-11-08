#pragma once

#include "base.hpp"

#include "eWeaponAction.hpp"
#include "WeaponParams.hpp"
#include "weapWeapon.hpp"

namespace rdr2
{
	class rdrMatrixAudioEntity
	{
	public:
		void PlayWeaponSound(eWeaponAction param_1, WeaponParams *param_2, weapWeapon *param_3, bool param_4);
	};
}