#!/usr/bin/env python3
"""Sweep unported baseline entries that already own a shadowed corpus and
report which ones replay cleanly through the current C routers.

`tools/replay_scan.py` covers every unported entry, which is slow on a cold
cache.  This driver is the same probe restricted to the largest N entries, so
the promotion queue can be re-ranked quickly after a port lands.

    python tools/sweep_top.py --top 60 --workers 8
"""
import argparse
import csv
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXE = ROOT / "build" / "vf3matrixfamily.exe"
LEDGER = ROOT / "docs" / "decomp_status.csv"
BASELINE = ROOT / "extract" / "analysis" / "funcs_1ST_READ.unsc.bin.csv"
ANALYSIS = ROOT / "extract" / "analysis"


def load_ledger():
    seen = set()
    with LEDGER.open(encoding="utf-8", errors="replace") as f:
        for row in csv.DictReader(f):
            e = (row.get("entry") or "").lower().replace("0x", "")
            if e:
                seen.add(e)
    return seen


def load_sizes():
    sizes = {}
    with BASELINE.open(encoding="utf-8", errors="replace") as f:
        for row in csv.DictReader(f):
            sizes[row["entry"].lower()] = int(row["size"])
    return sizes


def shadowed_corpora(entries):
    """entry -> [(corpus_dir, case_count)] for corpora with RAM shadows."""
    found = {}
    for root, _dirs, files in os.walk(ANALYSIS):
        names = set(files)
        for name in names:
            if not (name.startswith("f_") and name.endswith(".cases")):
                continue
            entry = name[2:-6]
            if entry not in entries:
                continue
            if not any(x.endswith(".in.bin") for x in names):
                continue
            cases = root + os.sep + name
            try:
                with open(cases, encoding="ascii", errors="ignore") as f:
                    n = sum(1 for _ in f)
            except OSError:
                continue
            found.setdefault(entry, []).append((Path(root), n))
    return found


def run_one(entry, corpus):
    env = dict(os.environ)
    env["VF3_STRICT_REPLAY"] = "1"
    cases = corpus / f"f_{entry}.cases"
    try:
        p = subprocess.run([str(EXE), f"0x{entry}", str(cases)], cwd=str(ROOT / "build"),
                           capture_output=True, text=True, env=env, timeout=900)
    except subprocess.TimeoutExpired:
        return 0, "timeout", 0
    tail = (p.stdout + p.stderr).strip().splitlines()
    summary = next((l for l in reversed(tail) if "cases match" in l), tail[-1] if tail else "")
    n = 0
    for tok in summary.replace("(", " ").replace(")", " ").split():
        if tok.isdigit():
            n = int(tok)
            break
    ok = 1 if (p.returncode == 0 and "PASS" in summary) else 0
    return ok, summary, n


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--workers", type=int, default=8)
    ap.add_argument("--out", default="extract/analysis/sweep_top.csv")
    a = ap.parse_args()
    if not EXE.is_file():
        raise SystemExit("build/vf3matrixfamily.exe missing - build first")
    ledger = load_ledger()
    sizes = load_sizes()
    unported = {e for e in sizes if e not in ledger}
    order = sorted(unported, key=lambda e: -sizes[e])[: a.top]
    corpora = shadowed_corpora(set(order))
    jobs = []
    for e in order:
        for c, n in corpora.get(e, []):
            jobs.append((e, c))
    print(f"sweep_top: {len(order)} entries, {len(jobs)} (entry,corpus) runs", flush=True)
    rows = {}
    results = {}
    with ThreadPoolExecutor(max_workers=a.workers) as pool:
        futs = {pool.submit(run_one, e, c): (e, c) for e, c in jobs}
        for fut, key in futs.items():
            ok, summary, n = fut.result()
            e = key[0]
            # corpus directory names repeat across parents, so key on the
            # repo-relative corpus path.
            ckey = key[1].relative_to(ROOT).as_posix()
            results[(e, ckey)] = (ok, summary, n)
            r = rows.setdefault(e, {"entry": f"0x{e}", "size": sizes[e], "corpora": 0,
                                    "pass_all": 1, "cases_total": 0, "first_fail": ""})
            r["corpora"] += 1
            r["cases_total"] += n
            if not ok:
                r["pass_all"] = 0
                if not r["first_fail"]:
                    r["first_fail"] = f"{key[1].name}: {summary[:120]}"
    out = sorted(rows.values(), key=lambda r: -r["size"])
    # A per-entry row that lists only the corpora that replayed clean, in the
    # semicolon form tools/promote_replay.py expects in its "corpus" column.
    promo = []
    for r in out:
        e = r["entry"][2:]
        rels = []
        for c, _n in corpora.get(e, []):
            ckey = c.relative_to(ROOT).as_posix()
            if results.get((e, ckey), (0, "", 0))[0]:
                rels.append(f"{ckey}/f_{e}.cases")
        if not rels:
            continue
        promo.append({"entry": r["entry"], "size": r["size"], "corpora": len(rels),
                      "pass_all": 1, "cases_total": r["cases_total"], "big_pending": 0,
                      "first_fail": "", "corpus": ";".join(rels)})
    with open(ROOT / a.out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "size", "corpora", "pass_all",
                                           "cases_total", "big_pending", "first_fail",
                                           "corpus"])
        w.writeheader()
        w.writerows(promo)
    print("\nper-corpus (clean = 0 skips, exit 0):")
    for e, c in sorted(jobs, key=lambda k: (-sizes[k[0]], k[1].as_posix())):
        ckey = c.relative_to(ROOT).as_posix()
        ok, summary, n = results[(e, ckey)]
        mark = "CLEAN" if ok else "    "
        print(f"  {mark} 0x{e} {sizes[e]:>5} B  {summary:<58}  {ckey}")
    print(f"\npromotable (>=1 clean corpus): {len(promo)} entries, "
          f"{sum(r['size'] for r in promo)} bytes -> {a.out}")
    for r in promo:
        print(f"  0x{r['entry'][2:]} {r['size']:>5} B  {r['corpora']} corpora  {r['cases_total']} cases")
    return 0


if __name__ == "__main__":
    sys.exit(main())
