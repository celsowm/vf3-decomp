/* sys/aica_arm.c - the AICA's ARM7 firmware and the chip around it.
 *
 * The reference is flycast's AICA:
 *
 *   aica.cpp timeStep()       one sample: the three timers by one, the
 *                             SAMPLE_DONE bits, the mixer, the interrupt
 *                             update
 *   aica.cpp update_arm_interrupts()  SCIEB & SCIPD -> the first pending
 *                             interrupt's level
 *   arm_mem.cpp update_e68k() the e68k latch holds that level until REG_M
 *                             accepts it
 *   arm7.cpp update_armintc() the latch is the ARM7's FIQ line
 *
 * The bus is the ARM7's view of the chip: sound RAM below 0x00800000, the
 * register file above it (offset & 0x7FFF), and the two ARM-side registers
 * REG_L (0x2D00, read) and REG_M (0x2D04, write to accept an interrupt).
 * A 32-bit access to the register file is a 16-bit access on this chip, which
 * is the reference's own readReg/writeReg rule.
 */
#include "sys/aica_arm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- optional one-shot write trace, for the live-runtime diagnostic
 * (tests/aica_live_replay.c).  A normal run never touches it: the buffer is
 * NULL until vf3_aica_arm_trace_begin arms it, and disabled after.  Each
 * entry is four u64: (sample, at, value, size) for every ARM7 bus write. */
static uint64_t *tr_writes;
static uint32_t tr_max, tr_count, tr_enabled;

void vf3_aica_arm_trace_begin(uint32_t max)
{
    free(tr_writes);
    tr_writes = NULL;
    if (max) tr_writes = (uint64_t *)malloc((size_t)max * 5u * sizeof(uint64_t));
    tr_max = max;
    tr_count = 0;
    tr_enabled = tr_writes != NULL;
}

void vf3_aica_arm_trace_end(void)
{
    tr_enabled = 0;
}

uint32_t vf3_aica_arm_trace_count(void)
{
    return tr_count;
}

const uint64_t *vf3_aica_arm_trace_get(void)
{
    return tr_writes;
}

/* The register file's offsets this module has an opinion about. */
#define AICA_REG_SCI       0x289Cu
#define AICA_REG_SCIPD     0x28A0u
#define AICA_REG_SCIRE     0x28A4u
#define AICA_REG_SCILV0    0x28A8u
#define AICA_REG_SCILV1    0x28ACu
#define AICA_REG_SCILV2    0x28B0u
#define AICA_REG_MCI       0x28B4u
#define AICA_REG_MCIPD     0x28B8u
#define AICA_REG_MCIRE     0x28BCu
#define AICA_REG_REG_L     0x2D00u
#define AICA_REG_REG_M     0x2D04u
#define AICA_REG_ARMRST    0x2C00u
#define AICA_REG_TIMER_A   0x2890u
#define AICA_REG_TIMER_B   0x2894u
#define AICA_REG_TIMER_C   0x2898u

/* The interrupt bits the reference names (its InterruptInfo layout). */
#define AICA_IRQ_MIDI_IN    (1u << 3)
#define AICA_IRQ_DMA_END    (1u << 4)
#define AICA_IRQ_SCPU       (1u << 5)
#define AICA_IRQ_TIMER_A    (1u << 6)
#define AICA_IRQ_TIMER_B    (1u << 7)
#define AICA_IRQ_TIMER_C    (1u << 8)
#define AICA_IRQ_SAMPLE     (1u << 10)

/* One sample of the chip is 512 cycles of its 22.5792 MHz clock. */
#define AICA_ARM_CYCLES_PER_SAMPLE 512u

/* The firmware's own mailbox: the word it publishes when it is up. */
#define AICA_INIT_OFFSET 0x5Cu
#define AICA_INIT_MAGIC  0x54494E49u

static uint32_t reg_word(const vf3_aica_arm *a, uint32_t offset)
{
    uint32_t v = 0;
    if (offset + 4u <= VF3_AICA_REG_SIZE)
        memcpy(&v, a->model->reg + offset, 4);
    return v;
}

static void reg_set_word(vf3_aica_arm *a, uint32_t offset, uint32_t value)
{
    if (offset + 4u <= VF3_AICA_REG_SIZE)
        memcpy(a->model->reg + offset, &value, 4);
}

/* The level a pending bit is wired to: SCILV0/1/2 carry one bit of the level
 * each, and the reference clamps the bit index above seven onto bit seven. */
static uint32_t interrupt_level(const vf3_aica_arm *a, unsigned which)
{
    const uint32_t bit = 1u << (which > 7u ? 7u : which);
    uint32_t level = 0;
    if (reg_word(a, AICA_REG_SCILV0) & bit) level |= 1u;
    if (reg_word(a, AICA_REG_SCILV1) & bit) level |= 2u;
    if (reg_word(a, AICA_REG_SCILV2) & bit) level |= 4u;
    return level;
}

/* The e68k latch: it captures the first pending interrupt and holds it until
 * the firmware writes REG_M.  It is the ARM7's FIQ input. */
static void update_armintc(vf3_aica_arm *a)
{
    if (a->e68k_out && !a->cpu.fiq_line) ++a->fiq_count;
    vf3_arm7_set_fiq(&a->cpu, a->e68k_out);
}

static void update_e68k(vf3_aica_arm *a)
{
    if (!a->e68k_out && a->aica_interr) {
        a->e68k_out = 1;
        a->reg_L = a->aica_reg_L;
        update_armintc(a);
    }
}

static void interrupt_change(vf3_aica_arm *a, uint32_t bits, uint32_t level)
{
    a->aica_interr = bits != 0;
    if (a->aica_interr) a->aica_reg_L = level;
    update_e68k(a);
}

/* SCIEB & SCIPD: the first pending bit (low bits first) names the level the
 * e68k latch sees. */
static void update_arm_interrupts(vf3_aica_arm *a)
{
    const uint32_t pending = reg_word(a, AICA_REG_SCI) &
                             reg_word(a, AICA_REG_SCIPD) & 0x7FFu;
    uint32_t level = 0;
    unsigned i;

    for (i = 0; i < 11u; ++i) {
        if (pending & (1u << i)) {
            level = interrupt_level(a, i);
            break;
        }
    }
    interrupt_change(a, pending, level);
}

/* The firmware accepts the interrupt through REG_M. */
static void e68k_accept(vf3_aica_arm *a)
{
    a->e68k_out = 0;
    update_e68k(a);
    update_armintc(a);
}

/* A timer's control byte is the second byte of its word: the low three bits
 * are the prescaler's shift.  Writing it while the shift changes restarts the
 * countdown, which is the reference's RegisterWrite. */
static void timer_register_write(vf3_aica_arm *a, unsigned id)
{
    const uint32_t shift = (a->model->reg[AICA_REG_TIMER_A + id * 4u + 1u]) & 7u;
    const uint32_t step = 1u << shift;
    if (step != a->timer[id].m_step) {
        a->timer[id].m_step = step;
        a->timer[id].c_step = step;
    }
}

/* One timer step of the reference's AicaTimer::StepTimer: the countdown runs
 * out every 1 << md samples and the eight-bit counter then wraps. */
static void timers_step(vf3_aica_arm *a)
{
    unsigned id;
    for (id = 0; id < 3u; ++id) {
        uint8_t *count = &a->model->reg[AICA_REG_TIMER_A + id * 4u];
        if (a->timer[id].c_step == 0)
            a->timer[id].c_step = a->timer[id].m_step;
        if (--a->timer[id].c_step == 0) {
            a->timer[id].c_step = a->timer[id].m_step;
            if (++*count == 0) {
                const uint32_t bit = AICA_IRQ_TIMER_A << id;
                reg_set_word(a, AICA_REG_SCIPD, reg_word(a, AICA_REG_SCIPD) | bit);
                reg_set_word(a, AICA_REG_MCIPD, reg_word(a, AICA_REG_MCIPD) | bit);
            }
        }
    }
}

/* ------------------------------------------------------------------ the bus */

static uint32_t ram_read(const uint8_t *ram, uint32_t address, unsigned size)
{
    const uint32_t base = address & (VF3_AICA_RAM_SIZE - 1u);
    uint32_t v = 0;
    unsigned i;
    if (size == 4u) {
        const unsigned shift = (base & 3u) * 8u;
        memcpy(&v, ram + (base & ~3u), 4);
        return shift ? (v >> shift) | (v << (32u - shift)) : v;
    }
    for (i = 0; i < size; ++i) v |= (uint32_t)ram[(base + i) & (VF3_AICA_RAM_SIZE - 1u)] << (8u * i);
    return v;
}

static void ram_write(uint8_t *ram, uint32_t address, uint32_t value, unsigned size)
{
    uint32_t base = address & (VF3_AICA_RAM_SIZE - 1u);
    unsigned i;
    if (size == 4u) {
        base &= ~3u;
        memcpy(ram + base, &value, 4);
        return;
    }
    for (i = 0; i < size; ++i)
        ram[(base + i) & (VF3_AICA_RAM_SIZE - 1u)] = (uint8_t)(value >> (8u * i));
}

static uint32_t arm_register_read(vf3_aica_arm *a, uint32_t address, unsigned size)
{
    const uint32_t offset = address & 0x7FFFu;
    if (offset == AICA_REG_REG_L) return a->reg_L;
    if (offset == AICA_REG_REG_M) return 0;
    /* A 32-bit register read is a 16-bit one on this chip. */
    if (size == 4u) size = 2u;
    return vf3_aica_read(a->model, offset, size);
}

static uint32_t arm_bus_read(void *context, uint32_t address, unsigned size)
{
    vf3_aica_arm *a = (vf3_aica_arm *)context;
    address &= 0x00FFFFFFu;
    if (address < VF3_AICA_RAM_SIZE) {
        uint32_t v = ram_read(a->model->ram, address, size);
        if (getenv("VF3_AICALOG") && getenv("VF3_ARMRING") && v != 0 &&
            address >= 0x400u && address < 0x500u)
            fprintf(stderr, "aica arm rd %04x = %08x / %u pc %04x\n",
                    address, v, size, a->cpu.last_pc);
        return v;
    }
    return arm_register_read(a, address, size);
}

static void arm_register_write(vf3_aica_arm *a, uint32_t address, uint32_t value, unsigned size)
{
    const uint32_t offset = address & 0x7FFFu;
    if (offset == AICA_REG_REG_L) return;              /* read only */
    if (offset == AICA_REG_REG_M) {                    /* accept the interrupt */
        if (value & 1u) e68k_accept(a);
        return;
    }
    if (size == 4u) {                                  /* 16-bit register file */
        value = (uint16_t)value;
        size = 2u;
    }
    ++a->reg_writes;
    /* The log is for the porting work, not for a transcript.  The firmware's
     * timer reload and its end-of-interrupt write happen once per FIQ (about
     * 134 times a field), and the driver zeroes all 1,152 channel registers at
     * start-up; neither says anything about a voice.  A channel register that
     * is given a value, and any write outside the timer/interrupt block, is
     * what the trace is for. */
    if (getenv("VF3_AICALOG") &&
        (offset < 0x2000u ? value != 0u : offset < 0x2800u || offset >= 0x3000u))
        fprintf(stderr, "aica arm wr %04x = %08x / %u\n", offset, value, size);
    vf3_aica_arm_note_write(a, offset, value, size);
}

static void arm_bus_write(void *context, uint32_t address, uint32_t value, unsigned size)
{
    vf3_aica_arm *a = (vf3_aica_arm *)context;
    address &= 0x00FFFFFFu;
    if (address < VF3_AICA_RAM_SIZE) {
        /* The music context table (0xc300) is what the A9/AB/BGM track walker
         * matches against; the 16 sequencer streams are at 0xcc50.  If the
         * firmware never populates the context table, no music command can
         * find a record and no voice is keyed.  Log any ARM7 write into the
         * context table with the PC that did it (VF3_CTXLOG).  The stream
         * records are watched through the periodic mix-report dump instead,
         * so this hook stays quiet (the sequencer writes its streams every
         * sample and would flood it). */
        if (getenv("VF3_CTXLOG") && address >= 0xC300u && address < 0xC400u)
            fprintf(stderr, "ctx wr %04x = %08x / %u pc %04x\n",
                    address, value, size, a->cpu.last_pc);
        if (getenv("VF3_CTXLOG") && a->cpu.last_pc >= 0x698cu &&
            a->cpu.last_pc <= 0x6a30u)
            fprintf(stderr, "commit wr %04x = %08x / %u pc %04x\n",
                    address, value, size, a->cpu.last_pc);
        ram_write(a->model->ram, address, value, size);
        if (tr_enabled && tr_count < tr_max) {
            tr_writes[tr_count * 5u + 0u] = a->samples;
            tr_writes[tr_count * 5u + 1u] = address;
            tr_writes[tr_count * 5u + 2u] = value;
            tr_writes[tr_count * 5u + 3u] = size;
            tr_writes[tr_count * 5u + 4u] = a->cpu.last_pc;
            ++tr_count;
        }
        return;
    }
    arm_register_write(a, address, value, size);
    if (tr_enabled && tr_count < tr_max) {
        tr_writes[tr_count * 5u + 0u] = a->samples;
        tr_writes[tr_count * 5u + 1u] = 0x80000000u | (address & 0x7FFFu);
        tr_writes[tr_count * 5u + 2u] = value;
        tr_writes[tr_count * 5u + 3u] = size;
        tr_writes[tr_count * 5u + 4u] = a->cpu.last_pc;
        ++tr_count;
    }
}

/* -------------------------------------------------------- the register file */

void vf3_aica_arm_note_write(vf3_aica_arm *a, uint32_t offset, uint32_t value,
                             unsigned size)
{
    if (offset >= VF3_AICA_REG_SIZE) return;

    /* the channel slots: the mixer reacts to the key-on trigger */
    if (offset < 0x2000u) {
        ++a->channel_writes;
        vf3_aica_mixer_write(a->mixer, offset, value, size);
        return;
    }
    /* the common and the DSP areas: bytes only (the DSP itself is not in the
     * circuit, see docs/re/aica_audio_model.md) */
    if (offset < 0x2800u || offset >= 0x3000u) {
        vf3_aica_write_bytes(a->model, offset, value, size);
        return;
    }
    /* 0x2800..0x2FFF: the chip's own registers */
    switch (offset) {
    case 0x2880u: case 0x2881u: case 0x2882u: case 0x2883u:
        /* MIDI input FIFO: no MIDI device is attached, so the byte is just
         * kept; the interrupt bits are not raised (the game plays no MIDI). */
        vf3_aica_write_bytes(a->model, offset, value, size);
        return;
    case AICA_REG_TIMER_A:
    case AICA_REG_TIMER_B:
    case AICA_REG_TIMER_C:
        vf3_aica_write_bytes(a->model, offset, value, size);
        timer_register_write(a, (offset - AICA_REG_TIMER_A) / 4u);
        return;
    case AICA_REG_SCI:
        reg_set_word(a, AICA_REG_SCI, value & 0x7FFu);
        update_arm_interrupts(a);
        return;
    case AICA_REG_SCIPD:
        /* Other bits are read-only; bit 5 is written by the CPU. */
        if (value & AICA_IRQ_SCPU) {
            reg_set_word(a, AICA_REG_SCIPD,
                         reg_word(a, AICA_REG_SCIPD) | AICA_IRQ_SCPU);
            update_arm_interrupts(a);
        }
        return;
    case AICA_REG_SCIRE:
        reg_set_word(a, AICA_REG_SCIPD,
                     reg_word(a, AICA_REG_SCIPD) & ~value);
        update_arm_interrupts(a);
        return;
    case AICA_REG_MCI:
        reg_set_word(a, AICA_REG_MCI, value & 0x7FFu);
        return;
    case AICA_REG_MCIPD:
        if (value & AICA_IRQ_SCPU)
            reg_set_word(a, AICA_REG_MCIPD,
                         reg_word(a, AICA_REG_MCIPD) | AICA_IRQ_SCPU);
        return;
    case AICA_REG_MCIRE:
        reg_set_word(a, AICA_REG_MCIPD,
                     reg_word(a, AICA_REG_MCIPD) & ~value);
        return;
    case AICA_REG_ARMRST:
        /* the reset line is a wire into the CPU, not a byte in the file */
        return;
    default:
        vf3_aica_write_bytes(a->model, offset, value, size);
        return;
    }
}

/* ------------------------------------------------------------- the machine */

void vf3_aica_arm_init(vf3_aica_arm *a, vf3_aica_model *model,
                       vf3_aica_mixer *mixer)
{
    vf3_arm7_bus bus;
    memset(a, 0, sizeof *a);
    a->model = model;
    a->mixer = mixer;
    bus.context = a;
    bus.read = arm_bus_read;
    bus.write = arm_bus_write;
    vf3_arm7_init(&a->cpu, &bus);
    vf3_aica_arm_reset(a);
}

void vf3_aica_arm_reset(vf3_aica_arm *a)
{
    unsigned id;
    vf3_arm7_reset(&a->cpu);
    a->aica_interr = 0;
    a->e68k_out = 0;
    a->aica_reg_L = 0;
    a->reg_L = 0;
    a->running = 0;
    a->samples = 0;
    a->reg_writes = 0;
    a->channel_writes = 0;
    a->fiq_count = 0;
    a->last_pc = 0;
    vf3_arm7_set_fiq(&a->cpu, 0);
    for (id = 0; id < 3u; ++id) {
        const uint32_t shift = a->model->reg[AICA_REG_TIMER_A + id * 4u + 1u] & 7u;
        a->timer[id].m_step = 1u << shift;
        a->timer[id].c_step = a->timer[id].m_step;
    }
}

uint32_t vf3_aica_arm_word(const vf3_aica_arm *a, uint32_t offset)
{
    uint32_t v = 0;
    if (offset + 4u <= VF3_AICA_RAM_SIZE)
        memcpy(&v, a->model->ram + offset, 4);
    return v;
}

int vf3_aica_arm_release(vf3_aica_arm *a, uint32_t max_cycles)
{
    uint32_t spent = 0;
    vf3_aica_arm_reset(a);
    a->running = 1;
    while (spent < max_cycles) {
        spent += vf3_arm7_run(&a->cpu, AICA_ARM_CYCLES_PER_SAMPLE);
        timers_step(a);
        reg_set_word(a, AICA_REG_SCIPD,
                     reg_word(a, AICA_REG_SCIPD) | AICA_IRQ_SAMPLE);
        reg_set_word(a, AICA_REG_MCIPD,
                     reg_word(a, AICA_REG_MCIPD) | AICA_IRQ_SAMPLE);
        update_arm_interrupts(a);
        ++a->samples;
        if (vf3_aica_arm_word(a, AICA_INIT_OFFSET) == AICA_INIT_MAGIC) break;
    }
    a->last_pc = a->cpu.last_pc;
    return vf3_aica_arm_word(a, AICA_INIT_OFFSET) == AICA_INIT_MAGIC;
}

void vf3_aica_arm_sample(vf3_aica_arm *a, int16_t *right, int16_t *left)
{
    if (a->running) vf3_arm7_run(&a->cpu, AICA_ARM_CYCLES_PER_SAMPLE);
    timers_step(a);
    reg_set_word(a, AICA_REG_SCIPD,
                 reg_word(a, AICA_REG_SCIPD) | AICA_IRQ_SAMPLE);
    reg_set_word(a, AICA_REG_MCIPD,
                 reg_word(a, AICA_REG_MCIPD) | AICA_IRQ_SAMPLE);
    update_arm_interrupts(a);
    ++a->samples;
    a->last_pc = a->cpu.last_pc;
    vf3_aica_mixer_sample(a->mixer, right, left);
}
