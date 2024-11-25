#pragma once

#include "base.hpp"

#include "entEntityComponent.hpp"
#include "sagActorComponent.hpp"
#include "hlthHealthComponent.hpp"
#include "sagLayout.hpp"
#include "sagGuid.hpp"
#include "Vector3.hpp"

namespace rdr2
{
	class sagActor
	{
	public:
		void *GetInstance()
		{
			return sigs::sagActor_GetInstance.call<void *>(this);
		}

		bool IsIndoors()
		{
			return sigs::sagActor_IsIndoors.call<bool>(this);
		}

		bool GetHeadPosition(Vector3 &param_1)
		{
			return sigs::sagActor_GetHeadPosition.call<bool, sagActor *, Vector3 &>(this, param_1);
		}

		bool GetRootPosition(Vector3 &param_1)
		{
			return sigs::sagActor_GetRootPosition.call<bool, sagActor *, Vector3 &>(this, param_1);
		}

		void Init(int param_1, sagLayout *param_2)
		{
			sigs::sagActor_Init.call<void>(this, param_1, param_2);
		}

		bool ShouldStopUpdates()
		{
			return sigs::sagActor_ShouldStopUpdates.call<bool>(this);
		}

		uint8_t IsVariableMeshBitOn(int param_1)
		{
			return sigs::sagActor_IsVariableMeshBitOn.call<uint8_t>(this, param_1);
		}

		void FastDismount()
		{
			sigs::sagActor_FastDismount.call<void>(this);
		}

		const char *GetMostLocalDescription()
		{
			return sigs::sagActor_GetMostLocalDescription.call<const char *>(this);
		}

		void SpatialPositionUpdate(Vector3 *param_1)
		{
			sigs::sagActor_SpatialPositionUpdate.call<void>(this, param_1);
		}

		void Shutdown()
		{
			sigs::sagActor_Shutdown.call<void>(this);
		}

		bool ProcessPhase1()
		{
			return sigs::sagActor_ProcessPhase1.call<bool>(this);
		}

	public:
		entEntityComponent *GetEntityComponent()
		{
			return *reinterpret_cast<entEntityComponent **>(reinterpret_cast<uintptr_t>(this) + 0x50);
		}

		hlthHealthComponent *GetHealthComponent()
		{
			return *reinterpret_cast<hlthHealthComponent **>(reinterpret_cast<uintptr_t>(this) + 0x60);
		}

		sagActorComponent *GetActorComponent()
		{
			return *reinterpret_cast<sagActorComponent **>(reinterpret_cast<uintptr_t>(this) + 0xB0);
		}

		bool IsHuman()
		{
			sagActorComponent *const actor_component{ GetActorComponent() };

			if (!actor_component) {
				return false;
			}

			return actor_component->IsHuman();
		}

		bool IsAlive()
		{
			hlthHealthComponent *const health_component{ GetHealthComponent() };

			if (!health_component) {
				return false;
			}

			return health_component->GetHP() > 0.0f;
		}

		float GetHP()
		{
			hlthHealthComponent *const health_component{ GetHealthComponent() };

			if (!health_component) {
				return 0.0f;
			}

			return health_component->GetHP();
		}

		float GetMaxHP()
		{
			hlthHealthComponent *const health_component{ GetHealthComponent() };

			if (!health_component) {
				return 0.0f;
			}

			return health_component->GetMaxHP();
		}

		int GetActorEnum()
		{
			return *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(this) + 0x108);
		}
	};
}