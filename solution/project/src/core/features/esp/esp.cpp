#include "esp.hpp"

void ESP::run()
{
	if (!cfg::esp_active) {
		return;
	}

	rdr2::sagLayout *const actors{ rdr2::global::GetActorLayout() };

	if (!actors) {
		return;
	}

	for (rdr2::sagActor **it{ actors->First() }; it; it = actors->Next(it))
	{
		rdr2::sagActor *const actor{ *it };

		if (!actor) {
			continue;
		}

		rdr2::Vector3 head{};

		if (!actor->GetHeadPosition(head)) {
			continue;
		}

		rdr2::Vector2 head_2d{};

		if (!Draw::worldToScreen(head, head_2d)) {
			continue;
		}

		Draw::textOutlined(head_2d, "head", { 20, 220, 55, 255 }, Draw::CENTERXY);
	}
}