#!/usr/bin/env python3
"""switch_inputs.py — find every immediate-compare switch in a body and resolve
where its selector value actually comes from.

Why this exists
---------------
tools/oracle/gate_scan.py reports switches and descriptor offsets only for the
`r13` descriptor. Real bodies load a second global into another register and
dispatch on *that*:

    0x8c0c3222  mov.l <lit>,r10      # lit = 0x0c29b864
    0x8c0c3280  mov #125,r0
    0x8c0c3282  mov.b @(r0,r10),r5
    0x8c0c328c  cmp/eq #1,r0
    0x8c0c328e  bt   0x8c0c329c

That switch on r0 = *(0x0C29B864 + 125) gates every arm past 0x8c0c329c in
0x8C0C321E, and a seed plan that only sweeps the r13 descriptor walks none of
it. This tool tracks provenance forward so the plan can seed the real field.

    python tools/oracle/switch_inputs.py extract/analysis/dis_8c0c321e.txt
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

REC = re.compile(r"^([0-9a-f]{8})\s+([0-9a-f]{4})\s+(\S.*)$")
R = r"r\d+"


def parse(path: Path):
    out = []
    for line in path.read_text(encoding="utf-8", errors="replace").replace("\r", "").splitlines():
        m = REC.match(line)
        if m:
            pc, _, txt = m.groups()
            out.append((int(pc, 16), txt.lstrip("_").strip()))
    return out


def imm(tok: str):
    return int(tok, 16) if tok.startswith("0x") else int(tok, 0)


def walk(recs):
    """Forward pass. Returns switches with a resolved provenance for the
    register each one tests.

    provenance kinds:
      ('imm', v)            the selector is a literal
      ('global', base, off) the selector is byte/word at *base + off
      ('reg', r)            the selector came from another register
      ('unknown',)          could not be attributed
    """
    val: dict[str, int] = {}        # reg -> known integer
    prov: dict[str, tuple] = {}     # reg -> provenance
    switches = []

    for pc, txt in recs:
        # mov.l <lit>,rN   /   mov.w <lit>,rN
        m = re.match(rf"^mov\.l\s+0x[0-9a-f]+,({R})\s+#\s*lit=([0-9a-f]+)$", txt)
        if m:
            val[m.group(1)] = int(m.group(2), 16)
            prov[m.group(1)] = ("global", int(m.group(2), 16), None)
            continue
        m = re.match(rf"^mov\.w\s+0x[0-9a-f]+,({R})\s+#\s*lit\.w=([0-9a-f]+)$", txt)
        if m:
            v = int(m.group(2), 16)
            val[m.group(1)] = v
            prov[m.group(1)] = ("imm", v)
            continue
        # mov #imm,rN
        m = re.match(rf"^mov\s+#(-?(?:0x)?[0-9a-f]+),({R})$", txt)
        if m:
            v = imm(m.group(1))
            val[m.group(1)] = v
            prov[m.group(1)] = ("imm", v)
            continue
        # mov.b/l/w @(x,rB),rD     with x an immediate or a known register
        m = re.match(rf"^mov\.[blw]\s+@\(({R}|0x[0-9a-f]+|\d+),({R})\),({R})$", txt)
        if m:
            xtok, base, dst = m.groups()
            if xtok in val:
                off, kind = val[xtok], "reg"
            elif xtok.startswith("0x") or xtok.isdigit():
                off, kind = imm(xtok), "imm"
            else:
                off, kind = None, "unknown"
            val[dst] = off if off is not None else 0
            # Both a literal displacement and a register holding one are
            # constant offsets, so either way the read lands at base+off.
            if off is not None and base in prov and prov[base][0] == "global":
                prov[dst] = ("global", prov[base][1], off)
            else:
                prov[dst] = (kind,)
            continue
        # mov rX,rD  (plain copy)
        m = re.match(rf"^mov\s+({R}),({R})$", txt)
        if m:
            src, dst = m.groups()
            if src in val:
                val[dst] = val[src]
                prov[dst] = prov.get(src, ("unknown",))
            else:
                val.pop(dst, None)
                prov[dst] = ("unknown",)
            continue
        # cmp/eq #imm,rX
        m = re.match(rf"^cmp/eq\s+#(-?(?:0x)?[0-9a-f]+),({R})$", txt)
        if m:
            switches.append((pc, m.group(2), imm(m.group(1)),
                             prov.get(m.group(2), ("unknown",))))
            continue
    return switches


def main() -> int:
    path = Path(sys.argv[1] if len(sys.argv) > 1
                else "extract/analysis/dis_8c0c321e.txt")
    recs = parse(path)
    sw = walk(recs)
    print(f"{path}: {len(recs)} instructions, {len(sw)} cmp/eq #imm sites")

    # group into switch runs: same register, nearby PCs. Provenance is kept
    # per arm - merging it across the window reports fields that do not gate
    # this particular switch.
    groups: list[dict] = []
    for pc, reg, code, pr in sw:
        if groups and groups[-1]["reg"] == reg and pc - groups[-1]["last"] < 0x40:
            groups[-1]["arms"].append((code, pc, pr))
            groups[-1]["last"] = pc
        else:
            groups.append({"reg": reg, "arms": [(code, pc, pr)], "last": pc})

    print("\nswitches found (selector register and codes):")
    for g in groups:
        if len(g["arms"]) < 2:
            continue
        codes = ", ".join(str(c) for c, _, _ in g["arms"])
        print(f"  {g['arms'][0][1]:08x}  on {g['reg']}  codes [{codes}]")
    print("\nNOTE: this tool reports *where* a switch is, not reliably *which*")
    print("field feeds it. The per-arm provenance walk below is kept only as a")
    print("hint and has reproduced the wrong offset on 0x8C0C321E (reported +4")
    print("where the instruction stream clearly loads offset 125). Read the")
    print("disassembly directly before seeding a field - see the OPEN DEFECT")
    print("section in docs/re/entry_patch.md for why that matters right now.")
    print("candidate fields seen feeding these registers, in address order:")
    for g in groups:
        if len(g["arms"]) < 2:
            continue
        for code, apc, pr in g["arms"]:
            if pr[0] == "global":
                base, off = pr[1], pr[2]
                print(f"    arm #{code} @ {apc:08x}  *0x{base:08x}+{off}"
                      f"  (word 0x{base + (off & ~3):08x}, byte lane {off & 3})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
