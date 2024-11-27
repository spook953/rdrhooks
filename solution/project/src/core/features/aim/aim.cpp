#include "aim.hpp"

bool Aim::isVisible(rdr2::sagActor *const plr_actor, const Target &target)
{
	rdr2::sagPlayer *const plr{ rdr2::global::GetPlayer() };

	if (!plr) {
		return false;
	}

	rdr2::weapWeapon *const wep{ plr->GetActiveWeapon(true) };

	if (!wep) {
		return false;
	}

	rdr2::Vector3 muzzle_pos{};

	wep->GetMuzzleLocation(muzzle_pos);

	rdr2::phInst *exclude_insts[2]{ plr_actor->GetInstance(), target.ptr->GetInstance() };

	rdr2::phSegment segment{};

	segment.start = muzzle_pos;
	segment.end = target.pos;

	return rdr2::global::ProbeMultipleExcludeInsts(segment, 0, nullptr, 2, exclude_insts, 0x80000, 0) == 0;
}

bool Aim::getTarget(Target &target)
{
	rdr2::sagActor *const plr_actor{ rdr2::global::GetPlayerActor() };

	if (!plr_actor || !plr_actor->IsAlive()) {
		return false;
	}

	rdr2::Vector3 plr_actor_pos{};

	if (!plr_actor->GetRootPosition(plr_actor_pos)) {
		return false;
	}

	rdr2::sagLayout *const actors{ rdr2::global::GetActorLayout() };

	if (!actors) {
		return false;
	}

	std::vector<Target> potential{};

	for (rdr2::sagActor **it{ actors->First() }; it; it = actors->Next(it))
	{
		rdr2::sagActor *const actor{ *it };

		if (!actor || actor == plr_actor || !actor->IsHuman() || !actor->IsAlive()) {
			continue;
		}

		rdr2::Vector3 actor_pos{};

		if (!actor->GetHeadPosition(actor_pos)) {
			continue;
		}

		float actor_score{};

		if (cfg::aim_score_method == 0)
		{
			rdr2::Vector2 actor_pos_screen{};

			if (!Draw::worldToScreen(actor_pos, actor_pos_screen)) {
				continue;
			}

			const float screen_dist{ (actor_pos_screen - Draw::getScreenCenter()).Magnitude() };

			if (screen_dist > cfg::aim_max_screen_dist) {
				continue;
			}

			actor_score = screen_dist;
		}

		if (cfg::aim_score_method == 1)
		{
			const float world_dist{ (actor_pos - plr_actor_pos).Magnitude() };

			if (world_dist > cfg::aim_max_world_dist) {
				continue;
			}

			actor_score = world_dist;
		}

		potential.push_back({ actor, actor_pos, actor_score });
	}

	std::sort(potential.begin(), potential.end(), [&](const Target &a, const Target &b) {
		return a.score < b.score;
	});

	for (const Target &t : potential)
	{
		if (!isVisible(plr_actor, t)) {
			continue;
		}

		target = t;

		return true;
	}

	return false;
}

bool Aim::aimAt(const Target &target, rdr2::Vector3 &cam_angs)
{
	rdr2::sagActor *const plr_actor{ rdr2::global::GetPlayerActor() };

	if (!plr_actor) {
		return false;
	}

	rdr2::Vector3 cam_pos{};

	if (!rdr2::global::GetCamPos(cam_pos)) {
		return false;
	}

	cam_pos += plr_actor->GetVelocity() * (rdr2::global::GetFrameTime() * 1.0f);

	cam_angs = rdr2::utils::calcAngle(cam_pos, target.pos);

	return true;
}

bool Aim::run(rdr2::Vector3 &cam_angs)
{
	has_target = false;

	//Input::getKey() doesnt work on mouse keys..
	//TODO: figure out how to deal with input better because wndproc is weird in this game

	if (!cfg::aim_active || !GetAsyncKeyState(cfg::aim_key)) {
		return false;
	}

	Target target{};

	if (!getTarget(target)) {
		return false;
	}

	if (!aimAt(target, cam_angs)) {
		return false;
	}

	has_target = true;

	if (cfg::aim_auto_fire) {
		want_attack = true;
	}

	return true;
}

void Aim::processAttack(void *const some_ptr)
{
	if (!some_ptr || !has_target) {
		want_attack = false;
		return;
	}

	bool &attack_button{ *reinterpret_cast<bool *>(reinterpret_cast<uintptr_t>(some_ptr) + 0xB) };

	if (cfg::misc_force_auto_fire)
	{
		if (want_attack) {
			attack_button = true;
		}
	}

	else
	{
		static bool last_attack_button{};

		if (want_attack && !attack_button && !last_attack_button) {
			attack_button = true;
		}

		last_attack_button = attack_button;
	}

	want_attack = false;
}