#!/usr/bin/env python3
"""prune_corpus.py - copy the complete rows of a VF3 replay corpus.

Some capsule extractions lost individual ``f_<entry>_<row>.in/out.bin``
shadows while the per-row sidecars (xfin/xfout/extra/gbr/bank/dev) survived.
The replay harness skips a row whose shadow is gone; that is honest, but a
strict promotion run then reports skips and refuses the entry.

This tool writes a derived corpus containing only rows whose entry and exit
RAM blobs are present and whose window descriptors agree.  It preserves the
original row ordinals when slicing the sidecars, so the derived corpus is a
faithful subset of the recorded evidence (no state is invented, no row is
rewritten).

  python tools/oracle/prune_corpus.py \
      extract/analysis/.../percentage_..._8c097abc_8c09863e \
      f_8c097abc \
      extract/analysis/.../percentage_..._8c097abc_8c09863e_complete
"""
from __future__ import annotations

import argparse
import json
import shutil
import struct
from pathlib import Path

SIDECAR_SIZES = {
    "xfin.bin": 64,
    "xfout.bin": 64,
    "extra.bin": 16,
    "gbr.bin": 12,
    "bank.bin": 68,
}

# The oracle records up to 1024 RAM pages per specimen (docs/re/oracle_device_reads.md).
# A corpus row carries the *merged* windows, so the row bound has to admit
# everything the oracle can legally hand us; 128 silently truncated the pool.
MAX_WINDOWS = 1024


def parse_row(line: str):
    t = line.split()
    if len(t) < 77:
        raise ValueError(f"short row ({len(t)} tokens)")
    entry = t[74]
    nwin = int(t[75])
    if nwin <= 0 or nwin > MAX_WINDOWS:
        raise ValueError("bad entry window count")
    j = 76
    ebase, elen = [], []
    for _ in range(nwin):
        ebase.append(int(t[j], 16)); elen.append(int(t[j + 1], 16)); j += 2
    if j >= len(t):
        raise ValueError("missing exit windows")
    xexit = t[j]; nexit = int(t[j + 1]); j += 2
    if nexit < 0 or nexit > MAX_WINDOWS:
        raise ValueError("bad exit window count")
    xbase, xlen = [], []
    for _ in range(nexit):
        if j + 1 >= len(t):
            raise ValueError("truncated exit windows")
        xbase.append(int(t[j], 16)); xlen.append(int(t[j + 1], 16)); j += 2
    if j != len(t):
        raise ValueError(f"trailing tokens ({len(t) - j})")
    return entry, ebase, elen, xexit, xbase, xlen


def row_complete(src: Path, row) -> tuple[bool, str]:
    entry, ebase, elen, xexit, xbase, xlen = row
    if entry == "-":
        return False, "no entry shadow"
    ep = src / entry
    if not ep.is_file():
        return False, f"missing {entry}"
    if ep.stat().st_size != sum(elen):
        return False, f"size mismatch {entry}"
    if xexit != "-" and xlen:
        if (ebase, elen) != (xbase, xlen):
            return False, "window descriptors differ"
        xp = src / xexit
        if not xp.is_file():
            return False, f"missing {xexit}"
        if xp.stat().st_size != sum(xlen):
            return False, f"size mismatch {xexit}"
    return True, ""


def copy_sidecar_rows(src: Path, dst: Path, stem: str, keep: list[int]):
    for suffix, size in SIDECAR_SIZES.items():
        sp = src / f"{stem}.{suffix}"
        if not sp.is_file():
            continue
        data = sp.read_bytes()
        if len(data) < size * (max(keep) + 1 if keep else 0):
            raise ValueError(f"{sp.name}: short for selected rows")
        out = bytearray()
        for row in keep:
            out += data[row * size:(row + 1) * size]
        (dst / f"{stem}.{suffix}").write_bytes(out)

    dp = src / f"{stem}.dev.bin"
    if dp.is_file():
        data = dp.read_bytes()
        off = 0
        records = []
        while off < len(data):
            if off + 4 > len(data):
                raise ValueError("truncated device tape")
            count = struct.unpack_from("<I", data, off)[0]
            end = off + 4 + count * 16
            if count > 16384 or end > len(data):
                raise ValueError("bad device tape record")
            records.append(data[off:end])
            off = end
        if len(records) < (max(keep) + 1 if keep else 0):
            raise ValueError("device tape shorter than case rows")
        (dst / f"{stem}.dev.bin").write_bytes(
            b"".join(records[row] for row in keep))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", type=Path)
    ap.add_argument("stem")
    ap.add_argument("dst", type=Path)
    ap.add_argument("--force", action="store_true")
    a = ap.parse_args()

    cases = a.src / f"{a.stem}.cases"
    lines = cases.read_text(encoding="ascii", errors="replace").splitlines()
    keep_lines, keep_rows, dropped = [], [], []
    for i, line in enumerate(lines):
        try:
            row = parse_row(line)
            ok, why = row_complete(a.src, row)
        except ValueError as e:
            ok, why = False, str(e)
        if ok:
            keep_lines.append(line)
            keep_rows.append(i)
        else:
            dropped.append({"row": i, "reason": why})

    if not keep_rows:
        raise SystemExit("no complete rows")
    if a.dst.exists() and any(a.dst.iterdir()) and not a.force:
        raise SystemExit(f"{a.dst} exists and is not empty (use --force)")
    a.dst.mkdir(parents=True, exist_ok=True)

    (a.dst / f"{a.stem}.cases").write_text("\n".join(keep_lines) + "\n",
                                           encoding="ascii")
    # Copy each referenced shadow once.
    copied = set()
    for line in keep_lines:
        entry, _, _, xexit, _, _ = parse_row(line)
        for name in (entry, xexit):
            if name != "-" and name not in copied:
                shutil.copyfile(a.src / name, a.dst / name)
                copied.add(name)
    copy_sidecar_rows(a.src, a.dst, a.stem, keep_rows)
    ops = a.src / f"{a.stem}.ops.json"
    if ops.is_file():
        shutil.copyfile(ops, a.dst / ops.name)

    manifest = {
        "source": str(a.src),
        "stem": a.stem,
        "rows_kept": len(keep_rows),
        "rows_dropped": len(dropped),
        "kept_ordinals": keep_rows,
        "dropped": dropped,
    }
    (a.dst / "prune_manifest.json").write_text(
        json.dumps(manifest, indent=1) + "\n", encoding="ascii")
    print(f"prune_corpus: {len(keep_rows)} kept, {len(dropped)} dropped -> {a.dst}")
    for d in dropped:
        print(f"  row {d['row']}: {d['reason']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
