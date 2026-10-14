#!/usr/bin/env python3
"""promote_replay.py — write bindings + ledger rows for replay-clean entries.

Consumes extract/analysis/replay_scan.csv (pass_all=1), then for each entry:

  1. pick its corpora (shadowed only), re-run strict vf3matrixfamily on the
     chosen binding corpus — promotion is refused if that single re-run fails;
  2. resolve the owning router source (owned_pcs scan of src/fight routers);
  3. append tools/golden_bindings.json  {pc: {golden,port,source,strict,test}}
      and docs/decomp_status.csv       {entry,status,file,size,method,oracle}
     — exactly the shape used by the fourteenth coverage batch.

Nothing is written for entries that fail the re-run. Idempotent: entries
already present in the binding file or the ledger are skipped.

  python tools/promote_replay.py [--scan ...] [--dry-run] [--limit N]
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
EXE = REPO / "build" / "vf3matrixfamily.exe"
BINDINGS = REPO / "tools" / "golden_bindings.json"
LEDGER = REPO / "docs" / "decomp_status.csv"
FIELDS = ["entry", "status", "file", "size", "method", "oracle"]

sys.path.insert(0, str(Path(__file__).resolve().parent))
from coverage70_audit import router_owned_pcs  # noqa: E402


def corpora_for(entry: str) -> list[Path]:
    out = []
    for d in sorted(AN.glob("*cases")):
        if (d / f"f_{entry}.cases").exists() and (d / f"f_{entry}_0.in.bin").exists():
            out.append(d)
    return out


def strict_run(entry: str, corpus: Path) -> tuple[bool, str]:
    env = dict(os.environ, VF3_STRICT_REPLAY="1")
    p = subprocess.run(
        [str(EXE), f"0x{entry}", str(corpus / f"f_{entry}.cases")],
        capture_output=True, text=True, cwd=REPO, timeout=300, env=env)
    lines = ((p.stdout or "") + (p.stderr or "")).strip().splitlines()
    return p.returncode == 0, (lines[-1] if lines else "")


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--scan", default="extract/analysis/replay_scan.csv")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()

    rows = [r for r in csv.DictReader(open(REPO / a.scan, newline=""))
            if r["pass_all"] == "1" and r.get("big_pending", "0") == "0"]
    rows.sort(key=lambda r: -int(r["size"]))
    if a.limit:
        rows = rows[:a.limit]
    bindings = json.loads(BINDINGS.read_text(encoding="utf-8"))
    ledger = list(csv.DictReader(open(LEDGER, newline="")))
    ledger_ported = {r["entry"].lower()
                     for r in ledger if r.get("status", "").startswith("ported")}
    sizes = {r["entry"].lower().replace("0x", ""): int(r["size"])
             for r in csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv",
                                          newline=""))}
    owned = router_owned_pcs()

    promoted, skipped, failed = [], [], []
    for r in rows:
        e = r["entry"].lower().replace("0x", "")
        pc = f"0x{e}"
        if pc in bindings or pc in ledger_ported:
            skipped.append(pc)
            continue
        corpora = corpora_for(e)
        if not corpora:
            failed.append((pc, "no shadowed corpus"))
            continue
        binding_corpus = corpora[0]
        ok, tail = strict_run(e, binding_corpus)
        if not ok:
            failed.append((pc, tail[:80]))
            continue
        router = owned.get(int(pc, 16))
        if not router:
            failed.append((pc, "no router ownership"))
            continue
        all_tails = []
        for c in corpora:            # evidence across every corpus
            okc, tailc = strict_run(e, c)
            if not okc:
                failed.append((pc, f"{c.name}: {tailc[:60]}"))
                break
            all_tails.append(f"{c.name}: {tailc}")
        else:
            rel = binding_corpus.relative_to(REPO).as_posix()
            bindings[pc] = {
                "golden": f"{rel}/f_{e}.cases",
                "port": f"src/fight/{router}",
                "source": (f"Batch replay promotion (replay_scan): strict "
                           f"vf3matrixfamily replay PASS in {len(corpora)} "
                           f"corpora, {r['cases_total']} cases; RAM shadows "
                           f"byte-identical regenerations of the recorded "
                           f"capsule (tools/regen_ram_shadows.py)"),
                "strict": True,
                "test": f"build/vf3matrixfamily.exe {pc}"}
            ledger.append(dict(entry=pc, status="ported",
                               file=f"src/fight/{router}",
                               size=str(sizes.get(e, r["size"])),
                               method="capture-driven port (batch replay_scan)",
                               oracle="; ".join(all_tails)))
            promoted.append((pc, int(r["size"])))

    print(f"promote_replay: promoted={len(promoted)} "
          f"({sum(s for _, s in promoted)} B) skipped={len(skipped)} "
          f"failed={len(failed)}")
    for pc, why in failed[:15]:
        print(f"  FAIL {pc}: {why}")
    if a.dry_run or not promoted:
        return 0
    BINDINGS.write_text(json.dumps(bindings, indent=1) + "\n",
                        encoding="utf-8")
    # Sanitize ledger: only keep expected fields
    clean = [{k: r.get(k, "") for k in FIELDS} for r in ledger]
    with open(LEDGER, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=FIELDS)
        w.writeheader()
        w.writerows(sorted(clean, key=lambda r: r["entry"].lower()))
    print("written: golden_bindings.json, docs/decomp_status.csv")
    return 0


if __name__ == "__main__":
    sys.exit(main())
