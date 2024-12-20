#pragma once

#include "../../sdk/sdk.hpp"

#pragma region aim

MAKE_CFGVAR(aim_active, true);
MAKE_CFGVAR(aim_key, VK_XBUTTON1);
MAKE_CFGVAR(aim_auto_fire, true);

MAKE_CFGVAR(aim_aiming_method, 1); //(0 = normal) (1 = silent)
MAKE_CFGVAR(aim_score_method, 1); //(0 = screen dist) (1 = world dist)
MAKE_CFGVAR(aim_max_screen_dist, 200.0f);
MAKE_CFGVAR(aim_max_world_dist, 200.0f);

#pragma endregion

#pragma region esp

MAKE_CFGVAR(esp_active, true);

MAKE_CFGVAR(esp_humans_active, true);
MAKE_CFGVAR(esp_humans_name, true);
MAKE_CFGVAR(esp_humans_box, true);
MAKE_CFGVAR(esp_humans_health_bar, true);

#pragma endregion

#pragma region visuals

MAKE_CFGVAR(visuals_fov_override_active, true);
MAKE_CFGVAR(visuals_fov_override_mode, 0); //(0 = set) (1 = add)
MAKE_CFGVAR(visuals_fov_override_set_val, 65.0f);
MAKE_CFGVAR(visuals_fov_override_add_val, 5.0f);

MAKE_CFGVAR(visuals_no_cam_shake, true);

#pragma endregion

#pragma region misc

MAKE_CFGVAR(misc_god_mode, true);
MAKE_CFGVAR(misc_no_ammo_drain, true);
MAKE_CFGVAR(misc_no_shot_delay, true);
MAKE_CFGVAR(misc_no_weapon_spread, true);
MAKE_CFGVAR(misc_force_auto_fire, true);
MAKE_CFGVAR(misc_time_scale_override, 1.0f);

MAKE_CFGVAR(misc_speed_active, true);
MAKE_CFGVAR(misc_speed_key, VK_SHIFT);
MAKE_CFGVAR(misc_speed_amount, 10);

#pragma endregion