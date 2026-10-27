/* fight/boot_rte.c - the kernel's context-switch return.
 *
 * The SDK startup (0x8C010E3C..) saves a thread's context, then restores
 * another's, including SSR and SPC, and jumps to a three-instruction stub it
 * installed in RAM at 0x8C00FA20:
 *
 *   fa20  mov.l @(8,pc),r0   ; r0 = the pointer at 0x8C00FA2C
 *   fa22  mov.l @r0+,r2
 *   fa24  mov.l @r0+,r1
 *   fa26  mov.l @r0,r0
 *   fa28  rte                ; PC = SPC, SR = SSR
 *   fa2a  mov r0,r0
 *
 * The stub is data the startup writes, not code in the image, so the
 * translator cannot reach it; this is its source form.  SSR and SPC are the
 * two words the translated LDC instructions fill. */
#include "fight/matrix_family.h"

uint32_t vf3_boot_ssr, vf3_boot_spc;

#define BOOT_RTE_STUB 0x0C00FA20u

int vf3_boot_rte_adapter_contains(uint32_t pc)
{
    return (pc & 0x1FFFFFFFu) == BOOT_RTE_STUB;
}

int vf3_boot_rte_adapter(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)entry;
    uint32_t *r = s->v;
    const uint32_t pool = vf3_matrix_read(ram, BOOT_RTE_STUB + 12u, 4);   /* the word at fa2c */
    r[0] = pool;
    r[2] = vf3_matrix_read(ram, r[0], 4);       r[0] += 4;
    r[1] = vf3_matrix_read(ram, r[0], 4);       r[0] += 4;
    r[0] = vf3_matrix_read(ram, r[0], 4);
    r[17] = vf3_boot_ssr;                       /* RTE: SR = SSR ... */
    s->pc = vf3_boot_spc;                       /* ... and the jump to SPC */
    return vf3_matrix_family(vf3_boot_spc, s, ram);
}
