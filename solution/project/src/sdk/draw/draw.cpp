#include "draw.hpp"

rdr2::Vector2 Draw::getScreenSize()
{
	return { ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y };
}

void Draw::line(const rdr2::Vector2 &from, const rdr2::Vector2 &to, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddLine({ from.x, from.y }, { to.x, to.y }, IM_COL32(clr.r, clr.g, clr.b, clr.a));
}

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

void Draw::circle(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddCircle({ center.x, center.y }, radius, IM_COL32(clr.r, clr.g, clr.b, clr.a));
}

void Draw::circleFilled(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddCircleFilled({ center.x, center.y }, radius, IM_COL32(clr.r, clr.g, clr.b, clr.a));
}

void Draw::text(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const Align align)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	float x{ pos.x };
	float y{ pos.y };

	if (align)
	{
		const ImVec2 size{ ImGui::GetFont()->CalcTextSizeA(ImGui::GetFont()->FontSize, FLT_MAX, 0.0f, txt.data()) };

		if (align & LEFT) {
			x -= size.x;
		}

		if (align & TOP) {
			y -= size.y;
		}

		if (align & CENTERX) {
			x -= size.x * 0.5f;
		}

		if (align & CENTERY) {
			y -= size.y * 0.5f;
		}
	}

	dl->AddText({ x, y }, IM_COL32(clr.r, clr.g, clr.b, clr.a), txt.data());
}

void Draw::textOutlined(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const Align align)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	float x{ pos.x };
	float y{ pos.y };

	if (align)
	{
		const ImVec2 size{ ImGui::GetFont()->CalcTextSizeA(ImGui::GetFont()->FontSize, FLT_MAX, 0.0f, txt.data()) };

		if (align & LEFT) {
			x -= size.x;
		}

		if (align & TOP) {
			y -= size.y;
		}

		if (align & CENTERX) {
			x -= size.x * 0.5f;
		}

		if (align & CENTERY) {
			y -= size.y * 0.5f;
		}
	}

	const int offsets[8][2]
	{
		{ -1, -1 },	{ 0, -1 }, { 1, -1 },
		{ -1, 0 }, { 1, 0 },
		{ -1, 1 }, { 0, 1 }, { 1, 1 }
	};

	for (int n{}; n < 8; n++) {
		dl->AddText({ x + offsets[n][0], y + offsets[n][1] }, IM_COL32(0, 0, 0, clr.a), txt.data());
	}

	dl->AddText({ x, y }, IM_COL32(clr.r, clr.g, clr.b, clr.a), txt.data());
}