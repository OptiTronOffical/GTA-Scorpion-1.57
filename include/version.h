#pragma once
#include "types.h"

#define GTA_V_VERSION_MAJOR 1
#define GTA_V_VERSION_MINOR 57

/* Returns TRUE only if the runtime native table resolves the sentinel hashes
 * we use to sanity-check the loaded eboot. Called once at startup. */
BOOL game_is_1_57(void);
