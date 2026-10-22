#pragma once
#include "invoker.h"

/* Curated subset of GTA V natives used by this menu.
 * Hashes are stable across all game versions (joaat of the native name)
 * and are resolved at runtime by invoke_native().
 * Add new natives here in the same format. */

/* ---- SYSTEM ---- */
static void  WAIT(int ms)                       { invoke(0x4EDE34FBADD967A6, ms); }
static int   GET_GAME_TIMER(void)               { return *(int*)invoke(0x9CD27B0045628463); }

/* ---- PAD ---- */
static BOOL  IS_CONTROL_PRESSED(int c,int a)               { return *(BOOL*)invoke(0xF3A21BCD95725A4A, c, a); }
static BOOL  IS_DISABLED_CONTROL_PRESSED(int c,int a)      { return *(BOOL*)invoke(0xE2587F8CBBD87B1D, c, a); }
static BOOL  IS_DISABLED_CONTROL_JUST_PRESSED(int c,int a) { return *(BOOL*)invoke(0x91AEF906BCA88877, c, a); }
static void  SET_INPUT_EXCLUSIVE(int c,int a)              { invoke(0xEDE476E5EE29EDB1, c, a); }
static void  DISABLE_CONTROL_ACTION(int c,int a,BOOL d)    { invoke(0xFE99B66D079CF6BC, c, a, d); }

/* ---- HUD / TEXT ---- */
static void  SET_TEXT_FONT(int f)                     { invoke(0x66E0276CC5F6B9DA, f); }
static void  SET_TEXT_SCALE(float x,float y)          { invoke(0x07C837F9A01C34C9, FloatToU64(x), FloatToU64(y)); }
static void  SET_TEXT_COLOUR(int r,int g,int b,int a) { invoke(0xBE6B23FFA53FB442, r, g, b, a); }
static void  SET_TEXT_CENTRE(BOOL t)                  { invoke(0xC02F4DBFB51D988B, t); }
static void  SET_TEXT_RIGHT_JUSTIFY(BOOL t)           { invoke(0x6B3C4650BC8BEE47, t); }
static void  SET_TEXT_WRAP(float s,float e)           { invoke(0x63145D9C883A1A70, FloatToU64(s), FloatToU64(e)); }
static void  SET_TEXT_DROPSHADOW(int d,int r,int g,int b,int a) { invoke(0x465C84BC39F1C351, d, r, g, b, a); }
static void  SET_TEXT_OUTLINE(void)                   { invoke(0x2513DFB0FB8400FE); }
static void  SET_TEXT_PROPORTIONAL(BOOL t)            { invoke(0x038C1F517D7FDCF8, t); }
static void  BEGIN_TEXT_COMMAND_DISPLAY_TEXT(const char* s) { invoke(0x25FBB336DF1804CB, s); }
static void  END_TEXT_COMMAND_DISPLAY_TEXT(float x,float y,int p) { invoke(0xCD015E5BB0D96A57, FloatToU64(x), FloatToU64(y), p); }
static void  BEGIN_TEXT_COMMAND_SCALEFORM_STRING(const char* s) { invoke(0x80338406F3475E55, s); }
static void  END_TEXT_COMMAND_SCALEFORM_STRING(void)  { invoke(0x362E2D3FE93A9959); }
static void  ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const char* s) { invoke(0x6C188BE134E074AA, s); }
static void  ADD_TEXT_COMPONENT_INTEGER(int v)        { invoke(0x03B504CF259931BC, v); }
static void  ADD_TEXT_COMPONENT_FLOAT(float v,int d)  { invoke(0xE7DCB5B874BCD96E, FloatToU64(v), d); }
static BOOL  DOES_TEXT_LABEL_EXIST(const char* s)     { return *(BOOL*)invoke(0xAC09CA973C564252, s); }
static int   GET_LENGTH_OF_LITERAL_STRING(const char* s) { return *(int*)invoke(0xF030907CCBB8A9FD, s); }

/* ---- GRAPHICS / SCALEFORM ---- */
static int   REQUEST_SCALEFORM_MOVIE(const char* n)   { return *(int*)invoke(0x11FE353CF9733E6F, n); }
static BOOL  HAS_SCALEFORM_MOVIE_LOADED(int h)        { return *(BOOL*)invoke(0x85F01B8D5B90570E, h); }
static void  DRAW_SCALEFORM_MOVIE_FULLSCREEN(int h,int r,int g,int b,int a,int p) { invoke(0x0DF606929C105BE1, h, r, g, b, a, p); }
static BOOL  BEGIN_SCALEFORM_MOVIE_METHOD(int h,const char* m) { return *(BOOL*)invoke(0xF6E48914C7A8694E, h, m); }
static void  END_SCALEFORM_MOVIE_METHOD(void)         { invoke(0xC6796A8FFA375E53); }
static void  SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(int v) { invoke(0xC3D0841A0CC546A6, v); }

static void  DRAW_RECT(float x,float y,float w,float h,int r,int g,int b,int a,int p) { invoke(0x3A618A217E5154F0, FloatToU64(x), FloatToU64(y), FloatToU64(w), FloatToU64(h), r, g, b, a, p); }
static void  DRAW_SPRITE(const char* dict,const char* name,float x,float y,float w,float h,float rot,int r,int g,int b,int a,int p,int p2) { invoke(0xE7FFAE5EBF23D890, dict, name, FloatToU64(x), FloatToU64(y), FloatToU64(w), FloatToU64(h), FloatToU64(rot), r, g, b, a, p, p2); }
static void  SET_SCRIPT_GFX_DRAW_ORDER(int o)         { invoke(0x61BB1D9B3A95D802, o); }
static void  REQUEST_STREAMED_TEXTURE_DICT(const char* n, BOOL p) { invoke(0xDFA2EF8E04127DD5, n, p); }
static BOOL  HAS_STREAMED_TEXTURE_DICT_LOADED(const char* n) { return *(BOOL*)invoke(0x0145F696AAAAD2E4, n); }

/* ---- PLAYER / PED ---- */
static Player PLAYER_ID(void)                         { return *(Player*)invoke(0x4F8644AF03D0E0D6); }
static Ped    PLAYER_PED_ID(void)                      { return *(Ped*)invoke(0xD80958FC74E988A6); }
static Ped    GET_PLAYER_PED(Player p)                 { return *(Ped*)invoke(0x43A66C31C68491C0, p); }
static char*  GET_PLAYER_NAME(Player p)                { return *(char**)invoke(0x6D0DE6A7B5DA71F8, p); }
static BOOL   IS_PED_A_PLAYER(Ped p)                   { return *(BOOL*)invoke(0x12534C348C6CB68B, p); }
static BOOL   IS_PED_IN_ANY_VEHICLE(Ped p,BOOL at)     { return *(BOOL*)invoke(0x997ABD671D25CA0B, p, at); }
static void   SET_PED_INTO_VEHICLE(Ped p,Vehicle v,int s) { invoke(0xF75B0D629E1C063D, p, v, s); }
static void   SET_PED_CAN_SWITCH_WEAPON(Ped p,BOOL t)  { invoke(0xED7F7EFE9FABF340, p, t); }
static void   CLEAR_PED_TASKS(Ped p)                   { invoke(0xE1EF3C1216AFF2CD, p); }
static Vehicle GET_VEHICLE_PED_IS_USING(Ped p)         { return *(Vehicle*)invoke(0x6094AD011A2EA87D, p); }

/* ---- ENTITY ---- */
static BOOL   DOES_ENTITY_EXIST(Entity e)              { return *(BOOL*)invoke(0x7239B21A38F536BA, e); }
static void   SET_ENTITY_VISIBLE(Entity e,BOOL t,BOOL p) { invoke(0xEA1C610A04DB6BBB, e, t, p); }
static void   SET_ENTITY_INVINCIBLE(Entity e,BOOL t)   { invoke(0x3882114BDE571AD4, e, t); }
static void   SET_ENTITY_CAN_BE_DAMAGED(Entity e,BOOL t) { invoke(0x1760FFA8AB074D66, e, t); }
static void   SET_ENTITY_COORDS(Entity e,float x,float y,float z,BOOL a,BOOL b,BOOL c,BOOL d) { invoke(0x06843DA7060A026B, e, FloatToU64(x), FloatToU64(y), FloatToU64(z), a, b, c, d); }
static vector3 GET_ENTITY_COORDS(Entity e,BOOL a)      { return *(vector3*)invoke(0x3FEF770D40960D5A, e, a); }
static void   SET_ENTITY_HEADING(Entity e,float h)     { invoke(0x8E2530AA8ADA980E, e, FloatToU64(h)); }
static float  GET_ENTITY_HEADING(Entity e)             { return *(float*)invoke(0xE83D4F9BA2A38914, e); }
static void   SET_ENTITY_PROOFS(Entity e,BOOL a,BOOL b,BOOL c,BOOL d,BOOL f,BOOL g,BOOL h,BOOL i) { invoke(0xFAEE099C6F890BB8, e, a, b, c, d, f, g, h, i); }
static float  GET_ENTITY_SPEED(Entity e)               { return *(float*)invoke(0xD5037BA82E12416F, e); }
static vector3 GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Entity e,float x,float y,float z) { return *(vector3*)invoke(0x1899F328B0E12848, e, FloatToU64(x), FloatToU64(y), FloatToU64(z)); }
static void   DELETE_ENTITY(Entity* e)                 { invoke(0xAE3CBE5BF394C9C9, e); }
static void   SET_ENTITY_AS_MISSION_ENTITY(Entity e,BOOL a,BOOL b) { invoke(0xAD738C3085FE7E11, e, a, b); }

/* ---- VEHICLE ---- */
static Vehicle CREATE_VEHICLE(Hash m,float x,float y,float z,float h,BOOL n,BOOL s,BOOL p) { return *(Vehicle*)invoke(0xAF35D0D2583051B0, m, FloatToU64(x), FloatToU64(y), FloatToU64(z), FloatToU64(h), n, s, p); }
static void   SET_VEHICLE_FORWARD_SPEED(Vehicle v,float s) { invoke(0xAB54A438726D25D5, v, FloatToU64(s)); }
static void   SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(Vehicle v,BOOL t) { invoke(0x4C7028F78FFD3681, v, t); }
static void   SET_VEHICLE_TYRES_CAN_BURST(Vehicle v,BOOL t) { invoke(0xEB9DC3C7D8596C46, v, t); }
static void   SET_HELI_BLADES_FULL_SPEED(Vehicle v)    { invoke(0xA178472EBB8AE60D, v); }

/* ---- MODEL ---- */
static void   REQUEST_MODEL(Hash m)                    { invoke(0x963D27A58DF860AC, m); }
static BOOL   HAS_MODEL_LOADED(Hash m)                 { return *(BOOL*)invoke(0x98A4EB5D89A0C952, m); }
static void   SET_MODEL_AS_NO_LONGER_NEEDED(Hash m)    { invoke(0xE532F5D78798DAAB, m); }
static void   REQUEST_COLLISION_AT_COORD(float x,float y,float z) { invoke(0x07503F7948F491A7, FloatToU64(x), FloatToU64(y), FloatToU64(z)); }

/* ---- EXPLOSION ---- */
static void   ADD_OWNED_EXPLOSION(Ped p,float x,float y,float z,int t,float d,BOOL a,BOOL i,float c) { invoke(0x172AA1B624FA1013, p, FloatToU64(x), FloatToU64(y), FloatToU64(z), t, FloatToU64(d), a, i, FloatToU64(c)); }

/* ---- NETWORK ---- */
static BOOL   NETWORK_IS_PLAYER_ACTIVE(Player p)       { return *(BOOL*)invoke(0xB8DFD30D6973E135, p); }
static BOOL   NETWORK_IS_SESSION_ACTIVE(void)          { return *(BOOL*)invoke(0xD83C2B94E7508980); }
static int    GET_NUMBER_OF_PLAYERS(void)              { return *(int*)invoke(0x407C7F91DDB46C16); }
static BOOL   NETWORK_PLAYER_HAS_HEADSET(Player p)     { return *(BOOL*)invoke(0x3FB99A8B08D18FD6, p); }
static BOOL   NETWORK_IS_PLAYER_MUTED_BY_ME(Player p)  { return *(BOOL*)invoke(0x8C71288AE68EDE39, p); }
static BOOL   NETWORK_IS_PLAYER_TALKING(Player p)      { return *(BOOL*)invoke(0x031E11F3D447647E, p); }
static void   NETWORK_SET_IN_SPECTATOR_MODE(BOOL t,Ped p) { invoke(0x423DE3854BB50894, t, p); }
static void   NETWORK_SET_OVERRIDE_SPECTATOR_MODE(BOOL t) { invoke(0x70DA3BF8DACD3210, t); }
static int    NETWORK_GET_NETWORK_ID_FROM_ENTITY(Entity e) { return *(int*)invoke(0xA11700682F3AD45C, e); }
static void   NETWORK_REGISTER_ENTITY_AS_NETWORKED(Entity e) { invoke(0x06FAACD625D80CAA, e); }
static void   SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(int id,BOOL t) { invoke(0xE05E81A888FA63C8, id, t); }
static BOOL   NETWORK_REQUEST_CONTROL_OF_ENTITY(Entity e) { return *(BOOL*)invoke(0xB69317BF5E782347, e); }

/* ---- HUD ---- */
static void   HIDE_HUD_COMPONENT_THIS_FRAME(int id)    { invoke(0x6806C51AD12B83B8, id); }
static void   DISPLAY_AMMO_THIS_FRAME(BOOL d)          { invoke(0xA5E78BA2B1331C55, d); }
static void   DISPLAY_RADAR(BOOL t)                    { invoke(0xA0EBB943C300E693, t); }
static void   SET_CINEMATIC_BUTTON_ACTIVE(BOOL t)      { invoke(0x51669F7D1FB53D9F, t); }
static BOOL   IS_PAUSE_MENU_ACTIVE(void)               { return *(BOOL*)invoke(0xB0034A223497FFCB); }
static BOOL   IS_WARNING_MESSAGE_ACTIVE(void)          { return *(BOOL*)invoke(0xE18B138FABC53103); }

/* ---- AUDIO ---- */
static void   PLAY_SOUND_FRONTEND(int id,const char* n,const char* r,BOOL p) { invoke(0x67C540AA08E4A6F5, id, n, r, p); }
