#!/usr/bin/env python3
"""replay_scan.py — batch strict-replay probe for unported entries.

Runs build/vf3matrixfamily.exe (strict) for every unported baseline entry
against every corpus that holds <stem>.cases + RAM shadows, and reports which
entries already replay cleanly through the C routers — the promotion bench.

  python tools/replay_scan.py [--out extract/analysis/replay_scan.csv]
                              [--entry 0x8c035da6] [--verbose]

Output rows: entry,size,corpora,pass_all,cases_total,first_fail
  pass_all=1  -> every (entry, corpus) invocation exited 0 under
                 VF3_STRICT_REPLAY=1 with zero skips; ledger-promotable
                 subject to the batch gates (see docs/re/*_coverage_batch.md).
Entries whose corpora still lack RAM shadows are listed as shadow-missing
(restorable via tools/regen_ram_shadows.py when the capsule survives).
"""
from __future__ import annotations

import argparse
import csv
import os
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
EXE = REPO / "build" / "vf3matrixfamily.exe"


def load_ledger_and_sizes():
    ported, size = set(), {}
    for r in csv.DictReader(open(REPO / "docs" / "decomp_status.csv", newline="")):
        if r.get("status", "").startswith("ported"):
            ported.add(r["entry"].lower().replace("0x", ""))
    for r in csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="")):
        size[r["entry"].lower().replace("0x", "")] = int(r["size"])
    return ported, size


def corpora_map() -> dict[str, list[tuple[Path, bool]]]:
    """entry hex -> [(corpus dir, has_shadows)] over every captured corpus.

    Corpus directories are not all named ``*cases`` (e.g. ``coverage_65_*``
    and ``advance_*_dev_fp`` hold real, shadowed corpora), so discover by
    the ``f_<pc>.cases`` sidecar and use its parent directory.
    """
    out: dict[str, list[tuple[Path, bool]]] = {}
    for c in sorted(AN.rglob("f_*.cases")):
        d = c.parent
        e = c.stem[2:]
        shadowed = (d / f"{c.stem}_0.in.bin").exists()
        out.setdefault(e, []).append((d, shadowed))
    return out


def run_one(entry: str, corpus: Path) -> tuple[bool, str, int]:
    """(pass, tail-message, case-count) for one strict replay invocation."""
    env = dict(os.environ, VF3_STRICT_REPLAY="1")
    cases = corpus / f"f_{entry}.cases"
    p = subprocess.run([str(EXE), f"0x{entry}", str(cases)],
                       capture_output=True, text=True, cwd=REPO,
                       timeout=300, env=env)
    lines = ((p.stdout or "") + (p.stderr or "")).strip().splitlines()
    tail = lines[-1] if lines else ""
    n = 0
    if "cases match" in tail:
        try:
            n = int(tail.split(":")[1].split("/")[1].split()[0])
        except (IndexError, ValueError):
            pass
    return p.returncode == 0, tail, n


def run_slots(jobs, workers=4):
    """Run (entry, corpus, ncases) slots with a small thread pool."""
    from concurrent.futures import ThreadPoolExecutor
    results = {}
    done = [0]
    def one(slot):
        e, corpus, _n = slot
        ok, tail, n = run_one(e, corpus)
        done[0] += 1
        if done[0] % 50 == 0:
            print(f"  ... {done[0]}/{len(jobs)} runs", flush=True)
        return (e, corpus.name), (ok, tail, n)
    with ThreadPoolExecutor(max_workers=workers) as ex:
        for key, val in ex.map(one, jobs):
            results[key] = val
    return results


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default="extract/analysis/replay_scan.csv")
    ap.add_argument("--entry", help="scan a single entry (debug)")
    ap.add_argument("--deep", action="store_true",
                    help="also run big (>400-case) corpora for entries that "
                         "passed every small corpus")
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args()
    if not EXE.is_file():
        raise SystemExit("build/vf3matrixfamily.exe missing — build first")

    ported, size = load_ledger_and_sizes()
    cmap = corpora_map()
    targets = ([a.entry.lower().replace("0x", "")] if a.entry
               else sorted(e for e in cmap if e not in ported))

    # Precompute slot case counts; phase 1 skips huge corpora (documented
    # slow zone: 400+ cases * RAM shadows can take a minute per run).
    slots = {}
    shadow_missing = []
    for e in targets:
        s = []
        for corpus, shadowed in cmap[e]:
            if not shadowed:
                continue
            n = sum(1 for _ in open(corpus / f"f_{e}.cases", encoding="ascii",
                                    errors="ignore"))
            s.append((corpus, n))
        if not s:
            shadow_missing.append(e)
            continue
        slots[e] = s

    jobs, big = [], {}
    for e, s in slots.items():
        big[e] = [(c, n) for c, n in s if n > 400]
        jobs += [(e, c, n) for c, n in s if n <= 400]
    print(f"replay_scan: {len(slots)} entries, phase-1 runs={len(jobs)} "
          f"(big-corpus runs deferred: {sum(len(v) for v in big.values())})",
          flush=True)
    results = run_slots(jobs, a.workers)

    rows, promotable, pending_deep = [], [], []
    for e in sorted(slots):
        small = [(c, n) for c, n in slots[e] if n <= 400]
        ok_all, total, first_fail = True, 0, ""
        for c, _n in small:
            ok, tail, n = results[(e, c.name)]
            total += n
            if not ok:
                ok_all = False
                first_fail = first_fail or f"{c.name}: {tail[:90]}"
                if a.verbose:
                    print(f"FAIL 0x{e} {c.name}: {tail}")
            elif a.verbose:
                print(f"PASS 0x{e} {c.name}: {tail}")
        big_pending = len(big[e])
        if ok_all and big_pending and a.deep:
            for c, _n in big[e]:
                ok, tail, n = run_one(e, c)
                total += n
                big_pending -= 1
                if not ok:
                    ok_all = False
                    first_fail = first_fail or f"{c.name}: {tail[:90]}"
                    break
        rows.append(dict(entry=f"0x{e}", size=size.get(e, 0),
                         corpora=len(slots[e]), pass_all=int(ok_all),
                         cases_total=total, big_pending=big_pending,
                         first_fail=first_fail))
        if ok_all and not big_pending:
            promotable.append((e, size.get(e, 0), total))
        elif ok_all:
            pending_deep.append((e, size.get(e, 0)))

    with open(a.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "size", "corpora",
                                          "pass_all", "cases_total",
                                          "big_pending", "first_fail"])
        w.writeheader()
        w.writerows(rows)
    ok_bytes = sum(s for _, s, _ in promotable)
    deep_bytes = sum(s for _, s in pending_deep)
    print(f"replay_scan: {len(rows)} unported entries probed -> {a.out}")
    print(f"  pass_all (no big corpora): {len(promotable)} entries / "
          f"{ok_bytes} B (gap 21725 B)")
    print(f"  pass small, big pending:   {len(pending_deep)} entries / "
          f"{deep_bytes} B (run --deep)")
    print(f"  shadow-missing (restore first): {len(shadow_missing)}")
    for e, s, n in sorted(promotable, key=lambda t: -t[1])[:20]:
        print(f"    0x{e} {s:>5}B cases={n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
