/* bios_syscall.c - register-level front end of the GD-ROM model; see bios_syscall.h */
#include "sys/bios_syscall.h"

static uint32_t polls_per_step = 1, polls_seen;
static uint64_t cycles_per_poll, cycles_per_step, cycle_acc;

void vf3_bios_gd_set_cycle_clock(uint32_t per_poll, uint32_t per_step)
{
    cycles_per_poll = per_poll;
    cycles_per_step = per_step;
    cycle_acc = 0;
}

void vf3_bios_gd_set_poll_divider(uint32_t polls)
{
    polls_per_step = polls ? polls : 1;
    polls_seen = 0;
}

void vf3_bios_gd_advance_cycles(vf3_gdrom *gd, uint64_t cycles)
{
    if (!cycles_per_step || gd->st.status != VF3_GDC_BUSY) return;
    for (cycle_acc += cycles; cycle_acc >= cycles_per_step; cycle_acc -= cycles_per_step) vf3_gd_sched_step(gd);
}

int vf3_bios_gd_syscall_clocked(vf3_gdrom *gd, const vf3_guest_mem *mem, const uint32_t r[8], uint32_t *r0_out)
{
    if (r[6] == 0 && r[7] == VF3_GD_GET_CMD_STAT && gd->st.status == VF3_GDC_BUSY && cycles_per_step) {
        for (cycle_acc += cycles_per_poll; cycle_acc >= cycles_per_step; cycle_acc -= cycles_per_step) vf3_gd_sched_step(gd);
    } else if (r[6] == 0 && r[7] == VF3_GD_GET_CMD_STAT && gd->st.status == VF3_GDC_BUSY && ++polls_seen >= polls_per_step) {
        polls_seen = 0;
        vf3_gd_sched_step(gd);
    }
    return vf3_bios_gd_syscall(gd, mem, r, r0_out);
}

int vf3_bios_gd_syscall(vf3_gdrom *gd, const vf3_guest_mem *mem, const uint32_t r[8], uint32_t *r0_out)
{
    if (r[6] != 0) return 0;
    switch (r[7]) {
    case VF3_GD_REQ_CMD: {
        uint32_t params[4] = { 0, 0, 0, 0 };
        if (r[5])
            for (int i = 0; i < 4; ++i) params[i] = mem->read32(mem->ctx, r[5] + 4u * (uint32_t)i);
        *r0_out = vf3_gd_req_cmd(gd, r[4], params);
        return 1;
    }
    case VF3_GD_GET_CMD_STAT: {
        uint32_t ext[4] = { 0, 0, 0, 0 };
        *r0_out = (uint32_t)vf3_gd_get_cmd_stat(gd, r[4], ext);
        if (r[5])
            for (int i = 0; i < 4; ++i) mem->write32(mem->ctx, r[5] + 4u * (uint32_t)i, ext[i]);
        return 1;
    }
    case VF3_GD_EXEC_SERVER:
        vf3_gd_exec_server(gd);
        *r0_out = 0;
        return 1;
    case VF3_GD_INIT_SYSTEM:
        *r0_out = 0;
        return 1;
    case VF3_GD_GET_DRV_STAT:   /* r4 -> { drive status (1: paused), disc type (0x80: GD-ROM) } */
        if (r[4]) { mem->write32(mem->ctx, r[4], 1u); mem->write32(mem->ctx, r[4] + 4u, 0x80u); }
        *r0_out = 0;
        return 1;
    case VF3_GD_G1_DMA_END:     /* callback registration: the model delivers no G1 DMA interrupt */
    case VF3_GD_CHANGE_DATA_TYPE:
        *r0_out = 0;
        return 1;
    case VF3_GD_CHECK_DMA_TRANS: {   /* r5 -> bytes still to transfer; OK while a transfer is pending, else BUSY */
        if (r[5]) mem->write32(mem->ctx, r[5], gd->st.multi_read_count);
        *r0_out = gd->st.status == VF3_GDC_CONTINUE ? 0u : 1u;
        return 1;
    }
    case VF3_GD_READ_ABORT: {
        const int32_t s = gd->st.status;
        if (r[4] == gd->st.last_request_id && (s == VF3_GDC_CONTINUE || s == VF3_GDC_BUSY || s == VF3_GDC_COMPLETE)) {
            gd->st.multi_read_count = 0;
            *r0_out = 0;
        } else {
            *r0_out = (uint32_t)-1;
        }
        return 1;
    }
    case VF3_GD_RESET:
        gd->st.last_request_id = 0xFFFFFFFFu;
        gd->st.status = VF3_GDC_OK;
        *r0_out = 0;
        return 1;
    default:
        return 0;
    }
}
