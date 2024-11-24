#pragma once

#include "../cfg.hpp"

class ESP final
{
private:
	static inline const rdr2::Color32 ESP_CLR_TEXT{ 200, 200, 200, 255 };
	static inline const rdr2::Color32 ESP_CLR_OUTLINE{ 0, 0, 0, 180 };

private:
	static inline const float ESP_SPACING{ 2.0f };
	static inline const float ESP_SPACING_NAME{ 4.0f };

private:
	static bool getActorBounds(rdr2::sagActor *const actor, float &x, float &y, float &w, float &h);
	static rdr2::Color32 getHealthColor(const float hp, const float max_hp);
	static rdr2::Color32 getActorColor(rdr2::sagActor *const actor);
	static std::string getActorName(rdr2::sagActor *const actor);

private:
	static void drawName(const float x, const float y, const float w, const float h, std::string_view name, const rdr2::Color32 clr);
	static void drawBox(const float x, const float y, const float w, const float h, const rdr2::Color32 clr);
	static void drawHpBar(const float x, const float y, const float w, const float h, float hp, const float max_hp, const rdr2::Color32 clr);

public:
	static void run();
};