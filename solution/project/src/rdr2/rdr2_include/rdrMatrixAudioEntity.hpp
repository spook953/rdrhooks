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
		void PlayWeaponSound(eWeaponAction param_1, WeaponParams *param_2, weapWeapon *param_3, bool param_4)
		{
			sigs::rdrMatrixAudioEntity_PlayWeaponSound.call<void>(this, param_1, param_2, param_3, param_4);
		}
	};
}