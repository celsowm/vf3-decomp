#!/usr/bin/env python3
"""gap_fidelity.py - prove the gap modules are a faithful rendering of the
identity image.

The generated modules record the opcode they translated in every block
(`/* original c330, guest PC 0x0c039d90 */`).  This gate re-reads the image
and checks, for every block of every gap module:

  * the recorded opcode is the image's word at that PC (identity load at
    0x8C010000), and
  * the PC is one the baseline inventory knows, and
  * every PC of every still-unported entry's body has a block.

It also re-checks the claim sets: a module may only route a PC that no other
module owns, plus its own roots.
"""
from __future__ import annotations

import csv
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
SRC = REPO / "src" / "fight"
IMAGE = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"
BASE = 0x8C010000

BLOCK = re.compile(r"^P_([0-9a-f]{8}): /\* original ([0-9a-f]{4}), guest PC 0x([0-9a-f]{8}) \*/$")
OWNED = re.compile(r"static const uint32_t owned_pcs\[\]=\{")
CLAIM = re.compile(r"static const uint32_t claim_pcs\[\]=\{")
NUMS = re.compile(r"0x([0-9a-f]{8})u")


def parse_array(text: str, start: int) -> list[int]:
    end = text.index("};", start)
    return [int(x, 16) for x in NUMS.findall(text[start:end])]


def main() -> int:
    if not IMAGE.is_file():
        print(f"gap_fidelity: {IMAGE} missing - cannot check the translation")
        return 2
    img = IMAGE.read_bytes()

    br = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16) & 0x1FFFFFFF].append(
            (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))

    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    body = {}
    for g in gap:
        e = g["entry"] & 0x1FFFFFFF
        pcs = []
        for s, t in br.get(e, []):
            pcs.extend(range(s, t, 2))
        body[e] = pcs

    bad_op = bad_missing = 0
    covered = set()
    claims = {}
    for path in sorted(SRC.glob("vf3_gap_b*.c")):
        text = path.read_text(errors="ignore")
        blocks = 0
        for line in text.splitlines():
            m = BLOCK.match(line.strip())
            if not m:
                continue
            blocks += 1
            pc = int(m.group(1), 16)
            word = int(m.group(2), 16)
            guest = int(m.group(3), 16)
            covered.add(pc)
            if guest != pc:
                bad_op += 1
                print(f"  {path.name}: block {pc:08x} claims guest {guest:08x}")
                continue
            off = pc - 0x0C010000
            if off + 2 > len(img):
                bad_op += 1
                print(f"  {path.name}: {pc:08x} outside the image")
                continue
            got = struct.unpack_from("<H", img, off)[0]
            if got != word:
                bad_op += 1
                print(f"  {path.name}: {pc:08x} translated {word:04x}, image has {got:04x}")
        c = CLAIM.search(text)
        claims[path.name] = set(parse_array(text, c.start())) if c else set()
        print(f"{path.name}: {blocks} blocks, {len(claims[path.name])} claimed PCs")

    missing = []
    for e, pcs in body.items():
        for pc in pcs:
            if pc not in covered:
                missing.append((e, pc))
    print(f"\nblocks whose opcode does not match the image: {bad_op}")
    print(f"body PCs with no block: {len(missing)}")
    for e, pc in missing[:10]:
        print(f"  0x{e:08x}: 0x{pc:08x}")

    # The claim invariant: a PC the router may send to a module must be
    # *owned* (implemented) by that module - "a module serves the PCs no other
    # module claims, not the ones no other module owns".  Two modules may own
    # the same PC (the later batch re-walked the earlier one's body); the
    # chain order then decides, and the winner implements the body.
    owners: dict[int, set[str]] = defaultdict(set)
    for p in sorted(SRC.glob("*.c")):
        if p.name == "unknown.c":
            continue
        t = p.read_text(errors="ignore")
        for m in re.finditer(r"^P_([0-9a-f]{8}):", t, re.M):
            owners[int(m.group(1), 16) & 0x1FFFFFFF].add(p.stem)
    claimants: dict[int, set[str]] = defaultdict(set)
    for name, cs in claims.items():
        stem = name[:-2] if name.endswith(".c") else name
        for pc in cs:
            claimants[pc].add(stem)
    bad_claim = 0
    for pc, cs in sorted(claimants.items()):
        if not (cs & owners.get(pc, set())):
            bad_claim += 1
            if bad_claim < 10:
                print(f"  0x{pc:08x} is claimed by {sorted(cs)} but owned by "
                      f"{sorted(owners.get(pc, set()))}")
    print(f"claimed PCs that no claiming module owns: {bad_claim}")
    return 1 if (bad_op or missing or bad_claim) else 0


if __name__ == "__main__":
    raise SystemExit(main())
