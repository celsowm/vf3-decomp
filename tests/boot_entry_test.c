/* Unit cases are synthetic boundary tests, not gameplay evidence. Optional
 * --reference mode compares complete captured contexts and all 16 MiB RAM. */
#include "sys/boot_entry.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_BASE 0x0C000000u
#define RAM_LEN  0x01000000u
static int failures;
#define CHECK(c, ...) do { if (!(c)) { ++failures; fprintf(stderr, "FAIL line %d: ", __LINE__); \
    fprintf(stderr, __VA_ARGS__); fputc('\n', stderr); } } while (0)

static void put32(uint8_t *ram, uint32_t offset, uint32_t value)
{ for (unsigned i = 0; i < 4; ++i) ram[offset + i] = (uint8_t)(value >> (8 * i)); }
static uint32_t get32(const uint8_t *bytes)
{ return (uint32_t)bytes[0] | (uint32_t)bytes[1] << 8 | (uint32_t)bytes[2] << 16 | (uint32_t)bytes[3] << 24; }
static void code(uint8_t *ram, uint32_t offset, const uint16_t *words, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        ram[offset + i * 2] = (uint8_t)words[i];
        ram[offset + i * 2 + 1] = (uint8_t)(words[i] >> 8);
    }
}
static vf3_matrix_state seeded_state(uint32_t pc)
{
    vf3_matrix_state s = {0};
    for (unsigned i = 0; i < 54; ++i) s.v[i] = 0xA1000000u + i;
    for (unsigned i = 0; i < 8; ++i) s.bank[i] = 0xA2000000u + i;
    s.gbr = 0x0C160000u;
    s.gbr_known = s.bank_known = 1;
    s.v[17] = 0x700000E0u;
    s.v[18] = 0x00040001u;
    s.pc = pc;
    s.budget = UINT_MAX;
    return s;
}
static void relocation_image(uint8_t *ram)
{
    static const uint16_t words[] = {0xD006,0xD107,0xD207,0x6302,0x2232,0x7004,0x7204,0x3100,0x8BF9,0xD004,0x402B,0x0009};
    code(ram, 0x10000, words, sizeof words / sizeof words[0]);
    put32(ram, 0x1001C, 0xAC010100u); put32(ram, 0x10020, 0xAC014000u); put32(ram, 0x10024, 0xAC004000u);
    for (unsigned i = 0; i < 0x3F00; ++i) ram[0x10100 + i] = (uint8_t)(i * 19u + i / 4u);
}
static void crt_image(uint8_t *ram)
{
    static const uint16_t words[] = {
        0xC720,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC720,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC719,0x6206,0xE300,0x6406,0x2232,0x4410,0x7204,0x8BFB,0x0009,
        0xC719,0x6F06,0x6006,0xE100,0xE200,0xE300,0xE400,0xE500,0xE600,0xE700,
        0xE800,0xE900,0xEA00,0xEB00,0xEC00,0xED00,0xEE00,
        0xF08D,0xF10C,0xF20C,0xF30C,0xF40C,0xF50C,0xF60C,0xF70C,
        0xF80C,0xF90C,0xFA0C,0xFB0C,0xFC0C,0xFD0C,0xFE0C,0xFF0C,0x400B,0x0009
    };
    code(ram, 0x20000, words, sizeof words / sizeof words[0]);
    put32(ram, 0x20084, 0x0C030000u); put32(ram, 0x20088, 3);
    put32(ram, 0x20094, 0x0C040000u); put32(ram, 0x20098, 5);
    put32(ram, 0x2008C, 0x0C050000u); put32(ram, 0x20090, 7);
    put32(ram, 0x2009C, 0x0C31FA80u); put32(ram, 0x200A0, 0x0C09574Eu);
}

typedef vf3_boot_status (*segment_fn)(vf3_matrix_state *, const vf3_ram_map *, vf3_boot_result *);
static void unchanged_failure(segment_fn fn, vf3_matrix_state *s, const vf3_ram_map *map, vf3_boot_status expected)
{
    vf3_matrix_state before = *s;
    uint8_t *copy = malloc(RAM_LEN);
    if (!copy) { CHECK(0, "cannot allocate boundary-test copy"); return; }
    memcpy(copy, map->wins[0].data, RAM_LEN);
    vf3_boot_result out;
    const vf3_boot_status status = fn(s, map, &out);
    CHECK(status == expected && out.status == expected, "rejection status %d, expected %d", status, expected);
    CHECK(memcmp(&before, s, sizeof before) == 0, "rejected segment changed CPU context");
    CHECK(memcmp(copy, map->wins[0].data, RAM_LEN) == 0, "rejected segment changed RAM");
    CHECK(out.bytes_written == 0, "rejected segment reported RAM writes");
    CHECK(map->oob == 0, "validation changed memory-map OOB counter");
    free(copy);
}

static void unit_tests(void)
{
    uint8_t *ram = malloc(RAM_LEN), *expected_ram = malloc(RAM_LEN);
    if (!ram || !expected_ram) { CHECK(0, "cannot allocate test RAM"); free(ram); free(expected_ram); return; }
    vf3_ram_win win = {ram, RAM_BASE, RAM_LEN};
    vf3_ram_map map = {&win, 1, 0, NULL, NULL, NULL};
    vf3_boot_result out;
    const uint32_t aliases[] = {0x0C000000u, 0x8C000000u, 0xAC000000u};
    for (unsigned alias = 0; alias < 3; ++alias) {
        memset(ram, 0xA5, RAM_LEN);
        relocation_image(ram);
        memcpy(expected_ram, ram, RAM_LEN);
        memcpy(expected_ram + 0x4000, expected_ram + 0x10100, 0x3F00);
        vf3_matrix_state s = seeded_state(aliases[alias] + 0x10000), expected = s;
        expected.v[0] = 0xAC004000u; expected.v[1] = 0xAC014000u; expected.v[2] = 0xAC007F00u;
        expected.v[3] = get32(ram + 0x13FFC); expected.v[17] |= 1;
        expected.pc = 0xAC004000u; expected.budget -= 24198;
        CHECK(vf3_boot_relocate(&s, &map, &out) == VF3_BOOT_OK, "relocation alias %08x failed", aliases[alias]);
        CHECK(out.instructions == 24198 && out.bytes_written == 0x3F00 && out.pc == expected.pc, "relocation accounting wrong");
        CHECK(memcmp(&s, &expected, sizeof s) == 0, "relocation changed an untouched context field");
        CHECK(memcmp(ram, expected_ram, RAM_LEN) == 0, "relocation changed bytes outside original destination");

        memset(ram, 0xA5, RAM_LEN); crt_image(ram);
        put32(ram, 0x20084, aliases[alias] + 0x30000);
        put32(ram, 0x20094, aliases[alias] + 0x40000);
        put32(ram, 0x2008C, aliases[alias] + 0x50000);
        memcpy(expected_ram, ram, RAM_LEN);
        memset(expected_ram + 0x30000, 0, 12); memset(expected_ram + 0x40000, 0, 20); memset(expected_ram + 0x50000, 0, 28);
        s = seeded_state(aliases[alias] + 0x20000);
        if (alias == 0) s.v[17] &= ~0x40000000u; /* P0 clears also work in user mode. */
        expected = s;
        expected.v[0] = 0x0C09574Eu;
        for (unsigned i = 1; i < 15; ++i) expected.v[i] = 0;
        for (unsigned i = 21; i < 37; ++i) expected.v[i] = 0;
        expected.v[15] = 0x0C31FA80u; expected.v[16] = aliases[alias] + 0x2007C;
        expected.v[17] |= 1; expected.pc = 0x0C09574Eu; expected.budget -= 110;
        CHECK(vf3_boot_crt0(&s, &map, &out) == VF3_BOOT_OK, "CRT alias %08x failed", aliases[alias]);
        CHECK(out.instructions == 110 && out.bytes_written == 60 && out.pc == expected.pc, "CRT accounting wrong");
        CHECK(memcmp(&s, &expected, sizeof s) == 0, "CRT context/return-address semantics differ");
        CHECK(memcmp(ram, expected_ram, RAM_LEN) == 0, "CRT did not restrict clearing to descriptor ranges");
    }

    /* A low entry does not grant access to P1/P2 clear destinations. Check all
     * three descriptors, including later ones after otherwise valid clears. */
    const uint32_t descriptors[] = {0x20084, 0x20094, 0x2008C};
    for (unsigned alias = 1; alias < 3; ++alias) {
        for (unsigned clear = 0; clear < 3; ++clear) {
            memset(ram, 0xA5, RAM_LEN); crt_image(ram);
            put32(ram, descriptors[clear], aliases[alias] + 0x30000 + clear * 0x10000);
            vf3_matrix_state user = seeded_state(0x0C020000u);
            user.v[17] &= ~0x40000000u;
            unchanged_failure(vf3_boot_crt0, &user, &map, VF3_BOOT_UNSUPPORTED_CPU);
        }
    }

    memset(ram, 0xA5, RAM_LEN); crt_image(ram);
    vf3_matrix_state s = seeded_state(0x0C020000u);
    s.budget = 109; unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BUDGET);
    s = seeded_state(0x0C020000u); s.v[17] |= 0x8000u;
    unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_UNSUPPORTED_CPU);
    s = seeded_state(0x0C020000u); s.v[18] |= 0x80000u;
    unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_UNSUPPORTED_CPU);
    s = seeded_state(0x0C020000u); s.v[18] |= 0x100000u;
    unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_UNSUPPORTED_CPU);
    s = seeded_state(0x0C020002u); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_ENTRY);
    s = seeded_state(0x0C020000u); ram[0x2000A] ^= 1;
    unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_IMAGE); crt_image(ram);
    put32(ram, 0x20088, 0); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_RAM); crt_image(ram);
    put32(ram, 0x20088, UINT_MAX); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_RAM); crt_image(ram);
    put32(ram, 0x20084, 0x0CFFFFFCu); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_RAM); crt_image(ram);
    put32(ram, 0x20084, 0x0C020084u); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_IMAGE); crt_image(ram);
    put32(ram, 0x2009C, 0); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_RAM); crt_image(ram);
    put32(ram, 0x200A0, 0xDEAD0000u); unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_IMAGE); crt_image(ram);
    win.len = 0x200A4; unchanged_failure(vf3_boot_crt0, &s, &map, VF3_BOOT_BAD_RAM); win.len = RAM_LEN;

    relocation_image(ram); s = seeded_state(0xAC010000u); s.budget = 24197;
    unchanged_failure(vf3_boot_relocate, &s, &map, VF3_BOOT_BUDGET);
    s = seeded_state(0xAC010000u); s.v[17] &= ~0x40000000u;
    unchanged_failure(vf3_boot_relocate, &s, &map, VF3_BOOT_UNSUPPORTED_CPU);
    s = seeded_state(0xAC010000u); put32(ram, 0x10024, 0xAC010000u);
    unchanged_failure(vf3_boot_relocate, &s, &map, VF3_BOOT_BAD_IMAGE);
    free(ram); free(expected_ram);
    printf("boot entry boundary tests: %d failures\n", failures);
}

static int read_exact(const char *path, uint8_t *data, size_t len)
{
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    const int ok = fread(data, 1, len, f) == len && fgetc(f) == EOF;
    fclose(f);
    return ok;
}
static int context_file(const char *path, vf3_matrix_state *s)
{
    uint8_t bytes[64 * 4];
    if (!read_exact(path, bytes, sizeof bytes)) return 0;
    memset(s, 0, sizeof *s);
    s->pc = get32(bytes);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = get32(bytes + (i + 1) * 4);
    s->gbr = get32(bytes + 55 * 4);
    for (unsigned i = 0; i < 8; ++i) s->bank[i] = get32(bytes + (56 + i) * 4);
    s->gbr_known = s->bank_known = 1; /* these fields are explicitly present */
    s->budget = UINT_MAX;           /* host execution budget, not captured CPU state */
    return 1;
}
static void reference_test(char **argv)
{
    segment_fn fn = !strcmp(argv[2], "relocate") ? vf3_boot_relocate : !strcmp(argv[2], "crt0") ? vf3_boot_crt0 : NULL;
    CHECK(fn != NULL, "unknown segment %s", argv[2]);
    if (!fn) return;
    uint8_t *ram = malloc(RAM_LEN), *expected_ram = malloc(RAM_LEN);
    vf3_matrix_state s, expected;
    const int loaded = ram && expected_ram && context_file(argv[3], &s) && read_exact(argv[4], ram, RAM_LEN) &&
                       context_file(argv[5], &expected) && read_exact(argv[6], expected_ram, RAM_LEN);
    CHECK(loaded, "reference files absent or wrong-sized; no fallback is permitted");
    if (loaded) {
        vf3_ram_win win = {ram, RAM_BASE, RAM_LEN};
        vf3_ram_map map = {&win, 1, 0, NULL, NULL, NULL};
        vf3_boot_result out;
        const vf3_boot_status status = fn(&s, &map, &out);
        CHECK(status == VF3_BOOT_OK, "native %s status %d at %08x", argv[2], status, out.pc);
        unsigned changed = 0, regdiff = 0;
        for (unsigned i = 0; i < RAM_LEN; ++i) if (ram[i] != expected_ram[i]) {
            if (changed < 8) fprintf(stderr, "RAM %08x native %02x reference %02x\n", RAM_BASE + i, ram[i], expected_ram[i]);
            ++changed;
        }
        for (unsigned i = 0; i < 54; ++i) if (s.v[i] != expected.v[i]) {
            fprintf(stderr, "register[%u] native %08x reference %08x\n", i, s.v[i], expected.v[i]); ++regdiff;
        }
        for (unsigned i = 0; i < 8; ++i) if (s.bank[i] != expected.bank[i]) {
            fprintf(stderr, "bank[%u] native %08x reference %08x\n", i, s.bank[i], expected.bank[i]); ++regdiff;
        }
        if (s.gbr != expected.gbr) { fprintf(stderr, "GBR native %08x reference %08x\n", s.gbr, expected.gbr); ++regdiff; }
        if (s.pc != expected.pc) { fprintf(stderr, "PC native %08x reference %08x\n", s.pc, expected.pc); ++regdiff; }
        CHECK(changed == 0 && regdiff == 0, "strict reference mismatch");
        printf("native %s reference: %u RAM bytes differ, %u/64 context words differ; %u instructions; handoff %08x\n",
               argv[2], changed, regdiff, out.instructions, s.pc);
    }
    free(ram); free(expected_ram);
}
int main(int argc, char **argv)
{
    if (argc == 1) unit_tests();
    else if (argc == 7 && !strcmp(argv[1], "--reference")) reference_test(argv);
    else {
        fprintf(stderr, "usage: %s [--reference relocate|crt0 before.context.bin before.memory.bin after.context.bin after.memory.bin]\n", argv[0]);
        return 2;
    }
    return failures != 0;
}
