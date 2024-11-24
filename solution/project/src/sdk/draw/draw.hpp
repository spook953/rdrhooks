#pragma once

#include "../../rdr2/rdr2.hpp"

class Draw final
{
public:
	enum Align
	{
		DEFAULT = (0 << 0),
		LEFT = (1 << 1),
		TOP = (1 << 2),
		CENTERX = (1 << 3),
		CENTERY = (1 << 4),
		CENTERXY = (CENTERX | CENTERY)
	};

public:
	static rdr2::Vector2 getScreenSize();
	static rdr2::Vector2 getTextSize(std::string_view txt);

public:
	static bool worldToScreen(const rdr2::Vector3 &world, rdr2::Vector2 &screen);

public:
	static void line(const rdr2::Vector2 &from, const rdr2::Vector2 &to, const rdr2::Color32 clr);
	static void rect(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr);
	static void rectFilled(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr);
	static void circle(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr);
	static void circleFilled(const rdr2::Vector2 &center, const float radius, const rdr2::Color32 clr);
	static void text(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const Align align = DEFAULT);
	static void textOutlined(const rdr2::Vector2 &pos, std::string_view txt, const rdr2::Color32 clr, const rdr2::Color32 clr2, const Align align = DEFAULT);
};