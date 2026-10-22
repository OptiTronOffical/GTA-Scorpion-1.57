cmake_minimum_required(VERSION 3.20)
project(gta5_menu_157 C)

# --- Locate OpenOrbis toolchain -------------------------------------------
if(NOT DEFINED ENV{OO_PS4_TOOLCHAIN})
    message(FATAL_ERROR "OO_PS4_TOOLCHAIN not set")
endif()
set(OO_PS4_TOOLCHAIN "$ENV{OO_PS4_TOOLCHAIN}")

include("${OO_PS4_TOOLCHAIN}/cmake/OpenOrbis-PS4-Toolchain.cmake")

# --- Project-wide flags ----------------------------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wno-unused-parameter -O2 -fPIC -fno-strict-aliasing)

# --- Sources ---------------------------------------------------------------
set(SOURCES
    src/main.c
    src/version.c
    src/settings.c
    src/draw.c
    src/input.c
    src/menu.c
    src/submenus.c
)

add_library(gta5menu SHARED ${SOURCES})
target_include_directories(gta5menu PRIVATE include)

# --- Link against PS4 libraries -------------------------------------------
# The game itself provides invoke_native / xprint_text / FloatToU64, so they're
# resolved at runtime via the SPRX loader's extern table.
target_link_libraries(gta5menu
    SceLibcInternal
    SceKernel
    SceSysmodule
    SceNet
    SceNetCtl
)

# --- Generate a PRX from the shared object --------------------------------
find_program(CREATE_FSELF create-fself
    HINTS "${OO_PS4_TOOLCHAIN}/bin/linux" "${OO_PS4_TOOLCHAIN}/bin")

if(CREATE_FSELF)
    add_custom_command(TARGET gta5menu POST_BUILD
        COMMAND ${CREATE_FSELF}
                -in=${CMAKE_CURRENT_BINARY_DIR}/libgta5menu.so
                -out=${CMAKE_CURRENT_BINARY_DIR}/gta5menu.prx
        COMMENT "Packing gta5menu.prx")
endif()
