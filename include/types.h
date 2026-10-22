#pragma once

typedef unsigned long long uintptr_t;

/* NOTE: on PS4 (LP64) 'long' is 8 bytes and 'int' is 4. The previous
 * project incorrectly typedef'd uint32_t = unsigned long long, which
 * silently broke every hash and every 32-bit RVA. */
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef unsigned long long uint64_t;

typedef signed char    int8_t;
typedef short          int16_t;
typedef int            int32_t;
typedef long long      int64_t;

typedef unsigned int   DWORD;
typedef unsigned char  BYTE;
typedef unsigned char  byte;

typedef char           BOOL;
typedef char           bool;
typedef float          FLOAT;
typedef unsigned int   Hash;
typedef int            Any;
typedef int            Entity;
typedef int            Player;
typedef int            Ped;
typedef int            Vehicle;
typedef int            Object;
typedef int            Pickup;
typedef int            Blip;
typedef int            Cam;
typedef int            Interior;
typedef int            FireId;
typedef int            ScrHandle;
typedef void*          Void;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

/* RAGE script vector3 has interleaved 8-byte stride. */
typedef struct { float x, _padX, y, _padY, z, _padZ; } vector3;
