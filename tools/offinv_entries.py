#!/usr/bin/env python3
"""offinv_entries.py - the function pointers the image holds that the Ghidra
inventory does not name.

The inventory (extract/analysis/funcs_1ST_READ.unsc.bin.csv) recognises a
function by its prologue, and it misses the ones whose first instruction is
not the `sts.l pr,@-r15` it looks for: a function that starts with
`mov.l r14,@-r15` and a compare, and whose real entry is two or four bytes
before the inventory's, is recorded at the wrong address.

The image still says where the function is: the function-pointer tables (the
vtables) hold the real entry.  A table entry that points into the code and is
*not* a baseline entry is therefore a function the inventory never named - and
one the router cannot dispatch to.

The tables are found by their shape: a run of consecutive 32-bit words that
all point into the code window.  A data constant that happens to look like a
pointer does not usually have a neighbour that looks like one too.

The report splits the entries in two classes:

* **prologue missed** - the entry is two or four bytes below a baseline entry,
  so the inventory simply started the function late;
* **off-inventory** - the entry is not near any baseline entry at all.

    python tools/offinv_entries.py
    python tools/offinv_entries.py --watch-out build/offinv_watch.txt
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
from sh4 import decode as sh4_decode  # noqa: E402

IMAGE = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
BASELINE = REPO / "extract" / "analysis" / "funcs_1ST_READ.unsc.bin.csv"

CODE_BASE = 0x0C010000


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--watch-out", type=Path,
                    help="write a translator watch file with the entries")
    ap.add_argument("--min-run", type=int, default=2,
                    help="how many consecutive pointers make a table")
    args = ap.parse_args()

    img = IMAGE.read_bytes()
    entries = {}
    with open(BASELINE, newline="") as fh:
        for row in csv.DictReader(fh):
            entries[int(row["entry"], 16) & 0x1FFFFFFF] = row

    words = []
    for off in range(0, len(img) - 3, 4):
        (value,) = struct.unpack_from("<I", img, off)
        words.append(value)

    def is_code(value: int) -> bool:
        return CODE_BASE <= value < CODE_BASE + len(img)

    # the tables: runs of consecutive code pointers
    tables: list[list[int]] = []
    run: list[int] = []
    for index, value in enumerate(words):
        if is_code(value):
            run.append(index)
        else:
            if len(run) >= args.min_run:
                tables.append(run)
            run = []
    if len(run) >= args.min_run:
        tables.append(run)

    found: dict[int, list[int]] = {}
    for table in tables:
        for index in table:
            target = words[index] & 0x1FFFFFFF
            if target in entries:
                continue
            found.setdefault(target, []).append(CODE_BASE + 4 * index)

    late = []
    away = []
    covered = set()
    ranges = REPO / "extract" / "analysis" / "function_body_ranges.csv"
    if ranges.exists():
        with open(ranges, newline="") as fh:
            for row in csv.DictReader(fh):
                covered.update(range(int(row["start"], 16) & 0x1FFFFFFF,
                                     int(row["end"], 16) & 0x1FFFFFFF, 2))

    def looks_like_entry(target: int) -> bool:
        """Does the first instruction look like the start of a function?

        The SH-4 prologue is a push of the callee-saved registers and of the
        link register.  A function that does not push them (a leaf) starts
        with its own work, so only the pushes are accepted here: the rest of
        the candidates are data that happens to look like a pointer.
        """
        offset = target - CODE_BASE
        if offset < 0 or offset + 2 > len(img):
            return False
        (word,) = struct.unpack_from("<H", img, offset)
        decoded = sh4_decode(word, target)
        if not decoded:
            return False
        text = " ".join(decoded)
        return ("@-r15" in text and text.startswith(("mov.l", "mov.w"))) or \
               text.startswith("sts.l")

    for target in sorted(found):
        if target in covered:
            continue          # inside a known body: not an entry, just data
        near = [e for e in entries if 0 < e - target <= 8]
        if near:
            late.append((target, near[0]))
        elif looks_like_entry(target):
            away.append((target, None))

    print(f"image: {len(img)} B, code window 0x{CODE_BASE:08x}.."
          f"0x{CODE_BASE + len(img):08x}")
    print(f"baseline entries: {len(entries)}")
    print(f"pointer tables found (runs of {args.min_run}+): {len(tables)}")
    print(f"function pointers the inventory does not name: {len(found)}")
    print(f"  of those outside every known body: "
          f"{len(late) + len(away)}")
    print(f"  prologue missed (2-8 bytes below a baseline entry): {len(late)}")
    print(f"  off-inventory (not near a baseline entry): {len(away)}")
    for target, near in late:
        print(f"  late   0x{target:08x}  baseline says 0x{near:08x}  "
              f"table site 0x{found[target][0]:08x}")
    for target, _ in away:
        print(f"  away   0x{target:08x}  table site 0x{found[target][0]:08x} "
              f"({len(found[target])} table(s))")

    if args.watch_out:
        lines = ["# The function pointers the image holds that the inventory does not name.",
                 "# Generated by tools/offinv_entries.py."]
        lines += [f"pc 0x{t:08x}" for t in sorted(found)]
        args.watch_out.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"wrote {args.watch_out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
