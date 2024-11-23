#include "draw.hpp"

rdr2::Vector2 Draw::getScreenSize()
{
	return { ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y };
}

bool Draw::worldToScreen(const rdr2::Vector3 &world, rdr2::Vector2 &screen)
{
	const float *const m{ sigs::WorldToScreenMtx.rcast<float *>() };

	if (!m) {
		return false;
	}

	const float clip_w{ world.x * m[3] + world.y * m[7] + world.z * m[11] + m[15] };

	if (clip_w <= 0.0f) {
		return false;
	}

	const float clip_x{ world.x * m[0] + world.y * m[4] + world.z * m[8] + m[12] };
	const float clip_y{ world.x * m[1] + world.y * m[5] + world.z * m[9] + m[13] };
	const float clip_z{ world.x * m[2] + world.y * m[6] + world.z * m[10] + m[14] };

	screen = { clip_x * (1.0f / clip_w) , clip_y * (1.0f / clip_w) };

	return true;
}

void Draw::line(const rdr2::Vector2 &from, const rdr2::Vector2 &to, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddLine
	(
		{ floorf(from.x), floorf(from.y)},
		{ floorf(to.x), floorf(to.y)},
		IM_COL32(clr.r, clr.g, clr.b, clr.a)
	);
}

void Draw::rect(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddRect
	(
		{ floorf(pos.x), floorf(pos.y) },
		{ floorf(pos.x) + floorf(size.x), floorf(pos.y) + floorf(size.y) },
		IM_COL32(clr.r, clr.g, clr.b, clr.a)
	);
}

void Draw::rectFilled(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddRectFilled
	(
		{ floorf(pos.x), floorf(pos.y) },
		{ floorf(pos.x) + floorf(size.x), floorf(pos.y) + floorf(size.y) },
		IM_COL32(clr.r, clr.g, clr.b, clr.a)
	);
}

void Draw::circle(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddCircle
	(
		{ floorf(center.x), floorf(center.y) },
		floorf(radius),
		IM_COL32(clr.r, clr.g, clr.b, clr.a)
	);
}

void Draw::circleFilled(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	dl->AddCircleFilled
	(
		{ floorf(center.x), floorf(center.y) },
		floorf(radius),
		IM_COL32(clr.r, clr.g, clr.b, clr.a)
	);
}

void Draw::text(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const Align align)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	float x{ floorf(pos.x) };
	float y{ floorf(pos.y) };

	if (align)
	{
		const ImVec2 size{ ImGui::GetFont()->CalcTextSizeA(ImGui::GetFont()->FontSize, FLT_MAX, 0.0f, txt.data()) };

		if (align & LEFT) {
			x -= floorf(size.x);
		}

		if (align & TOP) {
			y -= floorf(size.y);
		}

		if (align & CENTERX) {
			x -= floorf(size.x * 0.5f);
		}

		if (align & CENTERY) {
			y -= floorf(size.y * 0.5f);
		}
	}

	dl->AddText
	(
		{ x, y },
		IM_COL32(clr.r, clr.g, clr.b, clr.a), txt.data()
	);
}

void Draw::textOutlined(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const Align align)
{
	ImDrawList *const dl{ ImGui::GetBackgroundDrawList() };

	if (!dl) {
		return;
	}

	float x{ floorf(pos.x) };
	float y{ floorf(pos.y) };

	if (align)
	{
		const ImVec2 size{ ImGui::GetFont()->CalcTextSizeA(ImGui::GetFont()->FontSize, FLT_MAX, 0.0f, txt.data()) };

		if (align & LEFT) {
			x -= floorf(size.x);
		}

		if (align & TOP) {
			y -= floorf(size.y);
		}

		if (align & CENTERX) {
			x -= floorf(size.x * 0.5f);
		}

		if (align & CENTERY) {
			y -= floorf(size.y * 0.5f);
		}
	}

	const int offsets[8][2]
	{
		{ -1, -1 },	{ 0, -1 }, { 1, -1 },
		{ -1, 0 }, { 1, 0 },
		{ -1, 1 }, { 0, 1 }, { 1, 1 }
	};

	for (int n{}; n < 8; n++)
	{
		dl->AddText
		(
			{ x + offsets[n][0], y + offsets[n][1] },
			IM_COL32(0, 0, 0, clr.a),
			txt.data()
		);
	}

	dl->AddText
	(
		{ x, y },
		IM_COL32(clr.r, clr.g, clr.b, clr.a),
		txt.data()
	);
}