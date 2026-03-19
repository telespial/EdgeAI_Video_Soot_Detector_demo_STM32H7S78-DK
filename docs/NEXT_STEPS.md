# Next Steps

1. Keep display geometry fixed at portrait across runtime/generator (`480x800`).
2. Stabilize USB1 UVC stream startup in `Appli/Src/usb_host.c`:
   - verify probe/commit values accepted by camera
   - verify selected streaming alt setting is valid
   - confirm first payload packets are received
3. Keep USB1 host-only behavior during webcam tests (no DRD switching).
4. Add concise on-device diagnostics for UVC state and packet count.
5. Re-test webcam on USB1 after each flash and log LED/state result.
6. Once stream is active, map video frame into the intended UI video box region.
7. Record a fresh 120s clean baseline in stable lighting.
8. Capture contamination simulation samples.
9. Run compare/replay and save reports under `outputs/reports`.
10. Tune warn/fail thresholds based on replay output.
