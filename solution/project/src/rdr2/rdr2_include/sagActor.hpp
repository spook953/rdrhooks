#pragma once

#include "base.hpp"

#include "sagLayout.hpp"

namespace rdr2
{
	class sagActor
	{
	public:
		void *GetInstance();
		bool IsIndoors();
		bool GetHeadPosition(rage::Vector3 &param_1);
		bool GetRootPosition(rage::Vector3 &param_1);
		void Init(int param_1, sagLayout *param_2);
		bool ShouldStopUpdates();
		uint8_t IsVariableMeshBitOn(int param_1);
		void FastDismount();
		const char *GetMostLocalDescription();
		void SpatialPositionUpdate(rage::Vector3 *param_1);
		void Shutdown();
		bool ProcessPhase1();
	};
}