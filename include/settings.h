#pragma once
#include "types.h"

typedef struct {
    BOOL godmode;
    BOOL invisible;
    BOOL never_wanted;
    BOOL super_run;
    int  spawn_vehicle_hash;
    char submenu_title[64];
} MenuSettings;

extern MenuSettings g_settings;
