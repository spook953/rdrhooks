#pragma once

#include "../cfg.hpp"

class Aim final
{
private:
	struct Target final
	{
		rdr2::sagActor *ptr{};
		rdr2::Vector3 pos{};
		float score{};
	};

private:
	static bool isVisible(rdr2::sagActor *const plr_actor, const Target &target);
	static bool getTarget(Target &target);
	static bool aimAt(const Target &target, rdr2::Vector3 &cam_angs);

private:
	static inline bool has_target{};
	static inline bool want_attack{};

public:
	static bool run(rdr2::Vector3 &cam_angs);
	static void processAttack(void *const some_ptr);
};