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
#define GD_REG_BASE  0x005F7000u         /* the GD-ROM's register block */
#define GD_STATUS_DRDY 0x40u             /* the status register's DRDY bit */
#define GD_UNIT_STANDBY 0x02u            /* the unit status: the drive is stopped */
#define GUEST_RETURN_SENTINEL 0xDEAD0000u
#define SPG_VBLANK_IN_LINE 0x104u
#define BLOCK_BUDGET 1000000000u
/* An interrupt handler (a nested run) has no budget hook, so its budget is
 * its only end: the cap keeps a handler that waits for something that never
 * comes from hanging the port, and its failed PC says where it was. */
#define VF3_NATIVE_NESTED_BUDGET 4000000u

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

/* A guest store into the PVR2's texture memory.  The model intercepts it: the
 * hook gets the physical address, the value and the access size. */
void (*vf3_vram_store_hook)(uint32_t dest, uint32_t value, unsigned size);

/* The system bus' long mode bits: they pick the 32 bit or the 64 bit path of
 * the Tile Accelerator's texture memory window (0x11000000). */
void (*vf3_pvr_lmmode_hook)(uint32_t mode0, uint32_t mode1);

static struct {
    unsigned reads, writes, readable_calls, unowned_calls;
    uint32_t first_unowned;
    uint32_t *ta;
    size_t ta_len, ta_cap;
    uint8_t *ram;                /* the image of the run in progress */
    unsigned budget;             /* guest-step budget of a run (0: the default, effectively unlimited) */
    uint32_t extra_stop;         /* a second address that ends the run (0: none) */
    uint32_t stop_pc;            /* run ends when control reaches this address (0: the return sentinel) */
    vf3_gdrom *gd;               /* optional GD-ROM model behind the BIOS vector */
    unsigned bios_calls;
    uint32_t iml2;               /* SB_IML2NRM as last written */
    uint32_t istnrm;             /* ASIC normal interrupt status (SB_ISTNRM): pending events the model raised */
    unsigned render_started;     /* STARTRENDER writes not yet taken by the caller */
    unsigned render_starts_total; /* every STARTRENDER write of the run */
    uint32_t maple_list;         /* SB_MDSTAR as last written */
    unsigned maple_started;      /* Maple DMA starts (SB_MDST written with bit 0) not yet taken by the caller */
    unsigned dma2_started;       /* SH-4 DMAC channel 2 starts (CHCR2 written with DE) not yet taken by the caller */
    /* The SH-4's DMA channel 2 and the SB's channel 2 registers: the game
     * copies a block of main RAM into the PVR2's Tile Accelerator area with
     * them (the display commands that do not go through the store queue). */
    uint32_t dmac_sar2, dmac_dar2, dmac_dmatcr2, dmac_chcr2;
    uint32_t sb_c2dstat, sb_c2dlen;
    /* The system bus' long mode bits (SB_LMMODE0/1): they pick the 32 bit or
     * the 64 bit path of the PVR2's texture memory window at 0x11000000. */
    uint32_t sb_lmmode0, sb_lmmode1;
    /* The GD-ROM's registers: the status register (the drive is idle and
     * ready) and the unit status (the disc is in the drive). */
    uint32_t gd_status, gd_unit_status;
    /* the state of the run in progress: the device log wants the caller's PC */
    vf3_matrix_state *cur;
    /* the readable port that is running right now (0: none): a readable port
     * does not write the guest PC while it runs, so the watchdog needs its
     * own field to name the port the guest is stuck in. */
    uint32_t readable_entry;
} machine;

/* sound RAM (0x00800000): the loader reads the driver-published free size at 0x88. Kept outside `machine`, which nested runs copy */
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

/* The SH-4's on-chip registers (area 7, 0xFF000000..): the BSC, the DMAC, the TMU, the SCIF.
 * The startup writes them and reads them back (the DMAOR handshake loops until the
 * value it wrote is the value it reads), so a register that is not modelled holds
 * what was written to it. */
static uint8_t onchip_regs[0x01000000];
static int is_onchip(uint32_t address) { return (address & 0x1F000000u) == 0x1F000000u; }

static const uint8_t *bios_image;
static size_t bios_len;
void vf3_native_set_bios(const uint8_t *image, size_t len) { bios_image = image; bios_len = len; }

static uint32_t device_read(void *context, uint32_t address, unsigned size)
{
    (void)context; (void)size;
    if (bios_image && (address & 0x1FFFFFFFu) < 0x00200000u && (address & 0x1FFFFFFFu) + size <= bios_len) {
        uint32_t v = 0;
        memcpy(&v, bios_image + (address & 0x1FFFFFFFu), size > 4 ? 4 : size);
        return v;
    }
    ++machine.reads;
    if (getenv("VF3_DEVLOG")) fprintf(stderr, "devread %08x size %u pc %08x\n", address, size, machine.cur ? machine.cur->pc : 0);
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
    /* The SDK startup (0x8C010100) takes the board configuration from a byte
     * the G2 bus answers at 0xA30100C0 when the BIOS' system area (0x8C000070)
     * does not hold "00".  The reference's startup leaves 0x8F at 0x0C00F71C,
     * bit 7 of which releases the startup's command loop. */
    if ((address & 0x1FFFFFFFu) == 0x030100C0u) return 0x8Fu;
    /* SCIF SCFSR2: transmit empty and transmit end, nothing received. */
    if ((address & 0x1FFFFFFFu) == 0x1FE80010u) return 0x60u;
    /* PVR2 ID and revision: the video init (0x8C063446) takes its mode from them */
    if ((address & 0x1FFFFFFFu) == 0x005F8000u) return 0x17FD11DBu;
    if ((address & 0x1FFFFFFFu) == 0x005F8004u) return 0x11u;
    if ((address & 0x1FFFFFFFu) == 0x005F6910u) return machine.iml2;
    if ((address & 0x1FFFFFFFu) == 0x005F810Cu) return SPG_VBLANK_IN_LINE;
    if ((address & 0x1FFFFFFFu) == 0x005F6900u) {
        if (getenv("VF3_ASICLOG") && (machine.istnrm & ~8u)) fprintf(stderr, "istnrm read %08x\n", machine.istnrm);
        return machine.istnrm;
    }
    if ((address & 0x1FFFFFFFu) >= GD_REG_BASE && (address & 0x1FFFFFFFu) < GD_REG_BASE + 0x120u) {
        /* The GD-ROM's own register block.  The game's GDFS driver drives the
         * drive through these registers (the BIOS syscall the loader uses is
         * a different door), so the port has to answer them: a drive that is
         * present and idle reports DRDY, and its unit status is "standby".
         * With every register reading as zero the driver concluded the drive
         * was not there and the boot never read a file. */
        const uint32_t a = address & 0x1FFFFFFFu;
        if (a == 0x005F7018u || a == 0x005F709Cu) return machine.gd_status;   /* ALTSTAT / STATUS */
        if (a == 0x005F708Cu) return machine.gd_unit_status;                 /* SECTNUM */
        return 0;
    }
    if (is_onchip(address)) {
        uint32_t v = 0;
        memcpy(&v, onchip_regs + (address & 0x00FFFFFFu), size > 4 ? 4 : size);
        return v;
    }
    return 0;
}

/* The store queue's flush into the Tile Accelerator: the display commands. */
static void ta_flush(const uint32_t *words, unsigned n);

/* The SH-4's DMA channel 2 copying into the PVR2.
 *
 * The game uses this path for the display commands that do not go through the
 * store queue.  The source is in the main RAM, the destination is in the
 * PVR2: below 0x11000000 it is the Tile Accelerator's own area (the first
 * 8 MB is the polygon stream, the display commands), above it is the VRAM.
 *
 * The reference hands the Tile Accelerator every block it copied - it takes
 * them four at a time - so the port does the same.
 */
static void dma2_ch2_transfer(void)
{
    const uint32_t src = machine.dmac_sar2 & 0x1FFFFFE0u;
    const uint32_t dst = machine.sb_c2dstat & 0x01FFFFE0u;
    const uint32_t len = machine.sb_c2dlen;

    if ((src >> 26) == 3u && len) {
        const uint32_t off = src & 0x00FFFFFFu;   /* the main RAM is 16 MB at 0x0C000000 */
        if (off + len <= VF3_NATIVE_RAM_LEN) {
            if ((dst & 0x01000000u) == 0u && (dst & 0x800000u) == 0u) {
                /* the polygon stream: the display commands.  The hardware takes
                 * the copied blocks four at a time and hands all of them to the
                 * Tile Accelerator. */
                const unsigned blocks = len / 32u;
                for (unsigned b = 0; b < blocks; ++b) {
                    uint32_t buf[8];
                    const uint8_t *p = machine.ram + off + b * 32u;
                    for (unsigned w = 0; w < 8; ++w)
                        buf[w] = ((uint32_t)p[w * 4 + 3] << 24) | ((uint32_t)p[w * 4 + 2] << 16) |
                                 ((uint32_t)p[w * 4 + 1] << 8) | (uint32_t)p[w * 4];
                    ta_flush(buf, 8);
                }
            }
            else if ((dst & 0x01000000u) && vf3_vram_hook) {
                /* 0x11000000 and up is the VRAM, in its 64 bit view */
                for (uint32_t o = 0; o + 4u <= len; o += 4u) {
                    const uint8_t *p = machine.ram + off + o;
                    vf3_vram_hook(0x10000000u | ((dst + o) & 0x01FFFFFFu),
                                  (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24));
                }
            }
            /* the YUV converter (0x10800000) is not modelled yet */
        }
    }
    machine.sb_c2dlen = 0;
    machine.sb_c2dstat = 0;
    machine.dmac_chcr2 |= 0x0200u;      /* the transfer ended */
    machine.dmac_dmatcr2 = 0;
    machine.istnrm |= 0x00080000u;      /* the ch2-DMA end interrupt (bit 19) */
}

static void device_write(void *context, uint32_t address, unsigned size, uint32_t value)
{
    (void)context; (void)size;
    ++machine.writes;
    if (is_onchip(address)) memcpy(onchip_regs + (address & 0x00FFFFFFu), &value, size > 4 ? 4 : size);
    if (getenv("VF3_DEVLOG")) fprintf(stderr, "devwrite %08x size %u value %08x%c", address, size, value, 10);
    if (tmu_on && (address & 0x1FFFFFFFu) == 0x1FD8000Cu)   /* a guest write re-seeds TCNT0 */
        tmu_cycles = (uint64_t)(0xFFFFFFFFu - value) << 8;    if ((address & 0x1FFFFFFFu) == AICA_MBOX_CMD) aica_mbox_polls = 0;
    if ((address & 0x1FFFFFFFu) == AICA_UPLOAD_LEN) {
        aica_upload_len = value;
        aica_upload_polls_left = (uint64_t)value * AICA_UPLOAD_POLLS_PER_BYTE_X10 / 10u;
    }
    if ((address & 0x1FFFFFFFu) >= AICA_RAM_BASE && (address & 0x1FFFFFFFu) - AICA_RAM_BASE + size <= AICA_RAM_LEN)
        memcpy(aica_ram + ((address & 0x1FFFFFFFu) - AICA_RAM_BASE), &value, size > 4 ? 4 : size);
    if ((address & 0x1FFFFFFFu) == 0x005F6C04u) machine.maple_list = value;
    if ((address & 0x1FFFFFFFu) == 0x005F6C18u && (value & 1u)) ++machine.maple_started;
    /* The SH-4's DMA channel 2 and the SB's channel 2: the game copies a
     * block of main RAM into the PVR2 with them.  The copy runs when the SB's
     * ch2 start register is written with bit 0. */
    if ((address & 0x1FFFFFFFu) == 0x1FA00020u) machine.dmac_sar2 = value;
    if ((address & 0x1FFFFFFFu) == 0x1FA00024u) machine.dmac_dar2 = value;
    if ((address & 0x1FFFFFFFu) == 0x1FA00028u) machine.dmac_dmatcr2 = value;
    if ((address & 0x1FFFFFFFu) == 0x1FA0002Cu) { machine.dmac_chcr2 = value; if (value & 1u) ++machine.dma2_started; }
    if ((address & 0x1FFFFFFFu) == 0x005F6800u) machine.sb_c2dstat = value;
    if ((address & 0x1FFFFFFFu) == 0x005F6804u) machine.sb_c2dlen = value;
    if ((address & 0x1FFFFFFFu) == 0x005F6808u && (value & 1u)) dma2_ch2_transfer();
    if (getenv("VF3_DMALOG") && ((address & 0x1FFFFFFFu) < 0x1FA00080u ||
                                 ((address & 0x1FFFFFFFu) >= 0x005F6800u && (address & 0x1FFFFFFFu) < 0x005F6820u)))
        fprintf(stderr, "dma: devwrite %08x = %08x%c", address, value, 10);
    if ((address & 0x1FFFFFFFu) == 0x005F6910u) machine.iml2 = value;
    if ((address & 0x1FFFFFFFu) == 0x005F6900u) machine.istnrm &= ~value;   /* write-1-to-clear */
    /* SB_LMMODE0/1 (the system bus' long mode bits): they pick the 32 bit or
     * the 64 bit path of the PVR2's texture memory window at 0x11000000. */
    if ((address & 0x1FFFFFFFu) == 0x005F6884u) {
        machine.sb_lmmode0 = value & 1u;
        if (vf3_pvr_lmmode_hook) vf3_pvr_lmmode_hook(machine.sb_lmmode0, machine.sb_lmmode1);
    }
    if ((address & 0x1FFFFFFFu) == 0x005F6888u) {
        machine.sb_lmmode1 = value & 1u;
        if (vf3_pvr_lmmode_hook) vf3_pvr_lmmode_hook(machine.sb_lmmode0, machine.sb_lmmode1);
    }
    if (vf3_pvr_reg_hook) {
        /* The PVR2's register file is 32 KB and the Dreamcast shows it through
         * several mirrors: the uncached 32 bit view at 0x005F8000, the 0xA0
         * area at 0xA05F8000 (the same bits, the mask drops the area), and the
         * cached view at 0x8C000000, which the store path folds to
         * 0x1F800000.  The palette RAM (at +0x1000) and the fog table (at
         * +0x200) live in the same 32 KB, and the game writes the palette
         * through the 0xA0 mirror - so the window has to be 32 KB wide, not
         * the 8 KB the old mask allowed: with it the palette was dropped and
         * every palette-textured primitive came out black. */
        const uint32_t a = address & 0x1FFFFFFFu;
        if ((a & 0x1FFF8000u) == 0x005F8000u || (a & 0x1FFF8000u) == 0x1F800000u)
            vf3_pvr_reg_hook(a & 0x7FFFu, value);
    }
    if (vf3_vram_store_hook) {
        /* A plain store into the texture memory.  The Dreamcast shows its
         * VRAM through two windows of area 1: the 64 bit path at 0x04000000
         * (the banks one after the other, the view the Tile Accelerator
         * samples) and the 32 bit path at 0x05000000 (the banks interleaved),
         * each with a mirror at 0x06000000 and 0x07000000.  The game uploads
         * its textures through the 32 bit path, so without it the model's VRAM
         * stays empty and every texture samples as black.  The Tile
         * Accelerator's own window at 0x11000000 (and 0x13000000) shows the
         * VRAM too; the system bus' long mode bits pick which path it is. */
        const uint32_t a = address & 0x1FFFFFFFu;
        if ((a >= 0x04000000u && a < 0x08000000u) ||
            (a >= 0x11000000u && a < 0x12000000u) ||
            (a >= 0x13000000u && a < 0x14000000u))
            vf3_vram_store_hook(a, value, size);
    }
    if ((address & 0x1FFFFFFFu) == 0x005F8014u) { ++machine.render_started; ++machine.render_starts_total; }
    /* A plain store into the PVR2 area is a VRAM or a register write, not a
     * display command: the Tile Accelerator only receives the store queue's
     * flushes (vf3_ta_flush_hook). */
    if (address < TA_AREA_BASE || address >= TA_AREA_END) return;   /* QACR, store-queue folds */
}

/* The store queue's flush into the Tile Accelerator: the display commands. */
static void ta_flush(const uint32_t *words, unsigned n)
{
    for (unsigned i = 0; i < n; ++i) {
        if (machine.ta_len == machine.ta_cap) {
            machine.ta_cap = machine.ta_cap ? 2 * machine.ta_cap : 1u << 16;
            uint32_t *ta = realloc(machine.ta, machine.ta_cap * sizeof *ta);
            if (!ta) { machine.ta_cap = machine.ta_len = 0; return; }
            machine.ta = ta;
        }
        machine.ta[machine.ta_len++] = words[i];
    }
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

static int readable_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{
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
    const uint32_t saved_readable = machine.readable_entry;
    if (vf3_readable_find(entry)) machine.readable_entry = entry;
    const int ok = vf3_readable_override(entry, s, ram, handled);
    machine.readable_entry = saved_readable;
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
void vf3_native_set_extra_stop(uint32_t pc) { machine.extra_stop = pc; }
void vf3_native_set_budget(unsigned steps) { machine.budget = steps; }
void vf3_native_raise_asic(uint32_t mask) { machine.istnrm |= mask; }
int vf3_native_gd_attached(void) { return machine.gd != NULL; }
void vf3_native_aica_poke(uint32_t offset, uint32_t value) { if (offset <= AICA_RAM_LEN - 4) memcpy(aica_ram + offset, &value, 4); }
uint32_t vf3_native_asic_pending(void) { return machine.istnrm; }
uint32_t vf3_native_asic_iml2(void) { return machine.iml2; }
unsigned vf3_native_take_render(void) { const unsigned n = machine.render_started; machine.render_started = 0; return n; }
uint32_t vf3_native_current_pc(void)
{
    /* a readable port does not write the guest PC while it runs: the entry of
     * the port that is running right now names it */
    if (machine.readable_entry) return machine.readable_entry;
    return machine.cur ? machine.cur->pc : 0u;
}
unsigned vf3_native_take_maple(uint32_t *list) { const unsigned n = machine.maple_started; machine.maple_started = 0; if (list) *list = machine.maple_list; return n; }
unsigned vf3_native_take_dma2(void) { const unsigned n = machine.dma2_started; machine.dma2_started = 0; return n; }
static uint32_t (*budget_hook)(vf3_matrix_state *s);
void vf3_native_set_budget_hook(uint32_t (*hook)(vf3_matrix_state *s)) { budget_hook = hook; }

void vf3_native_attach_gdrom(vf3_gdrom *gd)
{
    machine.gd = gd;
    if (gd) { gd->write = gd_write; gd->write_ctx = NULL; }
    /* a drive with a disc in it is ready: its status register reports DRDY
     * and its unit status is "standby" (the reference emulator's
     * gd_setdisc). */
    machine.gd_status = GD_STATUS_DRDY;
    machine.gd_unit_status = GD_UNIT_STANDBY;
}

static void (*poll_hook)(void *);
static void *poll_ctx;
static unsigned run_depth;

void vf3_native_set_poll_hook(void (*hook)(void *), void *ctx) { poll_hook = hook; poll_ctx = ctx; }

static int unowned_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
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
            ++machine.bios_calls;
            s->v[0] = r0;
            s->pc = s->v[16];
            *handled = 1;
            if (poll_hook) poll_hook(poll_ctx);   /* time passes inside the poll: an interrupt may land here */
            return 1;
        }
    }
    if (entry == (GUEST_RETURN_SENTINEL & 0x1FFFFFFFu)) {
        /* a module handed the run's return address back as a call (the 29-bit mask hides the 0xDEAD0000 form): the
         * run is over, exactly as when the dispatcher meets it as a plain jump */
        s->pc = GUEST_RETURN_SENTINEL;
        *handled = 1;
        return 1;
    }
    if (getenv("VF3_UNOWNED")) fprintf(stderr, "unowned entry %08x pr %08x r11 %08x r15 %08x\n", entry, s->v[16], s->v[11], s->v[15]);
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
    /* a nested run (an interrupt taken inside a poll) leaves the interrupted run's machine as it found it */
    const int nested = run_depth > 0;
    const typeof(machine) saved = machine;
    uint32_t saved_xf[16];
    memcpy(saved_xf, snapshot_xf, sizeof saved_xf);
    ++run_depth;

    machine.reads = machine.writes = machine.readable_calls = machine.unowned_calls = 0;
    machine.first_unowned = 0;
    machine.bios_calls = 0;
    machine.ram = ram;
    /* the buffer itself is reused between runs; a nested run (an interrupt
     * taken inside a slice) appends to the outer run's words, because the
     * commands it emits belong to the same frame */
    if (!nested) machine.ta_len = 0;
    memset(&st, 0, sizeof st);
    machine.cur = &st;
    /* A nested run (an interrupt handler) has no budget hook, so its budget is
     * its only end: without a cap a handler that waits for something that
     * never comes spins for ever and the port hangs without a word.  The cap
     * turns that into a report: the handler's failed PC says where it was. */
    const unsigned budget = !nested && saved.budget ? saved.budget
                             : (nested ? VF3_NATIVE_NESTED_BUDGET : BLOCK_BUDGET);
    st.budget = budget;
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
    vf3_family_leave = getenv("VF3_TRACE_ENTRIES") ? trace_leave : NULL;
    vf3_family_call_entry = call_target;
    vf3_family_complete_calls = 1;
    vf3_family_extra_stop = machine.extra_stop;
    vf3_family_tail_retry = 1;
    vf3_ta_flush_hook = ta_flush;
    vf3_family_budget_hook = !nested && saved.budget ? budget_hook : NULL;   /* an interrupt taken inside a slice is not sliced */
    vf3_sq_model = 1;

    const int ok = vf3_matrix_family(entry, &st, &map);

    memset(out, 0, sizeof *out);
    out->ok = ok;
    out->pc = st.pc;
    out->failed_pc = st.failed_pc;
    out->steps_budget_used = budget - st.budget;
    out->budget_left = st.budget;
    out->readable_calls = machine.readable_calls;
    out->unowned_calls = machine.unowned_calls;
    out->first_unowned = machine.first_unowned;
    out->bios_calls = machine.bios_calls;
    out->device_reads = machine.reads;
    out->device_writes = machine.writes;
    out->ta_words = (unsigned)machine.ta_len;
    out->render_starts = machine.render_starts_total;
    out->oob = map.oob;
    out->ta = machine.ta;
    memcpy(out->regs, st.v, sizeof out->regs);
    --run_depth;
    if (!nested) machine.cur = NULL;
    if (nested) {
        uint32_t *ta = machine.ta;
        size_t ta_cap = machine.ta_cap;
        /* the nested run appended its display commands to the outer run's */
        size_t ta_len = machine.ta_len;
        /* the device state is the machine's, not the run's: what an interrupt handler did to it (a Maple or DMA start, the
         * ASIC's pending bits) must survive the handler's return */
        const typeof(machine) inner = machine;
        machine = saved;
        machine.istnrm = inner.istnrm;
        machine.iml2 = inner.iml2;
        machine.render_started = inner.render_started;
        machine.render_starts_total = inner.render_starts_total;
        machine.maple_list = inner.maple_list;
        machine.maple_started = inner.maple_started;
        machine.dma2_started = inner.dma2_started;
        machine.dmac_sar2 = inner.dmac_sar2; machine.dmac_dar2 = inner.dmac_dar2;
        machine.dmac_dmatcr2 = inner.dmac_dmatcr2; machine.dmac_chcr2 = inner.dmac_chcr2;
        machine.sb_c2dstat = inner.sb_c2dstat; machine.sb_c2dlen = inner.sb_c2dlen;
        machine.ta = ta;
        machine.ta_cap = ta_cap;
        machine.ta_len = ta_len;
        memcpy(snapshot_xf, saved_xf, sizeof saved_xf);
        vf3_family_budget_hook = run_depth == 1 && machine.budget ? budget_hook : NULL;
    }
    return ok;
}

unsigned vf3_native_take_ta(const uint32_t **words)
{
    const unsigned n = (unsigned)machine.ta_len;
    *words = machine.ta;
    machine.ta_len = 0;
    return n;
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
