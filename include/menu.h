#pragma once
#include "types.h"
#include "enums.h"

/* Shared menu state — one instance for the process. */
extern int NumMenu;
extern int NumMenuLevel;
extern int currentOption;
extern int optionCount;
extern int maxOptions;

extern int menuStack[16];
extern int optionStack[16];

/* Lifecycle */
void menu_init(void);
void menu_frame(void);     /* called from main loop while NumMenu != Closed */

/* Navigation */
void menu_open(void);                    /* NumMenu = Main_Menu */
void menu_close(void);                   /* NumMenu = Closed  */
void menu_enter(int submenu);            /* push current, switch */
void menu_back(void);                    /* pop */

/* Rendering helpers used by submenus */
void subtitle(const char* text);
BOOL option(const char* text);           /* returns TRUE if selected */
BOOL checkbox(const char* text, BOOL* value);
BOOL int_slider(const char* text, int* value, int min, int max);
BOOL submenu_option(const char* text, int next);
