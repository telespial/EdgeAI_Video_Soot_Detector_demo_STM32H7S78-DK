# Integration Checklist

1. Create/open STM32CubeIDE project for STM32H7S78-DK.
2. Ensure LCD and BSP display drivers initialize successfully.
3. Copy `include/splash_flow.h` and `src/splash_flow.c` into project.
4. Merge `src/main.c` state-flow logic into Cube-generated `main.c`.
5. Implement `board_*` hooks with real HAL/BSP calls.
6. Build and flash.
7. Verify behavior:
   - boot screen: `Life.Augmented`
   - then `Future Electronics`
   - remains frozen.
8. If needed, run `scripts/restore_backup.sh`.
