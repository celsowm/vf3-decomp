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
    default:
        return 0;
    }
}
