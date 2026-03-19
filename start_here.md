# Start Here (Soot Detector)

Project onboarding for `/projects/soot_detector`.

Read in this order:
1. `README.md`
2. `docs/START_HERE.md`
3. `docs/PROJECT_STATE.md`
4. `docs/NEXT_STEPS.md`
5. `docs/OPS_RUNBOOK.md`
6. `docs/HARDWARE_SETUP.md`

Notes:
- This project is scoped to `STM32H7S78-DK`.
- Treat `480x800` as the canonical TouchGFX runtime geometry.
- Keep restore safety in mind before any firmware flash operation.
- Current active blocker is USB1 webcam streaming (camera powered, LED red, no video stream).
