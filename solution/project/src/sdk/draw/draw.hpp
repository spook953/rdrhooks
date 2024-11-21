#pragma once

#include "../../rdr2/rdr2.hpp"

class Draw final
{
public:
	static void rect(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr);
	static void rectFilled(const rdr2::Vector2 &pos, const rdr2::Vector2 &size, const rdr2::Color32 clr);
};