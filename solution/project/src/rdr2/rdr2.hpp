#pragma once

#include "rdr2_include/camManager.hpp"
#include "rdr2_include/gohCamera.hpp"
#include "rdr2_include/gohCameraFactory.hpp"
#include "rdr2_include/hlthHealthComponent.hpp"
#include "rdr2_include/hlthMsgInjure.hpp"
#include "rdr2_include/sagActor.hpp"
#include "rdr2_include/weapProjectileInfo.hpp"
#include "rdr2_include/weapWeapon.hpp"

namespace rdr2
{
	sagActor *const GetPlayerActor();
	camManager *const GetCamManager();
}