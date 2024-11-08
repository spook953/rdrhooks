#include "camManager.hpp"

rdr2::camCamera *rdr2::camManager::GetCamera()
{
	return *reinterpret_cast<camCamera **>(reinterpret_cast<uintptr_t>(this) + 0x38);
}

rdr2::camCameraChannel *rdr2::camManager::GetCameraChannel()
{
	return *reinterpret_cast<camCameraChannel **>(reinterpret_cast<uintptr_t>(this) + 0x8);
}

rdr2::CameraViewport *rdr2::camManager::GetCameraViewport()
{
	return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x38); //same as GetCamera?
}

rdr2::gohCameraFactory *rdr2::camManager::GetCameraFactory()
{
	return MemAddr{ this }.offset(0x50).rcast<gohCameraFactory *>();
}