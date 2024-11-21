#include "draw.hpp"

void Draw::rect(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddRect({ pos.x, pos.y }, { pos.x + size.x, pos.y + size.y }, IM_COL32(clr.r, clr.g, clr.b, clr.a));
}

void Draw::rectFilled(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddRectFilled({ pos.x, pos.y }, { pos.x + size.x, pos.y + size.y }, IM_COL32(clr.r, clr.g, clr.b, clr.a));
}