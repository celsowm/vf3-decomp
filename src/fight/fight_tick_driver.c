/* fight_tick_driver.c - 0x8C055BE0  the per-object submit driver that wraps the polygon-header walker.
 *
 *   r4 -> the object record (words +4 / +8 are handed to the GBR-table routine at GBR + 16). Clears the header
 *   mode flag [0x0C055B80], then runs fixed steps through the helper table in the GBR block:
 *     0x8C03C4F0(0)          matrix select
 *     GBR[+20]()             prepare
 *     0x8C03DD00(FR4, FR5)   with FR4 = [[0x8C055D34]], FR5 = [[0x8C055D38]] (two float cells at 0x0C0EA534 / 38)
 *     GBR[+16](r4 = obj[+4], r5 = GBR[+44], r6 = obj[+8], r7 = obj)
 *     0x8C03C4A0(1)
 *   then raises GBR[+68] = 1 around the submit walk 0x8C055646(obj), copies GBR[+48] into GBR[+44] and GBR[+60]
 *   into GBR[+56], and clears GBR[+68].
 *
 *   Frame: r14..r8, pr and fr12..fr15 pushed (48 bytes), no locals. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 48, MODE_FLAG = 0x0C055B80u, CELL_A = 0x0C0EA534u, CELL_B = 0x0C0EA538u };

/* a code pointer kept in RAM may be written in either mirror; the call helper wants the cached form */
static uint32_t guest(uint32_t a) { return (a & 0x0FFFFFFFu) | 0x8C000000u; }

#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

int vf3_fight_tick_driver_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!s->gbr_known) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED, gbr = s->gbr;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };

    w32(ram, MODE_FLAG, 0);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_f[i]);
    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 16 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 48, pr0);
    R(15) = f;

    const uint32_t obj = R(4);
    R(14) = obj;
    R(3) = 0x0C03C4F0u; R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C055C06u);
    R(0) = m32(ram, gbr + 20);
    CALL(guest(R(0)), 0x8C055C0Cu);

    R(3) = 0x0C03DD00u;
    R(0) = 0x8C055D3Cu;
    F(4) = m32(ram, CELL_A);
    F(5) = m32(ram, CELL_B);
    R(1) = CELL_B;
    CALL(0x8C03DD00u, 0x8C055C1Au);

    R(4) = m32(ram, obj + 4);
    R(0) = m32(ram, gbr + 16);
    R(5) = m32(ram, gbr + 44);
    R(7) = obj;
    R(6) = m32(ram, obj + 8);
    CALL(guest(R(0)), 0x8C055C28u);

    R(3) = 0x0C03C4A0u; R(4) = 1;
    CALL(0x8C03C4A0u, 0x8C055C2Eu);

    R(4) = obj;
    R(0) = 1;
    R(1) = 0x0C055646u;
    w32(ram, gbr + 68, 1);
    CALL(0x8C055646u, 0x8C055C38u);

    w32(ram, gbr + 44, m32(ram, gbr + 48));
    w32(ram, gbr + 56, m32(ram, gbr + 60));
    R(0) = 0;
    w32(ram, gbr + 68, 0);

    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    for (int i = 0; i < 4; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
