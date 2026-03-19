#!/usr/bin/env bash
set -euo pipefail

BIN_PATH="${1:-$(dirname "$0")/../../../firmware_backups/stm32h7s78dk_flash_backup_20260317_051950.bin}"

if [[ ! -f "$BIN_PATH" ]]; then
  echo "Backup binary not found: $BIN_PATH" >&2
  exit 1
fi

STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -w "$BIN_PATH" 0x08000000 -v
