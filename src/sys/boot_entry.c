/* Retail 1ST_READ image entry and CRT0, up to (not including) their handoffs.
 * Instruction identity: tools/sh4full.py 8c010000 / 8c020000 on the untouched
 * retail image. Literal pools are data and are always read from supplied RAM. */
#include "sys/boot_entry.h"
#include <stddef.h>

#define RAM_BASE 0x0C000000u
#define RAM_END  0x0D000000u
#define SR_FD    0x00008000u
#define SR_MD    0x40000000u
#define FPSCR_PR 0x00080000u
#define FPSCR_SZ 0x00100000u

static int physical(uint32_t address, uint32_t *out)
{
    const uint32_t region = address & 0xE0000000u;
    if (region != 0 && region != 0x80000000u && region != 0xA0000000u) return 0;
    const uint32_t p = address & 0x1FFFFFFFu;
    if (p < RAM_BASE || p >= 0x10000000u) return 0;
    *out = RAM_BASE | (p & 0x00FFFFFFu);
    return 1;
}

static uint8_t *byte_at(const vf3_ram_map *ram, uint32_t address)
{
    uint32_t p;
    if (!ram || !ram->wins || !physical(address, &p)) return NULL;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (w->data && p >= w->base && p - w->base < w->len) return w->data + p - w->base;
    }
    return NULL;
}

static int range_present(const vf3_ram_map *ram, uint32_t address, uint32_t bytes)
{
    uint32_t p;
    if (!ram || !ram->wins || !physical(address, &p) || bytes > RAM_END - p) return 0;
    const uint32_t end = p + bytes;
    while (p < end) {
        uint32_t next = p;
        for (int i = 0; i < ram->n; ++i) {
            const vf3_ram_win *w = &ram->wins[i];
            if (w->data && p >= w->base && p - w->base < w->len) {
                const uint64_t limit = (uint64_t)w->base + w->len;
                const uint32_t candidate = limit > end ? end : (uint32_t)limit;
                if (candidate > next) next = candidate;
            }
        }
        if (next == p) return 0;
        p = next;
    }
    return 1;
}

static uint32_t read32(const vf3_ram_map *ram, uint32_t address)
{
    uint32_t value = 0;
    for (unsigned i = 0; i < 4; ++i) value |= (uint32_t)*byte_at(ram, address + i) << (8 * i);
    return value;
}
static void write32(const vf3_ram_map *ram, uint32_t address, uint32_t value)
{ for (unsigned i = 0; i < 4; ++i) *byte_at(ram, address + i) = (uint8_t)(value >> (8 * i)); }

static vf3_boot_status result(vf3_boot_result *out, vf3_boot_status status, uint32_t pc, uint32_t instructions, uint32_t bytes)
{
    if (out) { out->status = status; out->pc = pc; out->instructions = instructions; out->bytes_written = bytes; }
    return status;
}

static int matches(const vf3_ram_map *ram, uint32_t entry, const uint16_t *words, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        const uint32_t a = entry + (uint32_t)i * 2;
        const uint16_t word = (uint16_t)*byte_at(ram, a) | (uint16_t)((uint16_t)*byte_at(ram, a + 1) << 8);
        if (word != words[i]) return 0;
    }
    return 1;
}

vf3_boot_status vf3_boot_relocate(vf3_matrix_state *s, const vf3_ram_map *ram, vf3_boot_result *out)
{
    static const uint16_t code[] = {0xD006,0xD107,0xD207,0x6302,0x2232,0x7004,0x7204,0x3100,0x8BF9,0xD004,0x402B,0x0009};
    uint32_t p;
    if (!s || !physical(s->pc, &p) || p != 0x0C010000u)
        return result(out, VF3_BOOT_BAD_ENTRY, s ? s->pc : 0, 0, 0);
    const uint32_t entry = s->pc;
    if (!(s->v[17] & SR_MD)) return result(out, VF3_BOOT_UNSUPPORTED_CPU, entry, 0, 0);
    if (!range_present(ram, entry, 0x28)) return result(out, VF3_BOOT_BAD_RAM, entry, 0, 0);
    if (!matches(ram, entry, code, sizeof code / sizeof code[0])) return result(out, VF3_BOOT_BAD_IMAGE, entry, 0, 0);
    const uint32_t src = read32(ram, entry + 0x1C), end = read32(ram, entry + 0x20), dst = read32(ram, entry + 0x24);
    /* This segment has a fixed, disjoint copy contract in the original image.
     * A modified pool could overwrite executing instructions/literals. */
    if (src != 0xAC010100u || end != 0xAC014000u || dst != 0xAC004000u)
        return result(out, VF3_BOOT_BAD_IMAGE, entry + 0x1C, 0, 0);
    const uint32_t bytes = end - src, words = bytes / 4, instructions = words * 6 + 6;
    if (!range_present(ram, src, bytes) || !range_present(ram, dst, bytes)) return result(out, VF3_BOOT_BAD_RAM, entry + 6, 0, 0);
    if (s->budget < instructions) return result(out, VF3_BOOT_BUDGET, entry, instructions, 0);
    s->v[0] = src; s->v[1] = end; s->v[2] = dst;
    do {
        s->v[3] = read32(ram, s->v[0]);
        write32(ram, s->v[2], s->v[3]);
        s->v[0] += 4; s->v[2] += 4;
        s->v[17] = (s->v[17] & ~1u) | (s->v[0] == s->v[1]);
    } while (s->v[0] != s->v[1]);
    s->v[0] = read32(ram, entry + 0x24);
    s->pc = s->v[0];
    s->failed_pc = 0;
    s->budget -= instructions;
    return result(out, VF3_BOOT_OK, s->pc, instructions, bytes);
}

vf3_boot_status vf3_boot_crt0(vf3_matrix_state *s, const vf3_ram_map *ram, vf3_boot_result *out)
{
    static const uint16_t code[] = {
        0xC720,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC720,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC719,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC719,0x6F06,0x6006,0xE100,0xE200,0xE300,0xE400,0xE500,0xE600,0xE700,
        0xE800,0xE900,0xEA00,0xEB00,0xEC00,0xED00,0xEE00,
        0xF08D,0xF10C,0xF20C,0xF30C,0xF40C,0xF50C,0xF60C,0xF70C,
        0xF80C,0xF90C,0xFA0C,0xFB0C,0xFC0C,0xFD0C,0xFE0C,0xFF0C,0x400B,0x0009
    };
    uint32_t p;
    if (!s || !physical(s->pc, &p) || p != 0x0C020000u)
        return result(out, VF3_BOOT_BAD_ENTRY, s ? s->pc : 0, 0, 0);
    const uint32_t entry = s->pc;
    if ((entry & 0x80000000u) && !(s->v[17] & SR_MD)) return result(out, VF3_BOOT_UNSUPPORTED_CPU, entry, 0, 0);
    if (!range_present(ram, entry, 0xA4)) return result(out, VF3_BOOT_BAD_RAM, entry, 0, 0);
    if (!matches(ram, entry, code, sizeof code / sizeof code[0])) return result(out, VF3_BOOT_BAD_IMAGE, entry, 0, 0);
    if ((s->v[17] & SR_FD) || (s->v[18] & (FPSCR_PR | FPSCR_SZ)))
        return result(out, VF3_BOOT_UNSUPPORTED_CPU, entry + 0x58, 0, 0);
    const uint32_t descriptor[3] = {entry + 0x84, entry + 0x94, entry + 0x8C};
    uint32_t base[3], count[3], total_words = 0;
    for (unsigned i = 0; i < 3; ++i) {
        base[i] = read32(ram, descriptor[i]); count[i] = read32(ram, descriptor[i] + 4);
        if (!count[i] || count[i] > 0x400000u || (base[i] & 3u) || !range_present(ram, base[i], count[i] * 4))
            return result(out, VF3_BOOT_BAD_RAM, entry + i * 0x12 + 8, 0, 0);
        /* MOV.L stores use each descriptor's virtual address, even when CRT0
         * itself executes in P0. Validate every clear before any state changes. */
        if ((base[i] & 0x80000000u) && !(s->v[17] & SR_MD))
            return result(out, VF3_BOOT_UNSUPPORTED_CPU, entry + i * 0x12 + 8, 0, 0);
        physical(base[i], &p);
        if (p < 0x0C0200A4u && p + count[i] * 4 > 0x0C020000u)
            return result(out, VF3_BOOT_BAD_IMAGE, descriptor[i], 0, 0);
        total_words += count[i];
    }
    const uint32_t stack = read32(ram, entry + 0x9C), startup = read32(ram, entry + 0xA0);
    if ((stack & 3u) || !range_present(ram, stack - 4, 4)) return result(out, VF3_BOOT_BAD_RAM, entry + 0x38, 0, 0);
    if (startup != 0x0C09574Eu) return result(out, VF3_BOOT_BAD_IMAGE, entry + 0xA0, 0, 0);
    const uint32_t instructions = total_words * 4 + 50;
    if (s->budget < instructions) return result(out, VF3_BOOT_BUDGET, entry, instructions, 0);
    for (unsigned i = 0; i < 3; ++i) {
        s->v[0] = descriptor[i];
        s->v[2] = read32(ram, s->v[0]); s->v[0] += 4;
        s->v[3] = 0;
        s->v[4] = read32(ram, s->v[0]); s->v[0] += 4;
        do {
            write32(ram, s->v[2], s->v[3]);
            --s->v[4];
            s->v[17] = (s->v[17] & ~1u) | (s->v[4] == 0);
            s->v[2] += 4;
        } while (s->v[4]);
    }
    s->v[0] = entry + 0x9C;
    s->v[15] = read32(ram, s->v[0]); s->v[0] += 4;
    /* MOV.L @r0+,r0 does not postincrement when source == destination. */
    s->v[0] = read32(ram, s->v[0]);
    for (unsigned i = 1; i < 15; ++i) s->v[i] = 0;
    for (unsigned i = 21; i < 37; ++i) s->v[i] = 0; /* active FR bank; XF is untouched */
    s->v[16] = entry + 0x7C;                       /* original JSR return, including delay slot */
    s->pc = s->v[0];
    s->failed_pc = 0;
    s->budget -= instructions;
    return result(out, VF3_BOOT_OK, s->pc, instructions, total_words * 4);
}
