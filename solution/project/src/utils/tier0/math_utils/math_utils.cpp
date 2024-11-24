#include "math_utils.hpp"

float math::remap(const float val, const float in_min, const float in_max, const float out_min, const float out_max)
{
	if (in_min == in_max) {
		return val >= in_max ? out_max : out_min;
	}

	return out_min + (out_max - out_min) * std::clamp((val - in_min) / (in_max - in_min), 0.0f, 1.0f);
}