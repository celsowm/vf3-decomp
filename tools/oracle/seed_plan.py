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
    GATES = (0x0001, 0x0002, 0x0020, 0x0040, 0x0080,
             0x0100, 0x0400, 0x0800, 0x2000, 0x4000, 0xEFFF)
    # (descriptor offset, guard mask, codes) — the two cmp/eq switches.
    SWITCHES = ((0x2C, 0x0040, (0, 1, 2, 3, 4, 5, 6, 8, 10, 11)),
                (0x30, 0x0080, (0, 1, 2, 4, 6, 7, 8, 9, 10, 11)))
    PAYLOAD = (0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x20, 0x24, 0x28, 0x30, 0x34,
               0x38, 0x3C, 0x90, 0xB4)

    seeds: list[dict] = []
    zero = {o: 0 for o in range(0, 0x40, 4)}
    zero[0x90] = 0
    zero[0xB4] = 0
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
    return seeds


RECIPES = {
    0x8C05B20E: packbits,
}


def emit(target: int, triggers: list[int], seeds: list[dict], base: int, pr_offset: int,
         out: Path) -> None:
    lines = [f"# Generated by tools/oracle/seed_plan.py for target 0x{target:08x}.",
             f"# {len(seeds)} seed variants applied round-robin over each trigger's firings.",
             f"# scratch descriptor at 0x{base:08x} (page-aligned, restored after every probe).",
             f"# return fixture pr = trigger+{pr_offset}"
             + ("  (JSR call site: the skipped call is exactly what the probe performs)"
                if pr_offset == 4 else "  (prologue site: unsafe, prefer a call site)"),
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
                lines.append(f"reg 0x{trigger:08x} {reg} 0x{value & 0xFFFFFFFF:08x}")
            for offset, value in sorted(seed["ram"].items()):
                lines.append(f"ram 0x{trigger:08x} 0x{base + offset:08x} 0x{value & 0xFFFFFFFF:08x}")
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
                         "call site (instruction + delay slot), 2 for a bare one")
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
    print(f"wrote {out.relative_to(ROOT)}: {len(seeds)} variants x {len(triggers)} triggers")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
