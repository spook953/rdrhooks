#pragma once

#include "../../sdk/sdk.hpp"

MAKE_CFGVAR(esp_active, true);

MAKE_CFGVAR(esp_humans_active, true);
MAKE_CFGVAR(esp_humans_name, true);
MAKE_CFGVAR(esp_humans_box, true);
MAKE_CFGVAR(esp_humans_health_bar, true);

MAKE_CFGVAR(visuals_fov_override_active, true);
MAKE_CFGVAR(visuals_fov_override_val, 5.0f);

MAKE_CFGVAR(misc_god_mode, true);
MAKE_CFGVAR(misc_no_ammo_drain, true);
MAKE_CFGVAR(misc_no_shot_delay, true);
MAKE_CFGVAR(misc_force_auto_fire, false);