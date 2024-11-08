#include "sagActor.hpp"

void *rdr2::sagActor::GetInstance()
{
	return sigs::sagActor_GetInstance.call<void *>(this);
}

bool rdr2::sagActor::IsIndoors()
{
	return sigs::sagActor_IsIndoors.call<bool>(this);
}

bool rdr2::sagActor::GetHeadPosition(rage::Vector3 &param_1)
{
	return sigs::sagActor_GetHeadPosition.call<bool, sagActor *, rage::Vector3 &>(this, param_1);
}

bool rdr2::sagActor::GetRootPosition(rage::Vector3 &param_1)
{
	return sigs::sagActor_GetRootPosition.call<bool, sagActor *, rage::Vector3 &>(this, param_1);
}

void rdr2::sagActor::Init(int param_1, sagLayout *param_2)
{
	sigs::sagActor_Init.call<void>(this, param_1, param_2);
}

bool rdr2::sagActor::ShouldStopUpdates()
{
	return sigs::sagActor_ShouldStopUpdates.call<bool>(this);
}

uint8_t rdr2::sagActor::IsVariableMeshBitOn(int param_1)
{
	return sigs::sagActor_IsVariableMeshBitOn.call<uint8_t>(this, param_1);
}

void rdr2::sagActor::FastDismount()
{
	sigs::sagActor_FastDismount.call<void>(this);
}

const char *rdr2::sagActor::GetMostLocalDescription()
{
	return sigs::sagActor_GetMostLocalDescription.call<const char *>(this);
}

void rdr2::sagActor::SpatialPositionUpdate(rage::Vector3 *param_1)
{
	sigs::sagActor_SpatialPositionUpdate.call<void>(this, param_1);
}

void rdr2::sagActor::Shutdown()
{
	sigs::sagActor_Shutdown.call<void>(this);
}

bool rdr2::sagActor::ProcessPhase1()
{
	return sigs::sagActor_ProcessPhase1.call<bool>(this);
}