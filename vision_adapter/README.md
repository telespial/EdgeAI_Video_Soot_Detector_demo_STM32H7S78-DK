# Vision Adapter

The vision adapter converts camera/image/video frames into numeric feature vectors.

## Expected Input
- Live webcam stream (primary demo path).
- Optional image/video replay sources.

## Output
- CSV rows compatible with `../features/schema_feature_vector_v1.json`.

## Runtime Requirements
- Python runtime used by EIL tools.
- OpenCV (`cv2`) available in the active environment for camera mode.

## Behavior
- In normal demo mode, missing OpenCV/camera should raise a clear error.
- Synthetic fallback should only run if explicitly enabled for testing.
