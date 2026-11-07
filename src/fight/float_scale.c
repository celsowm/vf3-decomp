/* float_scale.c - SH-4 0x8C039C50 and 0x8C039C70: the fight engine's
 * unsigned-32-to-float scale.
 *
 * Each entry reads one 32-bit value through a global pointer, converts it to
 * a float, folds the sign bit back in with the textbook 2^32 addition when it
 * is set, scales the result by a constant read from the literal pool and
 * returns the truncated integer.
 *
 * Both are true leaves: they save no registers and open no frame.  Each one
 * reads three literal-pool slots at run time - the pointer to the value, a
 * float constant to add, and a float multiplier:
 *
 *   0x0C039D4C -> the value's address (the first entry's own global)
 *   0x0C039D58 -> the value's address (the second entry's own global)
 *   0x0C039D50 -> 4294967296.0f (0x4F800000) - the 2^32 the sign bit folds in
 *   0x0C039D54 -> 1.28f (0x3FA3D70A)        - the scale
 *
 * The "add 2^32 when negative" is the unsigned-wrapping trick: the SH-4's
 * `float FPUL,FRn` converts its 32-bit integer as signed, so to get the
 * float of the unsigned interpretation the guest loads the pool's 0x4F800000
 * straight into FPUL (via `lds`) and adds it as a float.
 *
 * Details the port has to keep:
 *
 *   * the `bt/s` **delay slot** (`float FPUL,FR3`) runs on **both** paths, so
 *     `fr3` always holds `float(value)` before the branch is resolved;
 *   * the add's operand is the **raw bits** of the pool word - `lds r2,FPUL;
 *     fsts FPUL,FR2` copies them without any conversion, so the port reuses
 *     the pool word as a float;
 *   * the multiplier is loaded with `fmov.s @r0,FR2` and overwrites `fr2`
 *     on every path (even the negative one, after the add), so the final
 *     `fr2` is the multiplier either way;
 *   * the **T bit** the caller sees is the `cmp/ge #0` at the very start
 *     (nothing after it touches SR), so it is `(value >= 0)`;
 *   * `ftrc` leaves the truncated integer in FPUL and the exit copies it into
 *     `r0`, so both carry the answer.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* The literal pool, read at run time. */
#define POOL_P1_A 0x0c039d4cu  /* the first entry's value pointer */
#define POOL_P1_B 0x0c039d58u  /* the second entry's value pointer */
#define POOL_PLUS 0x0c039d50u  /* 4294967296.0f, the sign-bit fold */
#define POOL_SCALE 0x0c039d54u /* 1.28f, the multiplier */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

static int float_scale(vf3_matrix_state *s, const vf3_ram_map *ram,
                       uint32_t pool_p1)
{
    /* The value: read through the pool's pointer, as a signed 32-bit word. */
    uint32_t p1 = vf3_mem_u32(ram, pool_p1);
    int32_t v = (int32_t)vf3_mem_u32(ram, p1);
    R(3) = (uint32_t)v;
    R(2) = p1;                    /* overwritten by P2 on the v < 0 path */

    /* The delay slot: fr3 = float(value) on both paths. */
    float f = vf3_f_from_int(s, v);
    set_t(s, v >= 0);

    if (v < 0) {
        /* The sign bit is set: fold it back in by adding the pool's 2^32,
         * whose raw bits were loaded straight into FPUL. */
        uint32_t plus_bits = vf3_mem_u32(ram, POOL_PLUS);
        R(2) = plus_bits;
        f = vf3_f_add(s, f, vf3_bits_f32(plus_bits));
    }

    /* The multiplier, loaded with fmov.s @r0,FR2 on every path. */
    uint32_t scale_bits = vf3_mem_u32(ram, POOL_SCALE);
    float mul = vf3_bits_f32(scale_bits);
    f = vf3_f_mul(s, f, mul);

    /* ftrc FR3,FPUL: the truncated integer, in both FPUL and r0. */
    uint32_t res = (uint32_t)vf3_f_trunc(f);
    R(53) = res;
    R(0) = res;
    vf3_fr_set(s, 3, f);
    vf3_fr_set(s, 2, mul);

    s->pc = R(16);
    return ram->oob == 0;
}

int vf3_float_scale_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    return float_scale(s, ram, POOL_P1_A);
}

int vf3_float_scale_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    return float_scale(s, ram, POOL_P1_B);
}
