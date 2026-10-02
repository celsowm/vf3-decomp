#!/usr/bin/env python3
"""Family map for uncovered baseline functions.

Groups the frozen baseline inventory by structural fingerprint so that large
same-shaped cohorts (like the 0x8C0B asset-table initializers) can be found
before individual ports are attempted. Reports, per family:

  * unique body bytes still uncovered (the real coverage leverage)
  * how many members executed in the archived traces (capture supply)
  * a shared callee target, when the cohort has one

Usage:
    python tools/family_map.py [--top 40] [--min-bytes 2000] [--covered]
"""
from __future__ import annotations

import argparse
import collections
import csv
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FUNCS = os.path.join(ROOT, "extract", "analysis", "funcs_1ST_READ.unsc.bin.csv")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")
BODY_RANGES = os.path.join(ROOT, "extract", "analysis", "body_ranges_1ST_READ.unsc.bin.csv")
HITS = os.path.join(ROOT, "extract", "analysis", "trace_hits.csv")

BASE = 0x8C010000


def read_inventory() -> list[tuple[int, int]]:
    rows = []
    with open(FUNCS, newline="") as fh:
        for row in csv.DictReader(fh):
            rows.append((int(row["entry"], 16), int(row["size"])))
    rows.sort()
    return rows


def read_ledger() -> tuple[set[int], set[int]]:
    """Return (ported entries, SDK-attributed entries)."""
    ported, sdk = set(), set()
    if not os.path.exists(LEDGER):
        return ported, sdk
    with open(LEDGER, newline="") as fh:
        for row in csv.DictReader(fh):
            entry = (row.get("entry") or "").strip().lower()
            if not entry:
                continue
            try:
                addr = int(entry, 16)
            except ValueError:
                continue
            status = (row.get("status") or "").strip()
            if status.startswith("ported"):
                ported.add(addr)
            elif "sdk" in status:
                sdk.add(addr)
    return ported, sdk


def read_hits() -> dict[int, int]:
    """Map entry address -> observed execution count, from the merged census."""
    counts: dict[int, int] = {}
    merged = os.path.join(ROOT, "extract", "analysis", "hits_merged.csv")
    candidates = [merged] if os.path.exists(merged) else [HITS]
    for path in candidates:
        if not os.path.exists(path):
            continue
        with open(path, newline="") as fh:
            for row in csv.DictReader(fh):
                raw = (row.get("entry") or row.get("pc") or "").strip().lower()
                if not raw:
                    continue
                try:
                    addr = int(raw, 16)
                except ValueError:
                    continue
                try:
                    counts[addr] = counts.get(addr, 0) + int(row.get("hits") or int(row.get("surveys") or 0))
                except ValueError:
                    counts[addr] = counts.get(addr, 0) + 1
    return counts


# --- structural fingerprint -------------------------------------------------

# One call-free slot: {N}=GPR, #imm=literal, @(disp,PC)=PC-relative load,
# Rm@Rn=register indirect. This abstracts away operand identities but keeps
# the control-flow skeleton that makes a cohort a family.
CALL = re.compile(r"\b(?:jsr|bsr|bsrf|braf)\b")


def load_words(addr: int, size: int) -> list[int]:
    path = os.path.join(ROOT, "extract", "exe", "1ST_READ.unsc.bin")
    with open(path, "rb") as fh:
        fh.seek(addr - BASE)
        blob = fh.read(size * 2)
    return [int.from_bytes(blob[i:i + 2], "big") for i in range(0, len(blob) - 1, 2)]


def fingerprint(words: list[int]) -> str:
    """Coarse op-class sequence: the family's controlling shape."""
    out = []
    for w in words:
        op = (w >> 8) & 0xF
        # group opcodes into semantic classes
        if op == 0:
            if (w & 0xF00F) == 0x008B:      # braf
                out.append("BRAF")
            elif (w & 0xF00F) == 0x000B:    # braf
                out.append("BRAF")
            elif (w & 0xFF00) == 0x8B00:    # bf
                out.append("BF")
            elif (w & 0xFF00) == 0x8F00:    # bt/s
                out.append("BT")
            else:
                out.append("NOP")
        elif op == 1:
            out.append("MOVL")
        elif op == 2:
            out.append("MOVW")
        elif op == 3:
            out.append("ADD")
        elif op == 4:
            out.append("CMP")
        elif op == 5:
            out.append("OR")
        elif op == 6:
            out.append("AND")
        elif op == 7:
            out.append("XOR")
        elif op == 8:
            out.append("MULU")
        elif op == 9:
            out.append("MUL")
        elif op == 0xA:
            out.append("CMPU")
        elif op == 0xB:
            out.append("SUB")
        elif op == 0xD:
            out.append("MOVL_hi")
        elif op == 0xE:
            out.append("MOVW_hi")
        elif op == 0xF:
            out.append("MAC")
        else:
            out.append("OP%x" % op)
    return "".join(out)


def callees(words: list[int], addr: int) -> tuple[int, ...]:
    """Literal targets of jsr/bra/jmp within the body, as displacement deltas."""
    targets = []
    for i, w in enumerate(words):
        disp = w & 0xFFF
        if disp > 0x7FF:
            disp -= 0x1000
        if (w & 0xF00F) in (0x000B, 0x0003) and (w >> 8) & 0xF == 0:
            targets.append(disp)
    return tuple(sorted(set(targets)))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--min-bytes", type=int, default=2000)
    ap.add_argument("--min-members", type=int, default=4)
    ap.add_argument("--covered", action="store_true",
                    help="report ported functions too (for shape reuse)")
    ap.add_argument("--executed", action="store_true",
                    help="only report functions observed executing (capture-possible)")
    args = ap.parse_args()

    inv = read_inventory()
    ported, sdk = read_ledger()
    hits = read_hits()

    covered = ported | sdk
    families: dict[tuple, list[tuple[int, int]]] = collections.defaultdict(list)
    for addr, size in inv:
        if not args.covered and addr in covered:
            continue
        if args.executed and hits.get(addr, 0) == 0:
            continue
        try:
            words = load_words(addr, size)
        except (OSError, ValueError):
            continue
        if not words:
            continue
        fp = fingerprint(words)
        families[(fp, callees(words, addr))].append((addr, size))

    rows = []
    for (fp, cl), members in families.items():
        if len(members) < args.min_members:
            continue
        total = sum(sz for _, sz in members)
        if total < args.min_bytes:
            continue
        executed = sum(1 for a, _ in members if hits.get(a, 0) > 0)
        rows.append((total, len(members), executed, fp, cl, members))

    rows.sort(reverse=True, key=lambda r: r[0])

    print("baseline: %d fns / %d body bytes" % (len(inv), sum(s for _, s in inv)))
    print("covered : %d fns (ported %d, sdk %d)"
          % (len(covered), len(ported), len(sdk)))
    if not hits:
        print("note    : no trace_hits.csv found; execution column is zero")
    print()
    hdr = "%-8s %-7s %-9s %-10s %s" % ("BYTES", "FNS", "EXECUTED", "SAME-CALLEE", "SHAPE")
    print(hdr)
    print("-" * len(hdr))
    for total, n, executed, fp, cl, members in rows[: args.top]:
        same = "yes" if len(cl) == 1 else ("n" if not cl else str(len(cl)))
        print("%-8d %-7d %-9d %-10s %s"
              % (total, n, executed, same, fp[:60]))
        if len(members) <= 6:
            for a, sz in members[:6]:
                print("           %08X %5d B  hits=%d" % (a, sz, hits.get(a, 0)))
    print()
    print("families listed: %d  (min_members=%d, min_bytes=%d)"
          % (len(rows), args.min_members, args.min_bytes))
    return 0


if __name__ == "__main__":
    sys.exit(main())
