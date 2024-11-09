#pragma once

#include "../../shared/shared.hpp"

#pragma region global

MAKE_SIG(GetPlayerActor, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 C0 74 DF").fixRip());

MAKE_SIG(camManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B D5 48 8B 48 50").fixRip(3).deref());
MAKE_SIG(WeatherManager_sm_instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B 48 54 85 C9 74 1C").fixRip(3).deref());
MAKE_SIG(sagLayoutManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 48 8B 48 10 48 8B 71 10 48 85 F6 0F 84 ? ? ? ? 0F 29 B4 24 ? ? ? ?").fixRip(3).deref());
MAKE_SIG(phLevelNew_sm_ActiveInstance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 4F 8D 04 40 4D 03 C0 48 8B 50 60").fixRip(3).deref());

#pragma endregion

#pragma region camCameraChannel

MAKE_SIG(camCameraChannel_RemoveCamera, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 53 38 45 33 C9").fixRip());
MAKE_SIG(camCameraChannel_PushCamera, mem::findBytes("RDR.exe", "E9 ? ? ? ? 41 83 F8 FF").fixRip());
MAKE_SIG(camCameraChannel_Update, mem::findBytes("RDR.exe", "48 89 5C 24 ? 57 48 83 EC 20 48 8B 59 18 48 8B F9 48 89 5C 24 ?"));

#pragma endregion

#pragma region CameraViewport

MAKE_SIG(CameraViewport_SetCameraMatrix, mem::findBytes("RDR.exe", "48 83 EC 28 44 8B 89 ? ? ? ?"));

#pragma endregion

#pragma region gohCameraFactory

MAKE_SIG(gohCameraFactory_GetCamera, mem::findBytes("RDR.exe", "4C 8B C9 85 D2 0F 84 ? ? ? ?"));

#pragma endregion

#pragma region invInventoryComponent

MAKE_SIG(invInventoryComponent_IsItemSwitchingWeaponToWeapon, mem::findBytes("RDR.exe", "40 53 48 81 EC ? ? ? ? F3 0F 10 05 ? ? ? ?"));

#pragma endregion

#pragma region sagActor

MAKE_SIG(sagActor_GetInstance, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 76 30").fixRip());
MAKE_SIG(sagActor_IsIndoors, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 88 65 63").fixRip());
MAKE_SIG(sagActor_GetHeadPosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 55 80 48 8B CB").fixRip());
MAKE_SIG(sagActor_GetRootPosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 47 19 01").fixRip());
MAKE_SIG(sagActor_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7C 24 ? ? 0F 84 ? ? ? ? 80 BC 24 ? ? ? ? ?").fixRip());
MAKE_SIG(sagActor_ShouldStopUpdates, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 27 48 85 FF").fixRip());
MAKE_SIG(sagActor_IsVariableMeshBitOn, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 4A").fixRip());
MAKE_SIG(sagActor_FastDismount, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 7E 70").fixRip());
MAKE_SIG(sagActor_GetMostLocalDescription, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B F8 48 85 C0 74 30 48 8D 15 ? ? ? ?").fixRip());
MAKE_SIG(sagActor_SpatialPositionUpdate, mem::findBytes("RDR.exe", "48 8B C4 56 41 57 48 83 EC 58"));
MAKE_SIG(sagActor_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B CB E8 ? ? ? ? 48 8B 5C 24 ?").fixRip());
MAKE_SIG(sagActor_ProcessPhase1, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 A9").fixRip());

#pragma endregion

#pragma region sagPlayer

MAKE_SIG(sagPlayer_CanSniperZoom, mem::findBytes("RDR.exe", "E8 ? ? ? ? 88 44 24 34").fixRip());
MAKE_SIG(sagPlayer_GetActiveWeapon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 89 45 B7").fixRip());
MAKE_SIG(sagPlayer_CanQuickPickActivate, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 28 48 8B 03").fixRip());
MAKE_SIG(sagPlayer_UpdateJumpHotspot, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 86 ? ? ? ? 41 B8 ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_ChangeState, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 06 89 87 ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_SetDeadEyeDueling, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B EE C7 43 ? ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_HandleFallThrough, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B EE C7 43 ? ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_UpdateWpnRadialSelectInput, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 28 74 24 ? 4C 8B 74 24 ?").fixRip());
MAKE_SIG(sagPlayer_UpdateReticle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8F ? ? ? ? E8 ? ? ? ? 3C 01").fixRip());
MAKE_SIG(sagPlayer_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 32 66 83 B9 ? ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_StorePlayerData, mem::findBytes("RDR.exe", "48 83 EC 08 80 B9 ? ? ? ? ?"));
MAKE_SIG(sagPlayer_PostCameraUpdate, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B 15 ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_UpdateHudReticles, mem::findBytes("RDR.exe", "4C 8B DC 49 89 53 10 53 41 54 41 55 41 56"));
MAKE_SIG(sagPlayer_CanDrawWeaponOfType, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 0F B6 C0 41 B1 01").fixRip());
MAKE_SIG(sagPlayer_UpdateTargeting, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 0F 57 F6 0F B7 8B ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_UpdateStateVehicle, mem::findBytes("RDR.exe", "40 53 57 48 83 EC 28 0F B7 81 ? ? ? ?"));
MAKE_SIG(sagPlayer_EndDeadEyeCommon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B6 93 ? ? ? ? 0F B6 83 ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_CancelDeadeye, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 8B C7 41 8B D7").fixRip());
MAKE_SIG(sagPlayer_UpdateAttackInput, mem::findBytes("RDR.exe", " 40 53 41 56 48 83 EC 28 66 83 B9 ? ? ? ? ?"));
MAKE_SIG(sagPlayer_UpdateWeaponSpecialMove, mem::findBytes("RDR.exe", "E8 ? ? ? ? 41 B1 01 49 8B CF").fixRip());
MAKE_SIG(sagPlayer_ResetData, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 83 ? ? ? ? ? 33 C0").fixRip());
MAKE_SIG(sagPlayer_UpdateStateHorse, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 9C 24 ? ? ? ? 48 8B B4 24 ? ? ? ? 0F 28 74 24 ?").fixRip());
MAKE_SIG(sagPlayer_UpdateInput, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8F ? ? ? ? 8B 51 08").fixRip());
MAKE_SIG(sagPlayer_UpdateZoomState, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 05 ? ? ? ? 32 D2").fixRip());
MAKE_SIG(sagPlayer_UpdateFoot, mem::findBytes("RDR.exe", "40 53 41 56 48 83 EC 58 0F B7 91 ? ? ? ?"));
MAKE_SIG(sagPlayer_IncrementStat, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 74 24 ? 48 8B BC 24 ? ? ? ?").fixRip());
MAKE_SIG(sagPlayer_UpdateState, mem::findBytes("RDR.exe", "40 55 57 48 83 EC 68"));
MAKE_SIG(sagPlayer_UpdateWeaponSelection, mem::findBytes("RDR.exe", "4C 8B DC 57 41 54 48 83 EC 68"));

#pragma endregion

#pragma region hlthHealthComponent

MAKE_SIG(hlthHealthComponent_SetHitPoints, mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 0F 2E C7").fixRip());

#pragma endregion

#pragma region weapWeapon

MAKE_SIG(weapWeapon_OnFireProjectile, mem::findBytes("RDR.exe", "48 89 54 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 44 0F B7 41 ?"));
MAKE_SIG(weapWeapon_GetReloadTimeScale, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 33 F6 0F 2F F0").fixRip());
MAKE_SIG(weapWeapon_ClampVelocityToMaxFlatDist, mem::findBytes("RDR.exe", "40 53 48 83 EC 50 48 63 41 30"));
MAKE_SIG(weapWeapon_ComputeMainMuzzlePosition, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BC 24 ? ? ? ? F3 44 0F 10 17").fixRip());
MAKE_SIG(weapWeapon_GetMuzzleLocationMatrix, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 05 ? ? ? ? 48 8B 83 ? ? ? ?").fixRip());
MAKE_SIG(weapWeapon_UpdateOpMode, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 44 8B 93 ? ? ? ?").fixRip());
MAKE_SIG(weapWeapon_GetThrownArmingDistanceSqrd, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 0F 10 7C 24 ? 44 0F 28 D8 F3 44 0F 10 4C 24 ?").fixRip());
MAKE_SIG(weapWeapon_IsThrownExploding, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 40 84 F6 74 34").fixRip());
MAKE_SIG(weapWeapon_AddAmmo, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D BD ? ? ? ? BE ? ? ? ?").fixRip());
MAKE_SIG(weapWeapon_UpdateRemoteGatlingData, mem::findBytes("RDR.exe", "40 56 48 81 EC ? ? ? ? 0F B7 51 20"));
MAKE_SIG(weapWeapon_SetAmmo, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8B 47 28").fixRip());
MAKE_SIG(weapWeapon_UpdateSkeletonState, mem::findBytes("RDR.exe", "40 57 48 83 EC 40 F6 81 ? ? ? ? ?"));
MAKE_SIG(weapWeapon_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 4F 08 48 3B 0D ? ? ? ?").fixRip());
MAKE_SIG(weapWeapon_UpdateAudio, mem::findBytes("RDR.exe", "E8 ? ? ? ? 83 A3 ? ? ? ? ? 40 84 ED").fixRip());
MAKE_SIG(weapWeapon_FireProjectile, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B AC 24 ? ? ? ? 48 85 FF").fixRip());
MAKE_SIG(weapWeapon_CreateExplodingProjectile, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B CB E8 ? ? ? ? 4D 8B 76 08").fixRip());
MAKE_SIG(weapWeapon_FindAndFireOpMode, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B7 4F 20 48 8B 05 ? ? ? ?").fixRip());
MAKE_SIG(weapWeapon_SetDrawn, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7B 20 00").fixRip());
MAKE_SIG(weapWeapon_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 03 48 83 C4 30").fixRip());
MAKE_SIG(weapWeapon_FireProjectileRemote, mem::findBytes("RDR.exe", "48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 63 41 30"));

#pragma endregion

#pragma region sagShellDerived

MAKE_SIG(sagShellDerived_Update, mem::findBytes("RDR.exe", "40 55 53 56 57 41 54 41 55 41 56 48 8D AC 24 ? ? ? ?"));

#pragma endregion

#pragma region scrThread

MAKE_SIG(scrThread_Run, mem::findBytes("RDR.exe", "89 54 24 10 55 53 57 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44 8B 79 10"));

#pragma endregion

#pragma region ConditionMoverNotOnGround

MAKE_SIG(ConditionMoverNotOnGround_Match, mem::findBytes("RDR.exe", "48 83 EC 28 48 83 7A ? ? 4C 8B C9"));

#pragma endregion

#pragma region bhPacketExec

MAKE_SIG(bhPacketExec_PerformWeapon, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BC 24 ? ? ? ? 4C 8B CE").fixRip());
MAKE_SIG(bhPacketExec_DoPerformWeapon, mem::findBytes("RDR.exe", "44 88 44 24 ? 55 53"));

#pragma endregion

#pragma region aniRide

MAKE_SIG(aniRide_FastDismount, mem::findBytes("RDR.exe", "E8 ? ? ? ? 83 7F 18 05").fixRip());

#pragma endregion

#pragma region rdrActorTracker

MAKE_SIG(rdrActorTracker_EndTrack, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F B6 86 ? ? ? ? 81 A6 ? ? ? ? ? ? ? ?").fixRip());

#pragma endregion

#pragma region rdrMatrixAudioEntity

MAKE_SIG(rdrMatrixAudioEntity_PlayWeaponSound, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B 05 ? ? ? ? 48 8B 0D ? ? ? ?").fixRip());

#pragma endregion

#pragma region animAnimatorComponent

MAKE_SIG(animAnimatorComponent_ResetMembers, mem::findBytes("RDR.exe", "E8 ? ? ? ? 40 38 AB ? ? ? ? 74 1E").fixRip());
MAKE_SIG(animAnimatorComponent_InitAnimator, mem::findBytes("RDR.exe", "48 89 5C 24 ? 55 48 83 EC 20 48 8B 41 10"));
MAKE_SIG(animAnimatorComponent_DetermineBodyType, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 4F 08 41 BE ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_StopParameterizedMotion, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B CE E8 ? ? ? ? 48 8B 7E 08").fixRip());
MAKE_SIG(animAnimatorComponent_IsCurrentAnimFadeOut, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 75 04 B3 01").fixRip());
MAKE_SIG(animAnimatorComponent_StopCurrentAnim, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 30 40 84 ED").fixRip());
MAKE_SIG(animAnimatorComponent_ScheduleAnimation, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 0F 2F DD").fixRip());
MAKE_SIG(animAnimatorComponent_PoseAndUpdateHeadTurn, mem::findBytes("RDR.exe", "40 53 48 83 EC 40 48 83 B9 ? ? ? ? ? 48 8B D9 0F 84 ? ? ? ? 48 8B 81 ? ? ? ?"));
MAKE_SIG(animAnimatorComponent_DetermineAndLoadNextIdle, mem::findBytes("RDR.exe", "E8 ? ? ? ? 41 C7 84 BF ? ? ? ? ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_Shutdown, mem::findBytes("RDR.exe", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 8B D9 48 8D B9 ? ? ? ?"));
MAKE_SIG(animAnimatorComponent_IsAnimationsLoaded, mem::findBytes("RDR.exe", "E8 ? ? ? ? 84 C0 74 71 48 8B 83 ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_ScheduleExpression, mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 43 38 01").fixRip());
MAKE_SIG(animAnimatorComponent_NotifyInjured, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 84 ED 4C 8B AC 24 ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_UpdateActionTreeGaitMixer, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 FF 74 5D").fixRip());
MAKE_SIG(animAnimatorComponent_InitFromSkeleton, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 39 B3 ? ? ? ? 0F 84 ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_UpdatePM, mem::findBytes("RDR.exe", "E8 ? ? ? ? F3 44 0F 10 15 ? ? ? ? 40 38 B3 ? ? ? ?").fixRip());
MAKE_SIG(animAnimatorComponent_EnableRepulsion, mem::findBytes("RDR.exe", "E8 ? ? ? ? 40 38 77 1C").fixRip());
MAKE_SIG(animAnimatorComponent_UpdateCharacterAnimation, mem::findBytes("RDR.exe", "40 53 48 83 EC 30 48 8B 41 10 44 8B C2"));
MAKE_SIG(animAnimatorComponent_HandleAttachmentImpact, mem::findBytes("RDR.exe", "E8 ? ? ? ? 49 8B 55 00 48 8B 5C 24 ?").fixRip());

#pragma endregion

#pragma region aniActionSet

MAKE_SIG(aniActionSet_Init, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B BB ? ? ? ? 48 39 2F").fixRip());
MAKE_SIG(aniActionSet_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 4B 08 48 8B D7").fixRip());

#pragma endregion

#pragma region crFrame

MAKE_SIG(crFrame_Set, mem::findBytes("RDR.exe", "E9 ? ? ? ? 48 8B 51 28").fixRip());

#pragma endregion

#pragma region animMotionTreeManager

MAKE_SIG(animMotionTreeManager_ScheduleAnimation, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4D 8B 77 08 EB 03").fixRip());
MAKE_SIG(animMotionTreeManager_Shutdown, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8B ? ? ? ? 33 FF 48 85 C9 74 0F").fixRip());

#pragma endregion

#pragma region aniAim

MAKE_SIG(aniAim_UpdateWeaponAttachment, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 8B ? ? ? ? 48 8B 49 28").fixRip());
MAKE_SIG(aniAim_Update, mem::findBytes("RDR.exe", "E8 ? ? ? ? 0F 28 74 24 ? 85 F6").fixRip());

#pragma endregion

#pragma region aniAnimProp

MAKE_SIG(aniAnimProp_UpdatePropAttachments, mem::findBytes("RDR.exe", "48 8B C4 48 89 70 18 48 89 78 20 55 41 56 41 57 48 8B EC"));

#pragma endregion

#pragma region aniGatling

MAKE_SIG(aniGatling_UpdateWeaponLocation, mem::findBytes("RDR.exe", "E8 ? ? ? ? EB 05 48 85 FF").fixRip());

#pragma endregion

#pragma region animAnimSetHandle

MAKE_SIG(animAnimSetHandle_GetObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 38 58 28").fixRip());

#pragma endregion

#pragma region phSimulator

MAKE_SIG(phSimulator_MoveObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 45 84 F6 74 08").fixRip());
MAKE_SIG(phSimulator_AddFixedObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 57 10").fixRip());

#pragma endregion

#pragma region phLevelNew

MAKE_SIG(phLevelNew_AddObject, mem::findBytes("RDR.exe", "E8 ? ? ? ? 8B F8 3D ? ? ? ?").fixRip());
MAKE_SIG(phLevelNew_AddObjectHelper, mem::findBytes("RDR.exe", "E8 ? ? ? ? 80 7C 24 ? ? 8B D8").fixRip());

#pragma endregion

#pragma region aniLedge

MAKE_SIG(aniLedge_CancelLedge, mem::findBytes("RDR.exe", "E8 ? ? ? ? E9 ? ? ? ? 83 F9 01").fixRip());

#pragma endregion