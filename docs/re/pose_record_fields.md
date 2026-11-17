# Pose Record Field Semantics (108-byte kind record at 0x0C10D3C4)

The pose orchestration (0x8C09EAF2) reads kind records from 0x0C10D3C4 using actor byte +0x61 as index with 108-byte stride. Each record contains 27 float fields (108 bytes exactly, 27 * 4 = 108 bytes, no padding).

## Field Organization

Each kind record is organized as 27 consecutive float fields (108 bytes, 27 * 4 = 108 bytes, no padding):

- **Indices 0-5**: Initial parameters, scale factors, configuration values
- **Indices 6-8**: POSE_VECTOR_FIRST (3 floats) - Primary translation/position parameters
- **Indices 9-11**: POSE_VECTOR_SECOND (3 floats) - Secondary position/rotation parameters  
- **Indices 12-14**: Neutral/default values
- **Indices 15-17**: POSE_VECTOR_AIM_B (3 floats) - Aim-specific parameters
- **Indices 18-26**: Y-suppression or other offset parameters

## Specific Field Semantics

### POSE_VECTOR_FIRST (indices 6-8)
Primary position/translation parameters for the actor:
- Index 6: Primary translation parameter (e.g., Y-axis offset, used by aim_frame builders)
- Index 7: Secondary translation/rotation parameter (e.g., Z-axis offset, used by aim_frame builders)
- Index 8: Fine adjustment parameter (small value for fine-tuning, used by aim_frame builders)

**Kind 0 (Akira) example:**
- Index 6: 0.125f (0.125)
- Index 7: 0.16f (0.16)
- Index 8: 0.07f (0.07)  // NOTE: This is the correct value; the doc previously claimed 0.015f (which is actually at index 2)

**Kind 7 (Jacky) example:**
- Index 6: 0.135f (0.135)
- Index 7: 0.185f (0.185)
- Index 8: 0.085f (0.085)

### POSE_VECTOR_SECOND (indices 9-11)
Secondary position/rotation parameters:
- Index 9: Secondary translation parameter
- Index 10: Secondary rotation parameter
- Index 11: Small adjustment/threshold value

**Kind 0 example:**
- Index 9: 0.125f (0.125)
- Index 10: 0.16f (0.16)
- Index 11: 0.07f (0.07)

**Kind 7 example:**
- Index 9: 0.135f (0.135)
- Index 10: 0.185f (0.185)
- Index 11: 0.085f (0.085)

### POSE_VECTOR_AIM_B (indices 15-17)
Aim-specific parameters used by aim_frame builders:
- Index 15: Primary aim parameter (e.g., primary rotation value)
- Index 16: Secondary aim parameter (e.g., secondary rotation)
- Index 17: Large adjustment or range parameter

**Kind 0 example:**
- Index 15: 0.205f
- Index 16: 0.181f
- Index 17: 0.35f

**Kind 7 example:**
- Index 15: 0.195f
- Index 16: 0.18f
- Index 17: 0.345f

### Additional Fields
- **Indices 0-5**: Initial parameters, scale factors, configuration values used early in pose computation
- **Indices 12-14**: Neutral/default values that may serve as fallbacks
- **Indices 18-26**: Y-suppression or other offset parameters that affect vertical positioning or suppression logic

## Usage Context

These fields are read by the pose orchestration (0x8C09EAF2) and passed as parameters to:
1. The aim_frame builders (0x8C09E060 / 0x8C09E6B2)
2. The aim_midpoints function (0x8C09E428)
3. The midpoint_angles function (0x8C09D452)
4. Various other pose-related functions

The fields are used to compute rotations, translations, and other pose-related parameters that ultimately determine how the fighter's model is positioned and animated.

## Raw Image Verification

The following fields were verified against the retail data image:

### Kind 0 (Akira) - 108-byte record:
- **Indices 0-5** (bytes 0-20): 0.25f, 0.065f, 0.015f, 0.0f, 0.0f, 0.125f
- **Indices 6-8** (bytes 24-32): 0.125f, 0.16f, 0.07f
- **Indices 9-11** (bytes 36-44): 0.125f, 0.16f, 0.07f
- **Indices 12-14** (bytes 48-56): 0.0f, 0.0f, 0.0f
- **Indices 15-17** (bytes 60-68): 0.205f, 0.181f, 0.35f
- **Indices 18-26** (bytes 72-104): -0.055f, -0.073f, -0.16f, 0.205f, 0.181f, 0.35f, -0.055f, -0.073f, -0.16f

### Kind 7 (Jacky) - 108-byte record:
- **Indices 0-5** (bytes 0-20): 0.27f, 0.075f, 0.01f, 0.025f, 0.0f, 0.18f
- **Indices 6-8** (bytes 24-32): 0.135f, 0.185f, 0.085f
- **Indices 9-11** (bytes 36-44): 0.135f, 0.185f, 0.085f
- **Indices 12-14** (bytes 48-56): 0.0f, 0.0f, -0.03f
- **Indices 15-17** (bytes 60-68): 0.195f, 0.18f, 0.345f
- **Indices 18-26** (bytes 72-104): -0.052f, -0.085f, -0.19f, 0.195f, 0.18f, 0.345f, -0.052f, -0.085f, -0.19f

### Kind 12 - 108-byte record (for reference):
- **Indices 0-5** (bytes 0-20): 0.34f, 0.06f, 0.0f, 0.035f, 0.0f, 0.12f
- **Indices 6-8** (bytes 24-32): 0.12f, 0.19f, 0.125f
- **Indices 9-11** (bytes 36-44): 0.12f, 0.19f, 0.125f
- **Indices 12-14** (bytes 48-56): 0.0f, 0.0f, -0.09f
- **Indices 15-17** (bytes 60-68): 0.23f, 0.18f, 0.335f
- **Indices 18-26** (bytes 72-104): -0.05f, -0.065f, -0.24f, 0.23f, 0.18f, 0.335f, -0.05f, -0.065f, -0.24f

## Notes

- All fields are stored as IEEE 754 32-bit floating-point values in the exact order shown
- The record layout is a flat array; there are no gaps or padding between fields
- Field indices refer to the float index within the 108-byte record (not byte offset)
- Field semantics are interpretations of the values; the actual usage in the game code may vary