#!/usr/bin/env python3
"""gap_serve_audit.py - who actually serves each gap entry, and does it cover the body?

`body_complete.py` proves every PC of an entry's Ghidra body carries a
translated label in *some* adapter.  That is the coverage claim.  It is not the
dispatch claim: the router serves an entry PC by walking the chain and taking
the first module whose `_contains` says yes - and `_contains` reads
`claim_pcs[]` for the modules that have one and `owned_pcs[]` for the legacy
modules that do not.

So a gap root that an *earlier* module owns is served by that earlier module,
not by the gap module that translated it.  That is fine only when the earlier
module implements the same body; when it does not, the entry is credited bytes
the router never runs.

This tool answers, for every gap entry:
  * the module the router really serves it with,
  * whether that module's owned set covers the whole baseline body range.

Usage:
    python tools/gap_serve_audit.py
    python tools/gap_serve_audit.py --verbose
"""
from __future__ import annotations

import argparse
import csv
import json
import re
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SRC = REPO / "src" / "fight"
RANGES = REPO / "extract" / "analysis" / "function_body_ranges.csv"
PROMOTE = REPO / "extract" / "analysis" / "gap_promote.csv"

CONTAINS_RE = re.compile(r"int vf3_(\w+)_contains\(uint32_t pc\)")
CLAIM_RE = re.compile(r"static const uint32_t claim_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
OWNED_RE = re.compile(r"static const uint32_t owned_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
HEX_RE = re.compile(r"0x([0-9a-fA-F]+)u?")


def chain_order() -> list[str]:
    """The module names, in the order the router tries them."""
    text = (SRC / "matrix_family.c").read_text(encoding="utf-8", errors="replace")
    start = text.find("static int vf3_matrix_family_core")
    end = text.find("static int vf3_matrix_family_dispatch")
    body = text[start:end]
    return [m.group(1) for m in re.finditer(r"if\(vf3_(\w+)_contains\(entry\)\)", body)]


def module_sets() -> dict[str, tuple[set[int], set[int], str]]:
    """router name -> (contains-set, owned-set, file).

    The contains-set is `claim_pcs[]` when the module has one and `owned_pcs[]`
    otherwise - that is what the generated `_contains` actually reads.
    """
    out: dict[str, tuple[set[int], set[int], str]] = {}
    for path in sorted(SRC.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        m = CONTAINS_RE.search(text)
        if not m:
            continue
        name = m.group(1)
        owned = {int(h, 16) & 0x1FFFFFFF for h in HEX_RE.findall(OWNED_RE.search(text).group(1))} \
            if OWNED_RE.search(text) else set()
        cm = CLAIM_RE.search(text)
        claims = {int(h, 16) & 0x1FFFFFFF for h in HEX_RE.findall(cm.group(1))} if cm else None
        contains = claims if claims is not None else owned
        # a module that has both arrays claims with claim_pcs[]; the owned set
        # is what it implements.
        out[name] = (contains, owned, path.name)
    return out


def fallback_module() -> tuple[str, set[int], str]:
    """The module the chain ends with, and the PCs it serves.

    The chain's last `return vf3_X(entry,s,ram);` is not guarded by a
    `_contains` test, so X serves every PC its translation carries.  It has no
    claim array and no `_contains` symbol, so it is invisible to a scan that
    only looks for those - and the PCs only it owns would look unreachable.
    """
    text = (SRC / "matrix_family.c").read_text(encoding="utf-8", errors="replace")
    start = text.find("static int vf3_matrix_family_core")
    end = text.find("static int vf3_matrix_family_dispatch")
    body = text[start:end]
    guarded = {body[m.start():m.end()] for m in re.finditer(
        r"if\(vf3_\w+_contains\(entry\)\) return vf3_\w+\(entry,s,ram\);", body)}
    name = None
    for m in re.finditer(r"return (vf3_\w+)\(entry,s,ram\);", body):
        if body[m.start():m.end()] not in guarded:
            name = m.group(1)
    if name is None:
        return "", set(), ""
    for path in sorted(SRC.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        if re.search(rf"^int {re.escape(name)}\(uint32_t entry,", text, re.M):
            owned = {int(h, 16) & 0x1FFFFFFF
                     for h in re.findall(r"^P_([0-9a-f]{8}):", text, re.M)}
            return name, owned, path.name
    return name, set(), ""


def body_ranges() -> dict[int, list[tuple[int, int]]]:
    by_entry: dict[int, list[tuple[int, int]]] = defaultdict(list)
    with RANGES.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            entry = int(row["entry"], 16) & 0x1FFFFFFF
            by_entry[entry].append((int(row["start"], 16) & 0x1FFFFFFF,
                                    int(row["end"], 16) & 0x1FFFFFFF))
    return by_entry


def gap_entries() -> list[int]:
    """The entries the gap batch promoted."""
    out: list[int] = []
    with PROMOTE.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            out.append(int(row["entry"], 16) & 0x1FFFFFFF)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--verbose", action="store_true",
                    help="list every entry, not only the problems")
    args = ap.parse_args()

    order = chain_order()
    mods = module_sets()
    ranges = body_ranges()
    entries = gap_entries()

    served_by_gap = 0
    served_by_older = 0
    uncovered = []
    shadowed = []
    unknown = []
    unservable = []

    # every PC the router can be asked to serve, over the whole chain
    servable: set[int] = set()
    for name in order:
        contains, owned, filename = mods.get(name, (set(), set(), ""))
        servable |= contains
    fb_name, fb_owned, fb_file = fallback_module()
    servable |= fb_owned
    print(f"  fallback module: {fb_name} ({fb_file}) serves {len(fb_owned)} PCs")

    for entry in entries:
        served = None
        for name in order:
            contains, owned, filename = mods.get(name, (set(), set(), ""))
            if entry in contains:
                served = (name, contains, owned, filename)
                break
        if served is None:
            unknown.append(entry)
            continue
        name, contains, owned, filename = served
        spans = ranges.get(entry, [])
        body = sum(b - a for a, b in spans)
        missing = [pc for a, b in spans for pc in range(a, b, 2) if pc not in owned]
        if missing:
            uncovered.append((entry, name, filename, body, missing[:6]))
        # the dispatch invariant: a call to any PC of the body must land on a
        # module that claims it.  A body split over several modules is fine -
        # each PC needs its own owner.
        lost = [pc for a, b in spans for pc in range(a, b, 2) if pc not in servable]
        if lost:
            unservable.append((entry, name, filename, body, lost[:6]))
        if name.startswith("gap_b"):
            served_by_gap += 1
        else:
            served_by_older += 1
            shadowed.append((entry, name, filename, body, len(missing)))

    print(f"gap entries audited: {len(entries)}")
    print(f"  served by a gap module : {served_by_gap}")
    print(f"  served by an older one : {served_by_older}")
    print(f"  served by nobody       : {len(unknown)}")
    print(f"  body PCs no module claims (the router cannot serve them): {len(unservable)}")
    for entry, name, filename, body, lost in unservable:
        print(f"    0x{entry:08x} served by {name} ({filename}) body={body} B: "
              + ", ".join("0x%08x" % m for m in lost))
    print(f"  body PCs the serving module does not own (split bodies): {len(uncovered)}")
    for entry, name, filename, body, missing in uncovered:
        print(f"    0x{entry:08x} served by {name} ({filename}) body={body} B "
              f"missing {len(missing)} PCs: "
              + ", ".join("0x%08x" % m for m in missing))
    if args.verbose:
        print("  entries an older module serves:")
        for entry, name, filename, body, missing in shadowed:
            print(f"    0x{entry:08x}  {name:<16} ({filename})  body={body:5d} B "
                  f"not-owned-by-servicer={missing}")
    return 1 if unservable or unknown else 0


if __name__ == "__main__":
    raise SystemExit(main())
