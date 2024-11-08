#include "ConditionMoverNotOnGround.hpp"

bool rdr2::ConditionMoverNotOnGround::Match(ActionContext *param_1)
{
	return sigs::ConditionMoverNotOnGround_Match.call<bool>(this, param_1);
}