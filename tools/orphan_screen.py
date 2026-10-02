#!/usr/bin/env python3
"""Screen the orphan baseline interval (no static path from any executed fn).

reach_static.py marks some uncovered bodies as orphans: no code-flow path from
any executed function reaches their entry. Orphans are a mix of (a) real code
behind dispatch/re-entries the tracing never opened, and (b) Ghidra seed
phantoms - literal-pool data, alignment padding, or dead locals misidentified
as code. This tool disassembles each orphan interval and scores how
`function-like` it is, so a port campaign can skip the phantoms and only spend
effort on real bodies that a scenario might yet reach.

Scores (coarse, one flag each):
  save_pr       body starts by sts.l pr,@-r15 (0x4f22)  -> real callee prologue
  has_rts       an rts (0x000b) appears in the interval  -> terminates as code
  calls         at least one jsr/bsr (0x4/0xb) present    -> does real work
  slop          >40% of words are literal-pool padding    -> data, not code

Usage:
    python tools/orphan_screen.py [--top 40]
Requires the sh4 decoder (run from tools/ or add tools to PYTHONPATH).
"""
from __future__ import annotations

import argparse
import collections
import csv
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
A = lambda *p: os.path.join(ROOT, "extract", "analysis", *p)
sys.path.insert(0, os.path.join(ROOT, "tools"))
import sh4  # noqa: E402

FUNCS = A("funcs_1ST_READ.unsc.bin.csv")
LEDGER = os.path.join(ROOT, "docs", "decomp_status.csv")
MERGED = A("hits_merged.csv")
XREFS = A("xrefs_1ST_READ.unsc.bin.csv")
RESOLVED = A("sh4_resolved.csv")
IMAGE = os.path.join(ROOT, "extract", "exe", "1ST_READ.unsc.bin")
BASE = 0x8C010000

FLOW_TYPES = {
    "UNCONDITIONAL_CALL", "CONDITIONAL_CALL", "COMPUTED_CALL",
    "UNCONDITIONAL_JUMP", "CONDITIONAL_JUMP", "COMPUTED_JUMP",
}


def hexint(t):
    return int(t.strip(), 16)


def load_baseline():
    with open(FUNCS, newline="") as fh:
        rows = [(hexint(r["entry"]), int(r["size"])) for r in csv.DictReader(fh)]
    rows.sort()
    return rows


def load_ledger():
    out = set()
    with open(LEDGER, newline="") as fh:
        for r in csv.DictReader(fh):
            e = (r.get("entry") or "").strip()
            if e:
                out.add(hexint(e))
    return out


def load_hits():
    if not os.path.exists(MERGED):
        return {}
    out = {}
    with open(MERGED, newline="") as fh:
        for r in csv.DictReader(fh):
            out[hexint(r["entry"])] = int(r["hits"] or 0)
    return out


def compute_orphans(entry_roots: str | None = None) -> set:
    """Uncovered bodies with no static path from the executed roots — or,
    with entry_roots, no static path from the given address roots (used to
    screen against true-image reachability from the program entrypoint)."""
    baseline = load_baseline()
    covered = load_ledger()
    hits = load_hits()
    sizes = dict(baseline)
    edges = collections.defaultdict(set)
    with open(XREFS, newline="") as fh:
        for r in csv.DictReader(fh):
            if r["type"] in FLOW_TYPES:
                edges[hexint(r["from"])].add(hexint(r["to"]))
    with open(RESOLVED, newline="") as fh:
        for r in csv.DictReader(fh):
            if r["class"] not in ("STATIC", "FIXED"):
                continue
            tgt = (r["target"] or "").strip()
            if not tgt:
                continue
            try:
                edges[hexint(r["site"])].add(int(tgt.split("@")[-1], 16))
            except ValueError:
                continue

    owner = {}
    for a, sz in baseline:
        for off in range(0, max(sz, 1) * 2, 2):
            owner[a + off] = a
        owner[a] = a

    import collections as C
    if entry_roots:
        seed_fns = set()
        seed_addrs = set()
        for tok in entry_roots.split(","):
            tok = tok.strip()
            if tok:
                seed_addrs.add(int(tok, 16))
    else:
        seed_fns = {a for a, _ in baseline if hits.get(a, 0) > 0}
        seed_addrs = set()
        for a in seed_fns:
            for off in range(0, max(sizes.get(a, 1), 1) * 2, 2):
                seed_addrs.add(a + off)
    seen_fns = {a for a in seed_fns if a in sizes}
    seen_addrs = set(seed_addrs)
    q = C.deque()
    q.extend(sorted(seen_addrs))
    while q:
        pc = q.popleft()
        f = owner.get(pc)
        if f is not None and f not in seen_fns:
            seen_fns.add(f)
            for off in range(0, max(sizes.get(f, 1), 1) * 2, 2):
                if f + off not in seen_addrs:
                    seen_addrs.add(f + off)
                    q.append(f + off)
        for nxt in edges.get(pc, ()):
            if nxt not in seen_addrs:
                seen_addrs.add(nxt)
                q.append(nxt)
    if entry_roots:
        # entry mode: report REACHABLE functions (caller computes the rest)
        return {a for a, _ in baseline if a in seen_fns}
    return {a for a, _ in baseline if a not in covered and a not in seen_fns}


def score(words: list[int]) -> dict:
    s = {"save_pr": False, "has_rts": False, "calls": 0, "branches": 0,
         "slop": False, "words": len(words)}
    if not words:
        return s
    if words[0] == 0x4F22:
        s["save_pr"] = True
    for w in words:
        if w == 0x000B:
            s["has_rts"] = True
        if (w & 0xF000) == 0xB000:            # bsr @literal
            s["calls"] += 1
        if (w & 0xF0FF) == 0x400B:            # jsr @Rm
            s["calls"] += 1
        if (w & 0xF0FF) == 0x0003:            # bsrf Rm
            s["calls"] += 1
        if (w & 0xF000) == 0xA000:            # bra
            s["branches"] += 1
        if (w & 0xF0FF) == 0x402B:            # jmp @Rm
            s["branches"] += 1
        if (w & 0xFF00) in (0x8F00, 0x8B00):  # bt/s, bf/s
            s["branches"] += 1
    # slop: no control flow at all is suspicious for a body >16 bytes
    if len(words) > 8 and not s["has_rts"] and not s["calls"] and not s["branches"]:
        s["slop"] = True
    return s


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--entry-roots",
                    default="0x8C010000,0x8C020000,0x8C09574E",
                    help="address roots for the true-image entry screen "
                         "(boot copy loop, CRT0, startup)")
    ap.add_argument("--out", default=A("phantom_screen.csv"),
                    help="write the per-orphan classification CSV")
    args = ap.parse_args()

    orphans = compute_orphans()
    entry_live = compute_orphans(entry_roots=args.entry_roots) if args.entry_roots else set()
    baseline = dict(load_baseline())
    hits = load_hits()
    image = open(IMAGE, "rb").read()

    rows = []
    for a in orphans:
        size = baseline[a]
        if size <= 0:
            continue
        off = a - BASE
        if off < 0 or off + size * 2 > len(image):
            continue
        words = [int.from_bytes(image[off + i:off + i + 2], "big")
                 for i in range(0, size * 2, 2)]
        sc = score(words)
        h = hits.get(a, 0)
        if not sc["save_pr"] and not sc["has_rts"] and sc["calls"] == 0:
            kind = "phantom"
        elif a in entry_live:
            kind = "entry-live"      # real code; a scenario could reach it
        else:
            kind = "fn-like-orphan"  # dispatch/table-only reachability
        rows.append((a, size, sc, h, kind))

    ph = [r for r in rows if r[4] == "phantom"]
    fl = [r for r in rows if r[4] != "phantom"]
    el = [r for r in rows if r[4] == "entry-live"]
    fo = [r for r in rows if r[4] == "fn-like-orphan"]

    print("orphan bodies          : %d / %d B" % (len(rows), sum(r[1] for r in rows)))
    print("  phantom (skip)       : %d / %d B" % (len(ph), sum(r[1] for r in ph)))
    print("  entry-live           : %d / %d B" % (len(el), sum(r[1] for r in el)))
    print("  fn-like orphan       : %d / %d B" % (len(fo), sum(r[1] for r in fo)))
    print()

    if args.out:
        with open(args.out, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["entry", "size", "hits", "class",
                       "save_pr", "has_rts", "calls", "branches", "slop"])
            for a, size, sc, h, kind in sorted(rows):
                w.writerow(["0x%08X" % a, size, h, kind,
                            int(sc["save_pr"]), int(sc["has_rts"]),
                            sc["calls"], sc["branches"], int(sc["slop"])])
        print("wrote %s" % args.out)
        print()

    # largest function-like orphans (real code worth a scenario to reach)
    print("== largest function-like orphans (reach candidates) ==")
    fl.sort(key=lambda r: -r[1])
    for a, size, sc, h, kind in fl[: args.top]:
        flags = [kind]
        for k, v in sc.items():
            if k == "words":
                continue
            if isinstance(v, bool) and v:
                flags.append(k)
            elif isinstance(v, int) and v:
                flags.append("%s=%d" % (k, v))
        print("  %08X %6d B hits=%5d %s" % (a, size, h, " ".join(flags)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
