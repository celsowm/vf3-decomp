#!/usr/bin/env python3
"""pair_cases.py — piecewise oracle cases from interior watch points.

A watched function that tail-jumps, loops, or spans kilobytes cannot be
validated entry->exit. This tool pairs each ENTRY hit with the next
INTERIOR hit (same call), so a C port of the [entry, interior] region can
be replayed: input = entry snapshot + entry RAM, expected = interior
snapshot + interior RAM.

Usage:
  python tools/pair_cases.py TRACE --entry 0x8C071A76 --at 0x8C071ABE \
      --out extract/analysis/goldens_vpb/f_0c071a76_head \
      [--max 8] [--gate "r2>r9"]

The --gate expression (optional) selects which entries to pair; supported
forms: rA>rB (signed), rA==N, rA!=N. Entries failing the gate are skipped
(their interior hit, if any, is consumed by the next gated entry only when
it falls between the two entries).

Output: <out>.cases (same layout as golden_extract: 37 in, 37 out,
entry-ram + wins, interior-ram + wins), <out>.in<k>.bin/.meta,
<out>.out<k>.bin/.meta. If the trace has XF groups at both PCs, also writes
<out>.xfin.bin and <out>.xfout.bin in row order.
"""
from __future__ import annotations

import argparse
import struct
import sys
from array import array
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from golden_extract import NVALS, read_records


def parse_gate(expr: str):
    expr = expr.replace(" ", "")
    if ">" in expr:
        a, b = expr.split(">", 1)
        return ("gt", a, b)
    if "==" in expr:
        a, b = expr.split("==", 1)
        return ("eq", a, b)
    if "!=" in expr:
        a, b = expr.split("!=", 1)
        return ("ne", a, b)
    raise SystemExit(f"bad gate {expr!r}")


def reg_val(snap: tuple, name: str) -> int:
    from golden_extract import REGNAMES
    return snap[REGNAMES.index(name)] & 0xFFFFFFFF


def s32(v: int) -> int:
    v &= 0xFFFFFFFF
    return v - 0x100000000 if v & 0x80000000 else v


def gate_ok(op, snap) -> bool:
    kind, a, b = op
    va = reg_val(snap, a)
    vb = int(b, 0) if not b.startswith("r") else reg_val(snap, b)
    if kind == "gt":
        return s32(va) > s32(vb)
    if kind == "eq":
        return va == vb
    return va != vb


def read_group(recs, j, close):
    """Read an 0xFA50/0xFA60 RAM group at record j (the open marker).
    Returns (wins, blob, next_j) or (None, None, j+1). RAM data words can
    mimic markers, so the group is accepted only when the close marker
    lands exactly at the computed end."""
    n = len(recs)
    if j + 1 >= n:
        return None, None, j + 1
    nwin = recs[j + 1] & 0xFFFFFFFF
    if nwin > 8:
        return None, None, j + 1
    k = j + 2
    wins = []
    blob = []
    for _ in range(nwin):
        if k + 1 >= n:
            return None, None, j + 1
        base = recs[k] & 0xFFFFFFFF
        ln = recs[k + 1] & 0xFFFFFFFF
        if ln > 0x1000000:
            return None, None, j + 1
        nw = ln // 4
        words = recs[k + 2:k + 2 + nw]
        if len(words) != nw:
            return None, None, j + 1
        wins.append((base, ln))
        blob.append(array("I", words).tobytes())
        k += 2 + nw
    if k >= n or (recs[k] & 0xFFFF) != close:
        return None, None, j + 1
    return wins, b"".join(blob), k + 1


def read_xf_group(recs, j, pc):
    """Read an optional 16-word FA70/FA71 matrix group at record j."""
    n = len(recs)
    if j >= n or (recs[j] & 0xFFFF) != 0xFA70 \
            or ((recs[j] >> 16) & 0xFFFFFFFF) != pc:
        return None, j
    k = j + 1
    values = []
    for _ in range(16):
        if k >= n or (recs[k] & 0xFFFF) != 0xFA72:
            return None, j
        values.append((recs[k] >> 16) & 0xFFFFFFFF)
        k += 1
    if k >= n or (recs[k] & 0xFFFF) != 0xFA71:
        return None, j
    return tuple(values), k + 1


def collect(recs, want_pc: int):
    """All (pos, snapshot, ram-or-None, xf-or-None) events for a watched pc."""
    out = []
    i = 0
    n = len(recs)
    while i < n:
        m = recs[i] & 0xFFFF
        if m == 0xFA30 and (recs[i] >> 16) == want_pc:
            vals = recs[i + 1:i + 1 + NVALS]
            j = i + 1 + NVALS + 1
            xf, j = read_xf_group(recs, j, want_pc)
            ram = None
            if j < n and (recs[j] & 0xFFFF) == 0xFA50 \
                    and (recs[j] >> 16) == want_pc:
                wins, blob, j2 = read_group(recs, j, 0xFA51)
                if wins:
                    ram = (wins, blob)
                    j = j2
            if len(vals) == NVALS:
                out.append((i, tuple(vals), ram, xf))
            i = j
            continue
        i += 1
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--entry", required=True)
    ap.add_argument("--at", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--max", type=int, default=8)
    ap.add_argument("--gate", default=None)
    a = ap.parse_args()

    entry_pc = int(a.entry, 0) & 0x0FFFFFFF
    at_pc = int(a.at, 0) & 0x0FFFFFFF
    gate = parse_gate(a.gate) if a.gate else None
    recs = read_records(Path(a.trace))
    entries = collect(recs, entry_pc)
    interiors = collect(recs, at_pc)
    print(f"entry hits: {len(entries)}, interior hits: {len(interiors)}")

    outp = Path(a.out)
    outp.parent.mkdir(parents=True, exist_ok=True)
    from golden_extract import REGNAMES
    lines = []
    xf_in_rows = []
    xf_out_rows = []
    any_xf = False
    used_interior = 0
    made = 0
    for entry_index, (epos, ins, iram, xfin) in enumerate(entries):
        if made >= a.max:
            break
        # first interior hit strictly after this entry
        while used_interior < len(interiors) \
                and interiors[used_interior][0] <= epos:
            used_interior += 1
        if used_interior >= len(interiors):
            break
        ipos, outs, oram, xfout = interiors[used_interior]
        # An entry with another watched entry between it and this interior
        # did not reach this boundary. Leave the interior for its own call.
        if entry_index + 1 < len(entries) \
                and ipos >= entries[entry_index + 1][0]:
            continue
        used_interior += 1
        if gate and not gate_ok(gate, ins):
            continue
        if iram is None or oram is None:
            continue
        if (xfin is None) != (xfout is None):
            raise SystemExit("entry and boundary XF capture presence differs")
        if xfin is not None:
            any_xf = True
            xf_in_rows.append(xfin)
            xf_out_rows.append(xfout)
        iwins, iblob = iram
        owins, oblob = oram
        rp = outp.parent / f"{outp.name}.in{made}.bin"
        rp.write_bytes(iblob)
        (outp.parent / f"{rp.stem}.meta").write_text(
            "\n".join(f"0x{b:08x} 0x{l:x}" for b, l in iwins) + "\n",
            encoding="utf-8")
        op = outp.parent / f"{outp.name}.out{made}.bin"
        op.write_bytes(oblob)
        (outp.parent / f"{op.stem}.meta").write_text(
            "\n".join(f"0x{b:08x} 0x{l:x}" for b, l in owins) + "\n",
            encoding="utf-8")
        lines.append(
            " ".join(f"{v:08x}" for v in ins) + " " +
            " ".join(f"{v:08x}" for v in outs) + " " +
            rp.name + " " + str(len(iwins)) + " " +
            " ".join(f"0x{b:08x} 0x{l:x}" for b, l in iwins) + " " +
            op.name + " " + str(len(owins)) + " " +
            " ".join(f"0x{b:08x} 0x{l:x}" for b, l in owins))
        made += 1
    (outp.parent / f"{outp.name}.cases").write_text(
        "\n".join(lines) + "\n", encoding="utf-8")
    if any_xf:
        if len(xf_in_rows) != made or len(xf_out_rows) != made:
            raise SystemExit("incomplete XF sidecars for paired cases")
        (outp.parent / f"{outp.name}.xfin.bin").write_bytes(
            b"".join(struct.pack("<16I", *row) for row in xf_in_rows))
        (outp.parent / f"{outp.name}.xfout.bin").write_bytes(
            b"".join(struct.pack("<16I", *row) for row in xf_out_rows))
    print(f"pair_cases: {made} cases -> {outp.name}.cases")
    return 0


if __name__ == "__main__":
    sys.exit(main())
