/* id_bytes_submit.c - 0x8C0A045C  stamp four id bytes into a request block and hand it to 0x8C0C11F4.
 *
 *   r4 = a value that ends up in the request word, r5 = a key. 0x8C0C66C8(key) answers a 32-bit word that is
 *   written big-endian to bytes +0x8C..+0x8F of the block at 0x0C29BCC4; then bytes +0x8C / +0x8D / +0x8E
 *   are overwritten with the answers of 0x8C0C66B8 for key, key + 1 and key + 2, and +0x8F is cleared.
 *   (The first four-byte store is therefore only visible in the last byte it wrote before the overwrite: +0x8F
 *   is zeroed, +0x8C..+0x8E hold the three per-byte answers.)
 *
 *   The routine ends in a tail jump to 0x8C0C11F4 with r4 = ((value + 12) << 7) | 28, r5 -> the stamped bytes
 *   and r6 = 1, after popping r12 / r13 / r14 and pr.
 *
 *   Frame: r14, r13, r12 and pr pushed, then 4 bytes holding r4. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 16, FRAME = 4, BLOCK = 0x0C29BCC4u, STAMP = 0x8C, REQUEST_FLAGS = 28, VALUE_SHIFT = 7 };

int vf3_id_bytes_submit_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[3] = { R(14), R(13), R(12) };
    const uint32_t value = R(4), key = R(5);

    for (int i = 0; i < 3; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 16, pr0);
    R(15) = f;
    w32(ram, f, value);
    R(14) = BLOCK;
    R(13) = key;

    R(4) = key;
    if (!vf3_guest_call(s, ram, 0x8C0C66C8u, 0x8C0A0472u)) return 0;
    R(15) = f;
    const uint32_t word = R(0);
    for (uint32_t i = 0; i < 4; ++i) vf3_mem_set_u8(ram, BLOCK + STAMP + i, (uint8_t)(word >> (24 - 8 * i)));

    R(12) = 0x0C0C66B8u;
    for (uint32_t i = 0; i < 3; ++i) {
        R(4) = key + i;
        if (!vf3_guest_call(s, ram, 0x8C0C66B8u, i == 0 ? 0x8C0A0498u : i == 1 ? 0x8C0A04A4u : 0x8C0A04B0u)) return 0;
        R(15) = f;
        vf3_mem_set_u8(ram, BLOCK + STAMP + i, (uint8_t)R(0));
    }
    vf3_mem_set_u8(ram, BLOCK + STAMP + 3, 0);

    R(6) = 1;
    R(4) = ((m32(ram, f) + 12) << VALUE_SHIFT) | REQUEST_FLAGS;
    R(5) = BLOCK + STAMP;
    R(14) = saved_r[0]; R(13) = saved_r[1]; R(12) = saved_r[2];
    R(VF3_REG_PR) = pr0;
    R(15) = sp0;
    if (!vf3_guest_call(s, ram, 0x8C0C11F4u, pr0)) return 0;
    s->pc = pr0;
    return 1;
}
