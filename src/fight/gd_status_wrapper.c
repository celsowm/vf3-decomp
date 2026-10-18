/* gd_status_wrapper.c - 0x8C0432DE  GET_CMD_STAT with the loader's own result codes.
 *
 * r4 = request id, r5 = pointer to the result word. The wrapper queries the BIOS (the stub at 0x8C0430A0, r5 = a 16-byte
 * stack quad: error, error1, size, wait) and translates the status into r4 and the result word:
 *     status  0 (idle)      -> 0, result untouched          status 1 (busy)    -> 4, result = size
 *     status  2 (complete)  -> 1, result = size             status 3 (stream)  -> 7
 *     status  4             -> 4                            any other status   -> returned as is
 *     status -1 (error)     -> 5, result = a negative code from the BIOS error word: -(27 + e) for e in 0..7, -35 for 11,
 *                              -36 for 16, -26 for every other value (including e >= 17); the error1 word is copied to
 *                              result + 4 first.
 * Returns the code in r0. The two result words are written only on the paths above, exactly as the original does. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c) (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_gd_status_wrapper_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 24;
    const uint32_t saved_r14 = R(14);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(14) = R(5);
    R(15) = f;
    R(3) = 0x0C0430A0u;
    R(5) = f;
    R(VF3_REG_PR) = 0x8C0432ECu;
    if (!vf3_guest_call(s, ram, 0x0C0430A0u, 0x8C0432ECu)) return 0;
    R(15) = f;
    R(4) = R(0);
    R(5) = m32(ram, f + 8);
    R(6) = 4;                                           /* delay slot of the bt/s */
    const int32_t status = (int32_t)R(0);
    if (status == -1) {
        R(2) = m32(ram, f + 4);
        R(4) = 5;
        w32(ram, R(14) + 4, R(2));
        R(0) = m32(ram, f);
        R(1) = 17;
        SET_T(R(0) >= R(1));
        if (R(VF3_REG_SR) & 1u) { R(2) = (uint32_t)-26; w32(ram, R(14), R(2)); goto done; }
        const uint32_t e = R(0);
        R(0) <<= 1;
        R(1) = R(0);
        R(0) = 0x0C043360u;
        static const int8_t code[17] = { -27, -28, -29, -30, -31, -32, -33, -34, -26, -26, -26, -35, -26, -26, -26, -26, -36 };
        const uint32_t v = (uint32_t)(int32_t)code[e];
        /* which scratch register the original leaves the code in depends on the table slot: r3 (0), r1 (1, 3, 5, 7, 16),
         * r2 (2, 4, 6, 11 and the shared -26 slot) */
        switch (e) {
        case 0: R(3) = v; break;
        case 1: case 3: case 5: case 7: case 16: R(1) = v; break;
        default: R(2) = v; break;
        }
        w32(ram, R(14), v);
        goto done;
    }
    SET_T(status >= 0 && status <= 4);                  /* the last cmp/eq that matched, else the failed cmp/eq #4 */
    if (status == 0) R(4) = 0;
    else if (status == 1) { R(4) = R(6); w32(ram, R(14), R(5)); }
    else if (status == 2) { R(4) = 1; w32(ram, R(14), R(5)); }
    else if (status == 3) R(4) = 7;
    else if (status == 4) R(4) = R(6);
done:
    R(15) = sp0;
    R(0) = R(4);
    R(14) = saved_r14;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
