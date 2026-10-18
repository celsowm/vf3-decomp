/* fighter_refresh.c - 0x8C0B1550  per-frame refresh of one fighter's slots (the 18 attach points and 15 effect slots).
 *
 * r4 = flag word pointer (stored in the frame at f+4 and tested again), r5 = fighter record (r14).
 * Overview of the original:
 *   1. 0x8C0C6742 decides whether the fighter is active at all (r0 == 0 leaves immediately).
 *   2. The mode byte at +0x60 is promoted to 26 / 27 / 28 when the matching flag byte of the global block at
 *      0x0C29B864 (+0xE4 / +0xE3) is set; it indexes the pointer tables 0x0C10F6D0 and 0x0C2A1C3C, giving r10, the
 *      mode's descriptor.
 *   3. The state word at +0 is filtered against the record's hit flags (0x40000 / 0x80000 / 0x01000000 /
 *      0x03000000), the new word is stored, and the "recompute everything" path (0x8C0B1CC4) runs when bit 4 of
 *      0x0C29BCC0 is set.
 *   4. For the modes 5 / 18 / 7 four per-limb descriptor slots (offsets +0xA8 apart from the table at 0x0C29BB84
 *      +0x68 or +0x6C) get their callback pointers swapped for the duration of the loop.
 *   5. Eighteen attach slots (stride 0x40 from +0x180) are walked: 0x8C091C20 for slots 5 and 9, the 0x8C0385C0
 *      set-up for 2 / 6 / 10 / 15, then 0x8C0B1A46 resolves the link and 0x8C0B1B2E refreshes the slot.
 *   6. The callbacks are restored, then a second pass over the 18 slots calls 0x8C03BD80 + 0x8C0A7662 for all but
 *      slots 1 / 5 / 9 / 14 / 17.
 *   7. When 0x0C29BCC0 bit 8 is clear and the pre-computed flags allow it, 15 effect slots (stride 0x40 from
 *      +0x7C0) are raised: the float at +0x34 keeps the larger of the slot and its successor, then 0x8C03B530
 *      (and, unless the link is -1, 0x8C03BD80 + 0x8C0A756C) run.
 *
 * The routine replays the original's pushes and register writes, so the frame it leaves is the original's.
 * Frame (f = sp - 88): f+0 stack argument for 0x8C0C6742 / later the active-flag, f+4 first argument / later the
 * "no hit" flag, f+8 the link pointer, f+C the 0x0C2A0974 pointer / later the +0xA8 slot addresses,
 * f+10 .. f+18 the other slot addresses, f+1C .. f+2C the saved callbacks, f+30 / f+34 the two flag words. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { MODE_OFF = 0x60, SLOT_BASE = 0x180, EFFECT_BASE = 0x7C0, SLOT_COUNT = 18, EFFECT_COUNT = 15, SLOT_STRIDE = 64 };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define TST(a, b)   SET_T((((a) & (b))) == 0)
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define U8(a)       ((uint32_t)vf3_mem_u8(ram, (a)))
#define S8(a)       ((uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, (a)))

int vf3_fighter_refresh_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 88;
    const uint32_t saved[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    w32(ram, sp0 - 32, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);
    R(14) = R(5);
    R(15) = f;
    w32(ram, f + 4, R(4));
    R(3) = 0x0C2A0974u;
    R(13) = 0x0C29B864u;
    w32(ram, f + 12, R(3));
    R(3) = 0x0C0C6742u;
    R(2) = 0x0C29BCC4u;
    w32(ram, f, R(2));
    CALL(0x8C0C6742u, 0x8C0B1574u);
    TST(R(0), R(0));
    if (R(0) == 0) goto done;

    R(0) = MODE_OFF;
    R(11) = S8(R(14) + R(0));
    R(0) = R(11) & 0xFFu;
    R(11) = R(0);
    SET_T(R(0) == 11);
    if (R(0) != 11) goto not_11;
    R(0) = 0xE4;
    R(2) = S8(R(13) + R(0));
    TST(R(2), R(2));
    if (R(2) != 0) R(11) = 26;
    goto mode_done;
not_11:
    R(0) = R(11);
    SET_T(R(0) == 24);
    if (R(0) != 24) goto not_24;
    R(0) = 0xE4;
    R(2) = S8(R(13) + R(0));
    TST(R(2), R(2));
    if (R(2) != 0) R(11) = 27;
    goto mode_done;
not_24:
    SET_T(R(0) == 12);
    if (R(0) != 12) goto mode_done;
    R(0) = 0xE3;
    R(2) = S8(R(13) + R(0));
    TST(R(2), R(2));
    if (R(2) != 0) R(11) = 28;

mode_done:
    R(0) = 0x0C10F6D0u;
    R(10) = R(11) << 2;
    R(5) = m32(ram, R(13));
    R(10) = m32(ram, R(0) + R(10));
    R(0) = 0x0C2A1C3Cu;
    R(3) = R(5);
    R(10) <<= 2;
    R(6) = 0x000C0000u;
    R(10) = m32(ram, R(0) + R(10));
    R(4) = m32(ram, R(14));
    TST(R(6), R(3));
    R(7) = m32(ram, R(13) + 4);                        /* delay slot of the bt/s below */
    if (R(VF3_REG_SR) & 1u) goto hit_test;
    R(0) = 0x3A7;
    R(1) = m32(ram, f);
    R(3) = S8(R(1) + R(0));
    TST(R(3), R(3));
    if (R(3) != 0) goto done;
    goto accept;
hit_test:
    R(2) = 0x03000000u;
    TST(R(2), R(5));
    if (R(VF3_REG_SR) & 1u) goto hit_mid;
    TST(R(6), R(7));
    if (!(R(VF3_REG_SR) & 1u)) goto accept;
hit_mid:
    R(2) = 1;
    TST(R(4), R(2));
    if (R(VF3_REG_SR) & 1u) goto done;
    R(1) = 0x01000000u;
    TST(R(4), R(1));
    if (R(VF3_REG_SR) & 1u) goto done;
    R(2) = 2;
    TST(R(4), R(2));
    if (!(R(VF3_REG_SR) & 1u)) goto done;

accept:
    w32(ram, R(14), R(4));
    R(2) = 0x0C29BCC0u;
    R(0) = m32(ram, R(2));
    TST(R(0), 16);
    if (!(R(VF3_REG_SR) & 1u)) {
        R(4) = R(14);
        CALL(0x8C0B1CC4u, 0x8C0B1618u);
        goto loops_done;
    }
    R(0) = m32(ram, f + 12);
    R(9) = 0x180;
    R(0) = m32(ram, R(0) + 4);
    TST(R(0), 1);
    R(9) += R(14);                                     /* delay slot of the bt/s below */
    if (R(VF3_REG_SR) & 1u) {
        R(1) = 0;
        w32(ram, f + 52, R(1));
    } else {
        R(2) = 1;
        w32(ram, f + 52, R(2));
    }
    R(2) = m32(ram, R(14));
    R(3) = 0x00400000u;
    TST(R(3), R(2));
    R(4) = (R(VF3_REG_SR) & 1u) ? 1 : 0;
    R(3) = m32(ram, f + 4);
    R(2) = 0x00080000u;
    R(1) = m32(ram, R(3));
    TST(R(2), R(1));
    R(5) = (R(VF3_REG_SR) & 1u) ? 1 : 0;
    R(5) |= R(4);
    w32(ram, f + 48, R(5));
    R(3) = m32(ram, f + 4);
    R(2) = 0x00040000u;
    R(1) = m32(ram, R(3));
    TST(R(2), R(1));
    if (R(VF3_REG_SR) & 1u) { R(2) = 1; }
    else {
        R(0) = m32(ram, R(14));
        R(3) = 0x00400000u;
        TST(R(3), R(0));
        R(2) = (R(VF3_REG_SR) & 1u) ? 1 : 0;
    }
    w32(ram, f + 4, R(2));
    R(2) = 0x0C29C05Fu;
    R(0) = S8(R(14) + 4);
    R(3) = S8(R(2));
    SET_T(R(3) == R(0));
    R(0) = R(VF3_REG_SR) & 1u;
    w32(ram, f, R(0));
    R(0) = 97;
    R(3) = S8(R(14) + R(0));
    TST(R(10), R(10));
    R(3) &= 0xFFu;
    w32(ram, f + 12, R(3));                            /* delay slot of the bt/s below */
    if (!(R(VF3_REG_SR) & 1u)) R(13) = R(10);
    R(3) = 0x0C055D00u;
    CALL(0x8C055D00u, 0x8C0B16C0u);
    R(2) = m32(ram, f);
    TST(R(2), R(2));
    if (R(2) != 0) {
        R(4) = R(14);
        CALL(0x8C0B1DECu, 0x8C0B16CAu);
        goto after_loops;
    }
    w32(ram, f + 8, R(13));
    R(3) = m32(ram, R(13) + 44);
    TST(R(3), R(3));
    if (R(3) == 0) goto loops_done;
    R(0) = m32(ram, f + 12);
    SET_T(R(0) == 9);
    if (R(0) == 9) {
        R(6) = m32(ram, f + 4);
        R(5) = R(13);
        R(4) = R(14);
        CALL(0x8C0B1EC0u, 0x8C0B16E8u);
        goto after_loops;
    }
    R(0) = R(11);
    if (R(0) == 5) goto mode_special;
    R(0) = R(11);
    if (R(0) == 18) goto mode_special;
    R(0) = R(11);
    if (R(0) != 7) goto slot_loop_init;
mode_special:
    R(0) = S8(R(14) + 4);
    R(4) = 0x0C29BB84u;
    TST(R(0), R(0));
    if (R(0) != 0) {
        R(0) = 108;
        R(1) = m32(ram, R(4) + R(0));
        w32(ram, f, R(1));
    } else {
        R(0) = 104;
        R(2) = m32(ram, R(4) + R(0));
        w32(ram, f, R(2));
    }
    R(3) = m32(ram, f);
    R(4) = 0xA8;
    R(3) += R(4);
    w32(ram, f + 12, R(3));
    R(3) += R(4);
    R(2) = R(3);
    R(2) += R(4);
    w32(ram, f + 20, R(3));
    w32(ram, f + 16, R(2));
    R(2) += R(4);
    w32(ram, f + 24, R(2));
    R(0) = m32(ram, f);
    R(0) = m32(ram, R(0));
    TST(R(0), 1);
    if (R(VF3_REG_SR) & 1u) goto slot_loop_init;
    /* Save the four callback pointers and plant the replacement ones where the slot is active. */
    R(2) = m32(ram, R(10) + 4);
    R(3) = m32(ram, R(2) + 4);
    w32(ram, f + 28, R(3));
    R(0) = 0xA4;
    R(2) = m32(ram, f);
    R(3) = m32(ram, R(2) + R(0));
    TST(R(3), R(3));
    if (R(3) != 0) {
        R(2) = 0x0C29C300u;
        R(3) = m32(ram, R(10) + 4);
        w32(ram, R(3) + 4, R(2));
    }
    R(4) = m32(ram, R(10) + 44);
    R(3) = m32(ram, R(4) + 4);
    R(2) = m32(ram, R(3) + 4);
    w32(ram, f + 32, R(2));
    R(3) = m32(ram, f + 20);
    R(0) = 0xA4;
    R(2) = m32(ram, R(3) + R(0));
    TST(R(2), R(2));
    if (R(2) != 0) {
        R(3) = 0x0C29E3D0u;
        R(2) = m32(ram, R(4) + 4);
        w32(ram, R(2) + 4, R(3));
    }
    R(4) = m32(ram, R(4) + 44);
    R(2) = m32(ram, R(4) + 4);
    R(3) = m32(ram, R(2) + 4);
    w32(ram, f + 36, R(3));
    R(2) = m32(ram, f + 12);
    R(0) = 0xA4;
    R(3) = m32(ram, R(2) + R(0));
    TST(R(3), R(3));
    if (R(3) != 0) {
        R(2) = 0x0C29D110u;
        R(3) = m32(ram, R(4) + 4);
        w32(ram, R(3) + 4, R(2));
    }
    R(4) = m32(ram, R(10) + 44);
    R(4) = m32(ram, R(4) + 48);
    R(3) = m32(ram, R(4) + 4);
    R(2) = m32(ram, R(3) + 4);
    w32(ram, f + 40, R(2));
    R(3) = m32(ram, f + 24);
    R(0) = 0xA4;
    R(2) = m32(ram, R(3) + R(0));
    TST(R(2), R(2));
    if (R(2) != 0) {
        R(3) = 0x0C29E5B0u;
        R(2) = m32(ram, R(4) + 4);
        w32(ram, R(2) + 4, R(3));
    }
    R(4) = m32(ram, R(4) + 44);
    R(2) = m32(ram, R(4) + 4);
    R(3) = m32(ram, R(2) + 4);
    w32(ram, f + 44, R(3));
    R(2) = m32(ram, f + 16);
    R(0) = 0xA4;
    R(3) = m32(ram, R(2) + R(0));
    TST(R(3), R(3));
    if (R(3) != 0) {
        R(2) = 0x0C29DA70u;
        R(3) = m32(ram, R(4) + 4);
        w32(ram, R(3) + 4, R(2));
    }

slot_loop_init:
    R(12) = 0;
    goto slot_test;
slot_body:
    R(2) = m32(ram, f + 4);
    TST(R(2), R(2));
    if (R(2) == 0) goto slot_next;
    R(0) = R(12);
    R(8) = 0x0C091C20u;
    if (R(0) == 5) {
        R(5) = 0x20C8;
        R(7) = 1;
        R(6) = R(9);
        R(5) += R(14);
        R(4) = R(14);
        CALL(0x8C091C20u, 0x8C0B17E2u);
        R(13) = m32(ram, f + 8);
        TST(R(13), R(13));
        if (R(13) == 0) goto slot_next;
        R(2) = m32(ram, R(13) + 48);
        w32(ram, f + 8, R(2));
        goto slot_next;
    }
    if (R(0) == 9) {
        R(5) = 0x217C;
        R(7) = 0;
        R(6) = R(9);
        R(5) += R(14);
        R(4) = R(14);
        CALL(0x8C091C20u, 0x8C0B17FCu);
        R(13) = m32(ram, f + 8);
        TST(R(13), R(13));
        if (R(13) == 0) goto slot_next;
        R(2) = m32(ram, R(13) + 48);
        w32(ram, f + 8, R(2));
        goto slot_next;
    }
    R(0) = R(12);
    R(8) = 0x0C0385C0u;
    if (R(0) == 2 || R(0) == 6) {
        CALL(0x8C0385C0u, 0x8C0B1844u);
        R(2) = 0x0C038590u;
        CALL(0x8C038590u, 0x8C0B184Au);
    } else if (R(0) == 10 || R(0) == 15) {
        CALL(0x8C0385C0u, 0x8C0B1852u);
    }
    R(15) = f - 4;
    w32(ram, R(15), R(12));
    R(5) = R(13);
    R(6) = R(15) + 12;
    R(7) = R(9);
    R(4) = R(14);
    if (!vf3_guest_call(s, ram, 0x8C0B1A46u, 0x8C0B1860u)) return 0;
    R(13) = R(0);
    R(0) = R(12);
    R(15) = f;
    SET_T(R(0) == 0);
    if (R(0) == 0 || R(0) == 11) {
        R(2) = 0x0C038590u;
        CALL(0x8C038590u, 0x8C0B1882u);
    } else {
        goto slot_next;
    }
slot_next:
    R(3) = m32(ram, f + 4);
    TST(R(3), R(3));
    if (R(3) != 0) {
        R(5) = R(12);
        R(4) = R(14);
        CALL(0x8C0B1B2Eu, 0x8C0B188Eu);
    }
    R(12) += 1;
    R(9) += SLOT_STRIDE;
slot_test:
    R(3) = SLOT_COUNT;
    SET_T((int32_t)R(12) >= (int32_t)R(3));
    if ((int32_t)R(12) < (int32_t)R(3)) goto slot_body;

loops_done:
    R(1) = 0x0C038570u;
    CALL(0x8C038570u, 0x8C0B189Eu);
    R(0) = R(11);
    if (R(0) == 5 || R(0) == 18 || R(0) == 7) {
        R(0) = m32(ram, f);
        R(0) = m32(ram, R(0));
        TST(R(0), 1);
        if (!(R(VF3_REG_SR) & 1u)) {
            R(0) = 0xA4;
            R(2) = m32(ram, f);
            R(3) = m32(ram, R(2) + R(0));
            TST(R(3), R(3));
            if (R(3) != 0) {
                R(2) = m32(ram, f + 28);
                R(3) = m32(ram, R(10) + 4);
                w32(ram, R(3) + 4, R(2));
            }
            R(0) = 0xA4;
            R(3) = m32(ram, f + 20);
            R(2) = m32(ram, R(3) + R(0));
            TST(R(2), R(2));
            R(4) = m32(ram, R(10) + 44);
            if (R(2) != 0) {
                R(3) = m32(ram, f + 32);
                R(2) = m32(ram, R(4) + 4);
                w32(ram, R(2) + 4, R(3));
            }
            R(0) = 0xA4;
            R(3) = m32(ram, f + 12);
            R(2) = m32(ram, R(3) + R(0));
            TST(R(2), R(2));
            R(4) = m32(ram, R(4) + 44);
            if (R(2) != 0) {
                R(3) = m32(ram, f + 36);
                R(2) = m32(ram, R(4) + 4);
                w32(ram, R(2) + 4, R(3));
            }
            R(0) = 0xA4;
            R(3) = m32(ram, f + 24);
            R(4) = m32(ram, R(10) + 44);
            R(2) = m32(ram, R(3) + R(0));
            TST(R(2), R(2));
            R(4) = m32(ram, R(4) + 48);
            if (R(2) != 0) {
                R(3) = m32(ram, f + 40);
                R(2) = m32(ram, R(4) + 4);
                w32(ram, R(2) + 4, R(3));
            }
            R(0) = 0xA4;
            R(3) = m32(ram, f + 16);
            R(2) = m32(ram, R(3) + R(0));
            TST(R(2), R(2));
            R(4) = m32(ram, R(4) + 44);
            if (R(2) != 0) {
                R(3) = m32(ram, f + 44);
                R(2) = m32(ram, R(4) + 4);
                w32(ram, R(2) + 4, R(3));
            }
        }
    }
    R(2) = m32(ram, f + 4);
    TST(R(2), R(2));
    if (R(2) == 0) goto final_flush;
    R(1) = 0x0C055D00u;
    CALL(0x8C055D00u, 0x8C0B1922u);
    R(12) = 0x180;
    R(11) = R(14);
    R(10) = 0x0C0A7662u;
    R(11) += 108;
    R(12) += R(14);
    R(13) = 0;
    goto relink_test;
relink_body:
    R(0) = R(13);
    if (R(0) == 5 || R(0) == 9 || R(0) == 14 || R(0) == 17 || R(0) == 1) goto relink_next;
    R(3) = 0x0C03BD80u;
    R(4) = R(12);
    CALL(0x8C03BD80u, 0x8C0B1968u);
    R(4) = m32(ram, R(11));
    CALL(0x8C0A7662u, 0x8C0B196Cu);
relink_next:
    R(13) += 1;
    R(11) += 4;
    R(12) += SLOT_STRIDE;
relink_test:
    R(2) = SLOT_COUNT;
    SET_T((int32_t)R(13) >= (int32_t)R(2));
    if ((int32_t)R(13) < (int32_t)R(2)) goto relink_body;
    R(1) = 0x0C038570u;
    CALL(0x8C038570u, 0x8C0B197Eu);
    R(3) = 0x0C072B40u;
    R(4) = R(14);
    CALL(0x8C072B40u, 0x8C0B1984u);

after_loops:
    R(1) = 0x0C29BCC0u;
    R(3) = 0x100;
    R(2) = m32(ram, R(1));
    TST(R(3), R(2));
    if (!(R(VF3_REG_SR) & 1u)) goto final_call;
    R(3) = 0x0C055D00u;
    CALL(0x8C055D00u, 0x8C0B1994u);
    R(0) = m32(ram, f + 4);
    TST(R(0), R(0));
    if (R(0) == 0) goto effects_done;
    R(0) = m32(ram, f + 52);
    TST(R(0), R(0));
    if (R(0) != 0) goto effects_done;
    R(0) = m32(ram, f + 48);
    TST(R(0), R(0));
    if (R(0) == 0) goto effects_done;
    R(11) = 0x1420;
    R(2) = EFFECT_BASE;
    R(11) += R(14);
    R(14) += R(2);
    R(13) = 0;
    goto effect_test;
effect_body:
    R(0) = R(13);
    R(12) = m32(ram, R(11));
    R(11) += 4;
    if (R(0) == 2 || R(0) == 3 || R(0) == 5 || R(0) == 6 || R(0) == 9 || R(0) == 10 || R(0) == 12 || R(0) == 13) {
        R(5) = R(14);
        R(0) = 52;
        R(14) += SLOT_STRIDE;
        F(5) = m32(ram, R(5) + R(0));
        F(4) = m32(ram, R(14) + R(0));
        SET_T(GT(5, 4));
        if (R(VF3_REG_SR) & 1u) w32(ram, R(5) + R(0), F(4));
        R(10) = 0x0C03B530u;
        R(4) = R(14);
        CALL(0x8C03B530u, 0x8C0B1A0Au);
    }
    R(0) = R(12);
    if ((int32_t)R(0) != -1) {
        R(2) = 0x0C03BD80u;
        R(4) = R(14);
        CALL(0x8C03BD80u, 0x8C0B1A16u);
        R(10) = 0x0C0A756Cu;
        R(4) = R(12);
        CALL(0x8C0A756Cu, 0x8C0B1A1Cu);
    }
    R(13) += 1;
    R(14) += SLOT_STRIDE;
effect_test:
    R(4) = EFFECT_COUNT;
    SET_T((int32_t)R(13) >= (int32_t)R(4));
    if ((int32_t)R(13) < (int32_t)R(4)) goto effect_body;
effects_done:
    R(2) = 0x0C038570u;
    CALL(0x8C038570u, 0x8C0B1A2Cu);
final_flush:
final_call:
    R(3) = 0x0C038570u;
    CALL(0x8C038570u, 0x8C0B1A32u);
done:
    R(15) = sp0;
    R(14) = saved[0]; R(13) = saved[1]; R(12) = saved[2]; R(11) = saved[3];
    R(10) = saved[4]; R(9) = saved[5]; R(8) = saved[6];
    s->pc = pr0;
    return 1;
}
