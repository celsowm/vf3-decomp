/* sys/arm7.c - the AICA's ARM7TDMI, an ARMv4T interpreter (see sys/arm7.h).
 *
 * The decoder follows the ARM7TDMI data sheet's instruction classes.  The
 * register file is kept in cpu->r[] for the active mode; switch_bank() moves
 * r13/r14 (and r8..r12 for FIQ) in and out of the banks, so an exception and
 * its return cannot leak a register between modes.
 *
 * PC convention inside an instruction: cpu->r[15] is the address of the
 * instruction being executed, and each handler leaves it at the next
 * instruction.  A read of r15 yields pc+8 (ARM) or pc+4 (Thumb), which is the
 * pipeline the ARM7TDMI has.  Exception returns restore CPSR from SPSR and
 * let switch_bank() put the mode's registers back.
 */
#include "sys/arm7.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_N 0x80000000u
#define FLAG_Z 0x40000000u
#define FLAG_C 0x20000000u
#define FLAG_V 0x10000000u
#define FLAG_I 0x00000080u
#define FLAG_F 0x00000040u
#define FLAG_T 0x00000020u

/* flycast's arm-new.h interpreter bills a base 6 cycles per retired
 * instruction (its "clockTicks += 6" before per-class access work).  See
 * vf3_arm7_step. */
#define VF3_ARM7_BASE_CYCLES 6u

/* The executed-PC histogram (see arm7.h).  The firmware lives below 0x10000
 * and is 4-byte aligned ARM, so 64 KiB of uint32 is the whole instrumented
 * region.  g_pc_hist is the windowed histogram (reset each report); g_tot is
 * cumulative for the whole run, which is how the rare ring-command handlers
 * (fired once a field at most) stay visible. */
static uint32_t g_pc_hist[0x4000u];
static uint32_t g_tot[0x4000u];

/* Optional sequential executed-PC log (VF3_ARMSEQ), for the melody-gap
 * root-cause work: when enabled, every retired instruction's PC is appended
 * to build/arm_seq.bin as one little-endian uint32, with a second pass gated
 * on VF3_ARMSEQLO/VF3_ARMSEGHI (in retired instruction-count, inclusive) so a
 * window can be captured.  g_seq is a FILE*, kept NULL unless armed. */
static FILE *g_seq;
static uint64_t g_seq_lo, g_seq_hi;
static int g_seq_armed;
static int g_seq_requested;

static void seq_maybe_open(uint64_t icount)
{
    if (g_seq || g_seq_requested) return;
    if (!getenv("VF3_ARMSEQ")) return;
    g_seq_requested = 1;
    const char *lo = getenv("VF3_ARMSEQLO"), *hi = getenv("VF3_ARMSEGHI");
    g_seq_lo = lo ? strtoull(lo, NULL, 0) : 0;
    g_seq_hi = hi ? strtoull(hi, NULL, 0) : UINT64_MAX;
    g_seq = fopen("build/arm_seq.bin", "wb");
    g_seq_armed = g_seq != NULL;
    if (g_seq && icount > g_seq_hi)
        g_seq_armed = 0;
}

static void seq_close(void)
{
    if (g_seq) fclose(g_seq);
    g_seq = NULL;
    g_seq_armed = 0;
    g_seq_requested = 0;
}

void vf3_arm7_seq_close(void) { seq_close(); }

void vf3_arm7_pc_hist_reset(void)
{
    memset(g_pc_hist, 0, sizeof(g_pc_hist));
}

/* ---------------------------------------------------------------- banking */

static unsigned bank_of(uint32_t mode)
{
    switch (mode & 0x1Fu) {
    case VF3_ARM_MODE_FIQ: return 1;
    case VF3_ARM_MODE_IRQ: return 2;
    case VF3_ARM_MODE_SVC: return 3;
    case VF3_ARM_MODE_ABT: return 4;
    case VF3_ARM_MODE_UND: return 5;
    default: return 0;                  /* USR and SYS share their bank */
    }
}

/* Move the active register file from `old_mode` to `new_mode`.  Every mode's
 * r13/r14 are banked, including USR/SYS (index 0); FIQ additionally banks
 * r8..r12 and keeps the non-FIQ five in usr_r8. */
static void switch_bank(vf3_arm7 *cpu, uint32_t old_mode, uint32_t new_mode)
{
    const unsigned o = bank_of(old_mode), n = bank_of(new_mode);
    unsigned i;
    if (o == n) return;
    cpu->bank_r13[o] = cpu->r[13];
    cpu->bank_r14[o] = cpu->r[14];
    if (o == 1) {
        for (i = 0; i < 5; ++i) cpu->fiq_r8[i] = cpu->r[8 + i];
    } else if (n == 1) {
        for (i = 0; i < 5; ++i) cpu->usr_r8[i] = cpu->r[8 + i];
    }
    cpu->r[13] = cpu->bank_r13[n];
    cpu->r[14] = cpu->bank_r14[n];
    if (n == 1) {
        for (i = 0; i < 5; ++i) cpu->r[8 + i] = cpu->fiq_r8[i];
    } else if (o == 1) {
        for (i = 0; i < 5; ++i) cpu->r[8 + i] = cpu->usr_r8[i];
    }
}

/* ---------------------------------------------------------------- memory */

static uint32_t bus_read(vf3_arm7 *cpu, uint32_t address, unsigned size)
{
    uint32_t v;
    if (!cpu->bus.read) return 0;
    v = cpu->bus.read(cpu->bus.context, address, size);
    if (size == 1) return v & 0xFFu;
    if (size == 2) return v & 0xFFFFu;
    return v;
}

static void bus_write(vf3_arm7 *cpu, uint32_t address, uint32_t value, unsigned size)
{
    if (cpu->bus.write) cpu->bus.write(cpu->bus.context, address, value, size);
}

static uint32_t fetch16(vf3_arm7 *cpu, uint32_t address)
{
    return bus_read(cpu, address & ~1u, 2);
}

static uint32_t fetch32(vf3_arm7 *cpu, uint32_t address)
{
    return bus_read(cpu, address & ~3u, 4);
}

/* Reading r15: the ARM7TDMI's pipeline is two instructions ahead in ARM
 * state and one ahead in Thumb. */
static uint32_t reg_read(vf3_arm7 *cpu, unsigned n, int thumb)
{
    if (n == 15) return cpu->r[15] + (thumb ? 4u : 8u);
    return cpu->r[n];
}

/* ---------------------------------------------------------------- flags */

static void set_nz(vf3_arm7 *cpu, uint32_t v)
{
    cpu->cpsr &= ~(FLAG_N | FLAG_Z);
    if (v & 0x80000000u) cpu->cpsr |= FLAG_N;
    if (!v) cpu->cpsr |= FLAG_Z;
}

static void set_nzcv(vf3_arm7 *cpu, uint32_t v, int carry, int overflow)
{
    set_nz(cpu, v);
    cpu->cpsr = (cpu->cpsr & ~(FLAG_C | FLAG_V)) |
                (carry ? FLAG_C : 0) | (overflow ? FLAG_V : 0);
}

static int add_overflow(uint32_t a, uint32_t b, uint32_t result)
{
    return (int)(((a ^ result) & (b ^ result)) >> 31);
}

static int sub_overflow(uint32_t a, uint32_t b, uint32_t result)
{
    return (int)(((a ^ b) & (a ^ result)) >> 31);
}

/* ---------------------------------------------------------------- shifts */

/* `by` is the shift amount.  type 0..3 = LSL, LSR, ASR, ROR.  `by` may be
 * 0..255; a register-specified amount of zero leaves the carry alone. */
static uint32_t shift(vf3_arm7 *cpu, uint32_t value, unsigned type, unsigned by, int *carry)
{
    (void)cpu;
    if (by == 0) return value;              /* register form: no change */
    switch (type) {
    case 0: /* LSL */
        if (by < 32) { *carry = (int)((value >> (32 - by)) & 1u); return value << by; }
        if (by == 32) { *carry = (int)(value & 1u); return 0; }
        *carry = 0;
        return 0;
    case 1: /* LSR */
        if (by < 32) { *carry = (int)((value >> (by - 1)) & 1u); return value >> by; }
        *carry = (int)(value >> 31);
        return 0;
    case 2: /* ASR */
        if (by < 32) {
            *carry = (int)((value >> (by - 1)) & 1u);
            return (uint32_t)((int32_t)value >> by);
        }
        *carry = (int)(value >> 31);
        return (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
    default: /* ROR */
        by &= 31u;
        if (by == 0) { *carry = (int)(value >> 31); return value; }
        *carry = (int)((value >> (by - 1)) & 1u);
        return (value >> by) | (value << (32 - by));
    }
}

/* The immediate-shift form: a zero amount means #32 for LSR/ASR, RRX for
 * ROR, and no shift for LSL. */
static uint32_t shift_imm(vf3_arm7 *cpu, uint32_t value, unsigned type, unsigned by, int *carry)
{
    if (by) return shift(cpu, value, type, by, carry);
    switch (type) {
    case 0: return value;                                             /* LSL #0 */
    case 1: *carry = (int)(value >> 31); return 0;                    /* LSR #32 */
    case 2: *carry = (int)(value >> 31);                              /* ASR #32 */
            return (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
    default: {                                                        /* RRX */
        const uint32_t c = (cpu->cpsr & FLAG_C) ? 0x80000000u : 0u;
        *carry = (int)(value & 1u);
        return (value >> 1) | c;
    }
    }
}

static uint32_t ror32(uint32_t value, unsigned by)
{
    by &= 31u;
    if (!by) return value;
    return (value >> by) | (value << (32 - by));
}

static uint32_t sign_extend(uint32_t value, unsigned bits)
{
    const uint32_t m = 1u << (bits - 1);
    return (value ^ m) - m;
}

/* ---------------------------------------------------------------- exceptions */

static void exception(vf3_arm7 *cpu, uint32_t vector, uint32_t mode,
                      uint32_t return_address, int mask_irq, int mask_fiq)
{
    const uint32_t old = cpu->cpsr;
    const unsigned b = bank_of(mode);
    cpu->bank_spsr[b] = old;
    switch_bank(cpu, old & 0x1Fu, mode);
    cpu->cpsr = (old & ~0x1Fu & ~FLAG_T) | (mode & 0x1Fu) |
                (mask_irq ? FLAG_I : 0) | (mask_fiq ? FLAG_F : 0);
    cpu->r[14] = return_address;
    cpu->r[15] = vector;
    ++cpu->exceptions;
}

/* An exception is taken before the instruction at r15 executes; the handler
 * returns to it with SUBS PC, LR, #4, so LR is that address plus four. */
static int take_exception(vf3_arm7 *cpu)
{
    const uint32_t next = cpu->r[15] + 4u;
    if (cpu->fiq_line && !(cpu->cpsr & FLAG_F)) {
        exception(cpu, 0x1Cu, VF3_ARM_MODE_FIQ, next, 1, 1);
        return 1;
    }
    if (cpu->irq_line && !(cpu->cpsr & FLAG_I)) {
        exception(cpu, 0x18u, VF3_ARM_MODE_IRQ, next, 1, 0);
        return 1;
    }
    return 0;
}

/* Restore CPSR from the active mode's SPSR (an exception return). */
static void restore_spsr(vf3_arm7 *cpu)
{
    const uint32_t old = cpu->cpsr;
    const uint32_t spsr = cpu->bank_spsr[bank_of(old & 0x1Fu)];
    switch_bank(cpu, old & 0x1Fu, spsr & 0x1Fu);
    cpu->cpsr = spsr;
}

/* ---------------------------------------------------------------- ARM */

/* flycast's multiply cost (arm-new.h MUL/MLA/UMULL/UMLAL cases): the tick
 * count is the width of |Rs| in bytes, on a base of 2 for the plain forms and
 * 3 for the accumulate forms.  A negative Rs is *complemented*, not negated -
 * the reference's own rule. */
static uint32_t multiply_ticks(uint32_t rs, uint32_t base)
{
    if ((int32_t)rs < 0) rs = ~rs;
    if ((rs & 0xFFFFFF00u) == 0) return base;
    if ((rs & 0xFFFF0000u) == 0) return base + 1;
    if ((rs & 0xFF000000u) == 0) return base + 2;
    return base + 3;
}

static uint32_t arm_data_processing(vf3_arm7 *cpu, uint32_t insn)
{
    const unsigned opcode = (insn >> 21) & 0xFu;
    const unsigned rn = (insn >> 16) & 0xFu, rd = (insn >> 12) & 0xFu;
    const int set_flags = (insn >> 20) & 1;
    uint32_t op2, result, a, b;
    int carry = (cpu->cpsr & FLAG_C) != 0;

    if (insn & (1u << 25)) {
        unsigned rotate = ((insn >> 8) & 0xFu) * 2u;
        op2 = ror32(insn & 0xFFu, rotate);
        if (rotate) carry = (int)((op2 >> 31) & 1u);
    } else if (insn & (1u << 4)) {
        const unsigned type = (insn >> 5) & 3u;
        const unsigned rs = (insn >> 8) & 0xFu;
        const uint32_t amount = reg_read(cpu, rs, 0) & 0xFFu;
        op2 = shift(cpu, reg_read(cpu, insn & 0xFu, 0), type, amount, &carry);
    } else {
        const unsigned type = (insn >> 5) & 3u;
        const unsigned amount = (insn >> 7) & 0x1Fu;
        op2 = shift_imm(cpu, reg_read(cpu, insn & 0xFu, 0), type, amount, &carry);
    }
    a = reg_read(cpu, rn, 0);
    b = op2;

    switch (opcode) {
    case 0x0: result = a & b; break;                                        /* AND */
    case 0x1: result = a ^ b; break;                                        /* EOR */
    case 0x2: result = a - b; break;                                        /* SUB */
    case 0x3: result = b - a; break;                                        /* RSB */
    case 0x4: result = a + b; break;                                        /* ADD */
    case 0x5: { const uint64_t u = (uint64_t)a + b + ((cpu->cpsr & FLAG_C) ? 1u : 0u);
                result = (uint32_t)u; break; }                                                /* ADC */
    case 0x6: { const uint64_t u = (uint64_t)a - b - ((cpu->cpsr & FLAG_C) ? 0u : 1u);
                result = (uint32_t)u; break; }                                                /* SBC */
    case 0x7: { const uint64_t u = (uint64_t)b - a - ((cpu->cpsr & FLAG_C) ? 0u : 1u);
                result = (uint32_t)u; break; }                                                /* RSC */
    case 0x8: result = a & b; break;                                        /* TST */
    case 0x9: result = a ^ b; break;                                        /* TEQ */
    case 0xA: result = a - b; break;                                        /* CMP */
    case 0xB: result = a + b; break;                                        /* CMN */
    case 0xC: result = a | b; break;                                        /* ORR */
    case 0xD: result = b; break;                                            /* MOV */
    case 0xE: result = a & ~b; break;                                       /* BIC */
    default:  result = ~b; break;                                           /* MVN */
    }

    if (set_flags || opcode >= 0x8) {
        switch (opcode) {
        case 0x2: case 0xA:
            set_nzcv(cpu, result, a >= b, sub_overflow(a, b, result));
            break;
        case 0x3:
            set_nzcv(cpu, result, b >= a, sub_overflow(b, a, result));
            break;
        case 0x4: case 0xB:
            set_nzcv(cpu, result, result < a, add_overflow(a, b, result));
            break;
        case 0x5: {
            const uint64_t u = (uint64_t)a + b + ((carry) ? 1u : 0u);
            set_nzcv(cpu, result, (int)(u >> 32), add_overflow(a, b, result));
            break;
        }
        case 0x6: {
            const uint64_t u = (uint64_t)a - b - (carry ? 0u : 1u);
            set_nzcv(cpu, result, (int)((u >> 32) == 0), sub_overflow(a, b, result));
            break;
        }
        case 0x7: {
            const uint64_t u = (uint64_t)b - a - (carry ? 0u : 1u);
            set_nzcv(cpu, result, (int)((u >> 32) == 0), sub_overflow(b, a, result));
            break;
        }
        default:
            set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0);
            break;
        }
    }

    if (rd == 15) {
        if (set_flags) restore_spsr(cpu);
        cpu->r[15] = (cpu->cpsr & FLAG_T) ? (result & ~1u) : (result & ~3u);
        /* flycast bills +1 only for the exception-return form (`movs pc,lr`),
         * not for every write to the PC (arm-new.h lines 1296-1302). */
        return set_flags ? 1u : 0u;
    }
    if (opcode < 0x8 || opcode >= 0xC) cpu->r[rd] = result;
    cpu->r[15] += 4;
    return 0;
}

static uint32_t arm_multiply(vf3_arm7 *cpu, uint32_t insn)
{
    const unsigned rd = (insn >> 16) & 0xFu, rn = (insn >> 12) & 0xFu;
    const unsigned rs = (insn >> 8) & 0xFu, rm = insn & 0xFu;
    /* Timing depends on the source value before the instruction writes its
     * destination; Rd and Rs are allowed to alias in the short multiply form. */
    const uint32_t rs_value = cpu->r[rs];

    if (!(insn & (1u << 23))) {
        uint32_t product = cpu->r[rm] * cpu->r[rs];
        uint32_t result;
        if (insn & (1u << 21)) product += cpu->r[rn];   /* MLA */
        result = product;
        cpu->r[rd] = result;
        if (insn & (1u << 20)) set_nz(cpu, result);
        cpu->r[15] += 4;
        return multiply_ticks(rs_value, (insn & (1u << 21)) ? 3u : 2u);
    } else {
        const int is_signed = (insn & (1u << 22)) != 0;
        const int accumulate = (insn & (1u << 21)) != 0;
        uint64_t product;
        if (is_signed)
            product = (uint64_t)((int64_t)(int32_t)cpu->r[rm] * (int64_t)(int32_t)cpu->r[rs]);
        else
            product = (uint64_t)cpu->r[rm] * (uint64_t)cpu->r[rs];
        if (accumulate) product += ((uint64_t)cpu->r[rd] << 32) | cpu->r[rn];
        cpu->r[rn] = (uint32_t)product;
        cpu->r[rd] = (uint32_t)(product >> 32);
        if (insn & (1u << 20)) {
            set_nz(cpu, cpu->r[rd]);
            cpu->cpsr &= ~(FLAG_C | FLAG_V);
        }
        cpu->r[15] += 4;
        return multiply_ticks(rs_value, accumulate ? 3u : 2u);
    }
}

static uint32_t arm_halfword(vf3_arm7 *cpu, uint32_t insn)
{
    const int pre = (insn >> 24) & 1, up = (insn >> 23) & 1;
    const int imm = (insn >> 22) & 1, wb = (insn >> 21) & 1, load = (insn >> 20) & 1;
    const unsigned rn = (insn >> 16) & 0xFu, rd = (insn >> 12) & 0xFu;
    const unsigned kind = (insn >> 5) & 3u;
    uint32_t offset, address, base;

    if (imm) offset = (((insn >> 8) & 0xFu) << 4) | (insn & 0xFu);
    else offset = reg_read(cpu, insn & 0xFu, 0);
    base = reg_read(cpu, rn, 0);
    address = pre ? (up ? base + offset : base - offset) : base;
    if (load) {
        uint32_t value;
        switch (kind) {
        case 1: value = bus_read(cpu, address, 2); break;                              /* LDRH */
        case 2: value = (uint32_t)(int32_t)(int8_t)bus_read(cpu, address, 1); break;   /* LDRSB */
        default: value = (uint32_t)(int32_t)(int16_t)bus_read(cpu, address, 2); break; /* LDRSH */
        }
        if (rd == 15) cpu->r[15] = (cpu->cpsr & FLAG_T) ? (value & ~1u) : (value & ~3u);
        else cpu->r[rd] = value;
    } else {
        bus_write(cpu, address, kind == 1 ? (cpu->r[rd] & 0xFFFFu) : cpu->r[rd], kind == 1 ? 2 : 4);
    }
    if (wb || !pre) cpu->r[rn] = up ? base + offset : base - offset;
    if (rd != 15 || load) cpu->r[15] += 4;
    /* flycast: LDRH/LDRSB/LDRSH +4, STRH +5 (arm-new.h halfword cases). */
    return load ? 4u : 5u;
}

static uint32_t arm_block_transfer(vf3_arm7 *cpu, uint32_t insn)
{
    const int pre = (insn >> 24) & 1, up = (insn >> 23) & 1;
    const int user = (insn >> 22) & 1;
    const int writeback = (insn >> 21) & 1, load = (insn >> 20) & 1;
    const unsigned rn = (insn >> 16) & 0xFu;
    uint32_t base = cpu->r[rn], address;
    unsigned i, count = 0;
    int pc_in_list = 0;

    for (i = 0; i < 16; ++i) if (insn & (1u << i)) ++count;
    if (!count) { cpu->r[15] += 4; return 2; }

    if (up) address = base + (pre ? 4u : 0u);
    else address = base - count * 4u + (pre ? 0u : 4u);

    for (i = 0; i < 16; ++i) {
        if (!(insn & (1u << i))) continue;
        if (load) {
            uint32_t value = bus_read(cpu, address, 4);
            if (i == 15) { pc_in_list = 1; cpu->r[15] = value & ~3u; }
            else cpu->r[i] = value;
        } else {
            /* An STM that stores the PC stores pc+12 on the ARM7TDMI (the
             * pipeline's +8 plus the block transfer's own +4), which is what
             * the firmware's `stmdb sp!,{pc}` call idiom depends on. */
            bus_write(cpu, address, i == 15 ? cpu->r[15] + 12u : cpu->r[i], 4);
        }
        address += 4;
    }
    if (writeback) cpu->r[rn] = up ? base + count * 4u : base - count * 4u;
    if (pc_in_list && user) {
        restore_spsr(cpu);
        if (cpu->cpsr & FLAG_T) cpu->r[15] &= ~1u; else cpu->r[15] &= ~3u;
    } else if (!pc_in_list) {
        cpu->r[15] += 4;
    }
    /* flycast's interpreter bills a block transfer as 2 at the top plus
     * `1 + CPUUpdateTicksAccess{Seq,}32` per register (both macros are 1), so
     * 2 + 2n either way; a loaded PC costs one more (its case adds 2 + 1). */
    if (load) return 2u + 2u * count + (pc_in_list ? 1u : 0u);
    return 2u + 2u * count;
}

static uint32_t arm_single_transfer(vf3_arm7 *cpu, uint32_t insn)
{
    /* In this class I=0 is the immediate offset and I=1 the register one. */
    const int imm_offset = !((insn >> 25) & 1);
    const int pre = (insn >> 24) & 1, up = (insn >> 23) & 1;
    const int byte = (insn >> 22) & 1, writeback = (insn >> 21) & 1, load = (insn >> 20) & 1;
    const unsigned rn = (insn >> 16) & 0xFu, rd = (insn >> 12) & 0xFu;
    uint32_t offset, address, base;

    if (imm_offset) offset = insn & 0xFFFu;
    else {
        int carry = (cpu->cpsr & FLAG_C) != 0;
        offset = shift_imm(cpu, reg_read(cpu, insn & 0xFu, 0), (insn >> 5) & 3u,
                           (insn >> 7) & 0x1Fu, &carry);
    }
    base = reg_read(cpu, rn, 0);
    address = pre ? (up ? base + offset : base - offset) : base;
    if (load) {
        uint32_t value = byte ? bus_read(cpu, address, 1) : bus_read(cpu, address, 4);
        if (rd == 15) cpu->r[15] = value & ~3u;
        else cpu->r[rd] = value;
    } else {
        bus_write(cpu, address, byte ? (reg_read(cpu, rd, 0) & 0xFFu) : reg_read(cpu, rd, 0),
                  byte ? 1 : 4);
    }
    if (!pre) {
        address = up ? address + offset : address - offset;
    }
    if ((!pre || writeback) && rn != 15 && !(load && rd == 15))
        cpu->r[rn] = address;
    if (rd != 15) cpu->r[15] += 4;
    /* flycast: LDR word +4 (+2 more when it writes the PC), LDRB +4,
     * STR word +3, STRB +3 (arm-new.h single-transfer cases). */
    if (!load) return 3u;
    if (byte) return 4u;
    return rd == 15 ? 6u : 4u;
}

static uint32_t arm_psr_transfer(vf3_arm7 *cpu, uint32_t insn)
{
    const int spsr = (insn >> 22) & 1;
    uint32_t mask = 0;

    if (!(insn & (1u << 25)) && (insn & (1u << 24)) && !(insn & (1u << 21))) {
        /* MRS */
        const unsigned rd = (insn >> 12) & 0xFu;
        uint32_t value;
        if (spsr) value = cpu->bank_spsr[bank_of(cpu->cpsr & 0x1Fu)];
        else value = cpu->cpsr;
        cpu->r[rd] = value;
        cpu->r[15] += 4;
        return 0;
    }

    if (insn & (1u << 19)) mask |= 0xFF000000u;
    if (insn & (1u << 18)) mask |= 0x00FF0000u;
    if (insn & (1u << 17)) mask |= 0x0000FF00u;
    if (insn & (1u << 16)) mask |= 0x000000FFu;
    {
        uint32_t value;
        if (insn & (1u << 25))
            value = ror32(insn & 0xFFu, ((insn >> 8) & 0xFu) * 2u);
        else
            value = cpu->r[insn & 0xFu];
        if (spsr) {
            uint32_t *p = &cpu->bank_spsr[bank_of(cpu->cpsr & 0x1Fu)];
            *p = (*p & ~mask) | (value & mask);
        } else {
            uint32_t old = cpu->cpsr;
            uint32_t newv;
            if ((old & 0x1Fu) == VF3_ARM_MODE_USR) mask &= 0xF0000000u;
            newv = (old & ~mask) | (value & mask);
            if ((newv & 0x1Fu) != (old & 0x1Fu))
                switch_bank(cpu, old & 0x1Fu, newv & 0x1Fu);
            cpu->cpsr = newv;
        }
    }
    cpu->r[15] += 4;
    return 0;
}

static uint32_t arm_swap(vf3_arm7 *cpu, uint32_t insn)
{
    const unsigned rn = (insn >> 16) & 0xFu, rd = (insn >> 12) & 0xFu, rm = insn & 0xFu;
    const int byte = (insn >> 22) & 1;
    const uint32_t address = cpu->r[rn];
    const uint32_t value = byte ? bus_read(cpu, address, 1) : bus_read(cpu, address, 4);
    bus_write(cpu, address, cpu->r[rm], byte ? 1 : 4);
    cpu->r[rd] = value;
    cpu->r[15] += 4;
    /* flycast's SWP case adds no tick at all (arm-new.h line 2286). */
    return 0;
}

static int condition_passed(const vf3_arm7 *cpu, unsigned cond)
{
    const int n = (cpu->cpsr & FLAG_N) != 0, z = (cpu->cpsr & FLAG_Z) != 0;
    const int c = (cpu->cpsr & FLAG_C) != 0, v = (cpu->cpsr & FLAG_V) != 0;
    switch (cond) {
    case 0x0: return z;
    case 0x1: return !z;
    case 0x2: return c;
    case 0x3: return !c;
    case 0x4: return n;
    case 0x5: return !n;
    case 0x6: return v;
    case 0x7: return !v;
    case 0x8: return c && !z;
    case 0x9: return !c || z;
    case 0xA: return n == v;
    case 0xB: return n != v;
    case 0xC: return !z && n == v;
    case 0xD: return z || n != v;
    case 0xE: return 1;
    default: return 0;              /* 0xF is the unconditional space */
    }
}

static uint32_t arm_branch(vf3_arm7 *cpu, uint32_t insn, uint32_t pc)
{
    const int link = (insn >> 24) & 1;
    const int32_t offset = (int32_t)(insn << 8) >> 6;
    if (link) cpu->r[14] = pc + 4;
    cpu->r[15] = pc + 8 + (uint32_t)offset;
    return 3;
}

static uint32_t arm_execute(vf3_arm7 *cpu, uint32_t insn)
{
    const uint32_t pc = cpu->r[15];
    const unsigned cond = insn >> 28;
    const unsigned cls = (insn >> 25) & 7u;

    if (cond == 0xF) {
        /* SWI and the coprocessor space (the AICA has no coprocessor). */
        if (insn & (1u << 24)) {
            exception(cpu, 0x08u, VF3_ARM_MODE_SVC, pc + 4, 1, 0);
            return 3;
        }
        cpu->r[15] = pc + 4;
        return 0;
    }
    if (!condition_passed(cpu, cond)) { cpu->r[15] = pc + 4; return 0; }

    switch (cls) {
    case 0:
        if ((insn & 0x0FC000F0u) == 0x00000090u) return arm_multiply(cpu, insn);
        if ((insn & 0x0FB00FF0u) == 0x01000090u) return arm_swap(cpu, insn);
        if ((insn & 0x0E000090u) == 0x00000090u) return arm_halfword(cpu, insn);
        if ((insn & 0x0FFFFFF0u) == 0x012FFF10u) {          /* BX */
            const uint32_t target = cpu->r[insn & 0xFu];
            if (target & 1u) cpu->cpsr |= FLAG_T; else cpu->cpsr &= ~FLAG_T;
            cpu->r[15] = target & ~1u;
            return 3;
        }
        if ((insn & 0x0FBF0FFFu) == 0x010F0000u ||
            (insn & 0x0FBF0FFFu) == 0x014F0000u) return arm_psr_transfer(cpu, insn);
        if ((insn & 0x0FB0FFF0u) == 0x0120F000u ||
            (insn & 0x0FB0FFF0u) == 0x0160F000u) return arm_psr_transfer(cpu, insn);
        return arm_data_processing(cpu, insn);
    case 1:
        if ((insn & 0x0FB0FFF0u) == 0x0320F000u ||
            (insn & 0x0FB0FFF0u) == 0x0360F000u) return arm_psr_transfer(cpu, insn);
        return arm_data_processing(cpu, insn);
    case 2:
        return arm_single_transfer(cpu, insn);
    case 3:
        if (insn & (1u << 4)) { cpu->r[15] = pc + 4; return 0; }  /* media space, unused */
        return arm_single_transfer(cpu, insn);
    case 4:
        return arm_block_transfer(cpu, insn);
    case 5:
        return arm_branch(cpu, insn, pc);
    default:
        cpu->r[15] = pc + 4;
        return 0;
    }
}

/* ---------------------------------------------------------------- Thumb */

static uint32_t thumb_alu(vf3_arm7 *cpu, uint32_t insn)
{
    const unsigned op = (insn >> 6) & 0xFu;
    const unsigned rd = insn & 7u, rs = (insn >> 3) & 7u;
    const uint32_t a = cpu->r[rd], b = cpu->r[rs];
    int carry = (cpu->cpsr & FLAG_C) != 0;
    uint32_t result = a;

    switch (op) {
    case 0x0: result = a & b; set_nz(cpu, result); cpu->r[rd] = result; break;
    case 0x1: result = a ^ b; set_nz(cpu, result); cpu->r[rd] = result; break;
    case 0x2: result = shift(cpu, a, 0, b & 0xFFu, &carry);
              set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0); cpu->r[rd] = result; break;
    case 0x3: result = shift(cpu, a, 1, b & 0xFFu, &carry);
              set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0); cpu->r[rd] = result; break;
    case 0x4: result = shift(cpu, a, 2, b & 0xFFu, &carry);
              set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0); cpu->r[rd] = result; break;
    case 0x5: { const uint32_t c = (cpu->cpsr & FLAG_C) ? 1u : 0u;
                const uint32_t sum = a + b + c;
                result = sum;
                set_nzcv(cpu, result, result < a || (result == a && b != 0),
                         add_overflow(a, b, result));
                cpu->r[rd] = result; break; }
    case 0x6: { const uint32_t c = (cpu->cpsr & FLAG_C) ? 0u : 1u;
                const uint32_t sum = a - b - c;
                result = sum;
                set_nzcv(cpu, result, a >= b + c, sub_overflow(a, b, sum));
                cpu->r[rd] = result; break; }
    case 0x7: result = shift(cpu, a, 3, b & 0xFFu, &carry);
              set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0); cpu->r[rd] = result; break;
    case 0x8: set_nz(cpu, a & b); break;                                  /* TST */
    case 0x9: result = (uint32_t)(-(int32_t)b);                            /* NEG */
              set_nzcv(cpu, result, b == 0, sub_overflow(0, b, result));
              cpu->r[rd] = result; break;
    case 0xA: result = a - b;                                              /* CMP */
              set_nzcv(cpu, result, a >= b, sub_overflow(a, b, result)); break;
    case 0xB: result = a + b;                                              /* CMN */
              set_nzcv(cpu, result, result < a, add_overflow(a, b, result)); break;
    case 0xC: result = a | b; set_nz(cpu, result); cpu->r[rd] = result; break;
    case 0xD: result = a * b; set_nz(cpu, result); cpu->r[rd] = result; break;
    case 0xE: result = a & ~b; set_nz(cpu, result); cpu->r[rd] = result; break;
    default:  result = ~b; set_nz(cpu, result); cpu->r[rd] = result; break;
    }
    cpu->r[15] += 2;
    return 1;
}

/* The high-register operations and BX (010001). */
static uint32_t thumb_high(vf3_arm7 *cpu, uint32_t insn)
{
    const unsigned op = (insn >> 8) & 3u;
    const unsigned rd = (insn & 7u) | ((insn >> 4) & 8u);
    const unsigned rs = (insn >> 3) & 0xFu;
    const uint32_t a = reg_read(cpu, rd, 1), b = reg_read(cpu, rs, 1);

    switch (op) {
    case 0: {   /* ADD */
        const uint32_t result = a + b;
        if (rd == 15) cpu->r[15] = result & ~1u;
        else cpu->r[rd] = result;
        break;
    }
    case 1: {   /* CMP */
        const uint32_t result = a - b;
        set_nzcv(cpu, result, a >= b, sub_overflow(a, b, result));
        break;
    }
    case 2:     /* MOV */
        if (rd == 15) cpu->r[15] = b & ~1u;
        else cpu->r[rd] = b;
        break;
    default: {  /* BX / BLX */
        const uint32_t target = b;
        if (target & 1u) cpu->cpsr |= FLAG_T; else cpu->cpsr &= ~FLAG_T;
        if (insn & (1u << 7)) cpu->r[14] = (cpu->r[15] + 2u) | 1u;   /* BLX */
        cpu->r[15] = target & ~1u;
        return 3;
    }
    }
    cpu->r[15] += 2;
    return 1;
}

static uint32_t thumb_load_store(vf3_arm7 *cpu, uint32_t insn)
{
    const uint32_t pc = cpu->r[15];
    const unsigned rd = insn & 7u, base = (insn >> 3) & 7u;

    if ((insn & 0xF000u) == 0x5000u) {          /* register offset */
        const unsigned op = (insn >> 9) & 7u;
        const uint32_t address = cpu->r[base] + cpu->r[(insn >> 6) & 7u];
        switch (op) {
        case 0: bus_write(cpu, address, cpu->r[rd], 4); break;                              /* STR */
        case 1: bus_write(cpu, address, cpu->r[rd] & 0xFFFFu, 2); break;                    /* STRH */
        case 2: bus_write(cpu, address, cpu->r[rd] & 0xFFu, 1); break;                      /* STRB */
        case 3: cpu->r[rd] = (uint32_t)(int32_t)(int8_t)bus_read(cpu, address, 1); break;    /* LDRSB */
        case 4: cpu->r[rd] = bus_read(cpu, address, 4); break;                              /* LDR */
        case 5: cpu->r[rd] = bus_read(cpu, address, 2); break;                              /* LDRH */
        case 6: cpu->r[rd] = bus_read(cpu, address, 1); break;                              /* LDRB */
        default: cpu->r[rd] = (uint32_t)(int32_t)(int16_t)bus_read(cpu, address, 2); break; /* LDRSH */
        }
        cpu->r[15] += 2;
        return 2;
    }
    if ((insn & 0xE000u) == 0x6000u) {          /* word/byte immediate */
        const int byte = (insn >> 12) & 1, load = (insn >> 11) & 1;
        const uint32_t address = cpu->r[base] + ((insn >> 6) & 0x1Fu);
        if (load) cpu->r[rd] = byte ? bus_read(cpu, address, 1) : bus_read(cpu, address, 4);
        else bus_write(cpu, address, byte ? (cpu->r[rd] & 0xFFu) : cpu->r[rd], byte ? 1 : 4);
        cpu->r[15] += 2;
        return 2;
    }
    if ((insn & 0xE000u) == 0x8000u) {          /* halfword immediate / SP-relative */
        if (insn & 0x1000u) {
            const unsigned rd2 = (insn >> 8) & 7u;
            const uint32_t address = cpu->r[13] + ((insn & 0xFFu) << 2);
            if (insn & 0x0800u) cpu->r[rd2] = bus_read(cpu, address, 4);
            else bus_write(cpu, address, cpu->r[rd2], 4);
        } else {
            const uint32_t address = cpu->r[base] + (((insn >> 6) & 0x1Fu) << 1);
            if (insn & 0x0800u) cpu->r[rd] = bus_read(cpu, address, 2);
            else bus_write(cpu, address, cpu->r[rd] & 0xFFFFu, 2);
        }
        cpu->r[15] += 2;
        return 2;
    }
    if ((insn & 0xF800u) == 0x4800u) {          /* LDR Rd,[PC,#imm8*4] */
        const uint32_t address = ((pc + 4u) & ~3u) + ((insn & 0xFFu) << 2);
        cpu->r[(insn >> 8) & 7u] = bus_read(cpu, address, 4);
        cpu->r[15] += 2;
        return 2;
    }
    cpu->r[15] += 2;
    return 1;
}

static uint32_t thumb_execute(vf3_arm7 *cpu, uint32_t insn)
{
    const uint32_t pc = cpu->r[15];

    if ((insn & 0xE000u) == 0x0000u) {                  /* 000 */
        if ((insn & 0x1800u) == 0x1800u) {              /* ADD/SUB */
            const unsigned rd = insn & 7u, rs = (insn >> 3) & 7u;
            const uint32_t b = cpu->r[rs];
            const uint32_t operand = (insn & 0x0400u) ? ((insn >> 6) & 7u) : cpu->r[(insn >> 6) & 7u];
            uint32_t result;
            if (insn & 0x0200u) {
                result = b - operand;
                cpu->r[rd] = result;
                set_nzcv(cpu, result, b >= operand, sub_overflow(b, operand, result));
            } else {
                result = b + operand;
                cpu->r[rd] = result;
                set_nzcv(cpu, result, result < b, add_overflow(b, operand, result));
            }
        } else {
            const unsigned type = (insn >> 11) & 3u;
            const unsigned amount = (insn >> 6) & 0x1Fu;
            const unsigned rd = insn & 7u, rs = (insn >> 3) & 7u;
            int carry = (cpu->cpsr & FLAG_C) != 0;
            const uint32_t result = shift_imm(cpu, cpu->r[rs], type, amount, &carry);
            cpu->r[rd] = result;
            set_nzcv(cpu, result, carry, (cpu->cpsr & FLAG_V) != 0);
        }
        cpu->r[15] += 2;
        return 1;
    }
    if ((insn & 0xE000u) == 0x2000u) {                  /* 001: MOV/CMP/ADD/SUB imm8 */
        const unsigned op = (insn >> 11) & 3u, rd = (insn >> 8) & 7u;
        const uint32_t imm = insn & 0xFFu, a = cpu->r[rd];
        switch (op) {
        case 0: cpu->r[rd] = imm; set_nz(cpu, imm); break;
        case 1: { const uint32_t r = a - imm; set_nzcv(cpu, r, a >= imm, sub_overflow(a, imm, r)); break; }
        case 2: { const uint32_t r = a + imm; cpu->r[rd] = r; set_nzcv(cpu, r, r < a, add_overflow(a, imm, r)); break; }
        default: { const uint32_t r = a - imm; cpu->r[rd] = r; set_nzcv(cpu, r, a >= imm, sub_overflow(a, imm, r)); break; }
        }
        cpu->r[15] += 2;
        return 1;
    }
    if ((insn & 0xE000u) == 0x4000u) {                  /* 010 */
        if (insn & 0x0400u) return thumb_high(cpu, insn);
        return thumb_alu(cpu, insn);
    }
    if ((insn & 0xE000u) == 0x6000u) {                  /* 011 */
        return thumb_load_store(cpu, insn);
    }
    if ((insn & 0xE000u) == 0x8000u) {                  /* 100 */
        return thumb_load_store(cpu, insn);
    }
    if ((insn & 0xF000u) == 0xA000u) {                  /* 1010: ADD rd,pc/sp */
        const uint32_t base = (insn & 0x0800u) ? cpu->r[13] : ((pc + 4u) & ~3u);
        cpu->r[(insn >> 8) & 7u] = base + ((insn & 0xFFu) << 2);
        cpu->r[15] += 2;
        return 1;
    }
    if ((insn & 0xF000u) == 0xB000u) {                  /* 1011 */
        if ((insn & 0x0600u) == 0x0000u) {              /* ADD/SUB SP */
            const int sub = (insn & 0x0080u) != 0;
            const uint32_t imm = (insn & 0x7Fu) << 2;
            cpu->r[13] = sub ? cpu->r[13] - imm : cpu->r[13] + imm;
            cpu->r[15] += 2;
            return 1;
        }
        if ((insn & 0x0600u) == 0x0400u) {              /* PUSH */
            const uint32_t list = (insn & 0xFFu) | ((insn & 0x0100u) ? 0x4000u : 0u);
            unsigned i, count = 0;
            uint32_t address;
            for (i = 0; i < 16; ++i) if (list & (1u << i)) ++count;
            address = cpu->r[13] - count * 4u;
            cpu->r[13] = address;
            for (i = 0; i < 16; ++i) {
                if (!(list & (1u << i))) continue;
                bus_write(cpu, address, cpu->r[i], 4);
                address += 4;
            }
            cpu->r[15] += 2;
            return 2 + count;
        }
        {                                               /* POP */
            const uint32_t list = (insn & 0xFFu) | ((insn & 0x0100u) ? 0x8000u : 0u);
            uint32_t address = cpu->r[13];
            unsigned i;
            for (i = 0; i < 16; ++i) {
                if (!(list & (1u << i))) continue;
                if (i == 15) cpu->r[15] = bus_read(cpu, address, 4) & ~1u;
                else cpu->r[i] = bus_read(cpu, address, 4);
                address += 4;
            }
            cpu->r[13] = address;
            if (!(list & 0x8000u)) cpu->r[15] += 2;
            return 2;
        }
    }
    if ((insn & 0xF000u) == 0xC000u) {                  /* STMIA/LDMIA */
        const unsigned rd = (insn >> 8) & 7u;
        const int load = (insn & 0x0800u) != 0;
        const uint32_t list = insn & 0xFFu;
        uint32_t address = cpu->r[rd];
        unsigned i, count = 0;
        for (i = 0; i < 8; ++i) if (list & (1u << i)) ++count;
        if (!count) { cpu->r[15] += 2; return 1; }
        for (i = 0; i < 8; ++i) {
            if (!(list & (1u << i))) continue;
            if (load) cpu->r[i] = bus_read(cpu, address, 4);
            else bus_write(cpu, address, cpu->r[i], 4);
            address += 4;
        }
        cpu->r[rd] = address;
        cpu->r[15] += 2;
        return 2 + count;
    }
    /* 111 */
    if ((insn & 0xF000u) == 0xD000u) {
        const unsigned cond = (insn >> 8) & 0xFu;
        if (cond == 0xFu) {                              /* SWI */
            exception(cpu, 0x08u, VF3_ARM_MODE_SVC, pc + 2, 1, 0);
            return 2;
        }
        if (cond < 0xE && condition_passed(cpu, cond)) {
            const uint32_t offset = sign_extend(insn & 0xFFu, 8) << 1;
            cpu->r[15] = pc + 4 + offset;
        } else {
            cpu->r[15] = pc + 2;
        }
        return 1;
    }
    if ((insn & 0xF800u) == 0xE000u) {                  /* unconditional B */
        const uint32_t offset = sign_extend(insn & 0x7FFu, 11) << 1;
        cpu->r[15] = pc + 4 + offset;
        return 1;
    }
    if ((insn & 0xF800u) == 0xF000u) {                  /* BL first half */
        const uint32_t offset = sign_extend(insn & 0x7FFu, 11) << 12;
        cpu->r[14] = pc + 4 + offset;
        cpu->r[15] = pc + 2;
        return 1;
    }
    if ((insn & 0xF800u) == 0xF800u) {                  /* BL second half */
        const uint32_t target = cpu->r[14] + ((insn & 0x7FFu) << 1);
        cpu->r[14] = (pc + 2) | 1u;
        cpu->r[15] = target & ~1u;
        return 3;
    }
    cpu->r[15] += 2;
    return 1;
}

/* ------------------------------------------------- flycast's ARM7 dynarec --
 *
 * The reference's AICA ARM7 is not the arm-new.h interpreter.  The x64 build
 * compiles the firmware with the recompiler (core/build.h leaves FEAT_AREC at
 * DYNAREC_JIT, and tools/oracle/vf3armtrace.h records that "PC is assigned by
 * the x64 ARM compiler"), and its time model differs from the interpreter's
 * in three ways that matter to the audio:
 *
 *   - a block is charged once, when it is dispatched, with the sum of the
 *     *decoded* cost of the opcodes it fetched (arm7_rec.cpp compile():
 *     `cycles += last_op.cycles`, then arm7_rec_x64.cpp compile():
 *     `sub [CYCL_CNT], cycles`), and the timeslice and the FIQ are checked
 *     only at a block dispatch (arm7_rec_x64.cpp arm_dispatch);
 *   - an opcode's decoded cost is static: a condition-failed instruction
 *     still pays its class cost (a not-taken conditional branch costs 9, not
 *     6), and a single-register LDM/STM is rewritten to one LDR/STR and pays
 *     that rewrite's cost plus four;
 *   - the opcodes the recompiler cannot compile (MUL/MLA/SWP, BX, a
 *     multi-register LDM/STM, the conditional or flag-setting write of the
 *     PC, the coprocessor/SWI row) contribute nothing to the block and are
 *     billed by interpret() (arm-new.h) when they run.
 *
 * dynarec_op_cost() is decodeArmOp()'s `cycles` plus the two flags the block
 * builder acts on; dynarec_nop() is compile()'s NOP skip (a NOP still costs 6
 * and still counts toward the 32-opcode block limit).
 */

static int dynarec_nop(uint32_t insn)
{
    return insn == 0u || insn == 0x41474553u;
}

static uint32_t dynarec_op_cost(uint32_t insn, int *fallback, int *sets_pc)
{
    const unsigned cond = insn >> 28;
    const unsigned group = (insn >> 26) & 3u;
    const unsigned op_type = (insn >> 21) & 0xFu;
    const unsigned rd = (insn >> 12) & 0xFu;
    const unsigned rn = (insn >> 16) & 0xFu;
    const unsigned imm_op = (insn >> 25) & 1u;
    const unsigned shift_imm = (insn >> 7) & 0x1Fu;
    const unsigned shift_type = (insn >> 5) & 3u;
    const unsigned set_flags = (insn >> 20) & 1u;
    const int is_compare = op_type >= 8u && op_type <= 11u;
    uint32_t cycles = 6u;

    *fallback = 0;
    *sets_pc = 0;
    if (cond == 0xFu) {                 /* NV: the interpreter owns it */
        *fallback = 1;
        return 0u;
    }

    switch (group) {
    case 0:                             /* data processing, multiply, swap */
        if ((insn & 0x0FFFFFF0u) == 0x012FFF10u) {
            *fallback = 1;              /* BX is handled by the interpreter */
            *sets_pc = 1;
            return 0u;
        }
        if ((op_type & 4u) == 0u && imm_op == 0u &&
            (insn & (1u << 4)) != 0u && (insn & (1u << 7)) != 0u) {
            *fallback = 1;              /* MUL, MLA, and SWP */
            return 0u;
        }
        if (is_compare && set_flags == 0u) {
            /* MSR / MRS: the register form of MSR pays one extra tick */
            if ((insn & 0x0FBF0FFFu) == 0x010F0000u) return 6u;   /* MRS */
            if ((insn & 0x0FB0FFF0u) == 0x0120F000u) return 7u;   /* MSR reg */
            return 6u;                                            /* MSR imm */
        }
        if (imm_op == 0u && (insn & (1u << 4)) != 0u) cycles += 1u;
        if (rd == 15u && !is_compare) {
            const int plain_reg = imm_op == 0u &&
                                  (insn & (1u << 4)) == 0u &&
                                  shift_type == 0u && shift_imm == 0u;
            if (op_type == 0xDu && plain_reg && set_flags == 0u) {
                cycles += 3u;           /* MOV pc, rn -> B */
                *sets_pc = 1;
            } else if (cond != 0xEu || set_flags) {
                *fallback = 1;          /* conditional/flag-setting PC write */
                return 0u;
            } else {
                cycles += 1u;
                *sets_pc = 1;
            }
        }
        return cycles;

    case 1: {                           /* LDR / STR */
        const unsigned pre = (insn >> 24) & 1u;
        const unsigned wb = (insn >> 21) & 1u;
        const unsigned load = (insn >> 20) & 1u;
        const unsigned imm12 = insn & 0xFFFu;
        const unsigned write_back =
            (wb || !pre) && rd != rn && (imm_op != 0u || imm12 != 0u);
        if (load) {
            if (rd == 15u) {
                *sets_pc = 1;
                if (cond != 0xEu) {
                    *fallback = 1;
                    return 0u;
                }
                cycles += 1u;
            }
            cycles += 4u;
        } else {
            cycles += 3u;
        }
        if (rn == 15u && write_back) {
            *fallback = 1;
            *sets_pc = 1;
            return 0u;
        }
        if (imm_op && (insn & 0xFu) == 15u) {
            *fallback = 1;
            return 0u;
        }
        return cycles;
    }

    case 2:                             /* LDM/STM, B/BL */
        if (imm_op) {
            *sets_pc = 1;
            return 9u;                  /* B / BL: base 6 + 3 */
        }
        {
            const uint32_t list = insn & 0xFFFFu;
            unsigned count = 0, first = 0, i;
            for (i = 0; i < 16u; ++i)
                if (list & (1u << i)) { ++count; first = i; }
            if (!(insn & (1u << 22)) && count == 1u) {
                /* compile()'s rewrite: one LDR/STR, immediate offset 4, and
                 * the rewrite's own cost plus four */
                const unsigned pre = (insn >> 24) & 1u;
                const unsigned up = (insn >> 23) & 1u;
                const unsigned wb = (insn >> 21) & 1u;
                const unsigned load = (insn >> 20) & 1u;
                const uint32_t rewrite =
                    0x04000000u | (insn & 0xF0000000u) |
                    (pre << 24) | (up << 23) | ((wb & pre) << 21) |
                    (load << 20) | (rn << 16) | (first << 12) | 4u;
                int inner_fb = 0, inner_pc = 0;
                const uint32_t inner =
                    dynarec_op_cost(rewrite, &inner_fb, &inner_pc);
                if (inner_fb) *fallback = 1;
                if (inner_pc) *sets_pc = 1;
                return inner + 4u;
            }
            *fallback = 1;              /* interpret() bills it at runtime */
            if ((list & 0x8000u) && (insn & (1u << 20))) *sets_pc = 1;
            return 0u;
        }

    default:                            /* coprocessor / SWI */
        *fallback = 1;
        if (imm_op && (op_type & 8u)) *sets_pc = 1;
        return 0u;
    }
}

/* ---------------------------------------------------------------- API */

void vf3_arm7_init(vf3_arm7 *cpu, const vf3_arm7_bus *bus)
{
    memset(cpu, 0, sizeof *cpu);
    if (bus) cpu->bus = *bus;
    vf3_arm7_reset(cpu);
}

void vf3_arm7_reset(vf3_arm7 *cpu)
{
    const vf3_arm7_bus bus = cpu->bus;
    memset(cpu, 0, sizeof *cpu);
    cpu->bus = bus;
    cpu->cpsr = VF3_ARM_MODE_SVC | FLAG_I | FLAG_F;
    cpu->r[15] = 0;
    cpu->arm7_clock_ticks = 0;
}

/* Fetch and retire one instruction, without the base tick.  The caller adds
 * VF3_ARM7_BASE_CYCLES when it bills the interpreter's per-instruction model
 * (vf3_arm7_step) and lets the dynarec's own static cost stand in for it
 * otherwise (vf3_arm7_run); the class charge this returns is what a fallback
 * opcode hands to interpret() on top of the base. */
static uint32_t arm7_execute_fetched(vf3_arm7 *cpu, uint32_t insn)
{
    uint32_t spent;

    seq_maybe_open(cpu->instructions);
    if (g_seq_armed && cpu->instructions >= g_seq_lo &&
        cpu->instructions <= g_seq_hi) {
        uint32_t p = cpu->r[15];
        fwrite(&p, 4, 1, g_seq);
    }

    cpu->last_pc = cpu->r[15];
    cpu->last_insn = insn;
    cpu->trace_pc[cpu->trace_at++ & 63u] = cpu->r[15];
    if (cpu->r[15] < 0x10000u) {
        ++g_pc_hist[cpu->r[15] >> 2];
        ++g_tot[cpu->r[15] >> 2];
    }

    if (cpu->cpsr & FLAG_T) spent = thumb_execute(cpu, insn);
    else spent = arm_execute(cpu, insn);

    ++cpu->instructions;
    return spent;
}

uint32_t vf3_arm7_step(vf3_arm7 *cpu)
{
    uint32_t spent;

    if (take_exception(cpu)) {
        /* flycast's CPUFiq() (arm7.cpp line 323) switches mode and vectors
         * without charging a tick; the handler's first fetched instruction
         * carries the cost. */
        ++cpu->instructions;
        return 0;
    }
    if (cpu->cpsr & FLAG_T)
        spent = arm7_execute_fetched(cpu, fetch16(cpu, cpu->r[15]));
    else
        spent = arm7_execute_fetched(cpu, fetch32(cpu, cpu->r[15]));
    /* flycast's arm-new.h interpreter bills a base 6 cycles per retired
     * instruction (line 1321) on top of the per-class access cost. */
    spent += VF3_ARM7_BASE_CYCLES;
    cpu->cycles += spent;
    return spent;
}

uint32_t vf3_arm7_run(vf3_arm7 *cpu, uint32_t cycles)
{
    uint32_t spent_cycles = 0;

    /* flycast's recompiler loop (arm7_rec_x64.cpp arm_dispatch): add the
     * sample's budget, then dispatch whole blocks while the accumulator is
     * positive.  The timeslice and the FIQ are looked at only between blocks,
     * so a block may overshoot the budget by its own cost - and its cost is
     * charged once, before it runs.  The leftover phase carries into the next
     * sample. */
    cpu->arm7_clock_ticks -= (int32_t)cycles;
    while (cpu->arm7_clock_ticks < 0) {
        uint32_t block = 0;
        unsigned fetched = 0;

        if (cpu->halted) break;
        if (take_exception(cpu)) {
            /* CPUFiq() charges nothing; the vector's block is charged when it
             * is dispatched. */
            ++cpu->instructions;
            continue;
        }
        if (cpu->cpsr & FLAG_T) {
            /* the recompiler is ARM-only: one instruction per dispatch, billed
             * by the interpreter model */
            block = VF3_ARM7_BASE_CYCLES +
                    arm7_execute_fetched(cpu, fetch16(cpu, cpu->r[15]));
        } else {
            do {
                int fallback = 0, sets_pc = 0;
                const uint32_t insn = fetch32(cpu, cpu->r[15]);
                const uint32_t static_cost =
                    dynarec_op_cost(insn, &fallback, &sets_pc);
                const uint32_t spent = arm7_execute_fetched(cpu, insn);
                block += static_cost;
                if (fallback)   /* interpret()'s own charge, base included */
                    block += VF3_ARM7_BASE_CYCLES + spent;
                ++fetched;
                if (sets_pc && !dynarec_nop(insn)) break;
            } while (fetched < 32u);
        }
        cpu->cycles += block;
        cpu->arm7_clock_ticks += (int32_t)block;
        spent_cycles += block;
    }
    return spent_cycles;
}

void vf3_arm7_set_irq(vf3_arm7 *cpu, int level) { cpu->irq_line = level != 0; }
void vf3_arm7_set_fiq(vf3_arm7 *cpu, int level) { cpu->fiq_line = level != 0; }

uint32_t vf3_arm7_reg(const vf3_arm7 *cpu, unsigned n)
{
    return n < 16 ? cpu->r[n] : cpu->cpsr;
}

void vf3_arm7_pc_hist_dump(unsigned top)
{
    /* Rank the executed firmware PCs.  Selection sort over the hot ones is
     * fine: the firmware is 16 KiB of addresses, so a scan is cheap. */
    static char scanned[0x4000];
    unsigned i;
    static const uint32_t markers[] = {
        0x62bc,  /* the ring-command dispatcher that A8..AB enter */
        0x671c,  /* the non-A0 track-record walker */
        0x6770,  /* the match arm of that walker */
        0x5e70,  /* the sequencer step loop */
        0x6944,  /* the stream routing entry after a match */
        0x6990,  /* the stream-commit: writes the stream record + jump 5e64 */
        0x69b8,  /* the active-marker store (strb sl,[r2,#0]) */
        0x5f4c,  /* the sequencer note-dispatch jump table */
        0x2454,  /* sequencer enqueue into FIFO 0xa400 (voice on) */
        0x2474,  /* sequencer enqueue into FIFO 0xc200 (voice off/control) */
        0x2578,  /* FIFO 0xc200 dequeue (the voice consumer) */
        0x31e8, 0x3304, 0x1ee0, 0x1f04, 0x264c, 0x3580, 0x3650, /* voice writes */
        0x6dc,   /* the generic echo path */
        0x704,   /* the A0 echo path */
        0xc20,   /* the ISR status==1 songstep branch */
        0xc24,   /* songstep ISR body */
        0xc54,   /* ISR -> 0x5d9c call */
        0x5d9c,  /* song-step: decrements the per-channel note counters */
    };
    memset(scanned, 0, sizeof(scanned));
    fprintf(stderr, "  markers:");
    for (i = 0; i < sizeof(markers) / sizeof(markers[0]); ++i)
        fprintf(stderr, " %04x:%u", markers[i],
                g_tot[markers[i] >> 2]);
    fprintf(stderr, " (tot)");
    fprintf(stderr, "\n");
    while (top--) {
        uint32_t best = 0;
        unsigned bi = (unsigned)-1;
        for (i = 0; i < 0x4000u; ++i) {
            if (scanned[i]) continue;
            if (bi == (unsigned)-1 || g_pc_hist[i] > best) {
                best = g_pc_hist[i];
                bi = i;
            }
        }
        if (bi == (unsigned)-1 || best == 0) break;
        scanned[bi] = 1;
        fprintf(stderr, "  arm pc %04x : %u\n", bi << 2, best);
    }
    vf3_arm7_pc_hist_reset();
}
