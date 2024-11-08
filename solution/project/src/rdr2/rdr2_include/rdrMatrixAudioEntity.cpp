#include "rdrMatrixAudioEntity.hpp"

void rdr2::rdrMatrixAudioEntity::PlayWeaponSound(eWeaponAction param_1, WeaponParams *param_2, weapWeapon *param_3, bool param_4)
{
	sigs::rdrMatrixAudioEntity_PlayWeaponSound.call<void>(this, param_1, param_2, param_3, param_4);
}