# Architecture

## Objective
Detect optical contamination symptoms (soot, ash, smudge, haze) without a full image classifier.

## System Pipeline
1. Live camera frame capture.
2. Vision feature extraction.
3. Feature stream contract (`features/schema_feature_vector_v1.json`).
4. EIL anomaly/adaptive runtime.
5. Output signals (`anomaly_score`, `alert_state`, `reason_code`).

## Current Implementation Status (2026-03-19)
- Display/UI path is functional.
- USB1 camera power path is functional.
- Live camera frame capture stage is currently blocked by UVC stream activation (camera remains in idle/red LED state).

## Why Feature-Based
- Lower compute and memory footprint than image classifiers.
- Easier to explain and debug.
- Better fit for embedded deployment paths.
- Works with baseline + drift detection flow for demo use.

## Key Runtime Modes
- `modelProfile`: `vision_contamination`
- `inputSource`: `live_camera`
- Fallback synthetic stream should only be used when explicitly enabled.

## Primary Risks
- Lighting drift can look like contamination.
- Motion blur can trigger false anomalies.
- Scene changes can distort baseline comparisons.

## Controls
- Capture baseline in stable conditions.
- Apply minimum-sample windows before alerts.
- Tune thresholds and reason codes after first replay pass.
