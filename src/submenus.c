#include "submenus.h"
#include "settings.h"
#include "natives.h"
#include <stdio.h>

void dispatch_submenu(int id) {
    switch (id) {
        case Main_Menu:        submenu_main();     break;
        case Self_Options:     submenu_self();     break;
        case Vehicle_Spawner:  submenu_spawner();  break;
        case Network_Options:  submenu_network();  break;
        case Settings:         submenu_settings(); break;
    }
}

void submenu_main(void) {
    subtitle("Scorpion V — 1.57");
    submenu_option("Self Options",     Self_Options);
    submenu_option("Vehicle Spawner",  Vehicle_Spawner);
    submenu_option("Network Options",  Network_Options);
    submenu_option("Settings",         Settings);
    option("Close Menu");
    if (currentOption == optionCount) menu_close();
}

void submenu_self(void) {
    subtitle("Self Options");
    Ped me = PLAYER_PED_ID();

    if (checkbox("Godmode", &g_settings.godmode))
        SET_ENTITY_INVINCIBLE(me, g_settings.godmode);

    if (checkbox("Invisible", &g_settings.invisible))
        SET_ENTITY_VISIBLE(me, !g_settings.invisible, 0);

    checkbox("Never Wanted", &g_settings.never_wanted);

    if (int_slider("Spawn Vehicle Hash", (int*)&g_settings.spawn_vehicle_hash, 0x1, 0x7FFFFFFF))
        SET_MODEL_AS_NO_LONGER_NEEDED(g_settings.spawn_vehicle_hash);
}

void submenu_spawner(void) {
    subtitle("Vehicle Spawner");
    if (option("Spawn Adder")) {
        Ped me = PLAYER_PED_ID();
        Hash m = 0xB779A091;
        REQUEST_MODEL(m);
        int timer = GET_GAME_TIMER() + 1500;
        while (!HAS_MODEL_LOADED(m) && GET_GAME_TIMER() < timer) WAIT(0);
        if (HAS_MODEL_LOADED(m)) {
            vector3 c = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(me, 0.0f, 5.0f, 0.0f);
            Vehicle v = CREATE_VEHICLE(m, c.x, c.y, c.z, GET_ENTITY_HEADING(me), TRUE, FALSE, FALSE);
            SET_PED_INTO_VEHICLE(me, v, -1);
            SET_MODEL_AS_NO_LONGER_NEEDED(m);
        }
    }
    if (option("Spawn Buzzard")) {
        Ped me = PLAYER_PED_ID();
        Hash m = 0x2F03547B;
        REQUEST_MODEL(m);
        int timer = GET_GAME_TIMER() + 1500;
        while (!HAS_MODEL_LOADED(m) && GET_GAME_TIMER() < timer) WAIT(0);
        if (HAS_MODEL_LOADED(m)) {
            vector3 c = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(me, 0.0f, 8.0f, 0.0f);
            Vehicle v = CREATE_VEHICLE(m, c.x, c.y, c.z, GET_ENTITY_HEADING(me), TRUE, FALSE, FALSE);
            SET_PED_INTO_VEHICLE(me, v, -1);
            SET_HELI_BLADES_FULL_SPEED(v);
            SET_MODEL_AS_NO_LONGER_NEEDED(m);
        }
    }
}

void submenu_network(void) {
    subtitle("Network");
    if (!NETWORK_IS_SESSION_ACTIVE()) {
        option("Not in session");
        return;
    }
    int n = GET_NUMBER_OF_PLAYERS();
    char buf[64];
    for (int i = 0; i < n && i < 16; i++) {
        if (!NETWORK_IS_PLAYER_ACTIVE(i)) continue;
        snprintf(buf, sizeof(buf), "[%d] %s", i, GET_PLAYER_NAME(i));
        option(buf);
    }
}

void submenu_settings(void) {
    subtitle("Settings");
    option("Save Config");
    option("Load Config");
    option("About");
}
