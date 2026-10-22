#include "input.h"
#include "natives.h"
#include "enums.h"

BOOL input_menu_toggle_pressed(void) {
    static int cooldown = 0;
    int now = GET_GAME_TIMER();
    if (now < cooldown) return FALSE;

    if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB) &&
        IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_X)) {
        cooldown = now + 250;
        return TRUE;
    }
    return FALSE;
}
