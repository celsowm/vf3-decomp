#!/usr/bin/env python3
"""sh4_calls.py — machine-decoded call-site cross-check for port_plan.

Ghidra's static call edges (disasm_*.calls.csv) miss call sites inside
seed-fragmented function bodies: bsr pairs (e.g. 0x8C08B7EE -> 0x8C08B89C /
0x8C08BB14), RAM-vector `jsr @r2` (0x8C0AF798), literal-vector `jsr @r3`
(0x8C0B1560). port_plan's leaf/closure_ok therefore overclaims.

This tool recursive-descends every baseline function body straight from the
image (identity load at 0x8C010000) and records:
  - static bsr edges (target = PC+4+disp*2)
  - dynamic sites: jsr @Rn / bsrf (register-indirect calls)
  - tail sites: jmp @Rn (register-indirect tail transfers; not calls but
    they also invalidate a leaf claim)

Only reachable code is decoded (branches followed, braf targets NOT
followed so switch-table data is never decoded as code), which keeps
literal-pool data from decoding as phantom calls.

Limitation (documented, safe direction): dynamic sites are over-approximate
— a literal-vector jsr whose target could be resolved is still reported dyn.
Clearing those needs literal tracking (future sh4_resolved follow-up).

Usage: python tools/sh4_calls.py [--out extract/analysis/sh4_calls.csv]
"""
from __future__ import annotations

import argparse
import csv
import struct
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
AN = REPO / "extract" / "analysis"
IMG = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
BASE = 0x8C010000


def s12(v: int) -> int:
    return v - 0x1000 if v & 0x800 else v


def s8(v: int) -> int:
    return v - 0x100 if v & 0x80 else v


def scan(data: bytes, entry: int, size: int):
    """Recursive descent over [entry, entry+size+16). Returns
    (static_targets, dyn_sites, tail_sites) as sorted addr lists.

    Literal pools are the trap: conditional-branch targets and linear
    fallthrough can land on pool words (e.g. 0xBF00/0xB880 decode as bsr).
    Fixpoint iteration: each pass collects PC-relative pool refs
    (mov.l/mov.w @(disp,PC) slots); the next pass refuses to decode inside
    known pool ranges. mova refs are CODE addresses, never blocked."""
    lo = entry
    hi = entry + size + 16
    n = len(data)
    pools: list = []          # (start, end) data ranges, fixpoint-grown

    def in_pool(pc: int) -> bool:
        return any(a <= pc < b for a, b in pools)

    static, dyn, tail = set(), set(), set()
    for _ in range(4):
        new_pools = []
        # results of the final pass win (early passes decode through
        # not-yet-known pools)
        cur_static, cur_dyn, cur_tail = set(), set(), set()
        visited = set()
        work = [entry]
        steps = 0

        def read(pc: int):
            off = pc - BASE
            if off < 0 or off + 2 > n:
                return None
            return struct.unpack_from("<H", data, off)[0]

        def observe(w: int, pc: int):
            """Record one word WITHOUT following control flow (delay slots,
            post-jump words). Returns pool range or None."""
            if w & 0xF000 == 0xD000:
                a = ((pc + 4) & ~3) + (w & 0xFF) * 4
                new_pools.append((a, a + 4))
            elif w & 0xF000 == 0x9000:
                a = pc + 4 + (w & 0xFF) * 2
                new_pools.append((a, a + 2))
            elif w & 0xF000 == 0xB000:
                cur_static.add(pc + 4 + s12(w & 0xFFF) * 2)
            elif w & 0xF0FF == 0x400B or w & 0xF00F == 0x0003:
                cur_dyn.add(pc)
            elif w & 0xF0FF == 0x402B:
                cur_tail.add(pc)

        def delay_only(pc: int):
            """Unconditional transfer: decode the single delay-slot word,
            then the path ends (never fall through)."""
            if pc in visited or pc < lo or pc >= hi or in_pool(pc):
                return
            w = read(pc)
            if w is None:
                return
            visited.add(pc)
            observe(w, pc)

        while work and steps < 8192:
            pc = work.pop()
            while steps < 8192:
                steps += 1
                if pc in visited or pc < lo or pc >= hi or in_pool(pc):
                    break
                w = read(pc)
                if w is None:
                    break
                visited.add(pc)
                npc = pc + 2
                if w & 0xF000 == 0xD000:        # mov.l @(disp,PC),Rn: pool slot
                    a = ((pc + 4) & ~3) + (w & 0xFF) * 4
                    new_pools.append((a, a + 4))
                    pc = npc
                    continue
                if w & 0xF000 == 0x9000:        # mov.w @(disp,PC),Rn: pool slot
                    a = pc + 4 + (w & 0xFF) * 2
                    new_pools.append((a, a + 2))
                    pc = npc
                    continue
                if w & 0xF000 == 0xB000:            # bsr disp12 (static call)
                    t = pc + 4 + s12(w & 0xFFF) * 2
                    cur_static.add(t)
                    if lo <= t < hi and t not in visited and not in_pool(t):
                        work.append(t)
                    pc = npc                       # bsr returns: keep going
                elif w & 0xF0FF == 0x400B:          # jsr @Rn (dynamic call)
                    cur_dyn.add(pc)
                    pc = npc                       # jsr returns: keep going
                elif w & 0xF00F == 0x0003:          # bsrf (dynamic call)
                    cur_dyn.add(pc)
                    pc = npc
                elif w & 0xF0FF == 0x402B:          # jmp @Rn: delay executes
                    cur_tail.add(pc)
                    delay_only(npc)
                    break
                elif w & 0xF000 == 0xA000:          # bra: delay executes only
                    t = pc + 4 + s12(w & 0xFFF) * 2
                    if lo <= t < hi and t not in visited and not in_pool(t):
                        work.append(t)
                    delay_only(npc)
                    break
                elif w & 0xF000 == 0x8000:          # bf/bt/bf.s/bt.s disp8
                    t = pc + 4 + s8(w & 0xFF) * 2
                    if lo <= t < hi and t not in visited and not in_pool(t):
                        work.append(t)
                    pc = npc
                elif w in (0x000B, 0x002B):         # rts / rte: delay executes
                    delay_only(npc)
                    break
                elif w & 0xF0FF == 0x2023:          # braf: delay executes only
                    delay_only(npc)
                    break
                else:
                    pc = npc
        grown = False
        for a, b in new_pools:
            if not any(c <= a and b <= d for c, d in pools):
                pools.append((a, b))
                grown = True
        static, dyn, tail = cur_static, cur_dyn, cur_tail
        if not grown:
            break
    return sorted(static), sorted(dyn), sorted(tail)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="extract/analysis/sh4_calls.csv")
    a = ap.parse_args()
    data = IMG.read_bytes()
    funcs = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            funcs.append((int(r["entry"], 16), int(r["size"])))
    rows = []
    n_static = n_dyn = n_tail = n_fn_dyn = 0
    for ent, size in funcs:
        st, dy, ta = scan(data, ent, size)
        n_static += len(st)
        n_dyn += len(dy)
        n_tail += len(ta)
        if dy:
            n_fn_dyn += 1
        rows.append({
            "entry": f"0x{ent:08X}", "size": size,
            "n_static": len(st),
            "static_targets": " ".join(f"0x{t:08X}" for t in st),
            "n_dyn": len(dy),
            "dyn_sites": " ".join(f"0x{d:08X}" for d in dy),
            "n_tail": len(ta),
            "tail_sites": " ".join(f"0x{t:08X}" for t in ta),
        })
    outp = Path(a.out)
    with open(outp, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "size", "n_static",
                                          "static_targets", "n_dyn",
                                          "dyn_sites", "n_tail", "tail_sites"])
        w.writeheader()
        w.writerows(rows)
    print(f"sh4_calls: {outp} ({len(rows)} fns, {n_static} static edges, "
          f"{n_dyn} dyn sites in {n_fn_dyn} fns, {n_tail} tail sites)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
