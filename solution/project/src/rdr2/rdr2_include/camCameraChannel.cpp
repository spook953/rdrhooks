#include "camCameraChannel.hpp"

void rdr2::camCameraChannel::RemoveCamera(camCamera *param_1)
{
	sigs::camCameraChannel_RemoveCamera.call<void>(this, param_1);
}

void rdr2::camCameraChannel::PushCamera(camCamera *param_1, camCameraTransitionBase *param_2, camCameraTransitionBase *param_3)
{
	sigs::camCameraChannel_PushCamera.call<void>(this, param_1, param_2, param_3);
}

void rdr2::camCameraChannel::Update()
{
	sigs::camCameraChannel_Update.call<void>(this);
}

rdr2::CameraViewport *rdr2::camCameraChannel::GetCameraViewport()
{
	return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x40);
}

rdr2::gohDofSettings *rdr2::camCameraChannel::GetDofSettings()
{
	return *reinterpret_cast<gohDofSettings **>(reinterpret_cast<uintptr_t>(this) + 0x610);
}

rdr2::TransitionCamera *rdr2::camCameraChannel::GetTransitionCamera()
{
	return *reinterpret_cast<TransitionCamera **>(reinterpret_cast<uintptr_t>(this) + 0x18);
}