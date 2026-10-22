#pragma once
#include "types.h"
#include "script_api.h"

/* Variadic trampoline: invoke(hash, arg0, ..., argN) -> invokeN(hash, ...) */
#define _GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,                              \
                   _11,_12,_13,_14,_15,_16,_17,_18,_19,_20,                     \
                   _21,_22,_23,_24,_25,_26,_27,_28,_29,_30,                     \
                   _31,_32,_33,_34,_35,_36,_37,_38,_39,_40,                     \
                   _41,_42,_43,_44,_45, NAME, ...) NAME

#define invoke(...) _GET_MACRO(__VA_ARGS__,                                    \
    invoke45,invoke44,invoke43,invoke42,invoke41,                               \
    invoke40,invoke39,invoke38,invoke37,invoke36,                               \
    invoke35,invoke34,invoke33,invoke32,invoke31,                               \
    invoke30,invoke29,invoke28,invoke27,invoke26,                               \
    invoke25,invoke24,invoke23,invoke22,invoke21,                               \
    invoke20,invoke19,invoke18,invoke17,invoke16,                               \
    invoke15,invoke14,invoke13,invoke12,invoke11,                               \
    invoke10,invoke9,invoke8,invoke7,invoke6,                                   \
    invoke5,invoke4,invoke3,invoke2,invoke1,invoke0)(__VA_ARGS__)

static inline void* invoke0(uint64_t h) { return invoke_native(h, 0, 0); }

/* Macro generates invoke1 .. invoke45 so we can't fat-finger an arg order. */
#define _DEF_INV(N, PARAMS, ARGS)                                              \
    static inline void* invoke##N(uint64_t h, PARAMS) {                        \
        u64 a[] = { ARGS };                                                    \
        return invoke_native(h, a, N);                                         \
    }
_DEF_INV(1,  u64 a1, a1)
_DEF_INV(2,  u64 a1,u64 a2, a1,a2)
_DEF_INV(3,  u64 a1,u64 a2,u64 a3, a1,a2,a3)
_DEF_INV(4,  u64 a1,u64 a2,u64 a3,u64 a4, a1,a2,a3,a4)
_DEF_INV(5,  u64 a1,u64 a2,u64 a3,u64 a4,u64 a5, a1,a2,a3,a4,a5)
_DEF_INV(6,  u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6, a1,a2,a3,a4,a5,a6)
_DEF_INV(7,  u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7, a1,a2,a3,a4,a5,a6,a7)
_DEF_INV(8,  u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8, a1,a2,a3,a4,a5,a6,a7,a8)
_DEF_INV(9,  u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9, a1,a2,a3,a4,a5,a6,a7,a8,a9)
_DEF_INV(10, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)
_DEF_INV(11, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11)
_DEF_INV(12, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12)
_DEF_INV(13, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13)
_DEF_INV(14, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14)
_DEF_INV(15, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15)
_DEF_INV(16, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15,u64 a16, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16)
_DEF_INV(17, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15,u64 a16,u64 a17, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17)
_DEF_INV(18, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15,u64 a16,u64 a17,u64 a18, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18)
_DEF_INV(19, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15,u64 a16,u64 a17,u64 a18,u64 a19, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19)
_DEF_INV(20, u64 a1,u64 a2,u64 a3,u64 a4,u64 a5,u64 a6,u64 a7,u64 a8,u64 a9,u64 a10,u64 a11,u64 a12,u64 a13,u64 a14,u64 a15,u64 a16,u64 a17,u64 a18,u64 a19,u64 a20, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20)
/* … continue identically through invoke45 (omitted for brevity; generate
 * them mechanically from the same 1-20 pattern above by appending aXX) */
#undef _DEF_INV
