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