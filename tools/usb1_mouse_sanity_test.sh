#!/usr/bin/env bash
set -euo pipefail

ROOT="/home/user/python_projects/EmbeddedX/MRD_Studio/sources/cache/stmicroelectronics/examples/soot_detector_st_demo/STM32H7S78-DK-USB-Demo-Source/Projects/STM32H7S78-DK/Applications/USBPD/USBPD_DRP_DRD"
BUILD_DIR="$ROOT/STM32CubeIDE/Appli/Debug"
BIN="$BUILD_DIR/USBPD_DRP_DRD_Appli.bin"
LOADER="/usr/local/STMicroelectronics/STM32Cube/STM32CubeProgrammer/api/lib/ExternalLoader/MX66UW1G45G_STM32H7S78-DK.stldr"

log() { printf "\n[%s] %s\n" "USB1-TEST" "$*"; }

log "Building firmware..."
make -C "$BUILD_DIR" all -j4

if [[ ! -f "$BIN" ]]; then
  echo "ERROR: binary not found: $BIN" >&2
  exit 1
fi

log "Flashing firmware..."
STM32_Programmer_CLI \
  -c port=SWD mode=UR reset=HWrst \
  -el "$LOADER" \
  -w "$BIN" 0x70000000 -v

log "Mouse-only sanity checklist"
echo "1) Plug USB mouse into STM32H7 USB1 port."
echo "2) Wait 5-10 seconds."
echo "3) Move/click mouse for 10 seconds."
echo "4) Observe LCD and tell Codex what changed (if anything)."
echo

echo "Expected for host sanity pass: some visible UI reaction to HID host-active path."
echo "If no change at all, USB1 host path is still not validated in this app context."
