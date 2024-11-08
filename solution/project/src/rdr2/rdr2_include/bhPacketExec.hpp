#pragma once

#include "base.hpp"

#include "bhWeaponsPacket.hpp"

namespace rdr2
{
	class bhPacketExec
	{
	public:
		void PerformWeapon(bhWeaponsPacket *param_1, bool param_2);
		void DoPerformWeapon(bhWeaponsPacket *param_1, bool param_2);
	};
}