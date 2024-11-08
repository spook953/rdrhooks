#include "camManager.hpp"

rdr2::gohCameraFactory *const rdr2::camManager::GetCameraFactory()
{
	return MemAddr{ this }.offset(0x50).rcast<gohCameraFactory *>();
}