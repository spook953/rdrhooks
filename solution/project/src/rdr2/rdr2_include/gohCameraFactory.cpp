#include "gohCameraFactory.hpp"

rdr2::gohCamera *const rdr2::gohCameraFactory::GetCamera(const int cam_type)
{
	static MemAddr addr{ mem::findBytes("RDR.exe", "4C 8B C9 85 D2 0F 84 ? ? ? ?") };

	if (!addr) {
		return nullptr;
	}

	return MemAddr{ addr.call<gohCamera *>(this, cam_type) }.offset(0x150).rcast<gohCamera *>();
}