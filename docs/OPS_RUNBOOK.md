# Operations Runbook

## Scope
- Board: `STM32H7S78-DK`
- Firmware work area: `firmware/STM32H7S78-DK-USB-Demo-Source/`
- Splash-flow module: `firmware/stm32h7s78dk/`
- Active bug work area: `Projects/STM32H7S78-DK/Applications/USBPD/USBPD_DRP_DRD/Appli/Src/usb_host.c`

## Quick Commands
- Restore known-good backup image:
  - `bash firmware/stm32h7s78dk/scripts/restore_backup.sh`
- Restore a specific backup image:
  - `bash firmware/stm32h7s78dk/scripts/restore_backup.sh firmware_backups/<backup>.bin`

## Flash Tooling
- Primary CLI expected by restore script:
  - `STM32_Programmer_CLI`
- Connection mode used by restore script:
  - `port=SWD mode=UR reset=HWrst`

## Firmware Integration Flow
1. Open/create STM32CubeIDE project for `STM32H7S78-DK`.
2. Integrate `firmware/stm32h7s78dk/include/splash_flow.h` and `firmware/stm32h7s78dk/src/splash_flow.c`.
3. Merge state-flow logic from `firmware/stm32h7s78dk/src/main.c`.
4. Implement `board_*` hooks with BSP/HAL LCD/time calls.
5. Build and flash candidate firmware.
6. Verify startup display behavior and frozen hold.

## Geometry Safety Check (Before Flash)
1. Generated screens are `480x800`.
2. `TouchGFXHAL` runtime geometry is `480x800`.
3. Nema stencil pool init is `480x800`.
4. Rebuild clean and flash with verify.

## USB Webcam Bug Snapshot (2026-03-19)
- Port under test: USB1 (host path)
- Current symptom: camera LED remains red, no active stream
- Confirmed fixed: USB1 VBUS no longer drops at boot
- Current focus: UVC handshake/session activation compatibility

Quick verification after flash:
1. Reset board.
2. Connect webcam on USB1.
3. Wait 10 seconds.
4. Record LED state and whether video appears.

## Related Docs
- `docs/PROJECT_STATE.md`
- `docs/NEXT_STEPS.md`
- `firmware/stm32h7s78dk/docs/INTEGRATION_CHECKLIST.md`
- `firmware_backups/README.md`
