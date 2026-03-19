# STM32H7S78-DK Firmware Module

This module defines the startup display behavior for the Soot Detector demo:

1. Show `FUTURE ELECTRONICS FIRE DEMO`
2. Freeze on that text

## Files
- `include/splash_flow.h`: splash state machine interface.
- `src/splash_flow.c`: splash state machine implementation.
- `src/main.c`: integration skeleton with board hook functions.

## Integration Notes
- Replace the `board_*` functions in `src/main.c` with STM32CubeIDE BSP/LCD APIs.
- Keep `freeze_enabled=true` to hold the `Future Electronics` display indefinitely.

## Restore Safety
If test firmware fails, restore board image from:
- `../../firmware_backups/stm32h7s78dk_flash_backup_20260317_051950.bin`
