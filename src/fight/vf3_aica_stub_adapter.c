/* Captured REIOS GD-ROM BIOS service used by the 0x8c09635a replay path.
 *
 * Flycast's reios HLE trace records GDROM_GET_DRV_STAT (r6=0, r7=4) once in
 * each of the 15 complete state-29 owner captures. Every observed response is
 * r0=GDC_OK, status=GD_STAT_PAUSE (1), disc type=GdRom (128). Keep the service
 * narrow: the other words at 0x0c001008.. are separate firmware vectors, not
 * SH-4 RAM code or the copy loop previously assumed here.
 */
#include "fight/matrix_family.h"
#include <stdio.h>
#include <stdlib.h>
#include "sys/bios_syscall.h"
#include "fight/native_tick.h"

/* GD-ROM command state for replay: VF3_GD_STATE names a one-line file of the 16 hex words tools/gd_model_check.py reads
 * from the observer log (last_request_id, next_request_id, status, command, params[4], result[4], cur_sector,
 * multi_read_sector, multi_read_offset, multi_read_count). With it, GET_CMD_STAT / EXEC_SERVER are answered by the
 * vf3_gdrom model instead of failing closed; the state is reloaded on every call (one case per process). */
static int load_gd_state(vf3_gdrom *gd)
{
    const char *path = getenv("VF3_GD_STATE");
    FILE *f = path ? fopen(path, "r") : NULL;
    unsigned w[16];
    int n = 0;
    if (!f) return 0;
    while (n < 16 && fscanf(f, "%x", &w[n]) == 1) ++n;
    fclose(f);
    if (n != 16) return 0;
    vf3_gd_init(gd, NULL, NULL, NULL);
    vf3_gd_state *st = &gd->st;
    st->last_request_id = w[0]; st->next_request_id = w[1]; st->status = (int32_t)w[2]; st->command = w[3];
    for (int i = 0; i < 4; ++i) { st->params[i] = w[4 + i]; st->result[i] = w[8 + i]; }
    st->cur_sector = w[12]; st->multi_read_sector = w[13]; st->multi_read_offset = w[14]; st->multi_read_count = w[15];
    st->multi_read_total = w[15];
    return 1;
}

static uint32_t gd_mem_read(void *ctx, uint32_t addr) { return vf3_matrix_read((const vf3_ram_map *)ctx, addr, 4u); }
static void gd_mem_write(void *ctx, uint32_t addr, uint32_t v) { vf3_matrix_write((const vf3_ram_map *)ctx, addr, v, 4u); }

int vf3_reios_system_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);
int vf3_reios_flashrom_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);

/* REIOS GD-ROM vector (0x8C001006, r6 = 0) against an idle drive.
 *
 * The loader stubs reach the BIOS through the pointer word at 0x8C0000BC and
 * the reference answers every command from the drive state.  Without a
 * captured drive state (VF3_GD_STATE) the drive is idle, which is what the
 * fight-state corpora recorded: no transfer is in flight, so the two
 * transfer requests are refused with GDC_ERR and the two completion checks
 * answer "not done" without touching memory.
 *
 * The command numbers are the REIOS ones (gdrom_hle.h): 6 REQ_DMA_TRANS,
 * 7 CHECK_DMA_TRANS, 12 REQ_PIO_TRANS, 13 CHECK_PIO_TRANS.
 */
static int reios_gd_idle(uint32_t *r, uint32_t entry, vf3_matrix_state *state,
                         const vf3_ram_map *ram)
{
    switch (r[7]) {
    case VF3_GD_EXEC_SERVER:          /* 2: the queue is empty, nothing changes */
        state->pc = r[16];
        return ram->oob == 0u;
    case VF3_GD_INIT_SYSTEM:          /* 3: the reference resets the drive and leaves r0 alone */
    case VF3_GD_RESET:                /* 9: same, the drive goes idle */
        state->pc = r[16];
        return ram->oob == 0u;
    case VF3_GD_G1_DMA_END:           /* 5 */
    case VF3_GD_CHANGE_DATA_TYPE:     /* 10 */
    case VF3_GD_SET_PIO_CALLBACK:     /* 11 */
        r[0] = 0u;                    /* GDC_OK */
        state->pc = r[16];
        return ram->oob == 0u;
    case VF3_GD_GET_DRV_STAT: {       /* 4: drive status (1: paused) + disc type (0x80) */
        vf3_matrix_write(ram, r[4], 1u, 4u);
        vf3_matrix_write(ram, r[4] + 4u, 128u, 4u);
        r[0] = 0u;
        state->pc = r[16];
        return ram->oob == 0u;
    }
    case VF3_GD_REQ_DMA_TRANS:        /* 6 */
    case VF3_GD_REQ_PIO_TRANS: {      /* 12 */
        /* The reference reads the two parameter words (buffer, size) before it
         * refuses the request, so the reads stay; an idle drive holds no
         * transfer, so the answer is GDC_ERR and no sector is copied. */
        (void)vf3_matrix_read(ram, r[5], 4u);
        (void)vf3_matrix_read(ram, r[5] + 4u, 4u);
        r[0] = (uint32_t)-1;          /* GDC_ERR */
        state->pc = r[16];
        return ram->oob == 0u;
    }
    case VF3_GD_CHECK_DMA_TRANS: {    /* 7: bytes left, then OK or BUSY */
        vf3_matrix_write(ram, r[5], 0u, 4u);
        r[0] = 1u;                    /* GDC_BUSY */
        state->pc = r[16];
        return ram->oob == 0u;
    }
    case VF3_GD_CHECK_PIO_TRANS:      /* 13: ERR unless a transfer is in flight */
        r[0] = (uint32_t)-1;          /* GDC_ERR */
        state->pc = r[16];
        return ram->oob == 0u;
    case VF3_GD_READ_ABORT:           /* 8: no request to abort */
        r[0] = (uint32_t)-1;          /* GDC_ERR */
        state->pc = r[16];
        return ram->oob == 0u;
    default:
        state->failed_pc = entry;
        return 0;
    }
}

int vf3_aica_stub_adapter(uint32_t entry, vf3_matrix_state *state,
                          const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    uint32_t pc = entry & 0x1fffffffu;
    static long d_=0; int dbg_=getenv("VF3_DEBUG_STUB")!=NULL;
    if(dbg_ && (d_++%50)==0) fprintf(stderr,"STUB pc=%08x r6=%08x r7=%08x r16=%08x budget=%u d=%ld\n",pc,r[6],r[7],r[16],state->budget,d_);

    if (pc == 0x0c001000u)
        return vf3_reios_system_adapter(entry, state, ram);
    if (pc == 0x0c001004u)
        return vf3_reios_flashrom_adapter(entry, state, ram);

    if (pc != 0x0c001006u || state->budget == 0u) {
        if(dbg_) fprintf(stderr,"STUB fail: pc=%08x budget=%u\n",pc,state->budget);
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;

    if (r[6] != 0u) {
        if(dbg_) fprintf(stderr,"STUB fail: r6=%08x (want 0)\n",r[6]);
        state->failed_pc = entry;
        return 0;
    }

    if ((r[7] == 1u || r[7] == 2u) && getenv("VF3_GD_STATE")) {
        vf3_gdrom gd;
        if (load_gd_state(&gd)) {
            const vf3_guest_mem gm = { (void *)ram, gd_mem_read, gd_mem_write };
            const uint32_t args[8] = { 0, 0, 0, 0, r[4], r[5], r[6], r[7] };
            uint32_t r0 = r[0];
            if (vf3_bios_gd_syscall(&gd, &gm, args, &r0)) {
                if (r[7] == 1u) {
                    r[0] = r0;
                }
                state->pc = r[16];
                return ram->oob == 0u;
            }
        }
    }

    /* GDROM_EXEC_SERVER (r6=0, r7=2): with the captured idle drive queue the
     * service returns immediately, leaving every register unchanged. */
    if (r[7] == 2u && !vf3_native_gd_attached()) {   /* with a drive model attached the native run serves it (native_tick.c) */
        state->pc = r[16];
        return ram->oob == 0u;
    }

    return reios_gd_idle(r, entry, state, ram);
}

int vf3_aica_stub_adapter_contains(uint32_t pc)
{
    pc &= 0x1fffffffu;
    return pc == 0x0c001006u || pc == 0x0c001000u || pc == 0x0c001004u;
}

/* REIOS FLASHROM_READ (vector 0x8c001004, r7=1): every recorded invocation
 * copies the two console-variant bytes 0xff 0xfe@0x1a05e into the caller's
 * buffer (matches the flycast HLE semantics read-from-flash and every
 * captured out-window). Other services fail closed. */
int vf3_reios_flashrom_adapter(uint32_t entry, vf3_matrix_state *state,
                               const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    if (r[7] != 1u || r[4] != 0x1a05eu || r[6] != 2u
        || state->budget == 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;
    vf3_matrix_write(ram, r[5], 0xfeffu, 2u);
    r[0] = 0u;
    state->pc = r[16];
    return ram->oob == 0u;
}

int vf3_reios_system_adapter(uint32_t entry, vf3_matrix_state *state,
                             const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    /* REIOS SYSINFO_INIT (vector 0x8c001000, r7=0): fills the 24-byte system
     * information record at 0x8c000068 from the boot flash. Every recorded
     * invocation (11 sampled cases across 5 corpora) contains the identical
     * constant record: 8-byte board id (flash 0x1a056), 0xfffe, "110",
     * then zeros. */
    static const uint8_t info[24] = {
        0xe6, 0x19, 0xf5, 0x4e, 0xb8, 0xcf, 0x7b, 0xd4,
        0xff, 0xfe, 0x31, 0x31, 0x30 };
    if (r[7] == 3u) {           /* SYSINFO_ID: r0 = &record */
        --state->budget;
        r[0] = 0x8c000068u;
        state->pc = r[16];
        return ram->oob == 0u;
    }
    if (r[7] == 2u) {           /* SYSINFO_ICON: size 704, -1 if r4 > 9 */
        --state->budget;
        r[0] = (r[4] > 9u) ? 0xffffffffu : 704u;
        state->pc = r[16];
        return ram->oob == 0u;
    }
    if (r[7] != 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;
    for (unsigned i = 0; i < sizeof(info); i += 4) {
        uint32_t w = (uint32_t)info[i]
                   | ((uint32_t)info[i + 1] << 8)
                   | ((uint32_t)info[i + 2] << 16)
                   | ((uint32_t)info[i + 3] << 24);
        vf3_matrix_write(ram, 0x8c000068u + i, w, 4u);
    }
    r[0] = 0u;
    state->pc = r[16];
    return ram->oob == 0u;
}
