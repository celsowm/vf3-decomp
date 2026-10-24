#!/usr/bin/env python3
"""adapter_owner.py - which generated module the chain serves for a PC.

Several modules carry the same guest PC: the same function was captured in
more than one campaign.  The router serves the *first* module in chain order
that owns the PC, so a readable port has to be written against that copy -
the others may model the same guest code differently (a different `rts`, a
different stack depth, the alias-aware continuation).

The chain order is the order of the `_contains` tests inside
`vf3_matrix_family_core` in src/fight/matrix_family.c; each module's owned
set is its sorted `owned_pcs[]` array.

Usage:
    python tools/adapter_owner.py 0x0c044068
    python tools/adapter_owner.py 0x0c037788 --all
    python tools/adapter_owner.py 0x0c044068 --body
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src" / "fight"

LABEL = re.compile(r"^P_([0-9a-f]{8}):")
OWNED = re.compile(r"static const uint32_t owned_pcs\[\]\s*=\s*\{(.*?)\};", re.S)
HEX = re.compile(r"0x[0-9a-fA-F]+")


def chain_order() -> list[str]:
    """The module names, in the order the router tries them."""
    text = (SRC / "matrix_family.c").read_text(encoding="utf-8", errors="replace")
    start = text.find("static int vf3_matrix_family_core")
    end = text.find("static int vf3_matrix_family_dispatch")
    body = text[start:end]
    return [m.group(1) for m in re.finditer(r"if\(vf3_(\w+)_contains\(entry\)\)", body)]


def owned_sets() -> dict[str, set[int]]:
    """Each module's owned PC set, keyed by the router's name for it."""
    out: dict[str, set[int]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        m = OWNED.search(text)
        if not m:
            continue
        pcs = {int(h, 16) for h in HEX.findall(m.group(1))}
        # the router names the module without the `_adapter` suffix it uses
        # for the file in some cases; index by both.
        out[path.stem] = pcs
    return out


def index_modules(owned: dict[str, set[int]]) -> dict[str, set[int]]:
    """Map the router's module name to its owned set.

    The router calls `vf3_<name>_adapter_contains`; the file that defines it
    is `<name>_adapter.c` or `<name>.c`.  Match on the defined symbol when
    the file name does not line up.
    """
    out: dict[str, set[int]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        m = OWNED.search(text)
        if not m:
            continue
        pcs = {int(h, 16) for h in HEX.findall(m.group(1))}
        fn = re.search(r"int vf3_(\w+)_contains\(uint32_t pc\)", text)
        if fn:
            out[fn.group(1)] = pcs
        else:
            out[path.stem] = pcs
    return out


def owner(pc: int) -> tuple[str | None, list[str]]:
    """The serving module for a PC, and every module that carries it."""
    mods = index_modules(owned_sets())
    order = chain_order()
    rank = {name: i for i, name in enumerate(order)}
    carriers = [name for name, pcs in mods.items() if pc in pcs]
    carriers = sorted(set(carriers), key=lambda n: (rank.get(n, 1 << 30), n))
    return (carriers[0] if carriers else None), carriers


def normalize(stem: str) -> str:
    """The family a file belongs to: `fifth_leaf_adapters_1` -> `fifth_leaf`.

    The router's name and the file's name do not line up: the router calls
    `vf3_fifth_leaf_adapter_contains` while the code lives in
    `fifth_leaf_adapters_0.c` and `fifth_leaf_adapters_1.c`, and
    `vf3_sweep_adapter_contains` lives in `vf3_sweep_adapters.c` with the code
    in `vf3_sweep_adapters_0.c`.
    """
    s = stem
    if s.startswith("vf3_"):
        s = s[4:]
    s = re.sub(r"_\d+$", "", s)
    for suf in ("_adapters", "_adapter", "adapters", "adapter"):
        if s.endswith(suf):
            s = s[: -len(suf)]
            break
    return s


def body_of(pc: int, module: str) -> list[tuple[str, list[tuple[int, str]]]]:
    """The generated source of a PC and its neighbours, in every file of the
    module's family that carries it.

    Several files can hold the same guest code (one family per campaign), so
    the body is reported per file.
    """
    want = normalize(module)
    label = f"P_{pc:08x}:"
    out: list[tuple[str, list[tuple[int, str]]]] = []
    for path in sorted(SRC.glob("*adapter*.c")):
        if normalize(path.stem) != want:
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        if label not in text:
            continue
        blocks: dict[int, list[str]] = {}
        cur: int | None = None
        for line in text.splitlines():
            m = LABEL.match(line)
            if m:
                cur = int(m.group(1), 16)
                blocks[cur] = []
                continue
            if cur is not None:
                s = line.strip()
                if s and not s.startswith("if(!s->budget--)"):
                    blocks[cur].append(s)
        body = [(p, " ".join(blocks[p])) for p in sorted(blocks)
                if pc <= p < pc + 0x40]
        if body:
            out.append((path.name, body))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("pc")
    ap.add_argument("--all", action="store_true",
                    help="list every module that carries the PC")
    ap.add_argument("--body", action="store_true",
                    help="print the serving module's generated source")
    args = ap.parse_args()

    pc = int(args.pc, 16) & 0x1FFFFFFF
    served, carriers = owner(pc)
    if args.all or served is None:
        for name in carriers:
            print(name)
        if served is not None:
            print(f"served: {served}")
    else:
        print(f"served: {served}")
        if len(carriers) > 1:
            print("carriers: " + ", ".join(carriers))
    if args.body and served:
        for name, body in body_of(pc, served):
            print(f"  --- {name}")
            for p, text in body:
                print(f"  {p:08x}  {text}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
