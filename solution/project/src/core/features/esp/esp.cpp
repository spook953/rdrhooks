#include "esp.hpp"

void ESP::run()
{
	if (!cfg::esp_active) {
		return;
	}

	rdr2::sagActor *const plr{ rdr2::global::GetPlayerActor() };

	if (!plr) {
		return;
	}

	rdr2::Vector3 plr_root{};
	rdr2::Vector3 plr_head{};

	if (!plr->GetRootPosition(plr_root) || !plr->GetHeadPosition(plr_head)) {
		return;
	}

	rdr2::Vector2 plr_root_2d{};
	rdr2::Vector2 plr_head_2d{};

	if (!Draw::worldToScreen(plr_root, plr_root_2d) || !Draw::worldToScreen(plr_head, plr_head_2d)) {
		return;
	}

	Draw::textOutlined(plr_root_2d, "root", { 20, 220, 55, 255 }, Draw::CENTERXY);
	Draw::textOutlined(plr_head_2d, "head", { 20, 220, 55, 255 }, Draw::CENTERXY);
}