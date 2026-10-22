#include "draw.h"
#include "natives.h"
#include <stdio.h>
#include <string.h>

int optionsFont = 0;
int options[64] = {0};

static const float ROW_Y0 = 0.165f;
static const float ROW_H  = 0.0320f;
static const float MENU_X = 0.154f;
static const float MENU_W = 0.2250f;
static const float OPT_H  = 0.0300f;

static void ensure_texture(const char* name) {
    if (!HAS_STREAMED_TEXTURE_DICT_LOADED(name))
        REQUEST_STREAMED_TEXTURE_DICT(name, FALSE);
}

void draw_menu_background(int max) {
    ensure_texture("commonmenu");
    SET_SCRIPT_GFX_DRAW_ORDER(2);
    for (int i = 0; i < max; i++) {
        float y = ROW_Y0 + i * ROW_H;
        DRAW_RECT(MENU_X, y, MENU_W, OPT_H, 0, 0, 0, 140, 0);
    }
}

void draw_menu_header(const char* title) {
    SET_SCRIPT_GFX_DRAW_ORDER(2);
    DRAW_RECT(MENU_X, 0.1465f, MENU_W, 0.0345f, 0, 0, 0, 200, 0);
    draw_text(title, 0, 0.045f, 0.1385f, 0.51f, 0.51f, 255, 255, 255, 255, FALSE);
}

void draw_menu_scroller(int selected, int max) {
    int row = selected <= max ? selected : max;
    SET_SCRIPT_GFX_DRAW_ORDER(4);
    DRAW_RECT(MENU_X, ROW_Y0 + (row - 1) * ROW_H, MENU_W, OPT_H, 255, 255, 255, 150, 0);
}

void draw_menu_option_text(const char* text, int idx, int font, float x) {
    BOOL selected = (idx == 0);  /* caller overrides via re-render */
    (void)selected; (void)font;
    float y = ROW_Y0 + (idx - 1) * ROW_H - OPT_H * 0.5f + OPT_H * 0.5f;
    draw_text(text, optionsFont, x, y - 0.006f, 0.33f, 0.33f, 255, 255, 255, 255, FALSE);
}

void draw_checkbox(int idx, BOOL v) {
    ensure_texture("commonmenu");
    SET_SCRIPT_GFX_DRAW_ORDER(11);
    float y = ROW_Y0 + (idx - 1) * ROW_H;
    DRAW_SPRITE("commonmenu", v ? "shop_box_tick" : "shop_box_blank",
                0.2450f, y, 0.030f, 0.040f, 0.0f,
                255, 255, 255, 255, 0, 0);
}

void draw_text(const char* text, int font, float x, float y,
               float sx, float sy, int r, int g, int b, int a, BOOL center)
{
    SET_TEXT_FONT(font);
    SET_TEXT_SCALE(sx, sy);
    SET_TEXT_COLOUR(r, g, b, a);
    SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
    if (center) SET_TEXT_CENTRE(TRUE);
    BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
    END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
    SET_TEXT_WRAP(0.0f, 1.0f);
}

void draw_text_right(const char* text, float wrap_x, int idx) {
    float y = ROW_Y0 + (idx - 1) * ROW_H - 0.006f;
    SET_TEXT_FONT(optionsFont);
    SET_TEXT_SCALE(0.33f, 0.33f);
    SET_TEXT_COLOUR(255, 255, 255, 255);
    SET_TEXT_DROPSHADOW(2, 0, 0, 0, 255);
    SET_TEXT_RIGHT_JUSTIFY(TRUE);
    SET_TEXT_WRAP(0.1f, wrap_x);
    BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
    END_TEXT_COMMAND_DISPLAY_TEXT(wrap_x, y, 0);
}
