/* readable.h - hand-written C ports of the fight engine, keyed by SH-4 entry.
 *
 * A "readable" function is source-level C: named fields, loops, no goto
 * ladders, no guest-register file inside its body. Each one is wrapped by a
 * tiny glue function with the guest-call ABI (arguments in s->v[], result
 * registers written back, s->pc = return address) so it can sit in the same
 * dispatcher chain as the generated adapters and be proven against the
 * oracle in tests/tick_mixed.c.
 *
 * `out_regs` lists the guest registers the function is contracted to leave
 * defined (bit i = s->v[i]); every other register is scratch and is not
 * compared. docs/decomp_status.csv carries the `readable` column.
 */
#ifndef VF3_READABLE_H
#define VF3_READABLE_H

#include <stdint.h>
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"

typedef int (*vf3_readable_fn)(vf3_matrix_state *s, const vf3_ram_map *ram);

typedef struct {
    uint32_t entry;         /* canonical 0x0C... entry */
    const char *name;
    vf3_readable_fn fn;
    uint64_t out_regs;      /* mask over s->v[0..53] */
} vf3_readable_entry;

extern const vf3_readable_entry vf3_readable_table[];
extern const unsigned vf3_readable_count;

/* Dispatcher hook (vf3_family_override): handled=1 when the entry is ported
 * readable. Install with vf3_family_override = vf3_readable_override. */
int vf3_readable_override(uint32_t entry, vf3_matrix_state *s,
                          const vf3_ram_map *ram, int *handled);
const vf3_readable_entry *vf3_readable_find(uint32_t entry);

/* Guest-memory accessors for readable bodies. */
uint32_t vf3_mem_u32(const vf3_ram_map *ram, uint32_t addr);
uint16_t vf3_mem_u16(const vf3_ram_map *ram, uint32_t addr);
uint8_t  vf3_mem_u8(const vf3_ram_map *ram, uint32_t addr);
float    vf3_mem_f32(const vf3_ram_map *ram, uint32_t addr);
void vf3_mem_set_u32(const vf3_ram_map *ram, uint32_t addr, uint32_t v);
void vf3_mem_set_u16(const vf3_ram_map *ram, uint32_t addr, uint16_t v);
void vf3_mem_set_u8(const vf3_ram_map *ram, uint32_t addr, uint8_t v);
void vf3_mem_set_f32(const vf3_ram_map *ram, uint32_t addr, float v);

/* Call a guest function from a readable body: pr is set to `ret_addr`, the
 * callee runs through the dispatcher (ported code, readable code, or an
 * oracle stub in tests), and the call fails if control does not come back
 * to `ret_addr`. Returns 0 on failure. */
int vf3_guest_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                   uint32_t target, uint32_t ret_addr);
int vf3_guest_tail_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                        uint32_t target, uint32_t pr);

#endif /* VF3_READABLE_H */
