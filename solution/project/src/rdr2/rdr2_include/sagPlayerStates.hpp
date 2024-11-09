#pragma once

#include "base.hpp"

namespace rdr2
{
	class sagPlayerStates
	{
	public:
		bool CheckIsUsingGringo()
		{
			return sigs::sagPlayerStates_CheckIsUsingGringo.call<bool>(this);
		}

		bool AllowWeaponsCycle()
		{
			return sigs::sagPlayerStates_AllowWeaponsCycle.call<bool>(this);
		}

		bool CheckIsSittingOnTrain()
		{
			return sigs::sagPlayerStates_CheckIsSittingOnTrain.call<bool>(this);
		}

		bool CheckIsDeadOrInvalid()
		{
			return sigs::sagPlayerStates_CheckIsDeadOrInvalid.call<bool>(this);
		}

		bool CheckIsRiding()
		{
			return sigs::sagPlayerStates_CheckIsRiding.call<bool>(this);
		}

		bool CheckIsUsingVehicle()
		{
			return sigs::sagPlayerStates_CheckIsUsingVehicle.call<bool>(this);
		}

		bool CheckIsInsideVehicle()
		{
			return sigs::sagPlayerStates_CheckIsInsideVehicle.call<bool>(this);
		}

		void EvaluateReticleDraw(float param_1, bool param_2)
		{
			sigs::sagPlayerStates_EvaluateReticleDraw.call<void>(this, param_1, param_2);
		}
	};
}