# Features

This folder contains numeric feature streams derived from frame input.

## Structure
- `raw/`: frame-level feature rows from live capture or replay.
- `windows/`: optional aggregated windows for smoothing/alerts.
- `schema_feature_vector_v1.json`: feature contract.

## Notes
- Live capture CSVs are timestamped.
- Use baseline-first capture before running anomaly scoring.
- Keep schema updates backward-compatible for replay tooling.
