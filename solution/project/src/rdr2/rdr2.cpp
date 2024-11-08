#include "rdr2.hpp"

rdr2::sagActor *const rdr2::GetPlayerActor()
{
	return sigs::GetPlayerActor.call<sagActor *>();
}

rdr2::camManager *const rdr2::GetCamManager()
{
	return sigs::atSingleton_camManager_sm_Instance.rcast<camManager *>();
}