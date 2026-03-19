# Start Here

This file is the canonical onboarding entrypoint for this project.

Read in this order:
1. `README.md`
2. `docs/PROJECT_STATE.md`
3. `docs/PLAN.md`
4. `docs/NEXT_STEPS.md`
5. `docs/OPS_RUNBOOK.md`
6. `docs/HARDWARE_SETUP.md`
7. `firmware/stm32h7s78dk/docs/INTEGRATION_CHECKLIST.md`

Guardrails:
- Do not change board target: `STM32H7S78-DK`.
- Keep display geometry portrait at runtime and generated layers: `480x800`.
- Keep firmware backups immutable; create a new timestamped backup before major flash changes.
- Use project-local paths and scripts only.
- Current blocker priority: USB1 webcam stream activation (camera LED red, no video).
