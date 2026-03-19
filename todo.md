# USB Webcam Fix TODO (STM32H7S78-DK)

## Scope and Guardrails
1. Keep board target fixed to `STM32H7S78-DK`.
2. Keep display geometry locked to `480x800`.
3. Keep firmware backup immutable and preserve restore path before major flash changes.
4. Keep USB1 in host-only mode during webcam bring-up (no DRD switching).

## Phase 1: Remove likely descriptor-limit blocker
1. Update USB host config limits in:
   - `firmware/STM32H7S78-DK-USB-Demo-Source/Projects/STM32H7S78-DK/Applications/USBPD/USBPD_DRP_DRD/Appli/Inc/usbh_conf.h`
2. Increase:
   - `USBH_MAX_SIZE_CONFIGURATION` (currently `256U`)
   - `USBH_MAX_NUM_INTERFACES` (currently `2U`)
   - `USBH_MAX_NUM_ENDPOINTS` (currently `2U`)
3. Rationale:
   - UVC webcams often expose larger config descriptors and many alternate settings/endpoints.
   - Current host parser clamps descriptor length and parse limits in middleware, which can truncate camera capability parsing.

## Phase 2: Add deterministic UVC diagnostics in `usb_host.c`
1. Add compact stage diagnostics for each state transition:
   - `GET_PROBE`, `SET_PROBE`, `SET_COMMIT`, `SET_INTERFACE`, `READY`, `FAILED`.
2. Record and expose:
   - active candidate index / count
   - selected interface/alt/endpoint/type/mps
   - probe length and key negotiated fields
   - control transfer return status
   - RX packet/byte counters and timeout count
3. Keep logs concise and stable so each flash/test cycle is comparable.

## Phase 3: Tighten UVC negotiation behavior
1. Keep camera-returned probe values after `GET_PROBE`, override only required fields.
2. Use deterministic candidate order for streaming alt trials.
3. Keep one fallback path for probe length (`34 -> 26`) to reduce noisy retry branches.
4. On each failure stage, emit exact fail reason before candidate rollover.

## Phase 4: Streaming success gate and test loop
1. Rebuild and flash firmware.
2. Perform USB1 validation after each flash:
   - reset board
   - connect webcam on USB1
   - wait 10 seconds
   - record LED state + stream status
3. Declare pass only when all are true:
   - `SET_INTERFACE` succeeds
   - first non-zero IN payload received
   - RX counters increment continuously for at least 10 seconds
   - camera exits idle red LED state
4. If timeout/failure, auto-advance candidate and retry with diagnostics.

## Phase 5: Post-unblock integration
1. Route active video frame into intended UI video box region.
2. Re-run baseline capture workflow:
   - fresh 120s clean baseline
   - contamination sample capture
   - compare/replay report generation under `outputs/reports`
3. Tune alert thresholds based on replay output.

## Verification Checklist
1. USB1 VBUS remains stable throughout test.
2. No host/device role churn while webcam is attached.
3. UVC state machine reaches `READY` with sustained RX traffic.
4. UI remains operational and geometry remains `480x800`.
