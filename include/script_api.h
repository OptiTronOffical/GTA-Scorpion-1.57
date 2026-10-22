#pragma once
#include "types.h"

/* These three are provided by the game (or the SPRX loader) at runtime.
 * They are never defined inside this project. */
extern void  xprint_text(const char* str, int ms);
extern void* invoke_native(uint64_t hash, const uint64_t* args, int argc);
extern u64   FloatToU64(float f);
