#include "bhPacketExec.hpp"

void rdr2::bhPacketExec::PerformWeapon(bhWeaponsPacket *param_1, bool param_2)
{
	sigs::bhPacketExec_PerformWeapon.call<void>(this, param_1, param_2);
}

void rdr2::bhPacketExec::DoPerformWeapon(bhWeaponsPacket *param_1, bool param_2)
{
	sigs::bhPacketExec_DoPerformWeapon.call<void>(this, param_1, param_2);
}