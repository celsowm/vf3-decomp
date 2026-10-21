/* native_tick.c - run one fight scheduler tick on host code only (see native_tick.h). */
#include "fight/native_tick.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

#define AICA_RAM_BASE 0x00800000u
#define AICA_RAM_LEN 0x200000u

static struct {
    uint32_t *ta;
    size_t ta_len, ta_cap;
    uint8_t *ram;                /* the last top-level image; GD can advance between calls */
    vf3_gdrom *gd;               /* optional GD-ROM model behind the BIOS vector */
    void (*gd_previous_write)(void *, uint32_t, const uint8_t *, uint32_t);
    void *gd_previous_write_ctx;
    uint32_t istnrm;             /* ASIC normal interrupt status (SB_ISTNRM): pending events the model raised */
    unsigned render_started;     /* STARTRENDER writes not yet taken by the caller */
    uint32_t maple_list;         /* SB_MDSTAR as last written */
    unsigned maple_started;      /* Maple DMA starts (SB_MDST written with bit 0) not yet taken by the caller */
    unsigned dma2_started;       /* SH-4 DMAC channel 2 starts (CHCR2 written with DE) not yet taken by the caller */
    vf3_native_device_bus bus;
} machine;

typedef struct {
    unsigned budget;
    uint32_t extra_stop, stop_pc;
    void (*poll_hook)(void *);
    void *poll_ctx;
    uint32_t (*budget_hook)(void);
} native_run_config;
static native_run_config next_run;

/* Execution frames belong to the host stack; hardware belongs to the session.
 * A nested interrupt commits device effects and contributes to its parent's
 * diagnostics, but cannot replace the interrupted invocation's configuration. */
typedef struct native_run {
    struct native_run *parent;
    native_run_config config;
    uint8_t *ram;
    uint32_t seed_xf[16];
    unsigned reads, writes, readable_calls, unowned_calls, bios_calls, ta_failed;
    unsigned device_errors;
    uint32_t first_device_error;
    uint32_t first_unowned, nested_oob;
    unsigned nested_failures;
    uint32_t first_nested_entry, first_nested_failed_pc;
    uint64_t granted_steps, nested_steps;
} native_run;
static native_run *active_run;

/* Sound RAM and device clocks persist across calls, including nested IRQs. */
static uint8_t aica_ram[AICA_RAM_LEN];

/* The ARM7 sound driver answers the SH-4 upload mailbox at 0x008000B0 (command, written by the SH-4) / 0x008000B4 (state,
 * written by the driver): the driver raises B4 once it is idle, the SH-4 sets B0 = 1, the driver clears B4 when it has taken
 * the data, the SH-4 clears B0. Poll counts measured in the emulator from savestate 21 (docs/re/phase4_findings.md). */
#define AICA_MBOX_CMD 0x008000B0u
#define AICA_MBOX_STATE 0x008000B4u
#define AICA_MBOX_IDLE_POLLS 2223u
#define AICA_MBOX_BUSY_POLLS 5947u
static unsigned aica_mbox_polls;
/* The upload engine: the SH-4 writes source / destination / length to 0x90 / 0x94 / 0x98 and polls 0x98, which reads back the
 * length until the driver has copied it. Emulator state 27: 325,867 and 315,413 busy reads for two 0x25EB0-byte uploads,
 * about 2.1 reads per byte. */
#define AICA_UPLOAD_LEN 0x00800098u
#define AICA_UPLOAD_POLLS_PER_BYTE_X10 21u
static uint32_t aica_upload_len;
static uint64_t aica_upload_polls_left;

/* The game's free-running frame clock: TMU channel 0 (TCNT0, 0xFFD8000C, read through the 0x1Fxxxxxx mirror after the
 * driver masks with 0x1FFFFFFF). The init at 0x8C039C10 starts all three channels from 0xFFFFFFFF with TCR = 2; the
 * emulator's TCNT0 counts down by 13,033 per frame (3,336,670 cycles / 256). The frame loop (0x8C059B48), the vblank
 * handler (0x8C063C40) and the ASIC handler (0x8C06402C) sample it and store old - new as the frame delta, so a reader
 * that always returns 0 makes every timed wait last for ever. Off by default: the fight ticks never read it. */
static int tmu_on;
static uint64_t tmu_cycles;

void vf3_native_enable_tmu(void) { tmu_on = 1; }
void vf3_native_tmu_advance(uint32_t cycles) { if (tmu_on) tmu_cycles += cycles; }
void vf3_native_tmu_set(uint32_t tcnt)
{
    /* tcnt = 0xFFFFFFFF - cycles/256, so seed the cycle accumulator from the value the savestate sampled last. */
    tmu_cycles = (uint64_t)(0xFFFFFFFFu - tcnt) << 8;
}

static uint32_t device_read(void *context, uint32_t address, unsigned size)
{
    (void)context; (void)size;
    ++active_run->reads;
    if (getenv("VF3_DEVLOG")) fprintf(stderr, "devread %08x size %u\n", address, size);
    if (tmu_on && (address & 0x1FFFFFFFu) == 0x1FD8000Cu)   /* TCNT0: counts down at CPU/256 */
        return (uint32_t)(0xFFFFFFFFu - (tmu_cycles >> 8));
    /* PVR SPG_STATUS: the vertical-blank handler samples the scanline (low 10 bits) it was raised on. The emulator's
     * recording shows line 260 (0x104) at the vblank-in interrupt; the run models no beam, so that is what a read
     * inside the interrupt sees. */
    if ((address & 0x1FFFFFFFu) == AICA_UPLOAD_LEN) {
        if (!aica_upload_polls_left) return 0;
        --aica_upload_polls_left;
        return aica_upload_len;
    }
    if ((address & 0x1FFFFFFFu) == AICA_MBOX_STATE) {
        uint32_t cmd;
        memcpy(&cmd, aica_ram + (AICA_MBOX_CMD - AICA_RAM_BASE), 4);
        ++aica_mbox_polls;
        return cmd ? (aica_mbox_polls >= AICA_MBOX_BUSY_POLLS ? 0u : 1u) : (aica_mbox_polls >= AICA_MBOX_IDLE_POLLS ? 1u : 0u);
    }
    if ((address & 0x1FFFFFFFu) >= AICA_RAM_BASE && (address & 0x1FFFFFFFu) - AICA_RAM_BASE + size <= AICA_RAM_LEN) {
        uint32_t v = 0;
        memcpy(&v, aica_ram + ((address & 0x1FFFFFFFu) - AICA_RAM_BASE), size > 4 ? 4 : size);
        return v;
    }
    if ((address & 0x1FFFFFFFu) == 0x005F810Cu) return SPG_VBLANK_IN_LINE;
    if ((address & 0x1FFFFFFFu) == 0x005F6900u) return machine.istnrm;
    if (machine.bus.read) {
        uint32_t value = 0;
        const int handled = machine.bus.read(machine.bus.context, address, size, &value);
        if (handled < 0) {
            if (!active_run->device_errors++) active_run->first_device_error = address;
            return 0;
        }
        if (handled) return value;
    }
    return 0;
}

static void device_write(void *context, uint32_t address, unsigned size, uint32_t value)
{
    (void)context; (void)size;
    ++active_run->writes;
    if (getenv("VF3_DEVLOG")) fprintf(stderr, "devwrite %08x size %u value %08x%c", address, size, value, 10);
    if (machine.bus.write && machine.bus.write(machine.bus.context, address, size, value) < 0) {
        if (!active_run->device_errors++) active_run->first_device_error = address;
        return;
    }
    if (tmu_on && (address & 0x1FFFFFFFu) == 0x1FD8000Cu)   /* a guest write re-seeds TCNT0 */
        tmu_cycles = (uint64_t)(0xFFFFFFFFu - value) << 8;
    if ((address & 0x1FFFFFFFu) == AICA_MBOX_CMD) aica_mbox_polls = 0;
    if ((address & 0x1FFFFFFFu) == AICA_UPLOAD_LEN) {
        aica_upload_len = value;
        aica_upload_polls_left = (uint64_t)value * AICA_UPLOAD_POLLS_PER_BYTE_X10 / 10u;
    }
    if ((address & 0x1FFFFFFFu) >= AICA_RAM_BASE && (address & 0x1FFFFFFFu) - AICA_RAM_BASE + size <= AICA_RAM_LEN)
        memcpy(aica_ram + ((address & 0x1FFFFFFFu) - AICA_RAM_BASE), &value, size > 4 ? 4 : size);
    if ((address & 0x1FFFFFFFu) == 0x005F6C04u) machine.maple_list = value;
    if ((address & 0x1FFFFFFFu) == 0x005F6C18u && (value & 1u)) ++machine.maple_started;
    if ((address & 0x1FFFFFFFu) == 0x1FA0002Cu && (value & 1u)) ++machine.dma2_started;
    if ((address & 0x1FFFFFFFu) == 0x005F6900u) machine.istnrm &= ~value;   /* write-1-to-clear */
    if ((address & 0x1FFFFFFFu) == 0x005F8014u) ++machine.render_started;
    if (address < TA_AREA_BASE || address >= TA_AREA_END) return;   /* QACR, store-queue folds */
    if (active_run->ta_failed) return;
    if (machine.ta_len == machine.ta_cap) {
        if (machine.ta_cap > SIZE_MAX / sizeof *machine.ta / 2) { active_run->ta_failed = 1; return; }
        const size_t cap = machine.ta_cap ? 2 * machine.ta_cap : 1u << 16;
        uint32_t *grown = realloc(machine.ta, cap * sizeof *machine.ta);
        if (!grown) { active_run->ta_failed = 1; return; }
        machine.ta = grown;
        machine.ta_cap = cap;
    }
    machine.ta[machine.ta_len++] = value;
}

/* the oracle-derived table only knows entries the captured fight ticks called; every readable port is a function entry too
 * (the boot loader's own functions are not in the fight table) */
static void trace_enter(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{
    (void)ok;
    fprintf(stderr, "enter %08x pr %08x sp %08x r4 %08x r5 %08x%c", entry, s->v[16], s->v[15], s->v[4], s->v[5], 10);
    if (entry == 0x0C040154u) fprintf(stderr, "  hdr r4 %08x [r4] %08x r5 %08x%c", s->v[4], vf3_matrix_read(ram, s->v[4], 4), s->v[5], 10);
    if (entry == 0x0C068FE4u) fprintf(stderr, "  scan r4 %08x%c", s->v[4], 10);
    if (entry == 0x0C06911Cu) fprintf(stderr, "  sc r4 %08x r5 %08x [0c113a0c] %08x fr4 %08x fr5 %08x%c", s->v[4], s->v[5], vf3_matrix_read(ram, 0x0C113A0Cu, 4), s->v[25], s->v[26], 10);
    if (entry == 0x0C06911Cu) fprintf(stderr, "  grid [29bcc4+1f0] %08x [29beb4] %08x [1b9610] %08x hdr %08x %08x %08x%c", vf3_matrix_read(ram, 0x0C29BCC4u + 0x1F0u, 4), vf3_matrix_read(ram, 0x0C29BEB4u, 4), vf3_matrix_read(ram, 0x0C1B9610u, 4), vf3_matrix_read(ram, 0x0CBCE800u, 4), vf3_matrix_read(ram, 0x0CBCE804u, 4), vf3_matrix_read(ram, 0x0CBCE808u, 4), 10);
    if (entry == 0x0C0A28D4u) fprintf(stderr, "  rec r4 %08x r5 %08x r6 %08x r7 %08x [r6+0..28] %08x %08x %08x %08x %08x %08x %08x %08x%c", s->v[4], s->v[5], s->v[6], s->v[7], vf3_matrix_read(ram, s->v[6], 4), vf3_matrix_read(ram, s->v[6] + 4, 4), vf3_matrix_read(ram, s->v[6] + 8, 4), vf3_matrix_read(ram, s->v[6] + 12, 4), vf3_matrix_read(ram, s->v[6] + 16, 4), vf3_matrix_read(ram, s->v[6] + 20, 4), vf3_matrix_read(ram, s->v[6] + 24, 4), vf3_matrix_read(ram, s->v[6] + 28, 4), 10);
    if (entry == 0x0C0A28D4u) fprintf(stderr, "  top [0c113a0c] %08x [0c113a18] %08x%c", vf3_matrix_read(ram, 0x0C113A0Cu, 4), vf3_matrix_read(ram, 0x0C113A18u, 4), 10);
    if (entry == 0x0C0A28D4u) fprintf(stderr, "  b0hdr %08x %08x %08x %08x %08x %08x %08x %08x%c", vf3_matrix_read(ram, 0x0C350000u, 4), vf3_matrix_read(ram, 0x0C350004u, 4), vf3_matrix_read(ram, 0x0C350008u, 4), vf3_matrix_read(ram, 0x0C35000Cu, 4), vf3_matrix_read(ram, 0x0C350010u, 4), vf3_matrix_read(ram, 0x0C350014u, 4), vf3_matrix_read(ram, 0x0C350018u, 4), vf3_matrix_read(ram, 0x0C35001Cu, 4), 10);
    if (entry == 0x0C035C60u) fprintf(stderr, "  [0c0ea314] %08x [0c0ea2ec] %08x%c", vf3_matrix_read(ram, 0x0C0EA314u, 4), vf3_matrix_read(ram, 0x0C0EA2ECu, 4), 10);
}

static void trace_leave(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{
    (void)ram;
    fprintf(stderr, "leave %08x ok %d r0 %08x pc %08x%c", entry, ok, s->v[0], s->pc, 10);
}

static int call_target(uint32_t entry)
{
    return vf3_native_call_target(entry) || vf3_readable_find(entry) != NULL;
}

static int gdrom_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled);

static int readable_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    /* An attached drive owns its live command state. Serve it before the
     * capture-specific REIOS adapter can answer with its synthetic idle/busy
     * state. Without a drive, leave that adapter unchanged for strict replay. */
    if (gdrom_hook(entry, s, ram, handled)) return 1;
    /* REIOS MISC (vector 0x8C001008): the game registers its interrupt handlers with it (r4 = function, r5 = vector id,
     * r6 = handler). The native run takes its vblank handlers directly, so the registration is only recorded. It is answered
     * here, before the chain: the generated gate dispatch escalates 0x0C001000..F back to the family dispatcher, which would
     * recurse for ever on a gate nobody owns. */
    if ((entry & 0x0FFFFFFFu) == 0x0C001008u) {
        if (getenv("VF3_TRACE_ENTRIES")) fprintf(stderr, "bios misc r4=%u r5=%08x r6=%08x\n", s->v[4], s->v[5], s->v[6]);
        s->v[0] = 0;
        s->pc = s->v[16];
        *handled = 1;
        return 1;
    }
    /* BIOS ROM-font syscall stubs (0x8C04A5C0 address, 0x8C04A5D4 lock, 0x8C04A5E8 unlock: jmp @[0x8C0000B4] with r1 = function).
     * No BIOS image is loaded: the font lives at its fixed address, a lock is granted and an unlock succeeds. */
    switch (entry & 0x0FFFFFFFu) {
    case 0x0C04A5C0u: s->v[0] = 0xA0100020u; s->pc = s->v[16]; *handled = 1; return 1;
    case 0x0C04A5D4u:
    case 0x0C04A5E8u: s->v[0] = 0; s->pc = s->v[16]; *handled = 1; return 1;
    default: break;
    }
    const int ok = vf3_readable_override(entry, s, ram, handled);
    if (*handled) ++active_run->readable_calls;
    return ok;
}

/* guest RAM behind the GD-ROM model: transfers land in the image of the run in progress */
static void gd_write(void *ctx, uint32_t addr, const uint8_t *data, uint32_t len)
{
    (void)ctx;
    const uint32_t off = (addr & 0x0FFFFFFFu) - VF3_NATIVE_RAM_BASE;
    uint8_t *ram = active_run ? active_run->ram : machine.ram;
    if (ram && (addr & 0x0FFFFFFFu) >= VF3_NATIVE_RAM_BASE && off <= VF3_NATIVE_RAM_LEN && len <= VF3_NATIVE_RAM_LEN - off)
        memcpy(ram + off, data, len);
}

static uint32_t gd_mem_read(void *ctx, uint32_t addr) { return vf3_mem_u32((const vf3_ram_map *)ctx, addr); }
static void gd_mem_write(void *ctx, uint32_t addr, uint32_t v) { vf3_mem_set_u32((const vf3_ram_map *)ctx, addr, v); }

void vf3_native_set_stop(uint32_t pc) { next_run.stop_pc = pc; }
void vf3_native_set_extra_stop(uint32_t pc) { next_run.extra_stop = pc; }
void vf3_native_set_budget(unsigned steps) { next_run.budget = steps; }
void vf3_native_raise_asic(uint32_t mask) { machine.istnrm |= mask; }
int vf3_native_gd_attached(void) { return machine.gd != NULL; }
void vf3_native_aica_poke(uint32_t offset, uint32_t value) { if (offset <= AICA_RAM_LEN - 4) memcpy(aica_ram + offset, &value, 4); }
uint32_t vf3_native_asic_pending(void) { return machine.istnrm; }
unsigned vf3_native_take_render(void) { const unsigned n = machine.render_started; machine.render_started = 0; return n; }
unsigned vf3_native_take_maple(uint32_t *list) { const unsigned n = machine.maple_started; machine.maple_started = 0; if (list) *list = machine.maple_list; return n; }
unsigned vf3_native_take_dma2(void) { const unsigned n = machine.dma2_started; machine.dma2_started = 0; return n; }
void vf3_native_set_budget_hook(uint32_t (*hook)(void)) { next_run.budget_hook = hook; }

void vf3_native_attach_gdrom(vf3_gdrom *gd)
{
    if (machine.gd == gd) return;
    if (machine.gd && machine.gd->write == gd_write && !machine.gd->write_ctx) {
        machine.gd->write = machine.gd_previous_write;
        machine.gd->write_ctx = machine.gd_previous_write_ctx;
    }
    machine.gd = gd;
    machine.gd_previous_write = gd ? gd->write : NULL;
    machine.gd_previous_write_ctx = gd ? gd->write_ctx : NULL;
    if (gd) { gd->write = gd_write; gd->write_ctx = NULL; }
}

void vf3_native_set_poll_hook(void (*hook)(void *), void *ctx) { next_run.poll_hook = hook; next_run.poll_ctx = ctx; }

int vf3_native_attach_device_bus(const vf3_native_device_bus *bus)
{
    if (active_run) return 0;
    if (bus) machine.bus = *bus;
    else memset(&machine.bus, 0, sizeof machine.bus);
    return 1;
}

int vf3_native_reset(void)
{
    if (active_run) return 0;
    vf3_native_attach_gdrom(NULL);
    free(machine.ta);
    memset(&machine, 0, sizeof machine);
    memset(&next_run, 0, sizeof next_run);
    memset(snapshot_xf, 0, sizeof snapshot_xf);
    memset(aica_ram, 0, sizeof aica_ram);
    aica_mbox_polls = 0;
    aica_upload_len = 0;
    aica_upload_polls_left = 0;
    tmu_on = 0;
    tmu_cycles = 0;
    vf3_bios_gd_set_cycle_clock(0, 0);
    vf3_bios_gd_set_poll_divider(1);
    vf3_matrix_reset_sq();
    return 1;
}

static int gdrom_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    if (machine.gd && (entry & 0x0FFFFFFFu) == VF3_BIOS_SYSCALL_VECTOR) {
        const vf3_guest_mem gm = { (void *)ram, gd_mem_read, gd_mem_write };
        const uint32_t args[8] = { 0, 0, 0, 0, s->v[4], s->v[5], s->v[6], s->v[7] };
        uint32_t r0 = 0;
        /* VF3_GD_NOCLOCK=1: a poll never advances the drive (isolates timing-dependent differences) */
        const int served = getenv("VF3_GD_NOCLOCK") ? vf3_bios_gd_syscall(machine.gd, &gm, args, &r0)
                                                     : vf3_bios_gd_syscall_clocked(machine.gd, &gm, args, &r0);
        if (served && getenv("VF3_GDTRACE")) fprintf(stderr, "gdsys r7 %u r4 %08x r5 %08x -> r0 %08x st %d left %u%c", s->v[7], s->v[4], s->v[5], r0, machine.gd->st.status, machine.gd->st.multi_read_count, 10);
        if (served && s->v[7] == 0 && getenv("VF3_GDTRACE")) fprintf(stderr, "  req cmd %u params %08x %08x %08x %08x%c", s->v[4], vf3_matrix_read(ram, s->v[5], 4), vf3_matrix_read(ram, s->v[5] + 4, 4), vf3_matrix_read(ram, s->v[5] + 8, 4), vf3_matrix_read(ram, s->v[5] + 12, 4), 10);
        if (served) {
            ++active_run->bios_calls;
            s->v[0] = r0;
            s->pc = s->v[16];
            *handled = 1;
            if (active_run->config.poll_hook) active_run->config.poll_hook(active_run->config.poll_ctx);
            return 1;
        }
    }
    return 0;
}

static int unowned_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
    if (gdrom_hook(entry, s, ram, handled)) return 1;
    if (!active_run->unowned_calls++) active_run->first_unowned = entry;
    *handled = 0;
    return 0;
}

static uint32_t run_budget_hook(void)
{
    native_run *run = active_run;
    const uint32_t more = run->config.budget_hook ? run->config.budget_hook() : 0;
    run->granted_steps += more;
    return more;
}

static unsigned reported_steps(uint64_t steps) { return steps > UINT_MAX ? UINT_MAX : (unsigned)steps; }

int vf3_native_tick_run(uint8_t *ram, const uint32_t regs[37], uint32_t entry, uint32_t gbr,
                        vf3_native_tick_result *out)
{
    vf3_ram_win window = { ram, VF3_NATIVE_RAM_BASE, VF3_NATIVE_RAM_LEN };
    vf3_ram_map map = { &window, 1, 0, device_read, device_write, NULL };
    vf3_matrix_state st;
    native_run run = {0};
    run.parent = active_run;
    run.config = next_run;
    run.ram = ram;
    memcpy(run.seed_xf, snapshot_xf, sizeof run.seed_xf);
    const int nested = run.parent != NULL;
    if (!nested) {
        machine.ram = ram;
        machine.ta_len = 0;            /* a nested IRQ appends to this stream */
    }
    const size_t ta_start = machine.ta_len;
    active_run = &run;
    const vf3_family_hook_fn saved_override = vf3_family_override, saved_missing = vf3_family_missing, saved_fail = vf3_family_fail;
    const vf3_family_obs_fn saved_enter = vf3_family_enter, saved_leave = vf3_family_leave;
    int (*saved_call_entry)(uint32_t) = vf3_family_call_entry;
    uint32_t (*saved_budget_hook)(void) = vf3_family_budget_hook;
    const int saved_complete = vf3_family_complete_calls, saved_retry = vf3_family_tail_retry, saved_sq = vf3_sq_model;
    const uint32_t saved_extra_stop = vf3_family_extra_stop;
    memset(&st, 0, sizeof st);
    const unsigned budget = !nested && run.config.budget ? run.config.budget : BLOCK_BUDGET;
    run.granted_steps = budget;
    st.budget = budget;
    memcpy(st.v, regs, 37 * sizeof regs[0]);
    memcpy(st.v + 37, run.seed_xf, sizeof run.seed_xf);
    st.v[16] = run.config.stop_pc ? run.config.stop_pc : GUEST_RETURN_SENTINEL;
    st.gbr = gbr;
    st.gbr_known = 1;
    st.bank_known = 1;                 /* the banked file is written before it is read */

    vf3_family_override = readable_hook;
    vf3_family_missing = unowned_hook;
    vf3_family_fail = NULL;
    vf3_family_enter = getenv("VF3_TRACE_ENTRIES") ? trace_enter : NULL;
    vf3_family_leave = getenv("VF3_TRACE_ENTRIES") ? trace_leave : NULL;
    vf3_family_call_entry = call_target;
    vf3_family_complete_calls = 1;
    vf3_family_extra_stop = run.config.extra_stop;
    vf3_family_tail_retry = 1;
    vf3_family_budget_hook = !nested && run.config.budget ? run_budget_hook : NULL;
    vf3_sq_model = 1;

    int ok = vf3_matrix_family(entry, &st, &map);
    if (run.ta_failed || run.device_errors || run.unowned_calls || map.oob ||
        run.nested_oob || run.nested_failures) ok = 0;
    /* Generated STEP decrements zero to UINT_MAX at exhaustion; that failed
     * attempt executes no guest instruction. Count all budget refills, too. */
    const uint64_t steps = run.granted_steps - (st.budget == UINT_MAX ? 0 : st.budget) + run.nested_steps;

    memset(out, 0, sizeof *out);
    out->ok = ok;
    out->pc = st.pc;
    out->failed_pc = st.failed_pc;
    out->steps_budget_used = reported_steps(steps);
    out->readable_calls = run.readable_calls;
    out->unowned_calls = run.unowned_calls;
    out->first_unowned = run.first_unowned;
    out->bios_calls = run.bios_calls;
    out->device_reads = run.reads;
    out->device_writes = run.writes;
    out->device_errors = run.device_errors;
    out->first_device_error = run.first_device_error;
    out->nested_failures = run.nested_failures;
    out->first_nested_entry = run.first_nested_entry;
    out->first_nested_failed_pc = run.first_nested_failed_pc;
    out->ta_words = (unsigned)(machine.ta_len - ta_start);
    out->ta_failed = run.ta_failed;
    out->oob = map.oob + run.nested_oob;
    out->ta = machine.ta ? machine.ta + ta_start : NULL;
    memcpy(out->regs, st.v, sizeof out->regs);
    vf3_family_override = saved_override;
    vf3_family_missing = saved_missing;
    vf3_family_fail = saved_fail;
    vf3_family_enter = saved_enter;
    vf3_family_leave = saved_leave;
    vf3_family_call_entry = saved_call_entry;
    vf3_family_complete_calls = saved_complete;
    vf3_family_extra_stop = saved_extra_stop;
    vf3_family_tail_retry = saved_retry;
    vf3_family_budget_hook = saved_budget_hook;
    vf3_sq_model = saved_sq;
    active_run = run.parent;
    if (nested) {
        native_run *parent = run.parent;
        if (!ok) {
            if (!parent->nested_failures) {
                parent->first_nested_entry = run.nested_failures ? run.first_nested_entry : entry;
                parent->first_nested_failed_pc = run.nested_failures ? run.first_nested_failed_pc : st.failed_pc;
            }
            /* Count each failed descendant once, including a child whose own
             * result failed because of a deeper invocation. Never overwrite
             * the interrupted CPU's PC/registers with the child's context. */
            parent->nested_failures += run.nested_failures + 1;
        }
        parent->reads += run.reads;
        parent->writes += run.writes;
        if (!parent->device_errors) parent->first_device_error = run.first_device_error;
        parent->device_errors += run.device_errors;
        parent->readable_calls += run.readable_calls;
        if (!parent->unowned_calls) parent->first_unowned = run.first_unowned;
        parent->unowned_calls += run.unowned_calls;
        parent->bios_calls += run.bios_calls;
        parent->ta_failed |= run.ta_failed;
        parent->nested_oob += out->oob;
        parent->nested_steps += steps;
        next_run = parent->config;
        memcpy(snapshot_xf, parent->seed_xf, sizeof snapshot_xf);
    }
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
    uint32_t xf[16] = {0};
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
                if (mine && !want_exit) xf[i] = (uint32_t)(v >> 16);
            }
        } else if (marker == 0xFA50 && stage == 1) {
            if (!read_windows(f, mine && !want_exit ? ram : NULL)) goto fail;
            if (mine && !want_exit) {
                if (*ram) memcpy(snapshot_xf, xf, sizeof snapshot_xf);
                fclose(f);
                return *ram != NULL;
            }
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
