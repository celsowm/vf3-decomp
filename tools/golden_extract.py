#!/usr/bin/env python3
"""golden_extract.py — per-function golden snapshots from VF3_FULL traces.

Reads a flycast VF3_TRACE stream produced with VF3_FULL=1 (probe groups
0xFA30/0xFA31 entry, 0xFA32/0xFA33 exit; 21 values = r0-r15, pr, sr, fpscr,
macl, mach) and pairs each watched entry with the exit that retired at the
same call depth. Emits one JSON per function plus an index CSV.

Usage:
  python tools/golden_extract.py extract/analysis/golden_fight.bin \
      --out extract/analysis/goldens [--max-samples 64] [--scenario fight]
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


RAMW = 0x1000000 // 4  # default 16 MB RAM window as u32 words


def extract(path: Path):
    recs = read_records(path)
    pending: dict[int, deque] = defaultdict(deque)
    samples: dict[int, list] = defaultdict(list)
    rams: dict[int, list] = defaultdict(list)
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
            pc = recs[i] >> 16
            nwin = recs[i + 1] & 0xFFFFFFFF
            j = i + 2
            wins = []
            blob = []
            total = 0
            for _ in range(nwin):
                base = recs[j] & 0xFFFFFFFF
                ln = recs[j + 1] & 0xFFFFFFFF
                nw = ln // 4
                words = recs[j + 2:j + 2 + nw]
                if len(words) != nw:
                    break
                wins.append((base, ln))
                blob.append(array("I", words).tobytes())
                total += nw
                j += 2 + nw
            if len(wins) == nwin:
                rams[pc].append((wins, b"".join(blob)))
            i = j + 1
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
    return samples, unpaired, rams


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--out", required=True)
    ap.add_argument("--max-samples", type=int, default=64)
    ap.add_argument("--scenario", default="capture")
    a = ap.parse_args()

    samples, unpaired, rams = extract(Path(a.trace))
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    index = []
    for pc, pairs in sorted(samples.items()):
        seen = set()
        uniq = []
        ram_blobs = rams.get(pc, [])
        for ordinal, (ins, outs) in enumerate(pairs):
            key = (ins, outs)
            ram = ram_blobs[ordinal] if ordinal < len(ram_blobs) else None
            if ram is None and key in seen:
                continue
            seen.add(key)
            uniq.append((key, ram))
            if len(uniq) >= a.max_samples:
                break
        fp = hashlib.sha256(
            b"".join(struct.pack(f"<{NVALS}Q{NVALS}Q", *i, *o)
                     for (i, o), _ in uniq)
        ).hexdigest()[:16]
        name = f"f_{pc:08x}"
        doc = {
            "pc": f"0x{pc:08x}", "name": name, "scenario": a.scenario,
            "samples": [],
        }
        sample_ram = []
        for (ins, outs), ram in uniq:
            sample = {"in": dict(zip(REGNAMES, ins)),
                      "out": dict(zip(REGNAMES, outs))}
            ramname = "-"
            if ram is not None:
                wins, blob = ram
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
            doc["samples"].append(sample)
            sample_ram.append(ramname)
        (out / f"{name}.json").write_text(json.dumps(doc), encoding="utf-8")
        # compact text form for C replay tests: register snapshots only
        lines = []
        for (i, o), _ in uniq:
            lines.append(" ".join(f"{v:08x}" for v in (*i, *o)))
        (out / f"{name}.txt").write_text("\n".join(lines) + "\n",
                                         encoding="utf-8")
        # .cases: in regs, out regs, ram file, up to two windows
        case_lines = []
        for idx, ((ins, outs), ram) in enumerate(uniq):
            wins = list(ram[0]) if ram is not None else [(0, 0)]
            wins += [(0, 0)] * (2 - len(wins))
            winstr = " ".join(f"0x{b:08x} 0x{l:x}" for b, l in wins[:2])
            case_lines.append(
                " ".join(f"{v:08x}" for v in ins) + " " +
                " ".join(f"{v:08x}" for v in outs) + " " +
                sample_ram[idx] + " " + winstr)
        (out / f"{name}.cases").write_text("\n".join(case_lines) + "\n",
                                           encoding="utf-8")
        index.append({"pc": f"0x{pc:08x}", "name": name,
                      "pairs": len(pairs), "unique": len(uniq),
                      "unpaired": unpaired.get(pc, 0), "fingerprint": fp})
        print(f"{name}: {len(pairs)} pairs, {len(uniq)} unique, "
              f"{unpaired.get(pc, 0)} unpaired, fp={fp}")
    with open(out / "goldens_index.csv", "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["pc", "name", "pairs", "unique",
                                          "unpaired", "fingerprint"])
        w.writeheader()
        w.writerows(index)
    print(f"golden_extract: {len(index)} fns -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
