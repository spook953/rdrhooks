#pragma once

#include "rdr2_include/ActionContext.hpp"
#include "rdr2_include/AmmoComponent.hpp"
#include "rdr2_include/aniActionSet.hpp"
#include "rdr2_include/aniActionSetData.hpp"
#include "rdr2_include/aniAim.hpp"
#include "rdr2_include/aniAnimProp.hpp"
#include "rdr2_include/aniGatling.hpp"
#include "rdr2_include/aniLedge.h"
#include "rdr2_include/animAnimatorComponent.hpp"
#include "rdr2_include/animAnimSetHandle.hpp"
#include "rdr2_include/AnimIdleBodyTypes.hpp"
#include "rdr2_include/animMotionTreeManager.hpp"
#include "rdr2_include/aniNavigationGait.hpp"
#include "rdr2_include/aniRide.hpp"
#include "rdr2_include/bhPacketExec.hpp"
#include "rdr2_include/bhWeaponsPacket.hpp"
#include "rdr2_include/camCamera.hpp"
#include "rdr2_include/camCameraChannel.hpp"
#include "rdr2_include/camCameraShakeBase.hpp"
#include "rdr2_include/camCameraTransitionBase.hpp"
#include "rdr2_include/camCameraTransitionFactory.hpp"
#include "rdr2_include/CameraShakeFactory.hpp"
#include "rdr2_include/CameraViewport.hpp"
#include "rdr2_include/camManager.hpp"
#include "rdr2_include/CollisionHelper.hpp"
#include "rdr2_include/Color32.hpp"
#include "rdr2_include/ConditionMoverNotOnGround.hpp"
#include "rdr2_include/crClip.hpp"
#include "rdr2_include/crExpressions.hpp"
#include "rdr2_include/crFrame.hpp"
#include "rdr2_include/crFrameFilter.hpp"
#include "rdr2_include/CutsceneCameraShotTuningManager.hpp"
#include "rdr2_include/eCameraChannelEnum.hpp"
#include "rdr2_include/eCodeSideStatistics.hpp"
#include "rdr2_include/entEntityComponent.hpp"
#include "rdr2_include/eObjectState.hpp"
#include "rdr2_include/eState.hpp"
#include "rdr2_include/eTransitionType.hpp"
#include "rdr2_include/eWeaponAction.hpp"
#include "rdr2_include/gohCamera.hpp"
#include "rdr2_include/gohCameraFactory.hpp"
#include "rdr2_include/gohCameraTarget.hpp"
#include "rdr2_include/gohDofSettings.hpp"
#include "rdr2_include/gohGUID.hpp"
#include "rdr2_include/grcViewport.hpp"
#include "rdr2_include/hlthHealthComponent.hpp"
#include "rdr2_include/hlthMsgInjure.hpp"
#include "rdr2_include/invBaseItem.hpp"
#include "rdr2_include/invInventoryComponent.hpp"
#include "rdr2_include/invWeaponType.hpp"
#include "rdr2_include/Math.hpp"
#include "rdr2_include/Matrix34.hpp"
#include "rdr2_include/Matrix44.hpp"
#include "rdr2_include/mvrMoverComponent.hpp"
#include "rdr2_include/mvrMsgLanded.hpp"
#include "rdr2_include/phInst.hpp"
#include "rdr2_include/phLevelNew.hpp"
#include "rdr2_include/phSimulator.hpp"
#include "rdr2_include/ProjectileLaunchData.hpp"
#include "rdr2_include/projProjectile.hpp"
#include "rdr2_include/Quaternion.hpp"
#include "rdr2_include/rdrActorTracker.hpp"
#include "rdr2_include/rdrAnimation.hpp"
#include "rdr2_include/rdrMatrixAudioEntity.hpp"
#include "rdr2_include/sagActor.hpp"
#include "rdr2_include/sagGuid.hpp"
#include "rdr2_include/sagLayout.hpp"
#include "rdr2_include/sagMsgAttachmentImpact.hpp"
#include "rdr2_include/sagMsgDestroyOnDeathNotify.hpp"
#include "rdr2_include/sagPlayer.hpp"
#include "rdr2_include/sagPlayerMgr.hpp"
#include "rdr2_include/sagPlayerStates.hpp"
#include "rdr2_include/tgtReticleComponent.hpp"
#include "rdr2_include/TransitionCamera.hpp"
#include "rdr2_include/Vector2.hpp"
#include "rdr2_include/Vector3.hpp"
#include "rdr2_include/Vector4.hpp"
#include "rdr2_include/weapBaseWeaponType.hpp"
#include "rdr2_include/WeaponParams.hpp"
#include "rdr2_include/WeaponSpecialRequest.hpp"
#include "rdr2_include/weapProjectileInfo.hpp"
#include "rdr2_include/weapWeapon.hpp"

namespace rdr2
{
	sagActor *GetPlayerActor()
	{
		return sigs::GetPlayerActor.call<sagActor *>();
	}

	weapWeapon *FindWeaponFromActor(sagActor *param_1, int param_2, AmmoComponent **param_3)
	{
		return sigs::FindWeaponFromActor.call<weapWeapon *>(param_1, param_2, param_3);
	}

	void *GetBonePointerById(int param_1, sagActor *param_2)
	{
		return sigs::GetBonePointerById.call<void *>(param_1, param_2);
	}

	int GetEquipSlot(int param_1)
	{
		return sigs::GetEquipSlot.call<int>(param_1);
	}

	int GetFeelingForTarget(sagActor *param_1, sagActor *param_2)
	{
		return sigs::GetFeelingForTarget.call<int>(param_1, param_2);
	}

	bool GetHardLockTargetAnchorPoint(Vector3 *param_1, Vector3 *param_2, Vector3 *param_3, gohGUID *param_4, bool param_5, Vector2 *param_6)
	{
		return sigs::GetHardLockTargetAnchorPoint.call<bool>(param_1, param_2, param_3, param_4, param_5, param_6);
	}

	bool GetHoofMatrix(int param_1, sagActor *param_2, Matrix34 *param_3)
	{
		return sigs::GetHoofMatrix.call<bool>(param_1, param_2, param_3);
	}

	int GetWeaponEnumForAmmoEnum(sagActor *param_1, int param_2)
	{
		return sigs::GetWeaponEnumForAmmoEnum.call<int>(param_1, param_2);
	}

	void GiveEnumeratedWeapon(sagActor *param_1, int param_2, float param_3, bool param_4, bool param_5)
	{
		sigs::GiveEnumeratedWeapon.call<void>(param_1, param_2, param_3, param_4, param_5);
	}

	bool IsViewVectorInBox(Vector3 *param_1, Matrix34 *param_2, Vector2 *param_3)
	{
		return sigs::IsViewVectorInBox.call<bool>(param_1, param_2, param_3);
	}

	bool SelectEnumeratedWeapon(sagActor *param_1, int param_2, bool param_3)
	{
		return sigs::SelectEnumeratedWeapon.call<bool>(param_1, param_2, param_3);
	}

	void SetWeaponAmmoForItem(sagActor *param_1, invBaseItem *param_2, float param_3)
	{
		sigs::SetWeaponAmmoForItem.call<void>(param_1, param_2, param_3);
	}
}

namespace rdr2
{
	camManager *GetCamManager()
	{
		return sigs::camManager_sm_Instance.rcast<camManager *>();
	}
}

namespace rdr2
{
	bool ActorHasWeapon(sagActor *const actor, weapWeapon *const weapon)
	{
		if (!actor || !weapon) {
			return false;
		}

		//4 = revolver
		//8 = carbine
		constexpr int max_it{ 16 };

		for (int n{}; n < max_it; n++)
		{
			if (FindWeaponFromActor(actor, n, nullptr) == weapon) {
				return true;
			}
		}

		return false;
	}
}