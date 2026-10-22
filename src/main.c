#include "natives.h"
#include "menu.h"
#include "input.h"
#include "version.h"
#include "settings.h"

/* Called once by the SPRX loader. */
void main(void) {
    menu_init();
    if (!game_is_1_57()) {
        xprint_text("GTA V 1.57 required — native table not recognised.", 5000);
        return;
    }
    xprint_text("Scorpion V 1.57 loaded. RB + X to open.", 3000);

    for (;;) {
        WAIT(0);

        if (NumMenu == Closed) {
            if (input_menu_toggle_pressed()) menu_open();
        } else {
            menu_frame();
        }
    }
}
