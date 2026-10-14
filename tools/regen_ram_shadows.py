#!/usr/bin/env python3
"""regen_ram_shadows.py — restore missing .in.bin/.out.bin RAM shadows.

Some capture corpora kept their .cases sidecars but lost the per-case RAM
shadow files (<stem>_<i>.in.bin / .out.bin), so vf3h_mem_load skips every
case ("no RAM cases") and the entry can never be replay-bound. The source
capsule recorded in batch_manifest.json still carries each specimen's RAM
pages, so the shadows are exactly regenerable.

Safety contract:
  * regenerate into a temp dir via tools/oracle/capsules.py convert(entries=...)
    (deterministic: same capsule bytes -> same corpus bytes);
  * require the regenerated <stem>.cases to be BYTE-IDENTICAL to the corpus's
    existing .cases before accepting any shadow (else abort that entry — the
    capsule/tool version disagrees with the shipped corpus);
  * never overwrite an existing shadow — only fill gaps;
  * verify-then-copy; temp dir removed afterwards.

Usage:
  python tools/regen_ram_shadows.py extract/analysis/tenpp_prologue_clean_cases \\
      [--capsule PATH ...] [--dry-run] [--keep-temp]

Without --capsule the paths are read from the corpus batch_manifest.json.
"""
from __future__ import annotations

import argparse
import json
import shutil
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "oracle"))
from capsules import convert  # noqa: E402

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"


def missing_stems(corpus: Path) -> list[str]:
    stems = []
    for cases in sorted(corpus.glob("f_*.cases")):
        stem = cases.stem
        if not (corpus / f"{stem}_0.in.bin").exists():
            stems.append(stem)
    return stems


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("corpus", type=Path, nargs="?",
                    help="corpus dir (omit when using --all)")
    ap.add_argument("--capsule", action="append", default=[], type=Path)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--keep-temp", action="store_true")
    ap.add_argument("--all", action="store_true", dest="all_corpora",
                    help="process every *cases dir that has missing shadows "
                         "and a readable batch_manifest.json capsule")
    a = ap.parse_args()
    if not a.all_corpora and a.corpus is None:
        ap.error("corpus is required unless --all is given")

    if a.all_corpora:
        jobs = [d for d in sorted(AN.glob("*cases"))
                if d.is_dir() and (d / "batch_manifest.json").exists()
                and missing_stems(d)]
        print(f"--all: {len(jobs)} corpora with missing shadows")
        rc = 0
        for d in jobs:
            try:
                rc |= main_one(d, [], a.dry_run, a.keep_temp)
            except SystemExit as exc:
                print(f"SKIP {d.name}: {exc}")
                rc = 1
        return rc

    return main_one(a.corpus, a.capsule, a.dry_run, a.keep_temp)


def main_one(corpus_arg, capsule_args, dry_run, keep_temp) -> int:
    a = argparse.Namespace(corpus=corpus_arg, capsule=list(capsule_args),
                           dry_run=dry_run, keep_temp=keep_temp)

    corpus = a.corpus.resolve()
    if not corpus.is_dir():
        raise SystemExit(f"not a corpus dir: {corpus}")
    caps = [p.resolve() for p in a.capsule]
    if not caps:
        man = json.loads((corpus / "batch_manifest.json").read_text())
        caps = [Path(r["capsule"]) for r in man["runs"]]
    for p in caps:
        if not p.is_file():
            raise SystemExit(f"capsule missing: {p}")

    stems = missing_stems(corpus)
    if not stems:
        print(f"{corpus.name}: no missing RAM shadows")
        return 0
    want = {int(s.split("_")[1], 16) for s in stems}
    print(f"{corpus.name}: {len(stems)} entries missing shadows; capsules: "
          f"{[p.name for p in caps]}")
    if a.dry_run:
        print("\n".join(stems))
        return 0

    tmp = Path(tempfile.mkdtemp(prefix=".regen_", dir=corpus.parent))
    try:
        convert([str(p) for p in caps], str(tmp), entries=want)
        ok, bad, absent = [], [], []
        for s in stems:
            gen, have = tmp / f"{s}.cases", corpus / f"{s}.cases"
            if not gen.exists():
                absent.append(s)
                continue
            if gen.read_bytes() != have.read_bytes():
                bad.append(s)
                continue
            ok.append(s)
        if absent:
            print(f"ABORT {len(absent)} entries absent after regen: {absent[:8]}")
        if bad:
            print(f"ABORT {len(bad)} .cases mismatch (capsule/tool drift): {bad[:8]}")
        if not ok:
            raise SystemExit("no entry passed byte-identity — refusing to write")
        copied = 0
        for s in ok:
            for gen in sorted(tmp.glob(f"{s}_*.bin")):
                name = gen.name
                if not (name.endswith(".in.bin") or name.endswith(".out.bin")):
                    continue
                dest = corpus / name
                if not dest.exists():
                    shutil.copy2(gen, dest)
                    copied += 1
        print(f"restored {copied} shadow files for {len(ok)} entries "
              f"({len(bad)} mismatched, {len(absent)} absent)")
        return 0 if not bad and not absent else 1
    finally:
        if a.keep_temp:
            print(f"temp kept: {tmp}")
        else:
            shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    raise SystemExit(main())
