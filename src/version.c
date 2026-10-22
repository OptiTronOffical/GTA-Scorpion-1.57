#include "version.h"
#include "script_api.h"

BOOL game_is_1_57(void) {
    static int cached = -1;
    if (cached < 0) {
        void* pWait = invoke_native(0x4EDE34FBADD967A6ULL, 0, 0);
        void* pPed  = invoke_native(0xD80958FC74E988A6ULL, 0, 0);
        cached = (pWait && pPed) ? 1 : 0;
    }
    return cached == 1;
}
