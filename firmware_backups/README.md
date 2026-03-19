# Firmware Backups

This folder stores board flash backups used as restore points.

Current backup set:
- `stm32h7s78dk_flash_backup_20260317_051950.bin`
- `stm32h7s78dk_flash_backup_20260317_051950.meta.txt`

Do not overwrite existing backups.
Create a new timestamped backup before each major flash change.

## Display Incident Context
- A repeated/tiled screen issue occurred during TouchGFX iteration.
- Root cause was runtime geometry mismatch (`800x480`) vs generated portrait UI (`480x800`), not backup corruption.
- Geometry was corrected and firmware reflashed with verify.

Recovery guidance:
1. Restore known-good firmware image if needed.
2. Confirm runtime geometry is `480x800` in `TouchGFXConfiguration.cpp`.
3. Rebuild and flash with verify/reset.
