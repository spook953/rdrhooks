#include "esp.hpp"

bool ESP::getActorBounds(rdr2::sagActor *const actor, float &x, float &y, float &w, float &h)
{
	if (!actor) {
		return false;
	}

	rdr2::Vector3 root_pos{};

	if (!actor->GetRootPosition(root_pos)) {
		return false;
	}

	//TODO: get bounds dynamically from actor ptr somehow
	rdr2::Vector3 mins{ -1.0f, -1.0f, -1.0f };
	rdr2::Vector3 maxs{ 1.0f, 1.0f, 1.0f };

	if (actor->IsHuman()) {
		mins = { -0.3f, -0.8f, -0.3f };
		maxs = { 0.3f, 0.8f, 0.3f };
	}

	const rdr2::Vector3 points[8]
	{
		{ mins.x, mins.y, mins.z },
		{ maxs.x, mins.y, mins.z },
		{ maxs.x, maxs.y, mins.z },
		{ mins.x, maxs.y, mins.z },
		{ mins.x, mins.y, maxs.z },
		{ maxs.x, mins.y, maxs.z },
		{ maxs.x, maxs.y, maxs.z },
		{ mins.x, maxs.y, maxs.z }
	};

	rdr2::Vector2 screen_points[8]{};

	for (int n{}; n < 8; n++)
	{
		if (!Draw::worldToScreen(root_pos + points[n], screen_points[n])) {
			return false;
		}
	}

	float min_x{ FLT_MAX };
	float min_y{ FLT_MAX };
	float max_x{ FLT_MIN };
	float max_y{ FLT_MIN };

	for (int n{}; n < 8; n++)
	{
		min_x = fminf(min_x, screen_points[n].x);
		min_y = fminf(min_y, screen_points[n].y);
		max_x = fmaxf(max_x, screen_points[n].x);
		max_y = fmaxf(max_y, screen_points[n].y);
	}

	x = floorf(min_x);
	y = floorf(min_y);
	w = floorf(max_x - min_x);
	h = floorf(max_y - min_y);

	return x <= Draw::getScreenSize().x && (x + w) >= 0.0f && y <= Draw::getScreenSize().y && (y + h) >= 0.0f;
}

rdr2::Color32 ESP::getHealthColor(const float hp, const float max_hp)
{
	const int r{ static_cast<int>(fminf((510.0f * (max_hp - hp)) / max_hp, 210.0f)) };
	const int g{ static_cast<int>(fminf((510.0f * hp) / max_hp, 230.0f)) };

	return rdr2::Color32
	{
		static_cast<uint8_t>(r),
		static_cast<uint8_t>(g),
		static_cast<uint8_t>(50),
		static_cast<uint8_t>(255)
	};
}

rdr2::Color32 ESP::getActorColor(rdr2::sagActor *const actor)
{
	rdr2::Color32 clr{ 0, 255, 255, 255 };

	if (!actor) {
		return clr;
	}

	if (actor == rdr2::global::GetPlayerActor()) {
		clr = ESP_CLR_PLAYER;
	}

	else
	{
		if (actor->IsHuman()) {
			clr = ESP_CLR_HUMAN;
		}
	}

	return clr;
}

std::string ESP::getActorName(rdr2::sagActor *const actor)
{
	std::string name{ "actor" };

	if (!actor) {
		return name;
	}

	if (actor == rdr2::global::GetPlayerActor()) {
		name = "player";
	}

	else
	{
		if (actor->IsHuman()) {
			name = "human";
		}
	}

	return name;
}

void ESP::drawName(const float x, const float y, const float w, const float h, std::string_view name, const rdr2::Color32 clr)
{
	Draw::textOutlined
	(
		{ x + (w * 0.5f), y - (Draw::getTextSize(name).y + ESP_SPACING_NAME) },
		name,
		ESP_CLR_TEXT,
		ESP_CLR_OUTLINE,
		Draw::CENTERX
	);
}

void ESP::drawBox(const float x, const float y, const float w, const float h, const rdr2::Color32 clr)
{
	Draw::rect({ x - 1.0f, y - 1.0f }, { w + 2.0f, h + 2.0f }, ESP_CLR_OUTLINE);
	Draw::rect({ x + 1.0f, y + 1.0f }, { w - 2.0f, h - 2.0f }, ESP_CLR_OUTLINE);

	Draw::rect({ x, y }, { w, h }, clr);
}

void ESP::drawHpBar(const float x, const float y, const float w, const float h, float hp, const float max_hp)
{
	if (hp > max_hp) {
		hp = max_hp;
	}

	const float bar_w{ 2.0f };
	const float bar_h{ h };

	const float bar_x{ x - ((bar_w * 2.0f) + ESP_SPACING) };
	const float bar_y{ y };

	const float fill_h{ floorf((hp / max_hp) * bar_h) };

	Draw::rectFilled({ bar_x - 1.0f, bar_y - 1.0f }, { bar_w + 2.0f, bar_h + 2.0f }, ESP_CLR_OUTLINE);
	Draw::rectFilled({ bar_x, bar_y + (bar_h - fill_h) }, { bar_w, fill_h }, getHealthColor(hp, max_hp));
}

void ESP::run()
{
	if (!cfg::esp_active) {
		return;
	}

	rdr2::sagLayout *const actors{ rdr2::global::GetActorLayout() };

	if (!actors) {
		return;
	}

	if (cfg::esp_humans_active)
	{
		for (rdr2::sagActor **it{ actors->First() }; it; it = actors->Next(it))
		{
			rdr2::sagActor *const actor{ *it };

			if (!actor || !actor->IsHuman() || !actor->IsAlive()) {
				continue;
			}

			float x{};
			float y{};
			float w{};
			float h{};

			if (!getActorBounds(actor, x, y, w, h)) {
				continue;
			}

			const rdr2::Color32 clr{ getActorColor(actor) };

			if (cfg::esp_humans_name) {
				drawName(x, y, w, h, getActorName(actor), clr);
			}

			if (cfg::esp_humans_box) {
				drawBox(x, y, w, h, clr);
			}

			if (cfg::esp_humans_health_bar) {
				drawHpBar(x, y, w, h, actor->GetHP(), actor->GetMaxHP());
			}
		}
	}
}