# Scorpion V — GTA V 1.57 (PS4 SPRX)

Clean-room reimplementation of the Scorpion V menu, retargeted at
**GTA V PS4 CUSA00411 v1.57**.

## Build (local)

1. Install the [OpenOrbis PS4 toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain).
2. Export `OO_PS4_TOOLCHAIN=/path/to/toolchain`.
3. Run:
   ```bash
   cmake -B build
   cmake --build build
