#pragma once

#include "rage/rage.hpp"

#pragma region global

MAKE_SIG(GetPlayerActor, mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 C0 74 DF").fixRip());
MAKE_SIG(atSingleton_camManager_sm_Instance, mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B D5 48 8B 48 50").fixRip(3).deref());

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