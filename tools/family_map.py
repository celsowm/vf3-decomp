#!/usr/bin/env python3
"""Family map for uncovered baseline functions.

Groups the frozen baseline inventory by structural fingerprint so that large
same-shaped cohorts (like the 0x8C0B asset-table initializers that delivered
+25 KB in batch 6) are found before individual ports are attempted.

The original word-sequence fingerprint was too strict: it hashed the raw
op-class of every word, so only identical-size bodies could ever group (it
reported 0 families). The 2026-10-02 rework groups by evidence that actually
makes a cohort a *porting family*:

  * callee-set key: the sorted set of static bsr targets (resolved to the
    containing baseline function when possible), plus the dynamic jsr/bsrf
    site count. All members of a family share their external contract, so
    one adapter skeleton + one capture cohort can cover many bodies
    regardless of body length.
  * leaf clones: bodies with no calls at all are keyed by their normalized
    mnemonic-class skeleton (operands masked), which only matches true
    clone shapes.

Per family it reports:
  * unique body bytes still uncovered (the real coverage leverage)
  * how many members executed in the archived traces (capture supply)
  * member list with size/hits

Usage:
    python tools/family_map.py [--top 40] [--min-bytes 2000] [--min-members 4]
                               [--covered] [--executed] [--show-skeleton]
"""
from __future__ import annotations

import argparse
import collections
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, ROOT)

import sh4  # noqa: E402  (tools/sh4.py full SH-4 decoder)

FUNCS = os.path.join(ROOT, "extract", "analysis", "funcs_1ST_READ.unsc.bin.csv")
BODY_RANGES = os.path.join(ROOT, "extract", "analysis", "function_body_ranges.csv")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")
HITS = os.path.join(ROOT, "extract", "analysis", "trace_fn_hits.csv")
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

# Coarse mnemonic classes for the leaf-clone skeleton. Operands are masked;
# the class sequence captures the body's control/data shape.
def mnem_class(mnem: str) -> str:
    if mnem.startswith("f") or mnem.endswith(".s") or mnem.endswith(".d"):
        return "f"                       # FPU
    if mnem.startswith("mov"):
        return "m"
    if mnem in ("add", "addc", "addv", "adds", "dmuls", "dmulu"):
        return "a"
    if mnem in ("sub", "subc", "subv", "subs"):
        return "s"
    if mnem.startswith("cmp") or mnem in ("tas", "tst"):
        return "c"
    if mnem in ("bsr", "jsr", "bsrf", "braf", "trapa"):
        return "C"
    if mnem in ("bra", "bt", "bf", "bt/s", "bf/s", "jmp"):
        return "b"
    if mnem in ("rts", "rte", "rte/nop"):
        return "R"
    if mnem.startswith(("lds", "sts", "lds.l", "sts.l")):
        return "l"
    if mnem.startswith(("ldc", "stc")):
        return "d"
    if mnem.startswith("mac") or mnem.startswith("mul") or mnem.startswith("dmul"):
        return "M"
    return "o"


_IMAGE: bytes | None = None
_BODIES: dict[int, list[tuple[int, int]]] | None = None


def image() -> bytes:
    global _IMAGE
    if _IMAGE is None:
        with open(os.path.join(ROOT, "extract", "exe", "1ST_READ.unsc.bin"), "rb") as fh:
            _IMAGE = fh.read()
    return _IMAGE


def body_segments(addr: int, size: int) -> list[tuple[int, list[int]]]:
    """Return SH-4 words from the real, possibly fragmented Ghidra body.

    The executable is already in its retail byte order.  In particular, do not
    interpret each body as `entry .. entry + size`: Ghidra bodies may contain
    gaps, and those gaps are often literal pools rather than instructions.
    """
    blob = image()
    global _BODIES
    if _BODIES is None:
        _BODIES = collections.defaultdict(list)
        with open(BODY_RANGES, newline="") as fh:
            for row in csv.DictReader(fh):
                _BODIES[int(row["entry"], 16)].append(
                    (int(row["start"], 16), int(row["end"], 16)))
    ranges = _BODIES.get(addr, [])
    if not ranges or sum(end - start for start, end in ranges) != size:
        raise ValueError("missing or inconsistent body ranges")
    segments = []
    for start, end in ranges:
        off = start - BASE
        if off < 0 or off + end - start > len(blob) or (end - start) % 2:
            raise ValueError("body range outside image or odd-sized")
        segments.append((start, [int.from_bytes(blob[i:i + 2], "little")
                                 for i in range(off, off + end - start, 2)]))
    return segments


def analyze(words: list[int], addr: int) -> tuple[tuple[int, ...], int, str]:
    """Return (static bsr callee targets, dynamic call-site count, skeleton)."""
    callees: set[int] = set()
    dyn = 0
    skel = []
    for i, w in enumerate(words):
        d = sh4.decode(w)
        if d is None:
            skel.append("?")
            continue
        mnem = d[0]
        pc = addr + i * 2
        if mnem == "bsr":
            # bsr disp12: target = pc + 4 + sign-extended(disp)*2
            disp = w & 0xFFF
            if disp > 0x7FF:
                disp -= 0x1000
            callees.add(pc + 4 + disp * 2)
        elif mnem in ("jsr", "bsrf"):
            dyn += 1
        skel.append(mnem_class(mnem))
    return tuple(sorted(callees)), dyn, "".join(skel)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--min-bytes", type=int, default=2000)
    ap.add_argument("--min-members", type=int, default=4)
    ap.add_argument("--covered", action="store_true",
                    help="report ported functions too (for shape reuse)")
    ap.add_argument("--executed", action="store_true",
                    help="only report functions observed executing (capture-possible)")
    ap.add_argument("--show-skeleton", action="store_true",
                    help="print each family's representative skeleton")
    args = ap.parse_args()

    inv = read_inventory()
    starts = [a for a, _ in inv]

    def containing(target: int) -> int | None:
        import bisect
        i = bisect.bisect_right(starts, target) - 1
        if i < 0:
            return target
        ent, size = inv[i]
        if target < ent + size:
            return ent
        return target  # off-function target: key on the raw address

    ported, sdk = read_ledger()
    hits = read_hits()
    covered = ported | sdk

    families: dict[tuple, list[tuple[int, int, str]]] = collections.defaultdict(list)
    for addr, size in inv:
        if not args.covered and addr in covered:
            continue
        if args.executed and hits.get(addr, 0) == 0:
            continue
        try:
            segments = body_segments(addr, size)
        except (OSError, ValueError):
            continue
        if not segments:
            continue
        callees, dyn, skel = set(), 0, []
        for pc, words in segments:
            sub_callees, sub_dyn, sub_skel = analyze(words, pc)
            callees.update(sub_callees)
            dyn += sub_dyn
            skel.append(sub_skel)
        callees, skel = tuple(sorted(callees)), "|".join(skel)
        # family key: shared external contract for calling bodies; exact
        # clone skeleton for leaves.
        if callees or dyn:
            key_callees = tuple(c if (c := containing(t)) is not None else t
                                for t in callees)
            key = ("call", key_callees, dyn)
        else:
            key = ("leaf", skel)
        families[key].append((addr, size, skel))

    rows = []
    for key, members in families.items():
        if len(members) < args.min_members:
            continue
        total = sum(sz for _, sz, _ in members)
        if total < args.min_bytes:
            continue
        executed = sum(1 for a, _, _ in members if hits.get(a, 0) > 0)
        rows.append((total, len(members), executed, key, members))
    rows.sort(reverse=True, key=lambda r: r[0])

    print("baseline: %d fns / %d body bytes" % (len(inv), sum(s for _, s in inv)))
    print("covered : %d fns (ported %d, sdk %d)"
          % (len(covered), len(ported), len(sdk)))
    if not hits:
        print("note    : no trace hits found; execution column is zero")
    print()
    hdr = "%-8s %-6s %-9s %-34s %s" % ("BYTES", "FNS", "EXECUTED", "KEY", "MEMBERS")
    print(hdr)
    print("-" * len(hdr))
    for total, n, executed, key, members in rows[: args.top]:
        if key[0] == "call":
            tgt = key[1]
            label = "call " + (("%d callee" % len(tgt)) if len(tgt) > 1
                                else ("->0x%08X" % tgt[0] if tgt else "?"))
            label += " dyn=%d" % key[2]
        else:
            label = "leaf clone len=%d" % len(key[1])
        print("%-8d %-6d %-9d %-34s %s"
              % (total, n, executed, label,
                 " ".join("0x%08X" % a for a, _, _ in members[:6])
                 + (" ..." if len(members) > 6 else "")))
        if args.show_skeleton and key[0] == "leaf":
            print("           skeleton: %s" % key[1][:72])
        if len(members) <= 6:
            for a, sz, _ in members[:6]:
                print("           0x%08X %5d B  hits=%d" % (a, sz, hits.get(a, 0)))
    print()
    print("families listed: %d  (min_members=%d, min_bytes=%d)"
          % (len(rows), args.min_members, args.min_bytes))
    return 0


if __name__ == "__main__":
    sys.exit(main())
