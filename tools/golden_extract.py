#!/usr/bin/env python3
"""golden_extract.py — per-function golden snapshots from VF3_FULL traces.

Reads one or more flycast VF3_TRACE streams produced with VF3_FULL=1 (probe
groups 0xFA30/0xFA31 entry, 0xFA32/0xFA33 exit; 37 values = r0-r15, pr, sr,
fpscr, macl, mach, fr0-fr15) and pairs each watched entry with the exit that
retired at the same call depth. Emits one JSON per function plus an index.
Multiple traces are merged per PC; each sample carries its scenario tag.

Usage:
  python tools/golden_extract.py extract/analysis/golden_fight.bin \
      [extract/analysis/golden_boot.bin ...] \
      --out extract/analysis/goldens [--scenario fight,boot]
      [--max-samples 64]
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import struct
import sys
from array import array
from collections import defaultdict, deque
from pathlib import Path

REGNAMES = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",
            "r10", "r11", "r12", "r13", "r14", "r15", "pr", "sr", "fpscr",
            "macl", "mach"] + [f"fr{i}" for i in range(16)]
NVALS = len(REGNAMES)


def read_records(path: Path):
    data = path.read_bytes()
    n = len(data) // 8
    return struct.unpack(f"<{n}Q", data[:n * 8])


def marker(rec: int) -> int:
    lo = rec & 0xFFFF
    return lo if lo >= 0xFA00 and (rec >> 16) != 0 else 0


def read_ram_group(recs, i):
    """Parse an 0xFA50/0xFA60 group at record i.
    Returns (pc, wins, blob, next_i)."""
    pc = recs[i] >> 16
    nwin = recs[i + 1] & 0xFFFFFFFF
    if nwin > 64:
        return pc, [], [], i + 1
    j = i + 2
    wins = []
    blob = []
    for _ in range(nwin):
        base = recs[j] & 0xFFFFFFFF
        ln = recs[j + 1] & 0xFFFFFFFF
        nw = ln // 4
        words = recs[j + 2:j + 2 + nw]
        if len(words) != nw:
            break
        wins.append((base, ln))
        blob.append(array("I", [w & 0xFFFFFFFF for w in words]).tobytes())
        j += 2 + nw
    return pc, wins, blob, j + 1 if len(wins) == nwin else i + 1


def extract(path: Path):
    recs = read_records(path)
    pending: dict[int, deque] = defaultdict(deque)
    samples: dict[int, list] = defaultdict(list)
    rams: dict[int, list] = defaultdict(list)
    exitrams: dict[int, list] = defaultdict(list)
    unpaired = defaultdict(int)
    i = 0
    n = len(recs)
    while i < n:
        m = marker(recs[i])
        if m == 0xFA30:
            pc = recs[i] >> 16
            vals = recs[i + 1:i + 1 + NVALS]
            if len(vals) == NVALS:
                pending[pc].append(vals)
            i += 1 + NVALS + 1
            continue
        if m == 0xFA50:
            pc, wins, blob, i = read_ram_group(recs, i)
            if wins:
                rams[pc].append((wins, b"".join(blob)))
            continue
        if m == 0xFA60:
            pc, wins, blob, i = read_ram_group(recs, i)
            if wins:
                exitrams[pc].append((wins, b"".join(blob)))
            continue
        if m == 0xFA32:
            pc = recs[i] >> 16
            vals = recs[i + 1:i + 1 + NVALS]
            if len(vals) == NVALS:
                if pending[pc]:
                    samples[pc].append((pending[pc].popleft(), vals))
                else:
                    unpaired[pc] += 1
            i += 1 + NVALS + 1
            continue
        i += 1
    return samples, unpaired, rams, exitrams


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace", nargs="+")
    ap.add_argument("--out", required=True)
    ap.add_argument("--max-samples", type=int, default=64)
    ap.add_argument("--scenario", default="capture",
                    help="scenario name, or one comma-separated name per trace")
    a = ap.parse_args()

    scens = a.scenario.split(",")
    if len(scens) == 1:
        scens = scens * len(a.trace)
    if len(scens) != len(a.trace):
        raise SystemExit("--scenario count must be 1 or match trace count")

    merged: dict[int, list] = defaultdict(list)
    unpaired_tot: dict[int, int] = defaultdict(int)
    pairs_tot: dict[int, int] = defaultdict(int)
    sources: dict[int, list] = defaultdict(list)
    for tp, sc in zip(a.trace, scens):
        p = Path(tp)
        if not p.exists():
            print(f"skip missing trace {tp}")
            continue
        samples, unpaired, rams, exitrams = extract(p)
        for pc, pairs in samples.items():
            sources[pc].append(sc)
            pairs_tot[pc] += len(pairs)
            rb = rams.get(pc, [])
            xb = exitrams.get(pc, [])
            for ordinal, (ins, outs) in enumerate(pairs):
                merged[pc].append({
                    "scenario": sc, "in": ins, "out": outs,
                    "ram": rb[ordinal] if ordinal < len(rb) else None,
                    "xram": xb[ordinal] if ordinal < len(xb) else None,
                })
        for pc, cnt in unpaired.items():
            unpaired_tot[pc] += cnt

    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    index = []
    for pc, rows in sorted(merged.items()):
        seen = set()
        uniq = []
        for r in rows:
            key = (r["in"], r["out"])
            if r["ram"] is None and r["xram"] is None and key in seen:
                continue
            seen.add(key)
            uniq.append(r)
            if len(uniq) >= a.max_samples:
                break
        fp = hashlib.sha256(
            b"".join(struct.pack(f"<{NVALS}Q{NVALS}Q", *r["in"], *r["out"])
                     for r in uniq)
        ).hexdigest()[:16]
        name = f"f_{pc:08x}"
        scen_all = ",".join(sorted(set(sources[pc])))
        trusted = unpaired_tot.get(pc, 0) == 0
        doc = {
            "pc": f"0x{pc:08x}", "name": name, "scenario": scen_all,
            "samples": [], "exitram_trusted": trusted,
        }
        sample_ram = []
        sample_xram = []
        for r in uniq:
            ins, outs = r["in"], r["out"]
            sample = {"scenario": r["scenario"],
                      "in": dict(zip(REGNAMES, ins)),
                      "out": dict(zip(REGNAMES, outs))}
            ramname = "-"
            if r["ram"] is not None:
                wins, blob = r["ram"]
                k = len([x for x in doc["samples"] if "ram" in x])
                rp = out / f"{name}.ram{k}.bin"
                rp.write_bytes(blob)
                mp = out / f"{name}.ram{k}.meta"
                mp.write_text("\n".join(f"0x{b:08x} 0x{l:x}" for b, l in wins)
                              + "\n", encoding="utf-8")
                sample["ram"] = f"{name}.ram{k}.bin"
                sample["ram_wins"] = [f"0x{b:08x} 0x{l:x}" for b, l in wins]
                doc.setdefault("ram_wins", sample["ram_wins"])
                ramname = sample["ram"]
                print(f"{name}: ram sample {k} -> {rp.name} ({len(blob)} B, "
                      f"{len(wins)} windows)")
            xramname = "-"
            if r["xram"] is not None:
                xwins, xblob = r["xram"]
                xk = len([x for x in doc["samples"] if "exit_ram" in x])
                xp = out / f"{name}.exitram{xk}.bin"
                xp.write_bytes(xblob)
                xp.with_suffix(".meta").write_text(
                    "\n".join(f"0x{b:08x} 0x{l:x}" for b, l in xwins)
                    + "\n", encoding="utf-8")
                sample["exit_ram"] = f"{name}.exitram{xk}.bin"
                sample["exit_ram_wins"] = [f"0x{b:08x} 0x{l:x}"
                                           for b, l in xwins]
                xramname = sample["exit_ram"]
                print(f"{name}: exit ram sample {xk} -> {xp.name}")
            doc["samples"].append(sample)
            sample_ram.append(ramname)
            sample_xram.append(xramname)
        (out / f"{name}.json").write_text(json.dumps(doc), encoding="utf-8")
        # compact text form for C replay tests: register snapshots only
        lines = []
        for r in uniq:
            lines.append(" ".join(f"{v:08x}" for v in (*r["in"], *r["out"])))
        (out / f"{name}.txt").write_text("\n".join(lines) + "\n",
                                         encoding="utf-8")
        # .cases (v2): in regs, out regs, entry ram nwin [base len]*,
        # exit ram nwin [base len]*
        case_lines = []
        for idx, r in enumerate(uniq):
            wins = list(r["ram"][0]) if r["ram"] is not None else []
            winstr = str(len(wins)) + "".join(
                f" 0x{b:08x} 0x{l:x}" for b, l in wins)
            xwins = list(r["xram"][0]) if r["xram"] is not None else []
            xwinstr = str(len(xwins)) + "".join(
                f" 0x{b:08x} 0x{l:x}" for b, l in xwins)
            case_lines.append(
                " ".join(f"{v:08x}" for v in r["in"]) + " " +
                " ".join(f"{v:08x}" for v in r["out"]) + " " +
                sample_ram[idx] + " " + winstr + " " +
                sample_xram[idx] + " " + xwinstr)
        (out / f"{name}.cases").write_text("\n".join(case_lines) + "\n",
                                           encoding="utf-8")
        index.append({"pc": f"0x{pc:08x}", "name": name,
                      "scenarios": scen_all, "pairs": pairs_tot.get(pc, 0),
                      "unique": len(uniq), "unpaired": unpaired_tot.get(pc, 0),
                      "fingerprint": fp})
        print(f"{name}: {pairs_tot.get(pc, 0)} pairs, {len(uniq)} unique, "
              f"{unpaired_tot.get(pc, 0)} unpaired, scenarios={scen_all}, fp={fp}")
    with open(out / "goldens_index.csv", "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["pc", "name", "scenarios", "pairs",
                                          "unique", "unpaired", "fingerprint"])
        w.writeheader()
        w.writerows(index)
    print(f"golden_extract: {len(index)} fns -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())