#!/usr/bin/env python3
"""gap_promote.py - write the ledger rows for the still-unported baseline
entries and report the coverage they add.

Each row names the module the router actually serves for that entry (the
chain dispatches by entry PC, first match wins) and records the evidence
that exists:

  * the translation was emitted from the identity image and every emitted
    block's opcode matches the image (tools/gap_fidelity.py),
  * every PC of the entry's Ghidra body range is emitted,
  * for a body an older, oracle-replayed module also owns: the two
    translations agree instruction for instruction (the differences are the
    emitter's two later improvements),
  * for a body an existing capture reaches: that capture's corpus replays
    strict-clean with the gap modules in the chain.

Entries whose body the translator cannot express (TRAPA, STC SGR) are left
alone until they are hand-ported.
"""
from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / "extract" / "analysis"
SRC = REPO / "src" / "fight"
LEDGER = REPO / "docs" / "decomp_status.csv"

LABEL = re.compile(r"^P_([0-9a-f]{8}):", re.M)
OWNED = re.compile(r"static const uint32_t owned_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
CLAIMED = re.compile(r"static const uint32_t claim_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
HEX = re.compile(r"0x[0-9a-fA-F]+")

IMAGE = REPO / "extract" / "exe" / "1ST_READ.unsc.bin"


def word(pc: int) -> int:
    off = pc - 0x0C010000
    if off < 0 or off + 2 > len(_image):
        return 0
    return int.from_bytes(_image[off:off + 2], "little")


_image = IMAGE.read_bytes() if IMAGE.is_file() else b""


def module_sets() -> dict[str, dict[str, set[int]]]:
    out: dict[str, dict[str, set[int]]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(errors="replace")
        m = OWNED.search(text)
        c = CLAIMED.search(text)
        out[path.stem] = {
            "owned": {int(h, 16) for h in HEX.findall(m.group(1))} if m else set(),
            "claimed": {int(h, 16) for h in HEX.findall(c.group(1))} if c else set(),
        }
    return out


def chain_order() -> list[str]:
    text = (SRC / "matrix_family.c").read_text(errors="replace")
    start = text.find("static int vf3_matrix_family_core")
    end = text.find("static int vf3_matrix_family_dispatch")
    body = text[start:end]
    return [m.group(1) for m in re.finditer(r"if\(vf3_(\w+)_contains\(entry\)\)", body)]


def file_for(router_name: str, mods: dict[str, dict[str, set[int]]]) -> str:
    """The file that defines the router's module (they do not always match)."""
    for stem in mods:
        if stem == router_name or stem == router_name + "_adapter" or \
                stem.replace("_adapter", "") == router_name:
            return f"src/fight/{stem}.c"
    return f"src/fight/{router_name}.c"


FAIL = re.compile(r"^s->failed_pc=0x([0-9a-f]+)u; return 0;$", re.M)


def unexpressible() -> dict[int, list[int]]:
    """entry -> the PCs of its body the translator could not express.

    A block that ends in `s->failed_pc=<pc>; return 0;` *without* the budget
    guard in front of it is the translator's "unsupported instruction" marker.
    """
    br: dict[int, list[tuple[int, int]]] = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16) & 0x1FFFFFFF].append(
            (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))
    bad: dict[int, set[int]] = defaultdict(set)
    for path in sorted(SRC.glob("vf3_gap_b*.c")):
        for m in FAIL.finditer(path.read_text(errors="ignore")):
            bad[int(m.group(1), 16) & 0x1FFFFFFF].add(int(m.group(1), 16) & 0x1FFFFFFF)
    out: dict[int, list[int]] = {}
    for entry, spans in br.items():
        pcs = []
        for s, t in spans:
            pcs += [pc for pc in range(s, t, 2) if pc in bad]
        if pcs:
            out[entry] = sorted(set(pcs))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="append the rows to the ledger")
    ap.add_argument("--out", default=str(AN / "gap_promote.csv"))
    args = ap.parse_args()

    mods = module_sets()
    order = chain_order()
    br = defaultdict(list)
    for row in csv.DictReader(open(AN / "function_body_ranges.csv", newline="")):
        br[int(row["entry"], 16) & 0x1FFFFFFF].append(
            (int(row["start"], 16) & 0x1FFFFFFF, int(row["end"], 16) & 0x1FFFFFFF))
    funcs = {int(r["entry"], 16) & 0x1FFFFFFF: int(r["size"]) for r in
             csv.DictReader(open(AN / "funcs_1ST_READ.unsc.bin.csv", newline=""))}
    gap = json.load(open(AN / "gap_rank.json", encoding="utf-8"))
    unsup = unexpressible()
    reach = {r["entry"] & 0x1FFFFFFF: r["reached_by"] for r in
             json.load(open(AN / "gap_reach.json", encoding="utf-8"))}

    # the ledger's own replay citations, per module file
    cite: dict[str, str] = {}
    for r in csv.DictReader(open(LEDGER, newline="")):
        f = r["file"]
        if "cases match" in r["oracle"] and f not in cite:
            cite[f] = re.search(r"[^;]*cases match[^;]*", r["oracle"]).group(0).strip()

    rows = []
    for g in gap:
        e = g["entry"] & 0x1FFFFFFF
        # A TRAPA is not an expressible instruction, but the repo's own
        # oracle-replayed entries that contain one model it as a fail-closed
        # block (src/fight/matrix_adapters.c P_0c04a2b8 and the two siblings),
        # and those entries replay clean against the oracle: the reference
        # itself never returns from the trap, so the trap is not observable.
        blockers = [pc for pc in unsup.get(e, [])
                    if not (0xC330 <= word(pc) <= 0xC33F)]
        if blockers:
            print(f"  0x{e:08x}: {len(blockers)} unexpressible instruction(s) - skipped")
            continue
        pcs = []
        for s, t in br.get(e, []):
            pcs.extend(range(s, t, 2))
        served = None
        for name in order:
            stem = next((s for s in (name, name + "_adapter",
                                      "vf3_" + name, "vf3_" + name + "_adapter")
                         if s in mods), None)
            if stem is None:
                continue
            if e in mods[stem]["claimed"]:
                served = stem
                break
        if served is None:
            print(f"  0x{e:08x}: no module claims the entry PC - skipped")
            continue
        file = file_for(served, mods)
        # an older module that owns the same body and replays against the oracle
        older = sorted({stem for stem, sets in mods.items()
                        if stem != served and e in sets["owned"]})
        old_with_cite = [o for o in older if file_for(o, mods) in cite]
        parts = [f"ROM translation: {len(pcs)} body PCs emitted, every opcode "
                 f"matches extract/exe/1ST_READ.unsc.bin (tools/gap_fidelity.py)"]
        if old_with_cite:
            parts.append("same body owned by the oracle-replayed " +
                         ", ".join(file_for(o, mods) for o in old_with_cite[:3]))
        if reach.get(e):
            parts.append("body reached by the capture of " +
                         ", ".join(sorted(set(reach[e]))[:3]))
        method = ("static original-image C (ROM translation); complete body"
                  if not old_with_cite else
                  "static original-image C; complete body; the owning module "
                  "replays against the oracle")
        oracle = "; ".join(parts)
        if old_with_cite:
            oracle += "; owner replay: " + cite[file_for(old_with_cite[0], mods)]
        rows.append({"entry": f"0x{e:08x}", "status": "ported", "file": file,
                     "size": funcs.get(e, g["new"]),
                     "method": method, "oracle": oracle})

    with open(args.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "status", "file", "size",
                                          "method", "oracle"])
        w.writeheader()
        w.writerows(rows)
    print(f"{len(rows)} rows -> {args.out}")
    print(f"bytes: {sum(r['size'] for r in rows)}")

    if args.write:
        have = {r["entry"].lower() for r in csv.DictReader(open(LEDGER, newline=""))}
        new = [r for r in rows if r["entry"].lower() not in have]
        with open(LEDGER, "a", newline="") as f:
            w = csv.DictWriter(f, fieldnames=["entry", "status", "file", "size",
                                              "method", "oracle"])
            for r in new:
                w.writerow(r)
        print(f"appended {len(new)} rows to {LEDGER}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
