/* scene_link.c - 0x8C0B1A46  run a scene pass for one list node and advance the caller's cursor.
 *
 *   r4 = object, r5 = list node, r6 -> cursor (a node pointer), r7 = pass argument, [sp] = mode (1, 5, 9, 11,
 *   13, 14, 16 or 17; others take the default paths). Frame: one word, the pass argument.
 *
 *   The pass starts with 0x8C03C4F0 (r4 = 0) and 0x8C03BD80 (r4 = the pass argument). Modes 1, 5, 9, 14 and 17
 *   then hand a field of the object to the hook at 0x8C0A7662 (the field offsets are 0x70, 0x80, 0x90, 0xA4 and
 *   0xB0); any other mode runs 0x8C0A76EC (FR4 = 1.0, r4 = node) when the node's second word is set.
 *
 *   The cursor is then advanced by mode: 1 stores node+48; 5 and 9 reload the cursor and store that node's +48;
 *   11 steps node to its +44 link (if any) and stores its +48; 13 reloads the cursor; 14, 16 and 17 leave it; the
 *   others step the node to its +44 link when there is one. The pass ends with 0x8C03C4A0 (r4 = 1) and returns
 *   the node. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 20, FRAME = 4, ONE = 0x3F800000u, HOOK = 0x0C0A7662u };

static int field_offset(uint32_t mode)
{
    switch (mode) {
    case 1:  return 0x70;
    case 5:  return 0x80;
    case 9:  return 0x90;
    case 14: return 0xA4;
    case 17: return 0xB0;
    default: return -1;
    }
}

int vf3_scene_link_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[4] = { R(14), R(13), R(12), R(11) };
    static const int pushed[4] = { 14, 13, 12, 11 };

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 20, pr0);
    R(14) = R(5); R(13) = R(4); R(11) = R(6);
    R(15) = f;
    w32(ram, f, R(7));
    const uint32_t mode = m32(ram, f + 24);

    R(4) = 0;
    if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C0B1A60u)) return 0;
    R(15) = f;
    R(4) = m32(ram, f);
    if (!vf3_guest_call(s, ram, 0x8C03BD80u, 0x8C0B1A66u)) return 0;
    R(15) = f;

    R(12) = HOOK;
    const int off = field_offset(mode);
    if (off >= 0) {
        R(0) = (uint32_t)off;
        R(4) = m32(ram, R(13) + (uint32_t)off);
        if (!vf3_guest_call(s, ram, 0x8C0A7662u, 0x8C0B1A9Eu)) return 0;
        R(15) = f;
    } else if (m32(ram, R(14) + 4) != 0) {
        F(4) = ONE;
        R(4) = R(14);
        if (!vf3_guest_call(s, ram, 0x8C0A76ECu, 0x8C0B1AD2u)) return 0;
        R(15) = f;
    }

    switch (mode) {
    case 1:
        w32(ram, R(11), m32(ram, R(14) + 48));
        break;
    case 5: case 9:
        R(14) = m32(ram, R(11));
        w32(ram, R(11), m32(ram, R(14) + 48));
        break;
    case 11:
        if (R(14) != 0) {
            R(14) = m32(ram, R(14) + 44);
            w32(ram, R(11), m32(ram, R(14) + 48));
        }
        break;
    case 13:
        R(14) = m32(ram, R(11));
        break;
    case 14: case 16: case 17:
        break;
    default:
        if (R(14) != 0) R(14) = m32(ram, R(14) + 44);
        break;
    }

    R(4) = 1;
    if (!vf3_guest_call(s, ram, 0x8C03C4A0u, 0x8C0B1B1Eu)) return 0;

    R(0) = R(14);
    for (int i = 0; i < 4; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
