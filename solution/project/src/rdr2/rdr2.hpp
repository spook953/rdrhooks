#pragma once

#include "rdr2_include/aActorTypeManager.hpp"
#include "rdr2_include/ActionContext.hpp"
#include "rdr2_include/AmmoComponent.hpp"
#include "rdr2_include/aniActionSet.hpp"
#include "rdr2_include/aniActionSetData.hpp"
#include "rdr2_include/aniAim.hpp"
#include "rdr2_include/aniAimSweep.hpp"
#include "rdr2_include/aniAnimProp.hpp"
#include "rdr2_include/aniGatling.hpp"
#include "rdr2_include/aniLedge.h"
#include "rdr2_include/animAnimatorComponent.hpp"
#include "rdr2_include/animAnimSetHandle.hpp"
#include "rdr2_include/AnimIdleBodyTypes.hpp"
#include "rdr2_include/animMotionTreeManager.hpp"
#include "rdr2_include/aniNavigationGait.hpp"
#include "rdr2_include/aniRide.hpp"
#include "rdr2_include/atArray.hpp"
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
#include "rdr2_include/CRadar.hpp"
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
#include "rdr2_include/Gamepad_c.hpp"
#include "rdr2_include/gohBase.hpp"
#include "rdr2_include/gohCamera.hpp"
#include "rdr2_include/gohCameraFactory.hpp"
#include "rdr2_include/gohCameraTarget.hpp"
#include "rdr2_include/gohDofSettings.hpp"
#include "rdr2_include/gohGUID.hpp"
#include "rdr2_include/grcViewport.hpp"
#include "rdr2_include/grmMatrixSet.hpp"
#include "rdr2_include/grmModel.hpp"
#include "rdr2_include/grmShaderGroup.hpp"
#include "rdr2_include/hlthHealthComponent.hpp"
#include "rdr2_include/hlthMsgInjure.hpp"
#include "rdr2_include/hudManager.hpp"
#include "rdr2_include/InputSystem_c.hpp"
#include "rdr2_include/InstanceTreeRenderer.hpp"
#include "rdr2_include/invBaseItem.hpp"
#include "rdr2_include/invInventoryComponent.hpp"
#include "rdr2_include/invWeaponType.hpp"
#include "rdr2_include/Math.hpp"
#include "rdr2_include/Matrix34.hpp"
#include "rdr2_include/Matrix44.hpp"
#include "rdr2_include/mvrMoverComponent.hpp"
#include "rdr2_include/mvrMsgLanded.hpp"
#include "rdr2_include/phInst.hpp"
#include "rdr2_include/phIntersection.hpp"
#include "rdr2_include/phLevelNew.hpp"
#include "rdr2_include/phSegment.hpp"
#include "rdr2_include/phSimulator.hpp"
#include "rdr2_include/ProjectileLaunchData.hpp"
#include "rdr2_include/projProjectile.hpp"
#include "rdr2_include/Quaternion.hpp"
#include "rdr2_include/rdrActorTracker.hpp"
#include "rdr2_include/rdrAnimation.hpp"
#include "rdr2_include/rdrMatrixAudioEntity.hpp"
#include "rdr2_include/rmcInstanceRenderBase.hpp"
#include "rdr2_include/Roam_Camera.hpp"
#include "rdr2_include/sagActor.hpp"
#include "rdr2_include/sagActorComponent.hpp"
#include "rdr2_include/sagGuid.hpp"
#include "rdr2_include/sagLayout.hpp"
#include "rdr2_include/sagLayoutManager.hpp"
#include "rdr2_include/sagMsgAttachmentImpact.hpp"
#include "rdr2_include/sagMsgDestroyOnDeathNotify.hpp"
#include "rdr2_include/sagObjRscHandler.hpp"
#include "rdr2_include/sagPlayer.hpp"
#include "rdr2_include/sagPlayerMgr.hpp"
#include "rdr2_include/sagPlayerStates.hpp"
#include "rdr2_include/tgtReticleComponent.hpp"
#include "rdr2_include/TransitionCamera.hpp"
#include "rdr2_include/TreeDrawList.hpp"
#include "rdr2_include/Vector2.hpp"
#include "rdr2_include/Vector3.hpp"
#include "rdr2_include/Vector4.hpp"
#include "rdr2_include/weapBaseWeaponType.hpp"
#include "rdr2_include/WeaponParams.hpp"
#include "rdr2_include/WeaponSpecialRequest.hpp"
#include "rdr2_include/weapProjectileInfo.hpp"
#include "rdr2_include/weapWeapon.hpp"
#include "rdr2_include/ZombieDLCManager.hpp"

namespace rdr2::global
{
	inline InputSystem_c *GetInputSystem()
	{
		return sigs::InputSystem_c_Get.call<InputSystem_c *>();
	}

	inline int ProbeMultipleExcludeInsts(
		const phSegment &param_1,
		int param_2,
		phIntersection *param_3,
		int param_4,
		/*const*/ phInst */*const*/ *param_5,
		int param_6,
		int param_7)
	{
		return sigs::ProbeMultipleExcludeInsts.call
			<int, const phSegment &, int, phIntersection *, int, /*const*/ phInst */*const*/ *, int, int>
			(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
	}
	
	inline unsigned int ConfigureActorExcludeInsts(sagGuid *param_1, phInst **param_2, int param_3, unsigned int param_4)
	{
		return sigs::ConfigureActorExcludeInsts.call<unsigned int>(param_1, param_2, param_3, param_4);
	}

	inline void SetDrawActor(sagActor *a1, bool a2)
	{
		sigs::SetDrawActor.call<void>(a1, a2);
	}

	inline float &GetFrameTime()
	{
		return *reinterpret_cast<float *>(sigs::FrameTimeFloat.get());
	}

	inline sagLayoutManager *GetLayoutManager()
	{
		return sigs::sagLayoutManager_sm_Instance.rcast<sagLayoutManager *>();
	}

	inline sagLayout *GetActorLayout()
	{
		sagLayoutManager *const layout_mgr{ GetLayoutManager() };

		if (!layout_mgr) {
			return nullptr;
		}

		return layout_mgr->GetActorLayout();
	}

	inline camManager *GetCamManager()
	{
		return sigs::camManager_sm_Instance.rcast<camManager *>();
	}

	inline bool GetCamPos(Vector3 &cam_pos)
	{
		camManager *const cam_mgr{ GetCamManager() };

		if (!cam_mgr) {
			return false;
		}

		CameraViewport *const cam_viewport{ cam_mgr->GetCameraViewport() };

		if (!cam_viewport) {
			return false;
		}

		cam_pos = cam_viewport->m_Matrix1.As34().pos;

		return true;
	}

	inline ZombieDLCManager *GetZombieDLCManager()
	{
		return sigs::ZombieDLCManager_sm_Instance.rcast<ZombieDLCManager *>();
	}

	inline sagPlayer *GetPlayer()
	{
		return *sigs::sagPlayer_ptr.rcast<sagPlayer **>();
	}

	inline phSimulator *GetSimulator()
	{
		return sigs::phSimulator_sm_ActiveInstance.rcast<phSimulator *>();
	}

	inline hudManager *GetHudManager()
	{
		return sigs::atSingleton_hudManager_sm_Instance.rcast<hudManager *>();
	}

	inline grcViewport *GetCurViewport()
	{
		return sigs::grcViewport_sm_Current.rcast<grcViewport *>();
	}

	inline sagActor *GetPlayerActor()
	{
		return sigs::GetPlayerActor.call<sagActor *>();
	}

	inline weapWeapon *FindWeaponFromActor(sagActor *param_1, int param_2, AmmoComponent **param_3)
	{
		return sigs::FindWeaponFromActor.call<weapWeapon *>(param_1, param_2, param_3);
	}

	inline void *GetBonePointerById(int param_1, sagActor *param_2)
	{
		return sigs::GetBonePointerById.call<void *>(param_1, param_2);
	}

	inline int GetEquipSlot(int param_1)
	{
		return sigs::GetEquipSlot.call<int>(param_1);
	}

	inline int GetFeelingForTarget(sagActor *param_1, sagActor *param_2)
	{
		return sigs::GetFeelingForTarget.call<int>(param_1, param_2);
	}

	inline bool GetHardLockTargetAnchorPoint(Vector3 *param_1, Vector3 *param_2, Vector3 *param_3, gohGUID *param_4, bool param_5, Vector2 *param_6)
	{
		return sigs::GetHardLockTargetAnchorPoint.call<bool>(param_1, param_2, param_3, param_4, param_5, param_6);
	}

	inline bool GetHoofMatrix(int param_1, sagActor *param_2, Matrix34 *param_3)
	{
		return sigs::GetHoofMatrix.call<bool>(param_1, param_2, param_3);
	}

	inline int GetWeaponEnumForAmmoEnum(sagActor *param_1, int param_2)
	{
		return sigs::GetWeaponEnumForAmmoEnum.call<int>(param_1, param_2);
	}

	inline void GiveEnumeratedWeapon(sagActor *param_1, int param_2, float param_3, bool param_4, bool param_5)
	{
		sigs::GiveEnumeratedWeapon.call<void>(param_1, param_2, param_3, param_4, param_5);
	}

	inline bool IsViewVectorInBox(Vector3 *param_1, Matrix34 *param_2, Vector2 *param_3)
	{
		return sigs::IsViewVectorInBox.call<bool>(param_1, param_2, param_3);
	}

	inline bool SelectEnumeratedWeapon(sagActor *param_1, int param_2, bool param_3)
	{
		return sigs::SelectEnumeratedWeapon.call<bool>(param_1, param_2, param_3);
	}

	inline void SetWeaponAmmoForItem(sagActor *param_1, invBaseItem *param_2, float param_3)
	{
		sigs::SetWeaponAmmoForItem.call<void>(param_1, param_2, param_3);
	}
}

namespace rdr2::utils
{
	inline float remap(const float val, const float in_min, const float in_max, const float out_min, const float out_max)
	{
		if (in_min == in_max) {
			return val >= in_max ? out_max : out_min;
		}

		return out_min + (out_max - out_min) * std::clamp((val - in_min) / (in_max - in_min), 0.0f, 1.0f);
	}

	inline Vector3 calcAngle(const Vector3 &from, const Vector3 &to)
	{
		const Vector3 delta{ to - from };

		float pitch{ atanf(delta.y / sqrtf((delta.x * delta.x) + (delta.z * delta.z))) };
		float yaw{ atan2f(delta.x, delta.z) };

		if (yaw < 0.0f) {
			yaw += 2.0f * rdr2::pi();
		}

		return { -pitch, yaw, 0.0f };
	}
}