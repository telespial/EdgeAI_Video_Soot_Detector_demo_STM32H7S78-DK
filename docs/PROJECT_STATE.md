# Project State

Last updated: 2026-03-19

## Status
- Project is now scoped as STMicro-only.
- Target board is locked to `STM32H7S78-DK`.
- Firmware backup was extracted from board flash and saved under `firmware_backups/`.
- Live camera feature capture workflow remains active.
- Display geometry mismatch incident is resolved (see Incident section below).
- USB1 webcam host bring-up remains blocked at streaming stage (camera LED red, no active video).

## Active Bug: USB1 Webcam Streaming Not Starting
Observed behavior:
- USB webcam receives power on USB1.
- Camera status LED stays red (does not indicate active streaming).
- No video appears in-app.

Confirmed progress:
- USB1 power no longer drops after boot.
- Host/device role churn in app flow has been constrained toward host-only behavior.
- Multiple UVC negotiation variants were implemented in `Appli/Src/usb_host.c`, including:
  - Probe/commit handshake sequencing
  - Alternate-setting retries
  - Probe-length fallbacks (`34`/`26`)
  - Endpoint/iso sizing adjustments

Current assessment:
- Power path is working.
- Remaining issue is UVC session negotiation/stream activation compatibility with the connected webcam.

Next debug focus:
1. Add deterministic UVC stage diagnostics in firmware.
2. Validate descriptor-selected format/frame/alt against the actual camera.
3. Confirm first successful isoch/bulk IN payload reception.

## Working Evidence
- ST-LINK communication and SWD target reads succeeded.
- Board backup image saved as:
  - `firmware_backups/stm32h7s78dk_flash_backup_20260317_051950.bin`
- Backup metadata/checksum saved as:
  - `firmware_backups/stm32h7s78dk_flash_backup_20260317_051950.meta.txt`

## Intent for Next Firmware Step
- Implement/verify startup flow:
  1. Show `FUTURE ELECTRONICS FIRE DEMO`
  2. Hold/freeze display state

## Known Gaps
- EmbeddedX to EIL project binding still needs tighter active-project context handling.
- One-command end-to-end launcher is still pending.
- Threshold tuning remains project-specific and should be finalized per demo run.

## Incident: Repeated/Tiled Screen Output (Resolved)
Observed behavior:
- UI/background rendered as repeated tiles (roughly 5 repeats), with unreadable composition.

Technical root cause:
- Runtime display geometry configured as `800x480` while generated TouchGFX screens/assets are `480x800`.
- The mismatch caused incorrect framebuffer interpretation (stride/geometry mismatch) at runtime.

Resolution:
- Updated runtime geometry in:
  - `TouchGFX/target/generated/src/TouchGFXConfiguration.cpp`
  - `TouchGFXHAL hal(..., 480, 800);`
  - `nema_vg_init_stencil_pool(480, 800, 1);`
- Rebuilt firmware and reflashed with verify/reset.

Verification outcome:
- Build: PASS
- Flash: PASS
- Verify: PASS

Prevention:
1. Treat `480x800` as the canonical geometry for this demo branch.
2. Validate runtime geometry after any TouchGFX regeneration.
3. Do not diagnose this symptom by image replacement first; geometry check must come first.

## Next Validation
1. Keep current firmware backup immutable.
2. Confirm display remains single-frame (no tiling) after power cycle.
3. Build/test splash-flow firmware candidate.
4. Flash candidate and verify freeze behavior.
5. If needed, restore from saved backup binary.

- Splash primary text updated in firmware source to `FUTURE ELECTRONICS FIRE DEMO`.
- Added ST board support source clone at `vendor_src/stm32h7s78-dk-bsp/` for local firmware integration work.
