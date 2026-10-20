#!/usr/bin/env python3
"""binding_steal.py — find golden bindings a new adapter would shadow.

New generated adapters are inserted into the router chain ahead of the generic
`matrix_adapters.c` fallback, so a module that owns a PC can take routing away
from the module that used to own it.  This tool lists the pre-existing golden
bindings whose entry address is now owned by a given adapter, so they can be
re-verified before the change is committed.

    python tools/binding_steal.py                       # default new modules
    python tools/binding_steal.py src/fight/vf3_c81_adapter.c
"""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
BINDINGS = REPO / "tools" / "golden_bindings.json"
DEFAULTS = ["src/fight/vf3_c80_adapter.c", "src/fight/vf3_c81_adapter.c"]


def owned_pcs(path: Path) -> set[int]:
    return {int(m.group(1), 16) & 0x1FFFFFFF
            for m in re.finditer(r"^P_([0-9a-f]+):", path.read_text(errors="ignore"), re.M)}


def main() -> int:
    targets = sys.argv[1:] or DEFAULTS
    bindings = json.loads(BINDINGS.read_text(encoding="utf-8"))
    bad = 0
    for rel in targets:
        path = REPO / rel
        if not path.is_file():
            print("%s: missing" % rel)
            bad += 1
            continue
        owned = owned_pcs(path)
        hits = []
        for pc, meta in bindings.items():
            try:
                entry = int(pc, 16) & 0x1FFFFFFF
            except ValueError:
                continue
            if entry in owned:
                hits.append((pc, meta.get("golden"), meta.get("test")))
        print("%s owns %d PCs" % (rel, len(owned)))
        print("  existing bindings whose entry it now owns: %d" % len(hits))
        for pc, golden, test in hits[:40]:
            print("     %s  golden=%s  test=%s" % (pc, golden, test))
    return 0


if __name__ == "__main__":
    sys.exit(main())
