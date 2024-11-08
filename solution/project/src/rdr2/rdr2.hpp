#pragma once

#include "rdr2_include/camCamera.hpp"
#include "rdr2_include/camCameraChannel.hpp"
#include "rdr2_include/camCameraTransitionBase.hpp"
#include "rdr2_include/CameraViewport.hpp"
#include "rdr2_include/camManager.hpp"
#include "rdr2_include/eState.hpp"
#include "rdr2_include/gohCamera.hpp"
#include "rdr2_include/gohCameraFactory.hpp"
#include "rdr2_include/gohDofSettings.hpp"
#include "rdr2_include/grcViewport.hpp"
#include "rdr2_include/hlthHealthComponent.hpp"
#include "rdr2_include/hlthMsgInjure.hpp"
#include "rdr2_include/invInventoryComponent.hpp"
#include "rdr2_include/sagActor.hpp"
#include "rdr2_include/sagPlayer.hpp"
#include "rdr2_include/TransitionCamera.hpp"
#include "rdr2_include/weapProjectileInfo.hpp"
#include "rdr2_include/weapWeapon.hpp"

namespace rdr2
{
	sagActor *const GetPlayerActor();
	camManager *const GetCamManager();
}