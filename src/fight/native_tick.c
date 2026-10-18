/* native_tick.c - run one fight scheduler tick on host code only (see native_tick.h). */
#include "fight/native_tick.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/family_hooks.h"
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "sys/bios_syscall.h"

#define TA_AREA_BASE 0x10000000u         /* area 4: Tile Accelerator FIFOs and texture memory */
#define TA_AREA_END  0x14000000u
#define GUEST_RETURN_SENTINEL 0xDEAD0000u
#define SPG_VBLANK_IN_LINE 0x104u
#define BLOCK_BUDGET 1000000000u

/* ---------------------------------------------------------------- loading */

/* A recording is a stream of 64-bit records: a marker word (low 16 bits 0xFA30 = entry registers,
 * 0xFA50 = RAM windows, 0xFA32 = exit registers, 0xFA60 = exit windows), then the payload. */
static int read_rec(FILE *f, uint64_t *v) { return fread(v, 8, 1, f) == 1; }

/* the extended bank (xfpc records) of the last loaded entry; zero when the capture carries none */
static uint32_t snapshot_xf[16];

void vf3_native_get_xf(uint32_t xf[16]) { memcpy(xf, snapshot_xf, sizeof snapshot_xf); }
void vf3_native_set_xf(const uint32_t xf[16]) { memcpy(snapshot_xf, xf, sizeof snapshot_xf); }

static int load_pair(const char *path, unsigned pair, int want_exit, uint32_t regs[37], uint8_t **ram);

int vf3_native_load_snapshot(const char *path, unsigned pair, uint32_t regs[37], uint8_t **ram)
{
    return load_pair(path, pair, 0, regs, ram);
}

/* ---------------------------------------------------------------- the machine around the tick */

static struct {
    unsigned reads, writes, readable_calls, unowned_calls;
    uint32_t first_unowned;
    uint32_t *ta;
    size_t ta_len, ta_cap;
    uint8_t *ram;                /* the image of the run in progress */
    uint32_t stop_pc;            /* run ends when control reaches this address (0: the return sentinel) */
    vf3_gdrom *gd;               /* optional GD-ROM model behind the BIOS vector */
    unsigned bios_calls;
} machine;

static uint32_t device_read(void *context, uint32_t address, unsigned size)
{
    (void)context; (void)size;
    ++machine.reads;
    /* PVR SPG_STATUS: the vertical-blank handler samples the scanline (low 10 bits) it was raised on. The emulator's
     * recording shows line 260 (0x104) at the vblank-in interrupt; the run models no beam, so that is what a read
     * inside the interrupt sees. */
    if ((address & 0x1FFFFFFFu) == 0x005F810Cu) return SPG_VBLANK_IN_LINE;
    return 0;
}

static void device_write(void *context, uint32_t address, unsigned size, uint32_t value)
{
    (void)context; (void)size;
    ++machine.writes;
    if (address < TA_AREA_BASE || address >= TA_AREA_END) return;   /* QACR, store-queue folds */
    if (machine.ta_len == machine.ta_cap) {
        machine.ta_cap = machine.ta_cap ? 2 * machine.ta_cap : 1u << 16;
        machine.ta = realloc(machine.ta, machine.ta_cap * sizeof *machine.ta);
        if (!machine.ta) { machine.ta_cap = machine.ta_len = 0; return; }
    }
    machine.ta[machine.ta_len++] = value;
}

/* the oracle-derived table only knows entries the captured fight ticks called; every readable port is a function entry too
 * (the boot loader's own functions are not in the fight table) */
static void trace_enter(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{
    (void)ram; (void)ok;
    fprintf(stderr, "enter %08x pr %08x sp %08x\n", entry, s->v[16], s->v[15]);
}

static int call_target(uint32_t entry)
{
    return vf3_native_call_target(entry) || vf3_readable_find(entry) != NULL;
}

static int readable_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    const int ok = vf3_readable_override(entry, s, ram, handled);
    if (*handled) ++machine.readable_calls;
    return ok;
}

/* guest RAM behind the GD-ROM model: transfers land in the image of the run in progress */
static void gd_write(void *ctx, uint32_t addr, const uint8_t *data, uint32_t len)
{
    (void)ctx;
    const uint32_t off = (addr & 0x0FFFFFFFu) - VF3_NATIVE_RAM_BASE;
    if (machine.ram && (addr & 0x0FFFFFFFu) >= VF3_NATIVE_RAM_BASE && off + len <= VF3_NATIVE_RAM_LEN)
        memcpy(machine.ram + off, data, len);
}

static uint32_t gd_mem_read(void *ctx, uint32_t addr) { return vf3_mem_u32((const vf3_ram_map *)ctx, addr); }
static void gd_mem_write(void *ctx, uint32_t addr, uint32_t v) { vf3_mem_set_u32((const vf3_ram_map *)ctx, addr, v); }

void vf3_native_set_stop(uint32_t pc) { machine.stop_pc = pc; }

void vf3_native_attach_gdrom(vf3_gdrom *gd)
{
    machine.gd = gd;
    if (gd) { gd->write = gd_write; gd->write_ctx = NULL; }
}

static int unowned_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    if (machine.gd && (entry & 0x0FFFFFFFu) == VF3_BIOS_SYSCALL_VECTOR) {
        const vf3_guest_mem gm = { (void *)ram, gd_mem_read, gd_mem_write };
        const uint32_t args[8] = { 0, 0, 0, 0, s->v[4], s->v[5], s->v[6], s->v[7] };
        uint32_t r0 = 0;
        /* VF3_GD_NOCLOCK=1: a poll never advances the drive (isolates timing-dependent differences) */
        const int served = getenv("VF3_GD_NOCLOCK") ? vf3_bios_gd_syscall(machine.gd, &gm, args, &r0)
                                                     : vf3_bios_gd_syscall_clocked(machine.gd, &gm, args, &r0);
        if (served) {
            ++machine.bios_calls;
            s->v[0] = r0;
            s->pc = s->v[16];
            *handled = 1;
            return 1;
        }
    }
    if (!machine.unowned_calls++) machine.first_unowned = entry;
    *handled = 0;
    return 0;
}

int vf3_native_tick_run(uint8_t *ram, const uint32_t regs[37], uint32_t entry, uint32_t gbr,
                        vf3_native_tick_result *out)
{
    vf3_ram_win window = { ram, VF3_NATIVE_RAM_BASE, VF3_NATIVE_RAM_LEN };
    vf3_ram_map map = { &window, 1, 0, device_read, device_write, NULL };
    vf3_matrix_state st;

    machine.reads = machine.writes = machine.readable_calls = machine.unowned_calls = 0;
    machine.first_unowned = 0;
    machine.bios_calls = 0;
    machine.ram = ram;
    machine.ta_len = 0;                /* the buffer itself is reused between runs */
    memset(&st, 0, sizeof st);
    st.budget = BLOCK_BUDGET;
    memcpy(st.v, regs, 37 * sizeof regs[0]);
    memcpy(st.v + 37, snapshot_xf, sizeof snapshot_xf);
    st.v[16] = machine.stop_pc ? machine.stop_pc : GUEST_RETURN_SENTINEL;
    st.gbr = gbr;
    st.gbr_known = 1;
    st.bank_known = 1;                 /* the banked file is written before it is read */

    vf3_family_override = readable_hook;
    vf3_family_missing = unowned_hook;
    vf3_family_fail = NULL;
    vf3_family_enter = getenv("VF3_TRACE_ENTRIES") ? trace_enter : NULL;
    vf3_family_leave = NULL;
    vf3_family_call_entry = call_target;
    vf3_family_complete_calls = 1;
    vf3_sq_model = 1;

    const int ok = vf3_matrix_family(entry, &st, &map);

    memset(out, 0, sizeof *out);
    out->ok = ok;
    out->pc = st.pc;
    out->failed_pc = st.failed_pc;
    out->steps_budget_used = BLOCK_BUDGET - st.budget;
    out->readable_calls = machine.readable_calls;
    out->unowned_calls = machine.unowned_calls;
    out->first_unowned = machine.first_unowned;
    out->bios_calls = machine.bios_calls;
    out->device_reads = machine.reads;
    out->device_writes = machine.writes;
    out->ta_words = (unsigned)machine.ta_len;
    out->oob = map.oob;
    out->ta = machine.ta;
    memcpy(out->regs, st.v, sizeof out->regs);
    return ok;
}

/* ---------------------------------------------------------------- the recorded exit */

/* Skips or loads one window list: <count>, then per window <base> <len> and len/4 word records. */
static int read_windows(FILE *f, uint8_t **ram)
{
    uint64_t v, windows;
    if (!read_rec(f, &windows)) return 0;
    for (uint32_t w = 0; w < (uint32_t)windows; ++w) {
        uint64_t base, len;
        if (!read_rec(f, &base) || !read_rec(f, &len)) return 0;
        const int is_ram = ram && (uint32_t)base == VF3_NATIVE_RAM_BASE && (uint32_t)len == VF3_NATIVE_RAM_LEN;
        if (is_ram && !*ram) *ram = malloc(VF3_NATIVE_RAM_LEN);
        for (uint32_t i = 0; i < (uint32_t)len / 4; ++i) {
            if (!read_rec(f, &v)) return 0;
            if (is_ram && *ram) {
                const uint32_t word = (uint32_t)v;
                memcpy(*ram + 4 * i, &word, 4);
            }
        }
    }
    return 1;
}

int vf3_native_load_exit(const char *path, unsigned pair, uint32_t regs[37], uint8_t **ram)
{
    return load_pair(path, pair, 1, regs, ram);
}

/* Walks the recording structurally (marker, then exactly its payload), so RAM words that happen to look like a marker are never
 * mistaken for one: per pair entry regs (0xFA30) [+ XF bank 0xFA70] + entry windows (0xFA50), exit regs (0xFA32) + exit windows (0xFA60). */
static int load_pair(const char *path, unsigned pair, int want_exit, uint32_t regs[37], uint8_t **ram)
{
    FILE *f = fopen(path, "rb");
    uint64_t v;
    unsigned seen = 0;
    int stage = 0; /* 0 entry regs, 1 entry windows, 2 exit regs, 3 exit windows */
    *ram = NULL;
    memset(snapshot_xf, 0, sizeof snapshot_xf);
    if (!f) return 0;
    while (read_rec(f, &v)) {
        const uint32_t marker = (uint32_t)(v & 0xFFFFu);
        if ((v >> 16) == 0 || marker < 0xFA30) continue;
        const int mine = seen == pair;
        if (marker == 0xFA30 && stage == 0) {
            for (int i = 0; i < 37; ++i) {
                if (!read_rec(f, &v)) goto fail;
                if (mine && !want_exit) regs[i] = (uint32_t)v;
            }
            stage = 1;
        } else if (marker == 0xFA70 && stage == 1) {
            for (int i = 0; i < 16; ++i) {
                if (!read_rec(f, &v)) goto fail;
                if (mine && !want_exit) snapshot_xf[i] = (uint32_t)(v >> 16);
            }
        } else if (marker == 0xFA50 && stage == 1) {
            if (!read_windows(f, mine && !want_exit ? ram : NULL)) goto fail;
            if (mine && !want_exit) { fclose(f); return *ram != NULL; }
            stage = 2;
        } else if (marker == 0xFA32 && stage == 2) {
            for (int i = 0; i < 37; ++i) {
                if (!read_rec(f, &v)) goto fail;
                if (mine && want_exit) regs[i] = (uint32_t)v;
            }
            stage = 3;
        } else if (marker == 0xFA60 && stage == 3) {
            if (!read_windows(f, mine && want_exit ? ram : NULL)) goto fail;
            if (mine && want_exit) { fclose(f); return *ram != NULL; }
            ++seen;
            stage = 0;
        }
    }
fail:
    fclose(f);
    free(*ram);
    *ram = NULL;
    return 0;
}
