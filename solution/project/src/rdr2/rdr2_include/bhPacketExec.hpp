#pragma once

#include "base.hpp"

#include "bhWeaponsPacket.hpp"

namespace rdr2
{
	class bhPacketExec
	{
	public:
		void PerformWeapon(bhWeaponsPacket *param_1, bool param_2)
		{
			sigs::bhPacketExec_PerformWeapon.call<void>(this, param_1, param_2);
		}

		void DoPerformWeapon(bhWeaponsPacket *param_1, bool param_2)
		{
			sigs::bhPacketExec_DoPerformWeapon.call<void>(this, param_1, param_2);
		}
	};
}