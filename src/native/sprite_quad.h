#ifndef VF3_NATIVE_SPRITE_QUAD_H
#define VF3_NATIVE_SPRITE_QUAD_H

#include "motion_aim.h"

/* Native port of 0x8C03F830, the billboard-sprite quad submission, onto
 * `vf3_native_aim`: the flat RAM, the FR bank and the register file.
 *
 * A self-contained FP leaf whose four fixed callees (sin 0x8C03A6E0, cos
 * 0x8C03A140, corner_fan 0x8C03FB10, color_pack 0x8C03FB80) are all already
 * native, so it calls their `vf3_native_*` entry points directly.
 *
 * r4 = sprite object.  Looks the object's sprite index up in the table at
 * 0x0C19E208, scales the four corner offsets by the object's size/rotation
 * (sin/cos of the angle at +28 through the corner fan), packs the 16-bit
 * texture coordinates, patches the sprite's TA header words (entry of 0x20
 * bytes in the table at 0x0C19E214) and pushes header + four vertices
 * through the store queue (3 SQ lines), then advances the SQ cursor kept
 * next to the table at 0x0C16CA08.
 *
 * See docs/re/native_sprite_quad.md.  The original saves r8-r14, FR13-FR15
 * and PR (44 bytes) and a 60 byte frame; the dead stack words are replayed
 * because they are visible in RAM. */
void vf3_native_sprite_quad(vf3_native_aim *a);

#endif
