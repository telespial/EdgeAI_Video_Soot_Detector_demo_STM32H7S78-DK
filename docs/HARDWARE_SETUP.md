# Hardware Setup

- Vendor: STMicroelectronics
- Board: `STM32H7S78-DK`
- Debug probe: ST-LINK (on-board)
- Typical interface: SWD
- Restore/flash utility: `STM32_Programmer_CLI`
- Active webcam test port: USB1 (host path)

Reference artifacts:
- Backup binaries: `firmware_backups/`
- Board firmware source base: `../../MRD_Studio/sources/cache/stmicroelectronics/examples/soot_detector_st_demo/STM32H7S78-DK-USB-Demo-Source/`

Current webcam bug note:
- Webcam powers on USB1 but remains in red-LED idle state (stream not active yet).
