#include "rdr2.hpp"

rdr2::sagActor *const rdr2::GetPlayerActor()
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 85 C0 74 DF").fixRip() };

	if (!addr) {
		return nullptr;
	}

	return addr.call<sagActor *>();
}

rdr2::camManager *const rdr2::GetCamManager()
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "48 8B 05 ? ? ? ? 8B D5 48 8B 48 50").fixRip(3).deref() };

	if (!addr) {
		return nullptr;
	}

	return addr.rcast<camManager *>();
}