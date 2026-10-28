#!/usr/bin/env python3
"""claim_hole_audit.py - find the guest PCs the router cannot serve.

Every generated module carries two arrays:

  owned_pcs[]  every PC the module implements (the coverage ledger counts them)
  claim_pcs[]  the PCs the module may route to

The router picks the module that *claims* a PC (the legacy modules, which have
no claim array, route their owned set), so a PC that is owned but claimed by
nobody is a hole: the router has nowhere to send the call and the run fails
with "unowned call at <pc>".

The chain ends with the fallback `vf3_matrix_adapter` (src/fight/matrix_adapters.c),
which has no `_contains` symbol: it serves *every* PC its own translation
carries.  A scan that only looks for the `_contains` symbols calls those PCs a
hole, so the fallback is part of the audit.

This audit reads the arrays straight out of the module sources, applies the
router's rule, and prints the holes.  Run it after a regeneration:

    python tools/claim_hole_audit.py            # the holes
    python tools/claim_hole_audit.py --verbose  # every module and its counts
"""
import argparse
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PAT_OWNED = re.compile(r"static const uint32_t owned_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
PAT_CLAIM = re.compile(r"static const uint32_t claim_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
PAT_CASE = re.compile(r"case 0x([0-9a-fA-F]+)u:")
HEXES = re.compile(r"0x([0-9a-fA-F]+)u")

# The chain's last module: the fallback the router ends with.  It has no
# `_contains` symbol, so the audit has to read the PCs out of its translation.
FALLBACK_FILE = "matrix_adapters.c"
FALLBACK_FN = "vf3_matrix_adapter"


def read_modules():
    """(file, owned, claimed) for every module that carries a PC array.

    `claimed` is None for a legacy module: it routes its owned set.
    """
    mods = []
    for path in sorted(glob.glob(os.path.join(ROOT, "src/fight/*.c"))):
        src = open(path, encoding="utf-8", errors="replace").read()
        owned = PAT_OWNED.search(src)
        claim = PAT_CLAIM.search(src)
        if not owned and not claim:
            continue
        o = [int(x, 16) for x in HEXES.findall(owned.group(1))] if owned else []
        c = [int(x, 16) for x in HEXES.findall(claim.group(1))] if claim else None
        mods.append((os.path.basename(path), o, c))
    return mods


def read_fallback():
    """The PCs the chain's last module (the fallback) serves.

    Its translation is a switch over the entry: every `case` is a PC it
    carries, and the router sends it everything the earlier modules did not
    claim.
    """
    path = os.path.join(ROOT, "src/fight", FALLBACK_FILE)
    if not os.path.exists(path):
        return set()
    src = open(path, encoding="utf-8", errors="replace").read()
    start = src.find("int %s(" % FALLBACK_FN)
    if start < 0:
        return set()
    end = src.find("default:", start)
    if end < 0:
        end = len(src)
    return {int(x, 16) for x in PAT_CASE.findall(src[start:end])}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--verbose", action="store_true", help="list every module")
    args = ap.parse_args()

    mods = read_modules()
    fallback = read_fallback()
    owned = {}
    servable = set(fallback)
    for name, o, c in mods:
        use = c if c is not None else o      # a modern module routes its claims
        for pc in o:
            owned.setdefault(pc, []).append(name)
        for pc in use:
            servable.add(pc)

    if args.verbose:
        for name, o, c in mods:
            kind = "claims %d" % len(c) if c is not None else "legacy (owned set)"
            print("%-36s owned %6d  routes %s" % (name, len(o), kind))
        print("%-36s carries %6d  (the chain's fallback)" % (FALLBACK_FILE, len(fallback)))

    holes = {pc: v for pc, v in owned.items() if pc not in servable}
    print("modules: %d   owned PCs: %d   routable PCs: %d   (the fallback carries %d)"
          % (len(mods), len(owned), len(servable), len(fallback)))
    print("OWNED BUT ROUTABLE BY NOBODY: %d" % len(holes))
    for pc in sorted(holes):
        print("   0x%08x  owned by %s" % (pc, ", ".join(sorted(set(holes[pc])))))
    return 1 if holes else 0


if __name__ == "__main__":
    sys.exit(main())
