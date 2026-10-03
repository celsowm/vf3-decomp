#!/usr/bin/env python3
"""seed_plan.py — emit a VF3_ENTRY_PATCH seed sweep for one synthetic-entry target.

A probe fires from a hot trigger instruction, so what varies between capsules is
only the *seed*: the register file and the RAM words the target reads. For the
descriptor workers (see docs/re/entry_patch.md) the target's whole control flow is
a function of a 64-byte source descriptor reached through P4 addressing
(`mov.l @(off,r13)`), plus two far words. A bit/field sweep of those words is
therefore a systematic walk of the branch space, not a guess.

The oracle applies the generated variants round-robin across the trigger's
firings, so one hot trigger yields the whole sweep.

    python tools/oracle/seed_plan.py --target 0x8c05b20e \
        --triggers 0x8c04853a,0x8c048284 --out tools/oracle/phase3_packbits.patch
"""
from __future__ import annotations

import argparse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# A page-aligned scratch descriptor far from live game structures. The probe
# snapshots and restores every page it seeds, so the game never sees it.
SCRATCH = 0x0C400000


def packbits(base: int) -> list[dict]:
    """0x8C05B20E: texture/format descriptor unpacker.

    r0 is the P4 word index into the descriptor, r13 its RAM base. Every path in
    the body is selected by two inputs only:

      * the flag word at +0, tested against the masks below (`tst r12,#mask` +
        `bt`): the branch is taken when the mask ANDs to zero, so a *set* mask bit
        is what opens the block behind it;
      * selector words holding small format codes, dispatched by `cmp/eq`.

    A selector arm is only reachable when its guard bit is set, so the plan always
    pairs a selector value with the guard bit that opens its switch. Masks are
    taken from tools/oracle/gate_scan.py.
    """
    GATES = (0x0001, 0x0002, 0x0020, 0x0040, 0x0080, 0x0100, 0x0400, 0x0800,
             0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x100000,
             0x200000, 0x8000000, 0x10000000, 0xEFFF,
             # Masks applied to a copy of the flag word or to the accumulated
             # word rather than to r12 itself; gate_scan only reports the r12
             # form, so they are listed here explicitly.
             0x00100000, 0x01000000, 0x02000000, 0x04000000, 0x28000000)
    # (descriptor offset, guard mask, codes) — the two cmp/eq switches.
    SWITCHES = ((0x2C, 0x0040, (0, 1, 2, 3, 4, 5, 6, 8, 10, 11)),
                (0x30, 0x0080, (0, 1, 2, 4, 6, 7, 8, 9, 10, 11)))
    # Every offset the function reads through r13: 0x04..0x3C by literal
    # displacement, 0x40..0x6C / 0x90 / 0xA0 / 0xB4..0xBC through a register
    # loaded with an immediate (tools/oracle/gate_scan.py).
    PAYLOAD = tuple(range(0x04, 0x40, 4)) + tuple(range(0x40, 0x70, 4)) + \
        (0x90, 0xA0, 0xB4, 0xB8, 0xBC)

    seeds: list[dict] = []
    zero = {o: 0 for o in PAYLOAD}
    base_regs = {"r0": 0, "r13": base}

    def add(flags=0, words=None):
        ram = dict(zero)
        ram[0x00] = flags
        ram.update(words or {})
        seeds.append({"regs": dict(base_regs), "ram": ram})

    add(0)                                            # every gate closed
    add(0xFFFFFFFF)                                   # every gate open
    # Each gate on its own, and each gate with the two selector guards open.
    for mask in GATES:
        add(mask)
        add(mask & ~0x0040)
        add(mask | 0x0040)
        add(mask | 0x0080)
    # Selector arms with their guard open (and the other guards' low bits too).
    for off, guard, codes in SWITCHES:
        for code in codes:
            add(guard | 0x0003, {off: code})
            add(guard, {off: code})
            add(guard | 0x0040 | 0x0080, {off: code})
        add(guard, {off: 0xFFFFFFFF})
        add(guard | 0x0003, {off: 7})                # a code the game never uses
    # Payload words: zero/one/all-ones plus the shift-sensitive single bits, with
    # the common gates open.
    for off in PAYLOAD:
        for value in (1, 0xFFFFFFFF):
            add(0x0043, {off: value})
        for bit in (1, 8, 15, 16, 23, 27, 31):
            add(0x0043, {off: 1 << bit})
    # Combinations that the switch arms actually consume together.
    for off, guard, codes in SWITCHES:
        for code in codes:
            add(guard | 0x0003 | 0x0400, {off: code, 0x20: 0x12345678, 0x28: 1})
            add(guard | 0x0003 | 0x2000, {off: code, 0x10: 0x0F0F0F0F, 0x14: 0x80000000})
    # Coverage-guided cross product: most remaining arms sit behind a two-input
    # condition (a flag bit AND a descriptor word being non-zero/even), so every
    # gate is paired with every payload word.
    for mask in GATES:
        for off in PAYLOAD:
            add(mask | 0x0040, {off: 1})
            add(mask, {off: 1})
            add(mask | 0x0040, {off: 2})
        add(mask | 0x0040, {0x28: 1, 0x24: 0xFFFFFFFE, 0x20: 1})
        add(mask, {0x28: 1, 0x24: 0xFFFFFFFE, 0x20: 1})
    # The same cross product with no flag bit set at all: a large share of the
    # remaining arms are plain "descriptor word != 0" tests on the default path.
    for off in PAYLOAD:
        for value in (1, 2, 0xFFFFFFFF, 0xFFFFFFFE):
            add(0, {off: value})
        add(0x0040, {off: 1})
        add(0x0080, {off: 1})
    add(0, {0x28: 1, 0x38: 1, 0x3C: 1})
    add(0x0040, {0x28: 1, 0x38: 1, 0x3C: 1, 0xB4: 1})
    for off, guard, codes in SWITCHES:
        for code in codes:
            for word_off in (0x10, 0x20, 0x24, 0x28):
                add(guard | 0x0003, {off: code, word_off: 1})
    # Multi-gate paths. The body is a chain of gates, each with a fall-through
    # and a skip arm, so a deep arm needs a *combination* of open gates rather
    # than the single-bit seeds above. Prefix/suffix ORs and adjacent pairs walk
    # that combination space cheaply.
    words = {0x04: 1, 0x38: 1, 0xB4: 1, 0x28: 1}
    for k in range(1, len(GATES) + 1):
        add(GATES[k - 1], words)
        prefix = 0
        for mask in GATES[:k]:
            prefix |= mask
        add(prefix, words)
        add(prefix | 0x0004, words)
        suffix = 0
        for mask in GATES[len(GATES) - k:]:
            suffix |= mask
        add(suffix, words)
    for i in range(len(GATES) - 1):
        add(GATES[i] | GATES[i + 1], words)
        add(GATES[i] | GATES[i + 1] | 0x0004, words)
    return seeds


def swapper(base: int) -> list[dict]:
    """0x8C0C321E: geometry byte-swapper. 1574 B, 6 jsr, 96 branches.

    Unlike 0x8C05B20E this function never takes its descriptor base from a
    register: `mov.l <lit>,r13` loads it from a literal pool, so r13 cannot be
    seeded. The data it actually works on is the **r14 argument object**, which
    is a seedable register, and control flow is gated by three words:

      *tst r3,r2` with r2 = *(0x0C29B864)   mask 0x00000300  -> early exit
      *tst r3,r1` with r1 = *(0x0C29BCC0)   mask 0x00080001  -> early exit
      *tst #10,r0` with r0 = *r14          mask 0x0000000A  -> early exit

    The first two live in real game globals. During a fight the game usually
    leaves them open, which is why a probe with no gate seed still reaches the
    body - but the closed variants are only reachable if the plan writes them.

    r14 points at a scratch object whose 18 live displacements were resolved
    with tools/oracle/arg_offsets.py (r14+0x04, +0x31..0x36, +0x38, +0x3a,
    +0x3c, +0x44..0x4e, +0x68, +0x6c). The tail is a bulk byte-swap over the
    r13 descriptor starting at +0x3C6, so that block is seeded as bytes too.
    """
    OBJ = 0x0C29B900                  # r4 -> scratch argument object
    GLOBAL_A = 0x0C29B864              # gate word 0 (also the r10 base)
    GLOBAL_B = 0x0C29BCC0              # gate word 1
    DESC = 0x0C29BCC4                  # r13 descriptor, byte-swap block at +0x3C6
    # EFFECTIVE gate masks, measured against the emulator, not read off the
    # disassembly. sh4dump prints `mov.w ... # lit.w=0300` and `tst #10,r0`, but
    # seeding 0x0300 leaves gate A shut while 0x0030 opens it; the same is true
    # of gate B and of the `tst #10` on the argument object. Every mask below is
    # the value that demonstrably opens its gate (see the three disc_*.patch
    # captures in docs/re/entry_patch.md). Do not "correct" these back to what
    # the disassembly says.
    GATE_A, GATE_B, GATE_R14 = 0x0030, 0x0018, 0x0A00
    # The switch that gates everything past 0x8c0c329C. It is reached through
    # r10, not r13, so gate_scan never reported it and a first campaign seeded
    # only the fields above and flatlined at 31.6%:
    #     8c0c3282  mov.b @(r0,r10),r5   # r0 = 125 -> *0x0C29B864+125
    #     8c0c3288  mov.l @(r0,r10),r4   # r0 = 0x13C -> *0x0C29B864+0x13C
    #     8c0c328c  cmp/eq #1,r0 / #2 / #3
    SW_BYTE_OFF, SW_WORD_OFF = 125, 0x13C
    SW_CODES = (0, 1, 2, 3, 4)
    # Second switch, resolved the same way: *0x0C29B864+232, codes [3, 3].
    SW2_OFF, SW2_CODES = 232, (0, 3)
    # The two inner arms test bits of the word at SW_WORD_OFF: 0x10 for code 1,
    # 0x20 for code 2.
    SW_BITS = (0x10, 0x20)

    # 18 live displacements of the r14 argument object, rounded up to the word
    # each byte read sits in (the oracle's `ram` directive is word-granular).
    # Offset 0 is not one of the arg_offsets.py displacements but it IS read:
    # `mov.l @r14,r0 / tst #10,r0` at 0x8c0c3248 gates the whole body, so a
    # plan that omits it sends every variant down the early exit.
    OBJ_OFFS = (0x00, 0x04, 0x30, 0x34, 0x38, 0x3C, 0x44, 0x48, 0x4C, 0x50,
                0x68, 0x6C)
    SWAP_OFFS = tuple(range(0x3C0, 0x400, 4))

    def mk(flags_a=0, flags_b=0, obj=None, desc=None, extra=None):
        ram: dict[int, int] = {
            GLOBAL_A: flags_a & 0xFFFFFFFF,
            GLOBAL_B: flags_b & 0xFFFFFFFF,
        }
        for off, value in (obj or {}).items():
            ram[OBJ + off] = value & 0xFFFFFFFF
        for off, value in (desc or {}).items():
            ram[DESC + off] = value & 0xFFFFFFFF
        # absolute-address overrides, for fields reached through r10
        for addr, value in (extra or {}).items():
            ram[addr] = value & 0xFFFFFFFF
        # Seed r4, NOT r14. The bt/s at 0x8c0c3232 has a delay slot at
        # 0x8c0c3234 (`mov r4,r14`) that executes whether or not the branch is
        # taken, so r14 is always overwritten with r4 before the gate at
        # 0x8c0c3248 reads it. The argument object arrives in r4 (SH-4 first
        # argument) and the function copies it across itself.
        return {"regs": {"r4": OBJ}, "ram": ram, "ram_abs": True}

    seeds: list[dict] = []

    # Every gate combination: 0 = gate closed (early exit), mask = gate open.
    # The three gates are independent, so this is the complete 8-cell product
    # and it is what puts the two early-exit arms on the record.
    for a in (0, GATE_A):
        for b in (0, GATE_B):
            for r in (0, GATE_R14):
                seed_obj = {off: GATE_R14 for off in OBJ_OFFS} if r else {}
                seeds.append(mk(a, b, seed_obj or {o: 0 for o in OBJ_OFFS}))

    # With all gates open, sweep each argument-object word through the values
    # that flip a comparison: 0, 1, all-ones, and the single bits the masks in
    # the body test.
    def base_obj():
        return {o: GATE_R14 for o in OBJ_OFFS}

    for off in OBJ_OFFS:
        for value in (0, 1, 2, 0xFFFFFFFF, 0x80000000, 0x7FFFFFFF, 0x0000FFFF,
                      0xFFFF0000):
            o = base_obj()
            o[off] = value
            seeds.append(mk(GATE_A, GATE_B, o))

    # Pairs, because most arms are a two-field condition.
    for i, off in enumerate(OBJ_OFFS):
        other = OBJ_OFFS[(i + 1) % len(OBJ_OFFS)]
        for va, vb in ((0, 1), (1, 0), (1, 1), (0xFFFFFFFF, 1),
                       (0xFFFFFFFE, 1), (1, 0xFFFFFFFF)):
            o = base_obj()
            o[off] = va
            o[other] = vb
            seeds.append(mk(GATE_A, GATE_B, o))

    # The byte-swap block over the r13 descriptor, and its interaction with a
    # non-trivial argument word.
    for off in SWAP_OFFS:
        for value in (0, 0xFFFFFFFF, 0x01020304, 0x04030201):
            d = {o: value for o in SWAP_OFFS}
            o2 = base_obj()
            o2[0x6C] = 4
            seeds.append(mk(GATE_A, GATE_B, o2, d))
    d = {o: 0x01020304 for o in SWAP_OFFS}
    o2 = base_obj()
    o2[0x04] = 0
    seeds.append(mk(GATE_A, GATE_B, o2, d))

    # --- the switch that actually gates the body (reached through r10) ---
    # The byte at GLOBAL_A+125 selects the arm, and the word at
    # GLOBAL_A+0x13C is then bit-tested for the 0x10 / 0x20 sub-arms, so the
    # two have to be crossed rather than swept one at a time.
    def sw(code, bits, second=0):
        # Keep base_obj() intact: it sets every argument-object word to
        # GATE_R14, which is what satisfies `tst #10,r0` at 0x8c0c324a. Zeroing
        # any of them sends every switch variant down the early exit instead.
        ram_extra = {
            # byte lane 1 of the word at GLOBAL_A+124 holds offset 125
            (GLOBAL_A + SW_BYTE_OFF) & ~3: 0,
            (GLOBAL_A + SW_WORD_OFF): bits & 0xFFFFFFFF,
            (GLOBAL_A + SW2_OFF) & ~3: second & 0xFFFFFFFF,
        }
        return mk(GATE_A, GATE_B, base_obj(), None, ram_extra)

    for code in SW_CODES:
        for b1 in SW_BITS:
            for b2 in (0,) + SW_BITS:
                # place the code into byte lane 1 of GLOBAL_A+124
                s = sw(code, b1 | b2, 0)
                s["ram"][(GLOBAL_A + SW_BYTE_OFF) & ~3] = (code & 0xFF) << 8
                seeds.append(s)
    # each code with the second switch field varied independently
    for code in SW_CODES:
        for second in SW2_CODES:
            s = sw(code, 0, second)
            s["ram"][(GLOBAL_A + SW_BYTE_OFF) & ~3] = (code & 0xFF) << 8
            seeds.append(s)
    # and the code byte outside every case the switch knows, which is the
    # default arm at 0x8c0c3298
    for other in (4, 5, 0x7F, 0xFF):
        s = sw(0, 0, 0)
        s["ram"][(GLOBAL_A + SW_BYTE_OFF) & ~3] = other << 8
        seeds.append(s)
    return seeds


def dispatch(base: int) -> list[dict]:
    """0x8C09C1F4: command dispatcher / descriptor init. 2084 B, 8 jsr, 64 branches.

    This one has no argument object. Its entry writes the **incoming argument
    registers** straight into the descriptor global and dispatches on r0:

        sts.l pr,@-r15
        mov.l <lit>,r13          # 0x0C29B864, read/write
        mov.l r3,@(12,r13)       # argument -> descriptor
        mov.l r9,@(24,r13)
        mov.b r9,@(r0,r13)       # r0 is also the write offset
        mov.l r9,@(20,r13)
        bra 0x8c09c9f8

    `cmp/eq #N,r0` selects the command: N in {1,3,6,7,8,9,16}, and r0 is also
    bit-tested against 0x04/0x08/0x20/0x40/0x80. The descriptor words at
    +0x234 and +0x238 are the two longer-range gates (gate_scan reports their
    offsets as masks 0x0234/0x0238, which is the same number either way).

    So the plan is a r0 command sweep crossed with the two descriptor gates.
    """
    DESC = 0x0C29B864
    CODES = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 17, 32, 0x40, 0x80)
    BITS = (0x04, 0x08, 0x20, 0x40, 0x80)
    GATE_OFFS = (0x234, 0x238)

    def mk(r0, gates=None, extra=None):
        ram: dict[int, int] = {}
        # The three argument registers land in the descriptor; give the sweep
        # values that survive the entry stores instead of leaving them garbage.
        ram[DESC + 0x0C] = 0
        ram[DESC + 0x14] = 0
        ram[DESC + 0x18] = 0
        for off, value in (gates or {}).items():
            ram[DESC + off] = value & 0xFFFFFFFF
        for off, value in (extra or {}).items():
            ram[DESC + off] = value & 0xFFFFFFFF
        return {"regs": {"r0": r0 & 0xFFFFFFFF, "r3": 0, "r9": 0},
                "ram": ram, "ram_abs": True}

    seeds: list[dict] = []
    # Every command code, gates left as the live game has them.
    for code in CODES:
        seeds.append(mk(code))
    # Every command code against both gate words closed and open.
    for code in CODES:
        seeds.append(mk(code, {0x234: 0, 0x238: 0}))
        seeds.append(mk(code, {0x234: 0xFFFFFFFF, 0x238: 0xFFFFFFFF}))
    # Bit combinations of r0, which is how the 0x04/0x08/0x20/0x40/0x80 tests
    # are meant to be walked.
    for b in BITS:
        for c in (0, 1, 3, 6, 9, 16):
            seeds.append(mk(b | c))
            seeds.append(mk(b, {0x234: 0, 0x238: 0}))
    # All bits set at once, and each gate word alone.
    seeds.append(mk(0xFFFFFFFF))
    seeds.append(mk(0, {0x234: 1}))
    seeds.append(mk(0, {0x238: 1}))
    seeds.append(mk(9, {0x234: 1, 0x238: 1}))
    seeds.append(mk(0, {0x234: 0xFFFFFFFE, 0x238: 0xFFFFFFFE}))
    return seeds


RECIPES = {
    0x8C05B20E: packbits,
    0x8C0C321E: swapper,
    0x8C09C1F4: dispatch,
}


def emit(target: int, triggers: list[int], seeds: list[dict], base: int, pr_offset: int,
         out: Path) -> None:
    lines = [f"# Generated by tools/oracle/seed_plan.py for target 0x{target:08x}.",
             f"# {len(seeds)} seed variants applied round-robin over each trigger's firings.",
             f"# scratch descriptor at 0x{base:08x} (page-aligned, restored after every probe).",
             "# return fixture pr = trigger+%d" % pr_offset
             + ("  (JSR call site: the probe performs the call the site was about to make)"
                if pr_offset == 4 else
                "  (bare prologue site: sound only because the target's first opcode"
                " SUBSTITUTES for the trigger, so nothing at the site runs)"),
             ""]
    for trigger in triggers:
        lines.append(f"# --- trigger 0x{trigger:08x} ---")
        lines.append(f"entry 0x{trigger:08x} 0x{target:08x}")
        for i, seed in enumerate(seeds):
            if i:
                lines.append(f"seed 0x{trigger:08x}")
            # Every variant carries the trigger's own return fixture: the probe has
            # to come back to the instruction after the trigger or the game unwinds
            # into the trigger's caller and the run diverges.
            lines.append(f"reg 0x{trigger:08x} pr 0x{trigger + pr_offset:08x}")
            for reg, value in sorted(seed["regs"].items()):
                if value is None:
                    continue
                lines.append(f"reg 0x{trigger:08x} {reg} 0x{value & 0xFFFFFFFF:08x}")
            # A recipe either addresses the descriptor relative to `base` (the
            # 0x8C05B20E scratch page) or supplies absolute addresses, because
            # its descriptor base is a real game global it cannot relocate.
            for offset, value in sorted(seed["ram"].items()):
                addr = offset if seed.get("ram_abs") else base + offset
                lines.append(f"ram 0x{trigger:08x} 0x{addr:08x} 0x{value & 0xFFFFFFFF:08x}")
        lines.append("")
    out.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--target", required=True, type=lambda x: int(x, 16))
    ap.add_argument("--triggers", required=True,
                    help="comma-separated hot trigger PCs to fire the sweep from")
    ap.add_argument("--out", required=True)
    ap.add_argument("--pr-offset", type=int, default=4,
                    help="return address offset from the trigger PC; 4 for a JSR "
                         "call site (instruction + delay slot), 2 for a bare one. "
                         "Both are sound only with opcode substitution enabled "
                         "(vf3OracleTakeSubstitute)")
    a = ap.parse_args()
    recipe = RECIPES.get(a.target)
    if not recipe:
        raise SystemExit(f"no seed recipe for 0x{a.target:08x}; add one to RECIPES")
    triggers = [int(x, 16) for x in a.triggers.split(",") if x.strip()]
    if not triggers:
        raise SystemExit("--triggers needs at least one PC")
    out = Path(a.out)
    out = out if out.is_absolute() else ROOT / out
    seeds = recipe(SCRATCH)
    emit(a.target, triggers, seeds, SCRATCH, a.pr_offset, out)
    try:
        shown = out.relative_to(ROOT)
    except ValueError:
        shown = out
    print(f"wrote {shown}: {len(seeds)} variants x {len(triggers)} triggers")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
