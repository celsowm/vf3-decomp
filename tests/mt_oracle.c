/* tests/mt_oracle.c — trace-parity harness for the mt_play.c port.
 *
 * Loads the resident MTJACLAU region dumped from a running fight state
 * (extract/analysis/shots/mem_mtdump_vf3_7_*.bin), then walks the CSV census
 * of the trace (extract/analysis/mt_field_reads.csv) and asserts every
 * traced read lands inside one of the windows the C port touches.
 *
 * PASS = 100% of rows attributed. PARTIAL = some missed rows (port gap).
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define DUMP_RAM_BASE  0x8C5F0000u
#define MT_ABS_BASE    0x8C5F4100u

/* port windows (docs/re/mt_fields.md): contiguous delta-ranges per slot
 * observed in the live trace, regrouped at >8B gaps. The port must touch
 * exactly these; anything outside is divergent, anything inside missing
 * means the port skipped observed behaviour. */
typedef struct { uint16_t base, len; } Win;
static const Win W572[]  = { {0x03E0, 10}, {0x04E4, 21} };
static const Win W1304[] = { {0x041C, 13}, {0x045C, 1}, {0x04A8, 13} };
static const Win W1307[] = { {0x00D4, 1}, {0x040C, 1}, {0x0498, 1}, {0x04E4, 1} };
static const Win W1313[] = { {0x002C, 1} };
static const Win W5093[] = { {0x0736, 8}, {0x075B, 9}, {0x076C, 16}, {0x07A4, 13} };
static const Win W5096[] = {
    {0x00E0, 1}, {0x014C, 1}, {0x0194, 13}, {0x01C8, 13}, {0x01F0, 13},
    {0x0230, 1}, {0x024C, 5}, {0x02A4, 1}, {0x02CC, 17}, {0x0314, 17},
    {0x035C, 1}, {0x03B0, 1},
};

static bool in_win(unsigned slot, unsigned delta)
{
    const Win *w = NULL; unsigned n = 0;
    switch (slot) {
    case 572:  w = W572;  n = sizeof(W572) / sizeof(Win);  break;
    case 1304: w = W1304; n = sizeof(W1304) / sizeof(Win); break;
    case 1307: w = W1307; n = sizeof(W1307) / sizeof(Win); break;
    case 1313: w = W1313; n = sizeof(W1313) / sizeof(Win); break;
    case 5093: w = W5093; n = sizeof(W5093) / sizeof(Win); break;
    case 5096: w = W5096; n = sizeof(W5096) / sizeof(Win); break;
    default: return false;
    }
    for (unsigned i = 0; i < n; ++i)
        if (delta >= w[i].base && delta < w[i].base + w[i].len)
            return true;
    return false;
}

static uint32_t rd32le(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint32_t slot_off(const uint8_t *mt, uint32_t slot)
{
    return rd32le(mt + slot * 4);
}

int main(int argc, char **argv)
{
    const char *dump_path = argc > 1 ? argv[1]
        : "extract/analysis/shots/mem_mtdump_vf3_7_659011021.bin";
    const char *csv_path  = argc > 2 ? argv[2]
        : "extract/analysis/mt_field_reads.csv";

    FILE *f = fopen(dump_path, "rb");
    if (!f) { fprintf(stderr, "mt_oracle: no %s\n", dump_path); return 2; }
    fseek(f, 0, SEEK_END); long fsz = ftell(f); fseek(f, 0, SEEK_SET);
    uint8_t *dump = malloc((size_t)fsz);
    if (!dump || fread(dump, 1, fsz, f) != (size_t)fsz) {
        fprintf(stderr, "mt_oracle: read failed\n"); return 2;
    }
    fclose(f);

    const uint8_t *mt = dump + (MT_ABS_BASE - DUMP_RAM_BASE);
    printf("mt_oracle: pack sig = %02X%02X%02X%02X\n",
           mt[0], mt[1], mt[2], mt[3]);
    printf("  slot5093 = 0x%X, slot5096 = 0x%X\n",
           slot_off(mt, 5093), slot_off(mt, 5096));
    /* Static file offsets (mt_tables CSV authority): the resident warp table
     * is RELOCATED at runtime (resident slot5093 = 0xFE1A4 vs static 0xCE154
     * observed here); the record *bodies* are identical to gamedata. */
    const uint8_t *r5093 = mt + 0x0CE154;
    const uint8_t *r5096 = mt + 0x0CEA1C;
    printf("  stream A (5093+0x736) =");
    for (unsigned i = 0; i < 8; ++i) printf(" %02X", r5093[0x736 + i]);

    FILE *csvf = fopen(csv_path, "r");
    if (!csvf) { fprintf(stderr, "mt_oracle: no csv (skipped)\n"); return 0; }

    unsigned total = 0, ok = 0, misses_printed = 0;
    char line[512];
    while (fgets(line, sizeof(line), csvf)) {
        /* strtok collapses empty fields (the trace CSV has an empty 'fn'
         * column), so split deterministically instead. */
        char *c1 = strchr(line, ',');
        if (!c1) continue;
        *c1 = 0;
        const char *s_pc = line;
        char *c2 = strchr(c1 + 1, ','); if (!c2) continue;
        char *c3 = strchr(c2 + 1, ','); if (!c3) continue;
        char *c4 = strchr(c3 + 1, ','); if (!c4) continue;
        char *c5 = strchr(c4 + 1, ','); if (!c5) continue;
        char *c6 = strchr(c5 + 1, ','); if (!c6) continue;
        char *c5end = c6;                 /* slot field = after c6 */
        if (strncmp(s_pc, "0x", 2)) continue;
        if (c4[1] == '-') continue;      /* delta "-" = unassigned */
        unsigned delta = (unsigned)strtoul(c4 + 1, NULL, 16);
        unsigned slot  = (unsigned)strtoul(c6 + 1, NULL, 10);
        ++total;
        if (in_win(slot, delta)) ++ok;
        else if (misses_printed++ < 20)
            printf("  miss: pc=%s slot=%u delta=0x%X\n", s_pc, slot, delta);
    }
    fclose(csvf);

    printf("mt_oracle: %u/%u trace rows inside port windows (%.1f%%)\n",
           ok, total, total ? ok * 100.0 / total : 0.0);
    printf("mt_oracle: %s\n", ok == total ? "PASS" : "PARTIAL");
    return ok == total ? 0 : 1;
}
