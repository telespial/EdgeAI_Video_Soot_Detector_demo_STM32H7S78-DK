# Implementation Plan

## Phase 1: Firmware Splash Control (Completed)
- Add startup state machine for display flow.
- Preserve board restore backup.
- Keep board target fixed to STM32H7S78-DK.
- Lock portrait display geometry (`480x800`) across generated and runtime layers.

Exit criteria:
- Splash state machine integrated into CubeIDE firmware.
- No repeated/tiled display artifacts after flash and power cycle.
- Startup flow verified on device.

## Phase 1.5: USB1 Webcam Host Bring-Up (Current)
- Keep board path fixed to USB1 host mode for camera tests.
- Stabilize UVC negotiation and stream activation in `usb_host.c`.
- Capture deterministic diagnostics for handshake stage and packet ingress.

Exit criteria:
- Webcam transitions from idle/red LED to active streaming state.
- First valid payload packets received and counted in firmware.
- Video can be routed to UI video region for display integration.

## Phase 2: Vision Feature Capture
- Confirm live camera ingest.
- Maintain stable feature schema.
- Record clean baseline window.

Exit criteria:
- Live feature CSV generated.
- Schema fields match runtime expectations.

## Phase 3: EIL Integration
- Keep EIL config in `vision_contamination` profile.
- Use anomaly/adaptive mode for scoring.
- Validate config and run diagnostics.

Exit criteria:
- Model config validates.
- Runtime produces score and reason code outputs.

## Phase 4: Demo Stabilization
- Run compare/replay on project data.
- Emit reports to `outputs/reports`.
- Lock thresholds for repeatable demonstration behavior.

Exit criteria:
- Repeatable clean-vs-contaminated output.
- Stable alert behavior with documented thresholds.
