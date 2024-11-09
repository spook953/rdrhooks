#pragma once

#include "base.hpp"

#include "hlthMsgInjure.hpp"
#include "mvrMsgLanded.hpp"
#include "sagActor.hpp"

namespace rdr2
{
	class hlthHealthComponent
	{
	public:
		void SetHitPoints(float param_1, bool param_2, bool param_3, hlthMsgInjure *param_4)
		{
			sigs::hlthHealthComponent_SetHitPoints.call<void>(this, param_1, param_2, param_4);
		}

		bool InstantCorpsify(bool param_1, bool param_2)
		{
			return sigs::hlthHealthComponent_InstantCorpsify.call<bool>(this, param_1, param_2);
		}

		void CreateBloodPool(sagActor *param_1)
		{
			sigs::hlthHealthComponent_CreateBloodPool.call<void>(this, param_1);
		}

		void HandleMoverLanded(mvrMsgLanded *param_1)
		{
			sigs::hlthHealthComponent_HandleMoverLanded.call<void>(this, param_1);
		}

		//most likely wrong
		//used like so in hlthHealthComponent::SetHitPoints:
		//Kill((hlthMsgInjure *)this,SUB81(param_4,0));
		hlthMsgInjure *Kill(hlthMsgInjure *param_1, bool param_2)
		{
			return sigs::hlthHealthComponent_Kill.call<hlthMsgInjure *>(this, param_1, param_2);
		}

		void Injure(float param_1, sagGuid param_2, Vector3 *param_3, int param_4, Vector3 *param_5, bool param_6, int param_7, hlthMsgInjure *param_8)
		{
			sigs::hlthHealthComponent_Injure.call<void>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
		}

		void HandleInjure(hlthMsgInjure *param_1)
		{
			sigs::hlthHealthComponent_HandleInjure.call<void>(this, param_1);
		}

	public:
		sagActor *GetActor()
		{
			return *reinterpret_cast<sagActor **>(reinterpret_cast<uintptr_t>(this) + 0x10);
		}
	};
}