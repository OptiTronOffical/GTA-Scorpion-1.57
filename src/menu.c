#include "menu.h"
#include "draw.h"
#include "input.h"
#include "natives.h"
#include "settings.h"
#include <string.h>

int NumMenu = Closed;
int NumMenuLevel = 0;
int currentOption = 1;
int optionCount = 0;
int maxOptions = 12;

int menuStack[16];
int optionStack[16];

static BOOL option_pressed;
static BOOL left_pressed, right_pressed;

/* ---- navigation ---------------------------------------------------- */

void menu_init(void) {
    NumMenu = Closed;
    NumMenuLevel = 0;
    currentOption = 1;
    optionCount = 0;
}

void menu_open(void) {
    NumMenu = Main_Menu;
    NumMenuLevel = 0;
    currentOption = 1;
    menuStack[0] = Closed;
    optionStack[0] = 1;
}

void menu_close(void) {
    NumMenu = Closed;
    NumMenuLevel = 0;
    currentOption = 1;
}

void menu_enter(int submenu) {
    if (NumMenuLevel + 1 >= 16) return;
    menuStack[NumMenuLevel] = NumMenu;
    optionStack[NumMenuLevel] = currentOption;
    NumMenuLevel++;
    NumMenu = submenu;
    currentOption = 1;
}

void menu_back(void) {
    if (NumMenuLevel == 0) { menu_close(); return; }
    NumMenuLevel--;
    NumMenu = menuStack[NumMenuLevel];
    currentOption = optionStack[NumMenuLevel];
}

/* ---- input --------------------------------------------------------- */

static void menu_read_input(void) {
    option_pressed = IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_ACCEPT);
    left_pressed   = IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT);
    right_pressed  = IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT);

    if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_CANCEL)) {
        menu_back();
        return;
    }
    if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_UP)) {
        currentOption--;
        if (currentOption < 1) currentOption = optionCount ? optionCount : 1;
    }
    if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_DOWN)) {
        currentOption++;
        if (currentOption > optionCount) currentOption = 1;
    }
}

/* ---- rendering helpers -------------------------------------------- */

void subtitle(const char* text) {
    draw_text(text, 0, 0.045f, 0.1465f, 0.51f, 0.51f, 255, 255, 255, 200, FALSE);
}

BOOL option(const char* text) {
    optionCount++;
    draw_menu_option_text(text, optionCount, options[optionsFont], 0.045f);
    return (currentOption == optionCount && option_pressed);
}

BOOL checkbox(const char* text, BOOL* value) {
    BOOL pressed = option(text);
    if (pressed) *value = !*value;
    draw_checkbox(optionCount, *value);
    return pressed;
}

BOOL int_slider(const char* text, int* value, int min, int max) {
    optionCount++;
    char buf[64];
    int n = snprintf(buf, sizeof(buf), "%d", *value);
    (void)n;
    draw_menu_option_text(text, optionCount, options[optionsFont], 0.045f);
    draw_text_right(buf, 0.245f, optionCount);
    if (currentOption == optionCount) {
        if (left_pressed)  { if (*value <= min) *value = max; else (*value)--; }
        if (right_pressed) { if (*value >= max) *value = min; else (*value)++; }
        return option_pressed;
    }
    return FALSE;
}

BOOL submenu_option(const char* text, int next) {
    BOOL pressed = option(text);
    if (pressed) menu_enter(next);
    return pressed;
}

/* ---- frame --------------------------------------------------------- */

void menu_frame(void) {
    /* block game controls while the menu is open */
    DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_CANCEL, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_LEFT, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RIGHT, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_DOWN, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_UP, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_UP, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_DOWN, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_LEFT, 1);
    DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_RIGHT, 1);
    SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_ACCEPT);
    SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
    SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_UP);
    SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_DOWN);

    menu_read_input();

    if (IS_PAUSE_MENU_ACTIVE() || IS_WARNING_MESSAGE_ACTIVE()) {
        menu_close();
        return;
    }

    optionCount = 0;
    draw_menu_background(maxOptions);

    extern void dispatch_submenu(int id);
    dispatch_submenu(NumMenu);

    draw_menu_header(g_settings.submenu_title);
    draw_menu_scroller(currentOption, maxOptions);
}
