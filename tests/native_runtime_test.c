/* ROM-free lifecycle unit test. This executable links native_tick.c and the
 * real GD model, but deliberately substitutes a controlled dispatcher for
 * game code. The scenarios below are test operations, not oracle evidence
 * or fabricated gameplay/boot states. No test hook enters the shipping API. */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <process.h>
#define process_id _getpid
#else
#include <unistd.h>
#define process_id getpid
#endif
#include "fight/native_tick.h"
#include "fight/readable.h"

vf3_family_hook_fn vf3_family_override, vf3_family_missing, vf3_family_fail;
vf3_family_obs_fn vf3_family_enter, vf3_family_leave;
int vf3_family_complete_calls, vf3_family_tail_retry, vf3_sq_model;
void vf3_matrix_reset_sq(void) { vf3_sq_model = 0; }
uint32_t vf3_family_extra_stop;
uint32_t (*vf3_family_budget_hook)(void);
int (*vf3_family_call_entry)(uint32_t);

enum { TEST_OUTER = 1, TEST_IRQ, TEST_INSPECT, TEST_BUDGET, TEST_UNKNOWN, TEST_BAD_IRQ,
       TEST_QUEUE, TEST_FRESH, TEST_BUS_OUTER, TEST_BUS_IRQ, TEST_BUS_PROBE,
       TEST_FAILURE_PARENT, TEST_UNSUPPORTED, TEST_CHILD_BUDGET, TEST_OOB, TEST_SWALLOW_UNKNOWN };
enum { OUTER_STOP = 0x12340000u, IRQ_STOP = 0x23450000u, OUTER_EXTRA = 0x12340004u,
       IRQ_EXTRA = 0x23450004u, TA_COUNT = 65537, TA_PREFIX = 0xAA123456u, TA_SUFFIX = 0xBB123456u };
static int failures;
static uint8_t *test_ram;
static vf3_gdrom test_gd;
static unsigned polls, budget_calls;
static unsigned prior_gd_writes;
static uint32_t parent_xf[16], irq_xf[16];
enum { BUS_READ = 0x005F9000u, BUS_WRITE = 0x005F9004u, BUS_ERROR_READ = 0x005F9008u, BUS_ERROR_WRITE = 0x005F900Cu };
static struct { unsigned reads, writes; uint32_t written; } bus_state;
#define CHECK(c, ...) do { if (!(c)) { ++failures; fprintf(stderr, "FAIL line %d: ", __LINE__); \
    fprintf(stderr, __VA_ARGS__); fputc('\n', stderr); } } while (0)

/* Minimal memory access needed by the real GD hook and optional diagnostics. */
uint32_t vf3_matrix_read(const vf3_ram_map *ram, uint32_t address, unsigned size)
{
    const uint32_t a = address & 0x1FFFFFFFu;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a - w->base <= w->len && size <= w->len - (a - w->base)) {
            uint32_t value = 0;
            memcpy(&value, w->data + a - w->base, size);
            return value;
        }
    }
    return ram->device_read(ram->device_context, address, size);
}
uint32_t vf3_mem_u32(const vf3_ram_map *ram, uint32_t address) { return vf3_matrix_read(ram, address, 4); }
void vf3_mem_set_u32(const vf3_ram_map *ram, uint32_t address, uint32_t value)
{
    memcpy(ram->wins[0].data + (address & 0x1FFFFFFFu) - ram->wins[0].base, &value, 4);
}
int vf3_native_call_target(uint32_t entry) { (void)entry; return 1; }
const vf3_readable_entry *vf3_readable_find(uint32_t entry) { (void)entry; return NULL; }
int vf3_readable_override(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{ (void)entry; (void)s; (void)ram; *handled = 0; return 0; }

static void write_device(const vf3_ram_map *ram, uint32_t address, uint32_t value)
{ ram->device_write(ram->device_context, address, 4, value); }
static uint32_t read_device(const vf3_ram_map *ram, uint32_t address)
{ return ram->device_read(ram->device_context, address, 4); }
static uint32_t no_budget(void) { return 0; }
static void unexpected_poll(void *unused) { (void)unused; CHECK(0, "nested poll hook leaked into parent"); }

int vf3_matrix_family(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == TEST_OUTER) {
        CHECK(s->v[16] == OUTER_STOP && vf3_family_extra_stop == OUTER_EXTRA, "outer configuration missing");
        CHECK(memcmp(s->v + 37, parent_xf, sizeof parent_xf) == 0, "outer XF seed changed");
        write_device(ram, 0x10000000u, TA_PREFIX);
        write_device(ram, 0x00800088u, 0x001E0000u);
        int handled = 0;
        s->v[6] = 0;
        s->v[7] = VF3_GD_INIT_SYSTEM;
        CHECK(vf3_family_override(VF3_BIOS_SYSCALL_VECTOR, s, ram, &handled) && handled, "real GD hook did not run");
        CHECK(vf3_family_extra_stop == OUTER_EXTRA && vf3_family_budget_hook != NULL, "nested execution changed parent hooks");
        CHECK(vf3_native_asic_pending() == 0x14u, "IRQ event changes rolled back: %08x", vf3_native_asic_pending());
        CHECK(read_device(ram, 0x00800088u) == 0x001D0000u, "IRQ AICA write lost");
        CHECK(read_device(ram, 0x1FD8000Cu) == 0xFFFFFEFFu, "IRQ TMU advance lost");
        write_device(ram, 0x10000000u, TA_SUFFIX);
        s->budget -= 3;
    } else if (entry == TEST_IRQ) {
        CHECK(vf3_native_reset() == 0, "reset succeeded inside an active invocation");
        CHECK(s->v[16] == IRQ_STOP && vf3_family_extra_stop == IRQ_EXTRA, "IRQ configuration missing");
        CHECK(vf3_family_budget_hook == NULL && s->budget > 1, "IRQ inherited outer slicing");
        CHECK(memcmp(s->v + 37, irq_xf, sizeof irq_xf) == 0, "IRQ XF seed missing");
        write_device(ram, 0x005F6900u, 0x2u);
        vf3_native_raise_asic(0x4u);
        write_device(ram, 0x005F6C04u, 0x0C123400u);
        write_device(ram, 0x005F6C18u, 1);
        write_device(ram, 0x1FA0002Cu, 1);
        write_device(ram, 0x005F8014u, 1);
        write_device(ram, 0x00800088u, 0x001D0000u);
        vf3_native_tmu_advance(256);
        for (unsigned i = 0; i < TA_COUNT; ++i) write_device(ram, 0x10000000u, 0x20000000u + i);
        s->budget -= 2;
    } else if (entry == TEST_INSPECT || entry == TEST_FRESH) {
        if (entry == TEST_FRESH) CHECK(s->budget == 1000000000u && vf3_family_extra_stop == 0 && !vf3_family_budget_hook,
                                      "reset retained budget/stop configuration");
        s->v[0] = read_device(ram, 0x00800088u);
        s->v[1] = read_device(ram, 0x1FD8000Cu);
        --s->budget;
    } else if (entry == TEST_QUEUE) {
        write_device(ram, 0x005F6C04u, 0x0C123400u);
        write_device(ram, 0x005F6C18u, 1);
        write_device(ram, 0x1FA0002Cu, 1);
        write_device(ram, 0x005F8014u, 1);
    } else if (entry == TEST_BUDGET) {
        CHECK(s->budget == 3, "initial step budget changed");
        s->budget = UINT_MAX; /* generated STEP's exhausted state */
        uint32_t more = vf3_family_budget_hook();
        CHECK(more == 2, "first refill %u, expected 2", more);
        s->budget = more;
        s->budget = UINT_MAX;
        CHECK(vf3_family_budget_hook() == 0, "second refill must yield");
        s->failed_pc = TEST_BUDGET;
        return 0;
    } else if (entry == TEST_BAD_IRQ) {
        uint32_t regs[37] = {0};
        vf3_native_tick_result child;
        CHECK(!vf3_native_tick_run(test_ram, regs, TEST_UNKNOWN, 0, &child), "unowned child unexpectedly succeeded");
        CHECK(child.unowned_calls == 1 && child.first_unowned == TEST_UNKNOWN, "child unowned diagnostic missing");
    } else if (entry == TEST_FAILURE_PARENT) {
        uint32_t regs[37] = {0};
        regs[0] = s->v[1]; /* optional next-level entry for the nested-parent case */
        vf3_native_tick_result child;
        CHECK(!vf3_native_tick_run(test_ram, regs, s->v[0], 0, &child), "controlled failing child succeeded");
        s->v[2] = 0xCAFE1234u; /* the parent continues and its dispatcher returns success */
    } else if (entry == TEST_UNSUPPORTED || entry == TEST_CHILD_BUDGET) {
        if (entry == TEST_CHILD_BUDGET) s->budget = UINT_MAX; /* exhausted STEP, with no unowned call */
        s->v[2] = 0xBAD01234u;
        s->failed_pc = entry;
        return 0;
    } else if (entry == TEST_OOB) {
        ++((vf3_ram_map *)ram)->oob; /* a failed access can be followed by dispatcher success */
    } else if (entry == TEST_SWALLOW_UNKNOWN) {
        int handled = 0;
        (void)vf3_family_missing(TEST_UNKNOWN, s, ram, &handled);
    } else if (entry == TEST_BUS_OUTER) {
        CHECK(!vf3_native_attach_device_bus(NULL), "device bus detached inside active run");
        CHECK(read_device(ram, BUS_READ) == 0x11223344u, "device bus read not routed");
        write_device(ram, BUS_WRITE, 0x55667788u);
        write_device(ram, 0x00800088u, 0xABCDu);
        CHECK(read_device(ram, 0x00800088u) == 0xABCDu, "unclaimed device request did not reach built-in AICA");
        write_device(ram, 0x10000000u, TA_PREFIX);
        uint32_t regs[37] = {0};
        vf3_native_tick_result child;
        CHECK(!vf3_native_tick_run(test_ram, regs, TEST_BUS_IRQ, 0, &child), "nested device errors did not fail invocation");
        CHECK(child.device_errors == 2 && child.first_device_error == BUS_ERROR_READ, "nested device diagnostics lost");
        CHECK(read_device(ram, BUS_READ) == 0x11223344u, "nested execution detached device bus");
    } else if (entry == TEST_BUS_IRQ) {
        (void)read_device(ram, BUS_ERROR_READ);
        write_device(ram, BUS_ERROR_WRITE, 1);
    } else if (entry == TEST_BUS_PROBE) {
        s->v[0] = read_device(ram, BUS_READ);
    } else {
        int handled = 0;
        s->failed_pc = entry;
        return vf3_family_missing(entry, s, ram, &handled);
    }
    s->pc = s->v[16];
    return 1;
}

static void nested_irq(void *ctx)
{
    CHECK(ctx == &polls, "parent poll context changed");
    ++polls;
    vf3_native_set_stop(IRQ_STOP);
    vf3_native_set_extra_stop(IRQ_EXTRA);
    vf3_native_set_budget(1);
    vf3_native_set_budget_hook(no_budget);
    vf3_native_set_poll_hook(unexpected_poll, NULL);
    vf3_native_set_xf(irq_xf);
    uint32_t regs[37] = {0};
    vf3_native_tick_result child;
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_IRQ, 0, &child), "IRQ failed");
    CHECK(child.ta_words == TA_COUNT && child.ta[0] == 0x20000000u && child.ta[TA_COUNT - 1] == 0x20000000u + TA_COUNT - 1,
          "nested TA view includes parent words or lost allocation growth");
    CHECK(child.device_writes == TA_COUNT + 6 && child.device_reads == 0 && child.steps_budget_used == 2,
          "IRQ counters wrong: writes %u reads %u steps %u", child.device_writes, child.device_reads, child.steps_budget_used);
    uint32_t xf[16];
    vf3_native_get_xf(xf);
    CHECK(memcmp(xf, parent_xf, sizeof xf) == 0, "nested XF configuration leaked");
}

static int prior_hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int *handled)
{ (void)entry; (void)s; (void)ram; (void)handled; return 0; }
static void prior_observer(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram, int ok)
{ (void)entry; (void)s; (void)ram; (void)ok; }
static void prior_gd_write(void *ctx, uint32_t address, const uint8_t *data, uint32_t len)
{
    CHECK(ctx == &prior_gd_writes && address == VF3_NATIVE_RAM_BASE + 16 && data && len == 4,
          "restored GD writer/context changed");
    ++prior_gd_writes;
}

static void nesting_and_reset(void)
{
    CHECK(vf3_native_reset(), "initial reset failed");
    vf3_gdi disc = {0};
    vf3_gd_init(&test_gd, &disc, prior_gd_write, &prior_gd_writes);
    vf3_native_attach_gdrom(&test_gd);
    /* Reattaching the same borrowed object must not replace its saved writer. */
    vf3_native_attach_gdrom(&test_gd);
    vf3_native_set_poll_hook(nested_irq, &polls);
    vf3_native_set_budget(4);
    vf3_native_set_stop(OUTER_STOP);
    vf3_native_set_extra_stop(OUTER_EXTRA);
    vf3_native_set_xf(parent_xf);
    vf3_native_enable_tmu();
    vf3_native_tmu_set(0xFFFFFF00u);
    vf3_native_raise_asic(0x12u);
    vf3_family_override = vf3_family_missing = vf3_family_fail = prior_hook;
    vf3_family_enter = vf3_family_leave = prior_observer;
    vf3_family_call_entry = vf3_native_call_target;
    vf3_family_budget_hook = no_budget;
    vf3_family_extra_stop = 0x9999u;
    vf3_family_complete_calls = 7;
    vf3_family_tail_retry = 8;
    vf3_sq_model = 9;
    uint32_t regs[37] = {0};
    vf3_native_tick_result out;
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_OUTER, 0, &out), "outer invocation failed");
    CHECK(out.pc == OUTER_STOP && polls == 1, "outer return/poll count wrong");
    CHECK(out.ta_words == TA_COUNT + 2 && !out.ta_failed, "outer TA size %u", out.ta_words);
    CHECK(out.ta[0] == TA_PREFIX && out.ta[out.ta_words - 1] == TA_SUFFIX, "outer TA prefix/suffix overwritten");
    for (unsigned i = 0; i < TA_COUNT; ++i) {
        if (out.ta[i + 1] != 0x20000000u + i) { CHECK(0, "TA ordering differs at %u", i); break; }
    }
    CHECK(out.device_writes == TA_COUNT + 9 && out.device_reads == 2 && out.bios_calls == 1 && out.steps_budget_used == 5,
          "inclusive counters wrong: writes %u reads %u BIOS %u steps %u", out.device_writes, out.device_reads, out.bios_calls, out.steps_budget_used);
    CHECK(vf3_family_override == prior_hook && vf3_family_missing == prior_hook && vf3_family_fail == prior_hook &&
          vf3_family_enter == prior_observer && vf3_family_leave == prior_observer && vf3_family_budget_hook == no_budget &&
          vf3_family_call_entry == vf3_native_call_target && vf3_family_extra_stop == 0x9999u &&
          vf3_family_complete_calls == 7 && vf3_family_tail_retry == 8 && vf3_sq_model == 9, "dispatcher hooks not restored");
    uint32_t list = 0;
    CHECK(vf3_native_take_maple(&list) == 1 && list == 0x0C123400u, "nested Maple event lost");
    CHECK(vf3_native_take_dma2() == 1 && vf3_native_take_render() == 1, "nested DMA/render event lost");
    CHECK(vf3_native_take_maple(NULL) == 0 && vf3_native_take_dma2() == 0 && vf3_native_take_render() == 0, "events not consumed");
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_INSPECT, 0, &out), "second invocation failed");
    CHECK(out.pc == OUTER_STOP && out.device_reads == 2 && out.device_writes == 0 && out.ta_words == 0,
          "per-call output or outer stop leaked from IRQ");
    CHECK(out.regs[0] == 0x001D0000u && out.regs[1] == 0xFFFFFEFFu, "hardware did not persist across top-level calls");

    const uint8_t data[4] = {1, 2, 3, 4};
    test_gd.write(test_gd.write_ctx, VF3_NATIVE_RAM_BASE + 16, data, 4);
    CHECK(memcmp(test_ram + 16, data, 4) == 0, "between-call GD transfer lost RAM binding");
    CHECK(prior_gd_writes == 0, "attached drive called the replaced writer");
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_QUEUE, 0, &out), "could not queue reset-test events");
    CHECK(vf3_native_reset() && vf3_native_reset(), "idle reset is not repeatable");
    CHECK(!vf3_native_gd_attached() && !vf3_native_asic_pending(), "reset retained drive/ASIC state");
    CHECK(vf3_native_take_maple(&list) == 0 && list == 0 && vf3_native_take_dma2() == 0 && vf3_native_take_render() == 0,
          "reset retained queued events");
    memset(test_ram + 16, 0, 4);
    CHECK(test_gd.write == prior_gd_write && test_gd.write_ctx == &prior_gd_writes, "reset did not restore borrowed drive callback");
    test_gd.write(test_gd.write_ctx, VF3_NATIVE_RAM_BASE + 16, data, 4);
    CHECK(test_ram[16] == 0 && prior_gd_writes == 1, "detached drive retained caller RAM binding");
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_FRESH, 0, &out), "fresh invocation failed");
    CHECK(out.pc == 0xDEAD0000u && out.regs[0] == 0 && out.regs[1] == 0, "reset retained stop/AICA/TMU state");
    for (unsigned i = 37; i < 53; ++i) CHECK(out.regs[i] == 0, "reset retained XF[%u]", i - 37);
}

static int bus_read(void *ctx, uint32_t address, unsigned size, uint32_t *value)
{
    CHECK(ctx == &bus_state && size == 4, "bus read context/size changed");
    if (address == BUS_READ) { ++bus_state.reads; *value = 0x11223344u; return 1; }
    if (address == BUS_ERROR_READ) { ++bus_state.reads; return -1; }
    return 0;
}
static int bus_write(void *ctx, uint32_t address, unsigned size, uint32_t value)
{
    CHECK(ctx == &bus_state && size == 4, "bus write context/size changed");
    if (address == BUS_WRITE) { ++bus_state.writes; bus_state.written = value; return 1; }
    if (address == BUS_ERROR_WRITE) { ++bus_state.writes; return -1; }
    return 0;
}
static void device_bus(void)
{
    uint32_t regs[37] = {0};
    vf3_native_tick_result out;
    CHECK(vf3_native_reset(), "bus test reset failed");
    const vf3_native_device_bus bus = {bus_read, bus_write, &bus_state};
    CHECK(vf3_native_attach_device_bus(&bus), "bus attach failed");
    CHECK(!vf3_native_tick_run(test_ram, regs, TEST_BUS_OUTER, 0, &out), "nested bus errors did not fail parent");
    CHECK(out.device_errors == 2 && out.first_device_error == BUS_ERROR_READ && out.unowned_calls == 0,
          "parent bus diagnostics are missing or misclassified");
    CHECK(out.device_reads == 4 && out.device_writes == 4 && out.ta_words == 1 && out.ta[0] == TA_PREFIX,
          "bus pass-through counters/TA changed");
    CHECK(bus_state.reads == 3 && bus_state.writes == 2 && bus_state.written == 0x55667788u, "bus handled operations lost");
    CHECK(vf3_native_reset(), "bus reset failed");
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_BUS_PROBE, 0, &out), "detached bus probe failed");
    CHECK(out.regs[0] == 0 && out.device_errors == 0 && bus_state.reads == 3, "reset did not detach bus");
    CHECK(vf3_native_attach_device_bus(&bus) && vf3_native_attach_device_bus(NULL), "idle bus detach failed");
}

static uint32_t refill(void) { return budget_calls++ == 0 ? 2 : 0; }
static void diagnostics(void)
{
    uint32_t regs[37] = {0};
    vf3_native_tick_result out;
    CHECK(vf3_native_reset(), "diagnostic reset failed");
    vf3_native_set_budget(3);
    vf3_native_set_budget_hook(refill);
    CHECK(!vf3_native_tick_run(test_ram, regs, TEST_BUDGET, 0, &out), "exhausted invocation succeeded");
    CHECK(out.steps_budget_used == 5 && budget_calls == 2 && out.unowned_calls == 0, "budget refills/exhaustion counted incorrectly");
    CHECK(vf3_native_reset(), "diagnostic reset failed");
    CHECK(!vf3_native_tick_run(test_ram, regs, TEST_BAD_IRQ, 0, &out) && !out.ok, "nested unowned failure did not fail parent");
    CHECK(out.unowned_calls == 1 && out.first_unowned == TEST_UNKNOWN, "nested unowned failure hidden from parent");
    CHECK(out.nested_failures == 1 && out.first_nested_entry == TEST_UNKNOWN && out.first_nested_failed_pc == TEST_UNKNOWN,
          "nested unowned failure provenance lost");
    CHECK(out.pc == 0xDEAD0000u && out.failed_pc == 0, "child failure replaced parent PC");

    const uint32_t cases[] = {TEST_UNSUPPORTED, TEST_CHILD_BUDGET, TEST_OOB, TEST_SWALLOW_UNKNOWN};
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; ++i) {
        memset(regs, 0, sizeof regs);
        CHECK(!vf3_native_tick_run(test_ram, regs, cases[i], 0, &out) && !out.ok,
              "own failure %u was accepted", cases[i]);
        CHECK(out.nested_failures == 0 && out.first_nested_entry == 0 && out.first_nested_failed_pc == 0,
              "own failure was misclassified as nested");
        regs[0] = cases[i];
        CHECK(!vf3_native_tick_run(test_ram, regs, TEST_FAILURE_PARENT, 0, &out) && !out.ok,
              "nested failure %u was swallowed", cases[i]);
        CHECK(out.nested_failures == 1 && out.first_nested_entry == cases[i], "nested failure provenance missing");
        CHECK(out.first_nested_failed_pc == ((cases[i] == TEST_UNSUPPORTED || cases[i] == TEST_CHILD_BUDGET) ? cases[i] : 0),
              "child failed PC was not preserved separately");
        CHECK(out.pc == 0xDEAD0000u && out.failed_pc == 0 && out.regs[0] == cases[i] && out.regs[2] == 0xCAFE1234u,
              "failed child replaced parent CPU context");
        CHECK(out.oob == (cases[i] == TEST_OOB ? 1u : 0u) &&
              out.unowned_calls == (cases[i] == TEST_SWALLOW_UNKNOWN ? 1u : 0u), "nested access diagnostics changed");
    }
    regs[0] = TEST_FAILURE_PARENT; regs[1] = TEST_UNSUPPORTED;
    CHECK(!vf3_native_tick_run(test_ram, regs, TEST_FAILURE_PARENT, 0, &out) && !out.ok, "grandchild failure was swallowed");
    CHECK(out.nested_failures == 2 && out.first_nested_entry == TEST_UNSUPPORTED && out.first_nested_failed_pc == TEST_UNSUPPORTED,
          "multi-level failure count or first provenance wrong");
    CHECK(out.pc == 0xDEAD0000u && out.failed_pc == 0 && out.regs[0] == TEST_FAILURE_PARENT && out.regs[2] == 0xCAFE1234u,
          "grandchild failure replaced parent CPU context");
    CHECK(vf3_native_tick_run(test_ram, regs, TEST_INSPECT, 0, &out) && out.ok, "failure leaked into next invocation");
    CHECK(out.nested_failures == 0 && out.first_nested_entry == 0 && out.first_nested_failed_pc == 0 && out.oob == 0 && out.unowned_calls == 0,
          "next invocation retained previous failure diagnostics");
}

static int record(FILE *f, uint64_t word) { return fwrite(&word, sizeof word, 1, f) == 1; }
static int windows(FILE *f)
{
    static const uint64_t zeros[4096] = {0};
    if (!record(f, 1) || !record(f, VF3_NATIVE_RAM_BASE) || !record(f, VF3_NATIVE_RAM_LEN)) return 0;
    for (unsigned i = 0; i < VF3_NATIVE_RAM_LEN / 4 / 4096; ++i)
        if (fwrite(zeros, sizeof zeros, 1, f) != 1) return 0;
    return 1;
}

static void capture_read_lifecycle(const char *stem)
{
    char path[1024];
    snprintf(path, sizeof path, "%s.%ld.bin", stem, (long)process_id());
    FILE *f = fopen(path, "wb");
    CHECK(f != NULL, "cannot create synthetic format fixture");
    if (!f) return;
    int valid = record(f, 0x1FA30u);
    for (unsigned i = 0; i < 37; ++i) valid &= record(f, 0x100u + i);
    valid &= record(f, 0x1FA70u);
    for (unsigned i = 0; i < 16; ++i) valid &= record(f, ((uint64_t)irq_xf[i] << 16) | 0xFA70u);
    valid &= record(f, 0x1FA50u) && windows(f) && record(f, 0x1FA32u);
    for (unsigned i = 0; i < 37; ++i) valid &= record(f, 0x200u + i);
    valid &= record(f, 0x1FA60u) && windows(f);
    valid &= fclose(f) == 0;
    CHECK(valid, "cannot write synthetic format fixture");
    uint32_t regs[37], xf[16];
    uint8_t *ram = NULL;
    vf3_native_set_xf(parent_xf);
    CHECK(vf3_native_load_exit(path, 0, regs, &ram), "cannot load format fixture exit");
    CHECK(regs[0] == 0x200u && ram != NULL, "wrong exit loaded");
    free(ram);
    vf3_native_get_xf(xf);
    CHECK(memcmp(xf, parent_xf, sizeof xf) == 0, "reading exit changed XF seed");
    CHECK(!vf3_native_load_snapshot(path, 7, regs, &ram), "absent pair unexpectedly loaded");
    vf3_native_get_xf(xf);
    CHECK(memcmp(xf, parent_xf, sizeof xf) == 0, "failed load changed XF seed");
    CHECK(vf3_native_load_snapshot(path, 0, regs, &ram), "cannot load format fixture entry");
    CHECK(regs[0] == 0x100u, "wrong entry loaded");
    free(ram);
    vf3_native_get_xf(xf);
    CHECK(memcmp(xf, irq_xf, sizeof xf) == 0, "successful entry load did not import XF");
    CHECK(remove(path) == 0, "cannot remove format fixture");
}

int main(int argc, char **argv)
{
    test_ram = calloc(1, VF3_NATIVE_RAM_LEN);
    if (!test_ram) return 2;
    for (unsigned i = 0; i < 16; ++i) { parent_xf[i] = 0x1000u + i; irq_xf[i] = 0x2000u + i; }
    nesting_and_reset();
    diagnostics();
    device_bus();
    capture_read_lifecycle(argc > 1 ? argv[1] : "native_runtime_capture");
    CHECK(vf3_native_reset(), "final reset failed");
    free(test_ram);
    printf("native runtime lifecycle: %d failures\n", failures);
    return failures != 0;
}
