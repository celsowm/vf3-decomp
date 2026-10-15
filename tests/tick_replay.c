/* tick_replay.c - whole-function replay of one VF3_FULL entry/exit pair with a
 * FULL 16 MiB RAM image on both sides (see tools/tick_capture.py).
 *
 * usage: vf3tick <entry> <trace.bin> [pair-index]
 *
 * Trace layout (vf3trace.cpp, VF3_FULL + "rampc <pc>"):
 *   pc<<16|FA30, 37 regs, pc<<16|FA31, pc<<16|FA50, nwin, base, len,
 *   len/4 words, pc<<16|FA51, ... pc<<16|FA32, 37 regs, pc<<16|FA33,
 *   [xf block], pc<<16|FA60, nwin, base, len, words, pc<<16|FA61
 * Registers: r0-r15, pr, sr, fpscr, macl, mach, fr0-fr15 (37 values).
 *
 * The native side runs the ported C from the entry registers + entry RAM and
 * the result is diffed against the emulator's exit RAM. Reports are grouped
 * into address ranges so the first diverging function is easy to name.
 * Hardware accesses outside RAM are logged and answered with zero.
 */
#include "fight/matrix_family.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_BASE 0x0C000000u
#define RAM_LEN 0x01000000u
#define MARK(rec) ((uint32_t)((rec) & 0xFFFFu))

typedef struct {
    uint32_t regs[37];
    uint32_t pc;
    uint8_t *ram;
    int have_regs, have_ram;
} Snap;

static uint32_t dev_log[64][3];
static unsigned dev_n, dev_total;

static uint32_t dev_read(void *c, uint32_t a, unsigned sz)
{
    (void)c;
    if (dev_n < 64) { dev_log[dev_n][0] = a; dev_log[dev_n][1] = sz; dev_log[dev_n][2] = 0xFFFFFFFFu; ++dev_n; }
    ++dev_total;
    return 0;
}

static void dev_write(void *c, uint32_t a, unsigned sz, uint32_t v)
{
    (void)c;
    if (dev_n < 64) { dev_log[dev_n][0] = a; dev_log[dev_n][1] = sz; dev_log[dev_n][2] = v; ++dev_n; }
    ++dev_total;
}

static int read_rec(FILE *f, uint64_t *v) { return fread(v, 8, 1, f) == 1; }

/* Find pair #idx: entry snapshot + entry RAM, exit snapshot + exit RAM. */
static int load_pair(const char *path, unsigned idx, Snap *in, Snap *out)
{
    FILE *f = fopen(path, "rb");
    uint64_t v;
    unsigned pair = 0;
    int stage = 0;               /* 0 wait entry, 1 entry ram, 2 wait exit, 3 exit ram */
    if (!f) return 0;
    memset(in, 0, sizeof *in); memset(out, 0, sizeof *out);
    while (read_rec(f, &v)) {
        uint32_t m = MARK(v);
        if ((v >> 16) == 0 || m < 0xFA30) continue;
        if (m == 0xFA30 || m == 0xFA32) {
            Snap *s = (m == 0xFA30) ? in : out;
            if (m == 0xFA30 && stage != 0) continue;
            if (m == 0xFA32 && stage != 2) continue;
            if (pair != idx) { if (m == 0xFA32) { ++pair; stage = 0; } else stage = 2; continue; }
            s->pc = (uint32_t)(v >> 16);
            for (int i = 0; i < 37; ++i) { if (!read_rec(f, &v)) goto done; s->regs[i] = (uint32_t)v; }
            s->have_regs = 1;
            stage = (m == 0xFA30) ? 1 : 3;
        } else if ((m == 0xFA50 && stage == 1) || (m == 0xFA60 && stage == 3)) {
            Snap *s = (m == 0xFA50) ? in : out;
            uint32_t nwin;
            if (!read_rec(f, &v)) goto done;
            nwin = (uint32_t)v;
            for (uint32_t w = 0; w < nwin; ++w) {
                uint64_t b, l;
                if (!read_rec(f, &b) || !read_rec(f, &l)) goto done;
                uint32_t base = (uint32_t)b, len = (uint32_t)l;
                if (base == RAM_BASE && len == RAM_LEN && !s->ram) s->ram = malloc(RAM_LEN);
                for (uint32_t i = 0; i < len / 4; ++i) {
                    if (!read_rec(f, &v)) goto done;
                    if (s->ram && base == RAM_BASE) memcpy(s->ram + i * 4, &(uint32_t){(uint32_t)v}, 4);
                }
            }
            s->have_ram = s->ram != NULL;
            if (m == 0xFA50) stage = 2;
            else { fclose(f); return in->have_regs && in->have_ram && out->have_regs && out->have_ram; }
        }
    }
done:
    fclose(f);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3) { fprintf(stderr, "usage: vf3tick entry trace.bin [pair]\n"); return 2; }
    uint32_t entry = (uint32_t)strtoul(argv[1], NULL, 0);
    unsigned idx = argc > 3 ? (unsigned)strtoul(argv[3], NULL, 0) : 0;
    Snap in, out;
    if (!load_pair(argv[2], idx, &in, &out)) { fprintf(stderr, "pair %u not found\n", idx); return 2; }

    vf3_ram_win win = { in.ram, RAM_BASE, RAM_LEN };
    vf3_ram_map ram = { &win, 1, 0, dev_read, dev_write, NULL };
    vf3_matrix_state st;
    memset(&st, 0, sizeof st);
    st.budget = 50000000u;
    memcpy(st.v, in.regs, sizeof in.regs);

    int ok = vf3_matrix_family(entry, &st, &ram);
    printf("run: %s  exit pc %08x (want pr-ish %08x)  budget left %u  oob %u  dev %u\n",
           ok ? "completed" : "UNSUPPORTED", ok ? st.pc : st.failed_pc,
           out.regs[16], st.budget, ram.oob, dev_total);
    for (unsigned i = 0; i < dev_n && i < 12; ++i)
        printf("  dev %c %08x/%u %08x\n", dev_log[i][2] == 0xFFFFFFFFu ? 'R' : 'W',
               dev_log[i][0], dev_log[i][1], dev_log[i][2] == 0xFFFFFFFFu ? 0 : dev_log[i][2]);

    /* register diff */
    static const char *names[37] = { "r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11","r12","r13",
        "r14","r15","pr","sr","fpscr","macl","mach","fr0","fr1","fr2","fr3","fr4","fr5","fr6","fr7","fr8","fr9",
        "fr10","fr11","fr12","fr13","fr14","fr15" };
    int regdiff = 0;
    for (int i = 0; i < 37; ++i)
        if (st.v[i] != out.regs[i]) { ++regdiff; if (regdiff <= 12) printf("  reg %-5s got %08x want %08x\n", names[i], st.v[i], out.regs[i]); }
    printf("reg diffs: %d\n", regdiff);

    /* RAM diff: group differing bytes into runs (gap <= 16) */
    unsigned runs = 0, total = 0;
    uint32_t s0 = 0, last = 0;
    int open = 0;
    for (uint32_t i = 0; i <= RAM_LEN; ++i) {
        int d = i < RAM_LEN && in.ram[i] != out.ram[i];
        if (d) {
            ++total;
            if (!open) { s0 = i; open = 1; }
            else if (i - last > 16) {
                if (runs < 40) printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last);
                ++runs; s0 = i;
            }
            last = i;
        }
    }
    if (open) { if (runs < 40) printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last); ++runs; }
    printf("ram diff bytes: %u in %u runs\n", total, runs);
    return ok && !regdiff && !total ? 0 : 1;
}
