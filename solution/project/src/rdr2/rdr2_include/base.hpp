#pragma once

#include "../../shared/shared.hpp"

//TODO: recheck if all these need a deref

//atSingleton<camManager>::sm_Instance
MAKE_SIG(camManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B D5 48 8B 48 50").rip(3).deref());

//WeatherManager::sm_instance
MAKE_SIG(WeatherManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B 48 54 85 C9 74 1C").rip(3).deref());

//sagLayoutManager::sm_Instance
MAKE_SIG(sagLayoutManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 10 ? ? ? 48 8B 48 10 48 8B 71 10 48 85 F6").rip(3).deref());

//rage::phLevelNew::sm_ActiveInstance
MAKE_SIG(phLevelNew_sm_ActiveInstance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 4F 8D 04 40 4D 03 C0 48 8B 50 60").rip(3).deref());

//rage::aGuidGeneral<>::sm_ManagerSlots
MAKE_SIG(aGuidGeneral_sm_ManagerSlots, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 44 8B 53 08 45 0F B7 CA 4D 03 C9").rip(3).deref());

//rage::aGuidGeneral<gohBase>::sm_ManagerSlots
MAKE_SIG(aGuidGeneral_gohBase_sm_ManagerSlots, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? 44 0F B7 C0 4D 03 C0").rip(3).deref());

//WeaponEnumManager::sm_EnumWeaponEnumTree
MAKE_SIG(WeaponEnumManager_sm_EnumWeaponEnumTree, mem::findBytes("RDR.exe", "48 8B 05 61 ? ? ? 48 85 C0 74 23 0F 1F 40 00").rip(3).deref());

//ZombieDLCManager::sm_instance
MAKE_SIG(ZombieDLCManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? 48 85 C9 74 07 33 D2 E8 ? ? ? ? 0F B6 D0 48 8B 03").rip(3));

//qword_1422CBF00 / local player ptr (sagPlayer **)
MAKE_SIG(sagPlayer_ptr, mem::findBytes("RDR.exe", "48 8B 1D ? ? ? ? 48 85 DB 74 6C 80 BB ? ? ? ? ? 74 63").rip(3));

//rage::phSimulator::sm_ActiveInstance
MAKE_SIG(phSimulator_sm_ActiveInstance, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? 4C 8D 4C 24 ? 4C 8D 44 24 ? 48 8B D7 E8 ? ? ? ? C6 83 ? ? ? ? ?").rip(3).deref());

//atSingleton<hudManager>::sm_Instance
MAKE_SIG(atSingleton_hudManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? 0F B6 81 ? ? ? ? A8 48 75 09 F6 81 ? ? ? ? ? 75 08 84 C0 79 0D A8 40 75 09 45 84 E4").rip(3).deref());

//IDXGISwapChain *
MAKE_SIG(IDXGISwapChain_ptr, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 48 8B 48 48 48 8B 01 FF 50 18").rip(3).deref().offset(0x48).deref().offset(0xB8).deref());

//ID3D12CommandQueue *
MAKE_SIG(ID3D12CommandQueue_ptr, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 48 8B 48 50 48 8B 89 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 0F 57 C9").rip(3).deref().offset(0x50).deref().offset(0x128).deref().offset(0x190).deref());

//rage::grcViewport::sm_Current
MAKE_SIG(grcViewport_sm_Current, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? F3 0F 11 05 ? ? ? ? F3 0F 10 4A ? F3 0F 11 0D ? ? ? ? F3 0F 10 42 ?").rip(3).deref());

//rage::grcViewport::sm_ScreenViewport
MAKE_SIG(grcViewport_sm_ScreenViewport, mem::findBytes("RDR.exe", "48 8B 0D ? ? ? ? 44 0F 28 C7 F3 44 0F 59 C0 F3 0F 11 7C 24 ? 66 0F 6E 81 ? ? ? ? 66 0F 6E 89 ? ? ? ?").rip(3).deref());

MAKE_SIG(GetPlayerActor, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 C0 74 DF").rip());
MAKE_SIG(FindWeaponFromActor, mem::findBytes("RDR.exe", "40 56 48 83 EC 20 49 8B F0"));
MAKE_SIG(GetBonePointerById, mem::findBytes("RDR.exe", "48 89 5C 24 ? 8B 41 38"));
MAKE_SIG(GetEquipSlot, mem::findBytes("RDR.exe", "83 F9 FF 74 3A 48 8B 05 ? ? ? ?"));
MAKE_SIG(GetFeelingForTarget, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8D 48 FD").rip());
MAKE_SIG(GetHardLockTargetAnchorPoint, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 38 BD ? ? ? ?").rip());
MAKE_SIG(GetHoofMatrix, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 38 48 63 07").rip());
MAKE_SIG(GetWeaponEnumForAmmoEnum, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B F2 48 85 C9"));
MAKE_SIG(GiveEnumeratedWeapon, mem::findBytes("RDR.exe", "48 85 C9 0F 84 ? ? ? ? 48 89 74 24 ? 57"));
MAKE_SIG(IsViewVectorInBox, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 A7 ? ? ? ? ? 02 C0").rip());
MAKE_SIG(SelectEnumeratedWeapon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8D BE ? ? ? ? 0F 1F 44 00 ?").rip());
MAKE_SIG(SetWeaponAmmoForItem, mem::findBytes("RDR.exe", "48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 40"));
MAKE_SIG(rmcInstDrawModelUnskinned, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B7 46 08 FF C3 3B D8 7C BA").rip());
MAKE_SIG(rmcInstDrawModelSkinned, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 0E 44 89 6C 24 ?").rip());
MAKE_SIG(DrawCircle, mem::findBytes("RDR.exe", "E8 ? ? ? ? E8 ? ? ? ? 44 8B 0D ? ? ? ?").rip());
MAKE_SIG(GameWndProc, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 30 49 8B D9 49 8B F8"));

MAKE_SIG(CRadar_DrawRadar, mem::findBytes("RDR.exe", "48 8B C4 F3 0F 11 50 ? 55 53 41 56"));

MAKE_SIG(sagObjRscHandler_DrawGrass, mem::findBytes("RDR.exe", "4C 89 44 24 ? 53 48 81 EC ? ? ? ?"));
MAKE_SIG(sagObjRscHandler_DrawTrees, mem::findBytes("RDR.exe", "44 89 4C 24 ? 55 53 56 57 41 54"));
MAKE_SIG(sagObjRscHandler_DrawBillboards, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 84 ED 74 0C").rip());

MAKE_SIG(camCameraChannel_RemoveCamera, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 53 38 45 33 C9").rip());
MAKE_SIG(camCameraChannel_PushCamera, mem::findBytes("RDR.exe", "E9 ? ? ? ? 41 83 F8 FF").rip());
MAKE_SIG(camCameraChannel_Update, mem::findBytes("RDR.exe", "48 89 5C 24 ? 57 48 83 EC 20 48 8B 59 18 48 8B F9 48 89 5C 24 ?"));
MAKE_SIG(camCameraChannel_ReleaseTransitionCamera, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB A4").rip());

MAKE_SIG(CameraViewport_SetCameraMatrix, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8B 8E ? ? ? ? 48 8B 01 FF 50 08 49 8B 86 ? ? ? ? B2 01").rip());
MAKE_SIG(CameraViewport_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 57 40 48 8D 8F ? ? ? ?").rip());
MAKE_SIG(CameraViewport_Lerp, mem::findBytes("RDR.exe", "E9 ? ? ? ? CC CC 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B 01").rip());
MAKE_SIG(CameraViewport_LerpArc, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 28 B4 24 ? ? ? ? 48 8B AC 24 ? ? ? ?").rip());
MAKE_SIG(CameraViewport_Reset, mem::findBytes("RDR.exe", "33 C0 48 C7 41 ? ? ? ? ? 48 8D 91 ? ? ? ?"));
MAKE_SIG(CameraViewport_UnknownFunc, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 60 48 8B 81 ? ? ? ?"));

MAKE_SIG(grcViewport_SetCameraMtx, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 8B 55 40").rip());

MAKE_SIG(camManager_EndDeathScreenCamera, mem::findBytes("RDR.exe", "40 53 48 83 EC 30 48 8B 41 40"));
MAKE_SIG(camManager_PostInit, mem::findBytes("RDR.exe", "48 83 EC 38 48 8B 05 ? ? ? ? 4C 8D 05 ? ? ? ?"));
MAKE_SIG(camManager_RemoveCameraOnChannel, mem::findBytes("RDR.exe", "85 D2 75 22 4C 8B 49 08"));
MAKE_SIG(camManager_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 0D ? ? ? ? 33 FF 48 85 C9").rip());

MAKE_SIG(gohCameraFactory_GetCamera, mem::findBytes("RDR.exe", "4C 8B C9 85 D2 0F 84 ? ? ? ?"));

MAKE_SIG(invInventoryComponent_IsItemSwitchingWeaponToWeapon, mem::findBytes("RDR.exe", "40 53 48 81 EC ? ? ? ? F3 0F 10 05 ? ? ? ?"));

MAKE_SIG(sagActor_GetInstance, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 76 30").rip());
MAKE_SIG(sagActor_IsIndoors, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 88 65 63").rip());
MAKE_SIG(sagActor_GetHeadPosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 55 80 48 8B CB").rip());
MAKE_SIG(sagActor_GetRootPosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 47 19 01").rip());
MAKE_SIG(sagActor_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7C 24 ? ? 0F 84 ? ? ? ? 80 BC 24 ? ? ? ? ?").rip());
MAKE_SIG(sagActor_ShouldStopUpdates, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 27 48 85 FF").rip());
MAKE_SIG(sagActor_IsVariableMeshBitOn, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 4A").rip());
MAKE_SIG(sagActor_FastDismount, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 7E 70").rip());
MAKE_SIG(sagActor_GetMostLocalDescription, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B F8 48 85 C0 74 30 48 8D 15 ? ? ? ?").rip());
MAKE_SIG(sagActor_SpatialPositionUpdate, mem::findBytes("RDR.exe", "48 8B C4 56 41 57 48 83 EC 58"));
MAKE_SIG(sagActor_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B CB E8 ? ? ? ? 48 8B 5C 24 ?").rip());
MAKE_SIG(sagActor_ProcessPhase1, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 A9").rip());

MAKE_SIG(sagPlayer_CanSniperZoom, mem::findBytes("RDR.exe", "E8 ? ? ? ? 88 44 24 34").rip());
MAKE_SIG(sagPlayer_GetActiveWeapon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 89 45 B7").rip());
MAKE_SIG(sagPlayer_CanQuickPickActivate, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 28 48 8B 03").rip());
MAKE_SIG(sagPlayer_UpdateJumpHotspot, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 86 ? ? ? ? 41 B8 ? ? ? ?").rip());
MAKE_SIG(sagPlayer_ChangeState, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 06 89 87 ? ? ? ?").rip());
MAKE_SIG(sagPlayer_SetDeadEyeDueling, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B EE C7 43 ? ? ? ? ?").rip());
MAKE_SIG(sagPlayer_HandleFallThrough, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B EE C7 43 ? ? ? ? ?").rip());
MAKE_SIG(sagPlayer_UpdateWpnRadialSelectInput, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 28 74 24 ? 4C 8B 74 24 ?").rip());
MAKE_SIG(sagPlayer_UpdateReticle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8F ? ? ? ? E8 ? ? ? ? 3C 01").rip());
MAKE_SIG(sagPlayer_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 32 66 83 B9 ? ? ? ? ?").rip());
MAKE_SIG(sagPlayer_StorePlayerData, mem::findBytes("RDR.exe", "48 83 EC 08 80 B9 ? ? ? ? ?"));
MAKE_SIG(sagPlayer_PostCameraUpdate, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B 15 ? ? ? ?").rip());
MAKE_SIG(sagPlayer_UpdateHudReticles, mem::findBytes("RDR.exe", "4C 8B DC 49 89 53 10 53 41 54 41 55 41 56"));
MAKE_SIG(sagPlayer_CanDrawWeaponOfType, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 0F B6 C0 41 B1 01").rip());
MAKE_SIG(sagPlayer_UpdateTargeting, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 0F 57 F6 0F B7 8B ? ? ? ?").rip());
MAKE_SIG(sagPlayer_UpdateStateVehicle, mem::findBytes("RDR.exe", "40 53 57 48 83 EC 28 0F B7 81 ? ? ? ?"));
MAKE_SIG(sagPlayer_EndDeadEyeCommon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B6 93 ? ? ? ? 0F B6 83 ? ? ? ?").rip());
MAKE_SIG(sagPlayer_CancelDeadeye, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 8B C7 41 8B D7").rip());
MAKE_SIG(sagPlayer_UpdateAttackInput, mem::findBytes("RDR.exe", " 40 53 41 56 48 83 EC 28 66 83 B9 ? ? ? ? ?"));
MAKE_SIG(sagPlayer_UpdateWeaponSpecialMove, mem::findBytes("RDR.exe", "E8 ? ? ? ? 41 B1 01 49 8B CF").rip());
MAKE_SIG(sagPlayer_ResetData, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 83 ? ? ? ? ? 33 C0").rip());
MAKE_SIG(sagPlayer_UpdateStateHorse, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 9C 24 ? ? ? ? 48 8B B4 24 ? ? ? ? 0F 28 74 24 ?").rip());
MAKE_SIG(sagPlayer_UpdateInput, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8F ? ? ? ? 8B 51 08").rip());
MAKE_SIG(sagPlayer_UpdateZoomState, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 32 D2").rip());
MAKE_SIG(sagPlayer_UpdateFoot, mem::findBytes("RDR.exe", "40 53 41 56 48 83 EC 58 0F B7 91 ? ? ? ?"));
MAKE_SIG(sagPlayer_IncrementStat, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 74 24 ? 48 8B BC 24 ? ? ? ?").rip());
MAKE_SIG(sagPlayer_UpdateState, mem::findBytes("RDR.exe", "40 55 57 48 83 EC 68"));
MAKE_SIG(sagPlayer_UpdateWeaponSelection, mem::findBytes("RDR.exe", "4C 8B DC 57 41 54 48 83 EC 68"));
MAKE_SIG(sagPlayer_Reset, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 3D ? ? ? ? ? 75 27").rip());

MAKE_SIG(sagLayout_DestroyActor, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F B6 DB").rip());

MAKE_SIG(sagPlayerStates_CheckIsUsingGringo, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 A7").rip());
MAKE_SIG(sagPlayerStates_AllowWeaponsCycle, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 4C 8B 01 48 8B D9"));
MAKE_SIG(sagPlayerStates_CheckIsSittingOnTrain, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 3D 48 8B 03").rip());
MAKE_SIG(sagPlayerStates_CheckIsDeadOrInvalid, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 48 85 D2 74 22").rip());
MAKE_SIG(sagPlayerStates_CheckIsRiding, mem::findBytes("RDR.exe", "E8 ? ? ? ? 3C 01 75 0F").rip());
MAKE_SIG(sagPlayerStates_CheckIsUsingVehicle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8B ? ? ? ? 44 0F B6 E8").rip());
MAKE_SIG(sagPlayerStates_CheckIsInsideVehicle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 3D 4D 85 C9").rip());
MAKE_SIG(sagPlayerStates_EvaluateReticleDraw, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8E ? ? ? ? 0F 57 F6").rip());

MAKE_SIG(sagShellDerived_Update, mem::findBytes("RDR.exe", "40 55 53 56 57 41 54 41 55 41 56 48 8D AC 24 ? ? ? ?"));

MAKE_SIG(entEntityComponent_HandleDestroyOnDeathNotify_newbodies, mem::findBytes("RDR.exe", "48 89 54 24 ? 55 41 55"));

MAKE_SIG(hlthHealthComponent_SetHitPoints, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 0F 2E C7").rip());
MAKE_SIG(hlthHealthComponent_InstantCorpsify, mem::findBytes("RDR.exe", "E8 ? ? ? ? 88 43 28").rip());
MAKE_SIG(hlthHealthComponent_CreateBloodPool, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 83 3D ? ? ? ? ? 40 88 6C 24 ?").rip());
MAKE_SIG(hlthHealthComponent_HandleMoverLanded, mem::findBytes("RDR.exe", "40 53 48 83 EC 30 48 8B 59 60 48 85 DB 0F 84 ? ? ? ? F3 0F 10 43 ?"));
MAKE_SIG(hlthHealthComponent_Kill, mem::findBytes("RDR.exe", "E9 ? ? ? ? F6 C1 84").rip());
MAKE_SIG(hlthHealthComponent_Injure, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 BB ? ? ? ? ? B9 ? ? ? ?").rip());
MAKE_SIG(hlthHealthComponent_HandleInjure, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B7 8F ? ? ? ? 4C 8B 05 ? ? ? ? 48 03 C9 0F B7 87 ? ? ? ? 66 41 39 44 C8 ?").rip());

MAKE_SIG(weapWeapon_OnFireProjectile, mem::findBytes("RDR.exe", "48 89 54 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 44 0F B7 41 ?"));
MAKE_SIG(weapWeapon_SomeShotDelayFunc, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 33 F6 0F 2F F0").rip());
MAKE_SIG(weapWeapon_ClampVelocityToMaxFlatDist, mem::findBytes("RDR.exe", "40 53 48 83 EC 50 48 63 41 30"));
MAKE_SIG(weapWeapon_ComputeMainMuzzlePosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BC 24 ? ? ? ? F3 44 0F 10 17").rip());
MAKE_SIG(weapWeapon_GetMuzzleLocationMatrix, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 05 ? ? ? ? 48 8B 83 ? ? ? ?").rip());
MAKE_SIG(weapWeapon_UpdateOpMode, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 44 8B 93 ? ? ? ?").rip());
MAKE_SIG(weapWeapon_GetThrownArmingDistanceSqrd, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 7C 24 ? 44 0F 28 D8 F3 44 0F 10 4C 24 ?").rip());
MAKE_SIG(weapWeapon_IsThrownExploding, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 40 84 F6 74 34").rip());
MAKE_SIG(weapWeapon_AddAmmo, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D BD ? ? ? ? BE ? ? ? ?").rip());
MAKE_SIG(weapWeapon_UpdateRemoteGatlingData, mem::findBytes("RDR.exe", "40 56 48 81 EC ? ? ? ? 0F B7 51 20"));
MAKE_SIG(weapWeapon_SetAmmo, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8B 47 28").rip());
MAKE_SIG(weapWeapon_UpdateSkeletonState, mem::findBytes("RDR.exe", "40 57 48 83 EC 40 F6 81 ? ? ? ? ?"));
MAKE_SIG(weapWeapon_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 4F 08 48 3B 0D ? ? ? ?").rip());
MAKE_SIG(weapWeapon_UpdateAudio, mem::findBytes("RDR.exe", "E8 ? ? ? ? 83 A3 ? ? ? ? ? 40 84 ED").rip());
MAKE_SIG(weapWeapon_FireProjectile, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B AC 24 ? ? ? ? 48 85 FF").rip());
MAKE_SIG(weapWeapon_CreateExplodingProjectile, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B CB E8 ? ? ? ? 4D 8B 76 08").rip());
MAKE_SIG(weapWeapon_FindAndFireOpMode, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B7 4F 20 48 8B 05 ? ? ? ?").rip());
MAKE_SIG(weapWeapon_SetDrawn, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7B 20 00").rip());
MAKE_SIG(weapWeapon_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 03 48 83 C4 30").rip());
MAKE_SIG(weapWeapon_FireProjectileRemote, mem::findBytes("RDR.exe", "48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 63 41 30"));
MAKE_SIG(weapWeapon_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B C3 B2 01").rip());

MAKE_SIG(scrThread_Run, mem::findBytes("RDR.exe", "89 54 24 10 55 53 57 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44 8B 79 10"));

MAKE_SIG(ConditionMoverNotOnGround_Match, mem::findBytes("RDR.exe", "48 83 EC 28 48 83 7A ? ? 4C 8B C9"));

MAKE_SIG(bhPacketExec_PerformWeapon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BC 24 ? ? ? ? 4C 8B CE").rip());
MAKE_SIG(bhPacketExec_DoPerformWeapon, mem::findBytes("RDR.exe", "44 88 44 24 ? 55 53"));

MAKE_SIG(rdrActorTracker_EndTrack, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B6 86 ? ? ? ? 81 A6 ? ? ? ? ? ? ? ?").rip());

MAKE_SIG(rdrMatrixAudioEntity_PlayWeaponSound, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 05 ? ? ? ? 48 8B 0D ? ? ? ?").rip());

MAKE_SIG(animAnimatorComponent_ResetMembers, mem::findBytes("RDR.exe", "E8 ? ? ? ? 40 38 AB ? ? ? ? 74 1E").rip());
MAKE_SIG(animAnimatorComponent_InitAnimator, mem::findBytes("RDR.exe", "48 89 5C 24 ? 55 48 83 EC 20 48 8B 41 10"));
MAKE_SIG(animAnimatorComponent_DetermineBodyType, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 4F 08 41 BE ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_StopParameterizedMotion, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B CE E8 ? ? ? ? 48 8B 7E 08").rip());
MAKE_SIG(animAnimatorComponent_IsCurrentAnimFadeOut, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 04 B3 01").rip());
MAKE_SIG(animAnimatorComponent_StopCurrentAnim, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 30 40 84 ED").rip());
MAKE_SIG(animAnimatorComponent_ScheduleAnimation, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 0F 2F DD").rip());
MAKE_SIG(animAnimatorComponent_PoseAndUpdateHeadTurn, mem::findBytes("RDR.exe", "40 53 48 83 EC 40 48 83 B9 ? ? ? ? ? 48 8B D9 0F 84 ? ? ? ? 48 8B 81 ? ? ? ?"));
MAKE_SIG(animAnimatorComponent_DetermineAndLoadNextIdle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 41 C7 84 BF ? ? ? ? ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_Shutdown, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 8B D9 48 8D B9 ? ? ? ?"));
MAKE_SIG(animAnimatorComponent_IsAnimationsLoaded, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 71 48 8B 83 ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_ScheduleExpression, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 43 38 01").rip());
MAKE_SIG(animAnimatorComponent_NotifyInjured, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 84 ED 4C 8B AC 24 ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_UpdateActionTreeGaitMixer, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 FF 74 5D").rip());
MAKE_SIG(animAnimatorComponent_InitFromSkeleton, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 39 B3 ? ? ? ? 0F 84 ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_UpdatePM, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 44 0F 10 15 ? ? ? ? 40 38 B3 ? ? ? ?").rip());
MAKE_SIG(animAnimatorComponent_EnableRepulsion, mem::findBytes("RDR.exe", "E8 ? ? ? ? 40 38 77 1C").rip());
MAKE_SIG(animAnimatorComponent_UpdateCharacterAnimation, mem::findBytes("RDR.exe", "40 53 48 83 EC 30 48 8B 41 10 44 8B C2"));
MAKE_SIG(animAnimatorComponent_HandleAttachmentImpact, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8B 55 00 48 8B 5C 24 ?").rip());

MAKE_SIG(aniActionSet_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BB ? ? ? ? 48 39 2F").rip());
MAKE_SIG(aniActionSet_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 4B 08 48 8B D7").rip());

MAKE_SIG(aniNavigationGait_Set, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 4D 20").rip());

MAKE_SIG(animMotionTreeManager_ScheduleAnimation, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4D 8B 77 08 EB 03").rip());
MAKE_SIG(animMotionTreeManager_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8B ? ? ? ? 33 FF 48 85 C9 74 0F").rip());

MAKE_SIG(aniAim_UpdateWeaponAttachment, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8B ? ? ? ? 48 8B 49 28").rip());
MAKE_SIG(aniAim_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 28 74 24 ? 85 F6").rip());
MAKE_SIG(aniAim_SetAim, mem::findBytes("RDR.exe", "40 53 48 83 EC 60 41 8B C0"));
MAKE_SIG(aniAim_FastDraw, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 55 5F").rip());
MAKE_SIG(aniAim_RequestReload, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 1F 83 F9 01").rip());
MAKE_SIG(aniAim_Throw, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 43 08 48 8B 48 10 48 8B 41 70").rip());
MAKE_SIG(aniAim_ScheduleThrow, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8C 24 ? ? ? ? 0F B6 D8 F0 0F C1 69 ?").rip());
MAKE_SIG(aniAim_Fire, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 55 45 33 C9").rip());
MAKE_SIG(aniAim_AddReloadToFrameMT, mem::findBytes("RDR.exe", "E8 ? ? ? ? E9 ? ? ? ? 48 8B 80 ? ? ? ?").rip());
MAKE_SIG(aniAim_FillAimFrameMT, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 29 BC 24 ? ? ? ? 48 8B CB").rip());
MAKE_SIG(aniAim_AddDrawHolsterToFrameMT, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B CE E8 ? ? ? ? E9 ? ? ? ? 48 8B 80 ? ? ? ?").rip());
MAKE_SIG(aniAim_UpdateInternalStates, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 87 ? ? ? ? F3 0F 10 4F ?").rip());

MAKE_SIG(aniAnimProp_UpdatePropAttachments, mem::findBytes("RDR.exe", "48 8B C4 48 89 70 18 48 89 78 20 55 41 56 41 57 48 8B EC"));
MAKE_SIG(aniAnimProp_SetProp, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 16 49 8B 8E ? ? ? ?").rip());
MAKE_SIG(aniAnimProp_Shutdown, mem::findBytes("RDR.exe", "41 57 48 83 EC 30 48 83 79 ? ?"));

MAKE_SIG(aniGatling_UpdateWeaponLocation, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 05 48 85 FF").rip());
MAKE_SIG(aniGatling_RequestFire, mem::findBytes("RDR.exe", "40 53 48 83 EC 30 8B 41 30"));
MAKE_SIG(aniGatling_Reset, mem::findBytes("RDR.exe", "48 89 5C 24 ? 57 48 83 EC 20 44 0F B7 41 ? 33 FF"));
MAKE_SIG(aniGatling_Update, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 80 63 40 F8"));
MAKE_SIG(aniGatling_UpdateGatlingMachine, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 63 40 F8").rip());
MAKE_SIG(aniGatling_UpdateBoneIDs, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 47 30 83 F8 03").rip());
MAKE_SIG(aniGatling_UpdateIK, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 53 10 0F B6 BB ? ? ? ?").rip());

MAKE_SIG(aniAimSweep_Reset, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 63 40 F0").rip());

MAKE_SIG(aniLedge_CancelLedge, mem::findBytes("RDR.exe", "E8 ? ? ? ? E9 ? ? ? ? 83 F9 01").rip());

MAKE_SIG(aniRide_FastDismount, mem::findBytes("RDR.exe", "E8 ? ? ? ? 83 7F 18 05").rip());

MAKE_SIG(animAnimSetHandle_GetObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 38 58 28").rip());

MAKE_SIG(crFrame_Set, mem::findBytes("RDR.exe", "E9 ? ? ? ? 48 8B 51 28").rip());

MAKE_SIG(phSimulator_MoveObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 84 F6 74 08").rip());
MAKE_SIG(phSimulator_AddFixedObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 57 10").rip());
MAKE_SIG(phSimulator_TeleportObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 8B ? ? ? ? 48 8B 01 FF 50 50").rip());

MAKE_SIG(phLevelNew_AddObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B F8 3D ? ? ? ?").rip());
MAKE_SIG(phLevelNew_AddObjectHelper, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7C 24 ? ? 8B D8").rip());

MAKE_SIG(camCamera_GetCollisionTarget, mem::findBytes("RDR.exe", "48 89 5C 24 ? 57 48 83 EC 20 48 8B 99 ? ? ? ? 49 8B C0"));
MAKE_SIG(camCamera_InitCameraSettingsFromCamera, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 88 65 C7").rip());
MAKE_SIG(camCamera_ProcessShake, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 48 8B 01 FF 50 28"));
MAKE_SIG(camCamera_Reset, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 48 8D 99 ? ? ? ? C7 81 ? ? ? ? ? ? ? ?"));
MAKE_SIG(camCamera_ShakeCameraRandom, mem::findBytes("RDR.exe", "E8 ? ? ? ? E9 ? ? ? ? F3 0F 59 73 ?").rip());
MAKE_SIG(camCamera_Update, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 ? ? ? ? 84 C0 74 35"));

MAKE_SIG(gohCameraTarget_GetPosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 83 ? ? ? ? 48 8D 45 6F").rip());

MAKE_SIG(CollisionHelper_PerformCollision, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 1C 41 80 7E ? ?").rip());

MAKE_SIG(CameraShakeFactory_ReturnCameraShake, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 C7 83 ? ? ? ? ? ? ? ? 48 8B 03").rip());

MAKE_SIG(TransitionCamera_Reset, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 13 4C 8D 05 ? ? ? ?").rip());

MAKE_SIG(camCameraTransitionFactory_ReleaseTransition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B E5").rip());
MAKE_SIG(camCameraTransitionFactory_GetTransition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 89 43 70").rip());

MAKE_SIG(camCameraTransitionBase_ComputeCollision, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 30 48 8B 01"));
MAKE_SIG(camCameraTransitionBase_Start, mem::findBytes("RDR.exe", "40 53 48 83 EC 20 F3 0F 10 0A"));

MAKE_SIG(gohBase_Destroy, mem::findBytes("RDR.exe", "E9 ? ? ? ? 48 8B 51 28").rip());