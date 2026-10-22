#pragma once
#include "types.h"

/* one UI entry point */
void draw_menu_background(int maxOptions);
void draw_menu_header(const char* title);
void draw_menu_scroller(int selected, int maxOptions);
void draw_menu_option_text(const char* text, int idx, int font, float x);
void draw_checkbox(int idx, BOOL value);
void draw_text(const char* text, int font, float x, float y, float sx, float sy, int r, int g, int b, int a, BOOL center);
void draw_text_right(const char* text, float wrap_x, int idx);

extern int options[64];
extern int optionsFont;
