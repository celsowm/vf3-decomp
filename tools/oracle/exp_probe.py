#!/usr/bin/env python3
"""exp_probe.py — minimal synthetic-entry probe for a real-global descriptor worker.

Throwaway harness that answers one question per target: does a probe fire from a
hot prologue trigger, seed the descriptor at its *real* global, and return a
usable capsule?

These functions load their descriptor base from a literal pool
(`mov.l <lit>,r13`), so r13 cannot be seeded the way tools/oracle/seed_plan.py
does for 0x8C05B20E. The seed has to be written at the real global instead.

Two alignment facts the oracle enforces (vf3oracle.cpp: `target<0x0c000000 ||
target>0x0cfffffc || (target&3)`):
  * every `ram` line must be a 4-byte aligned word, so a byte-granular
    descriptor read has to be seeded through its containing word;
  * a run that trips it aborts the whole capture (rc=0xC0000409, frames=-1),
    it does not degrade to a rejected specimen.

    python tools/oracle/exp_probe.py 0x8c0c321e
"""
from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCRATCH = 0x0C400000

# target -> (descriptor global, descriptor offsets, pointer-slot global)
TARGETS = {
    # 1574 B, 6 jsr, 96 branches - leaf-ish worker. 0x8C0C438E is deliberately
    # absent: 45 jsr makes it a manager, so its own body is mostly call setup.
    "0x8c0c321e": (0x0C29BCC4, (0x08, 0x2C), None),
    # 2084 B, 8 jsr, 64 branches - shares 0x0C29B864 and writes to it.
    "0x8c09c1f4": (0x0C29B864, (0x04, 0x08, 0x0C, 0x10, 0x14), None),
    # 1694 B but 45 jsr; kept only to reproduce the manager result.
    "0x8c0c438e": (0x0C29B864, (0x20, 0x24, 0x28, 0x2C, 0x61, 0x98),
                   (0x0C29BB84, 0x28, 0x2C)),
}


def seeds(desc_offs, ptr_cfg):
    zero = {("desc", o): 0 for o in desc_offs}

    def mk(extra=None, ptrs=SCRATCH):
        ram = dict(zero)
        ram.update({("desc", o): v for o, v in (extra or {}).items()})
        if ptr_cfg:
            pg, pa, pb = ptr_cfg
            ram[("ptr", pa)] = ptrs
            ram[("ptr", pb)] = ptrs
        return ram

    ones = {o: 1 for o in desc_offs}
    alls = {o: 0xFFFFFFFF for o in desc_offs}
    out = [("all-zero descriptor", mk()),
           ("every descriptor word = 1", mk(ones)),
           ("every descriptor word = 0xFFFFFFFF", mk(alls))]
    for o in desc_offs:
        out.append((f"descriptor+0x{o:02x} = 1", mk({o: 1})))
        out.append((f"descriptor+0x{o:02x} = 0xFFFFFFFF", mk({o: 0xFFFFFFFF})))
    if ptr_cfg:
        out.append(("pointer slots zero (chase must trap)", mk(ptrs=0)))
    return out


def main() -> int:
    target = sys.argv[1] if len(sys.argv) > 1 else "0x8c0c321e"
    desc_base, desc_offs, ptr_cfg = TARGETS[target]
    ptr_cfg = (ptr_cfg[0], ptr_cfg[1], ptr_cfg[2]) if ptr_cfg else None

    triggers = [int(x, 16) for x in
                (ROOT / "extract/analysis/tmp_pro_sites.txt")
                .read_text().split() if x.strip()]
    plan = seeds(desc_offs, ptr_cfg)

    lines = [f"# minimal probe experiment for {target}",
             f"# descriptor global 0x{desc_base:08x}, "
             f"offsets {[hex(o) for o in desc_offs]}"]
    for trigger in triggers:
        lines.append(f"# --- trigger 0x{trigger:08x} ---")
        lines.append(f"entry 0x{trigger:08x} {target}")
        for i, (label, ram) in enumerate(plan):
            if i:
                lines.append(f"seed 0x{trigger:08x}")
            lines.append(f"# {label}")
            # prologue trigger: the target's own `sts.l pr,@-r15` replaces the
            # skipped one, so pr = trigger+2 returns into the caller's prologue
            lines.append(f"reg 0x{trigger:08x} pr 0x{trigger + 2:08x}")
            words: dict[int, int] = {}
            for (kind, off), value in ram.items():
                addr = (ptr_cfg[0] if kind == "ptr" else desc_base) + off
                w = addr & ~3
                if w in words and words[w] != value:
                    print(f"  warning: offsets collide in word 0x{w:08x}")
                words[w] = value
            for addr, value in sorted(words.items()):
                lines.append(f"ram 0x{trigger:08x} 0x{addr:08x} "
                             f"0x{value & 0xFFFFFFFF:08x}")
            lines.append("")

    out = ROOT / f"tools/oracle/exp_{target[2:]}.patch"
    out.write_text("\n".join(lines), encoding="utf-8")
    print(f"wrote {out.relative_to(ROOT)}: {len(triggers)} triggers x "
          f"{len(plan)} seeds")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
