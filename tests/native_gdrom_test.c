/* ROM-free regression: a native run must use its attached GD-ROM state before
 * the capture-specific REIOS adapter, while no-drive replay retains the stub. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "sys/bios_syscall.h"

static int failures;
#define CHECK(c, ...) do { if (!(c)) { ++failures; fprintf(stderr, "FAIL line %d: ", __LINE__); \
    fprintf(stderr, __VA_ARGS__); fputc('\n', stderr); } } while (0)

static void put32(uint8_t *ram, uint32_t address, uint32_t value)
{
    memcpy(ram + (address & 0x0FFFFFFFu) - VF3_NATIVE_RAM_BASE, &value, sizeof value);
}

static uint32_t get32(const uint8_t *ram, uint32_t address)
{
    uint32_t value;
    memcpy(&value, ram + (address & 0x0FFFFFFFu) - VF3_NATIVE_RAM_BASE, sizeof value);
    return value;
}

static void count_poll(void *context) { ++*(unsigned *)context; }

static vf3_native_tick_result run(uint8_t *ram, uint32_t regs[37], uint32_t entry, int expected_ok)
{
    vf3_native_tick_result out;
    int ok = vf3_native_tick_run(ram, regs, entry, 0, &out);
    CHECK(ok == expected_ok && out.ok == expected_ok, "entry %08x: ok=%d pc=%08x failed=%08x",
          entry, ok, out.pc, out.failed_pc);
    CHECK(out.oob == 0, "entry %08x: %u out-of-bounds accesses", entry, out.oob);
    if (expected_ok) CHECK(out.unowned_calls == 0, "entry %08x: %u unowned calls", entry, out.unowned_calls);
    return out;
}

static void attached_drive(uint8_t *ram)
{
    const uint32_t params_addr = VF3_NATIVE_RAM_BASE + 0x100;
    const uint32_t result_addr = VF3_NATIVE_RAM_BASE + 0x200;
    const uint32_t params[4] = { 0x81ADB, 7, VF3_NATIVE_RAM_BASE + 0x1000, 0 };
    const uint32_t extended[4] = { 7, 9, 0x1234, 5 };
    uint32_t regs[37] = { 0 };
    vf3_gdi disc = { 0 }; /* No sectors are requested by this state-routing test. */
    vf3_gdrom gd;
    unsigned polls = 0;
    vf3_gd_init(&gd, &disc, NULL, NULL);
    vf3_native_attach_gdrom(&gd);
    vf3_native_set_poll_hook(count_poll, &polls);
    for (unsigned i = 0; i < 4; ++i) put32(ram, params_addr + 4 * i, params[i]);
    regs[4] = VF3_GDCC_DMAREAD;
    regs[5] = params_addr;
    regs[7] = VF3_GD_REQ_CMD;
    regs[15] = VF3_NATIVE_RAM_BASE + 0x8000;
    vf3_native_tick_result out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.regs[0] == 2, "REQ_CMD id %u, expected 2", out.regs[0]);
    CHECK(out.bios_calls == 1 && polls == 1, "REQ_CMD model/poll calls %u/%u", out.bios_calls, polls);
    CHECK(gd.st.status == VF3_GDC_BUSY && gd.st.command == VF3_GDCC_DMAREAD,
          "REQ_CMD did not enqueue DMAREAD (status %d, command %u)", gd.st.status, gd.st.command);
    CHECK(memcmp(gd.st.params, params, sizeof params) == 0, "REQ_CMD parameters differ");

    /* A second request stays refused by the real busy drive. */
    out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.regs[0] == 0 && gd.st.last_request_id == 2 && gd.st.next_request_id == 3,
          "busy drive accepted/replaced the request");
    CHECK(out.bios_calls == 1 && polls == 2, "busy REQ_CMD bypassed the model");

    /* Not armed yet, so the clocked status poll cannot read a disc sector.
     * Its nonzero result must reach guest RAM instead of the stub's zeros. */
    memcpy(gd.st.result, extended, sizeof extended);
    regs[4] = 2;
    regs[5] = result_addr;
    regs[7] = VF3_GD_GET_CMD_STAT;
    for (unsigned i = 0; i < 4; ++i) put32(ram, result_addr + 4 * i, 0xCCCCCCCCu);
    out = run(ram, regs, 0x0C001006u, 1);
    CHECK(out.regs[0] == VF3_GDC_BUSY, "GET_CMD_STAT returned %u, expected BUSY", out.regs[0]);
    CHECK(out.bios_calls == 1 && polls == 3, "GET_CMD_STAT model/poll calls %u/%u", out.bios_calls, polls);
    for (unsigned i = 0; i < 4; ++i)
        CHECK(get32(ram, result_addr + 4 * i) == extended[i], "GET_CMD_STAT result[%u] changed", i);
    CHECK(gd.st.result[2] == extended[2], "GET_CMD_STAT destroyed live result[2]");

    regs[7] = VF3_GD_EXEC_SERVER;
    out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.bios_calls == 1 && polls == 4, "EXEC_SERVER bypassed the model");
    CHECK(gd.st.multi_read_count == params[1] && gd.st.multi_read_offset == params[2],
          "EXEC_SERVER did not arm transfer (%u sectors at %08x)", gd.st.multi_read_count, gd.st.multi_read_offset);

    /* Exercise the actual readable loader wrapper and its nested BIOS call. */
    gd.st.status = VF3_GDC_COMPLETE;
    gd.st.multi_read_count = 0;
    gd.st.result[2] = params[1] * VF3_GD_SECTOR;
    put32(ram, VF3_NATIVE_RAM_BASE + 0xBC, 0x8C001006u);
    out = run(ram, regs, 0x8C0432DEu, 1);
    CHECK(out.regs[0] == 1, "loader wrapper did not report completion: %u", out.regs[0]);
    CHECK(get32(ram, result_addr) == params[1] * VF3_GD_SECTOR, "loader wrapper lost transfer byte count");
    CHECK(out.bios_calls == 1 && polls == 5, "loader wrapper bypassed the model");
    CHECK(gd.st.status == VF3_GDC_OK, "completed status was not consumed");

    regs[6] = 1; /* The r6=0 convention must still be enforced. */
    regs[7] = VF3_GD_REQ_CMD;
    out = run(ram, regs, 0x8C001006u, 0);
    CHECK(out.bios_calls == 0 && polls == 5 && out.unowned_calls == 1,
          "non-GD vector convention was incorrectly served");
    vf3_native_attach_gdrom(NULL);
    vf3_native_set_poll_hook(NULL, NULL);
}

static void capture_without_drive(uint8_t *ram)
{
    const uint32_t result_addr = VF3_NATIVE_RAM_BASE + 0x200;
    uint32_t regs[37] = { 0 };
    unsigned polls = 0;
    vf3_native_attach_gdrom(NULL);
    vf3_native_set_poll_hook(count_poll, &polls);
    regs[4] = VF3_GDCC_DMAREAD;
    regs[5] = 0xDEAD0000u; /* Captured refusal must not read the parameter block. */
    regs[7] = VF3_GD_REQ_CMD;
    vf3_native_tick_result out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.regs[0] == 0 && out.bios_calls == 0 && out.device_reads == 0,
          "no-drive REQ_CMD behavior changed");

    regs[4] = 2;
    regs[5] = result_addr;
    regs[7] = VF3_GD_GET_CMD_STAT;
    for (unsigned i = 0; i < 4; ++i) put32(ram, result_addr + 4 * i, 0xCCCCCCCCu);
    out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.regs[0] == VF3_GDC_OK && out.bios_calls == 0, "no-drive GET_CMD_STAT behavior changed");
    for (unsigned i = 0; i < 4; ++i)
        CHECK(get32(ram, result_addr + 4 * i) == 0, "no-drive result[%u] was not cleared", i);

    regs[0] = 0x12345678u;
    regs[7] = VF3_GD_EXEC_SERVER;
    out = run(ram, regs, 0x8C001006u, 1);
    CHECK(out.regs[0] == regs[0] && out.bios_calls == 0 && polls == 0,
          "no-drive EXEC_SERVER did not preserve captured behavior");
    vf3_native_set_poll_hook(NULL, NULL);
}

int main(void)
{
    /* Keep test behavior independent of optional local capture/clock settings. */
#ifdef _WIN32
    _putenv_s("VF3_GD_STATE", "");
    _putenv_s("VF3_GD_NOCLOCK", "");
#else
    unsetenv("VF3_GD_STATE");
    unsetenv("VF3_GD_NOCLOCK");
#endif
    vf3_native_set_stop(0);
    vf3_native_set_extra_stop(0);
    vf3_native_set_budget(10000);
    vf3_bios_gd_set_cycle_clock(0, 0);
    vf3_bios_gd_set_poll_divider(1);
    uint8_t *ram = calloc(1, VF3_NATIVE_RAM_LEN);
    if (!ram) { fputs("cannot allocate test RAM\n", stderr); return 2; }
    attached_drive(ram);
    capture_without_drive(ram);
    free(ram);
    printf("native GD-ROM routing: %d failures\n", failures);
    return failures != 0;
}
