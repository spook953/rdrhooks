#include "gohCameraFactory.hpp"

rdr2::gohCamera *const rdr2::gohCameraFactory::GetCamera(const int cam_type)
{
	return sigs::gohCameraFactory_GetCamera.call<gohCamera *>(this, cam_type);
}