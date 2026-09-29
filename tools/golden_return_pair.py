#!/usr/bin/env python3
"""Pair a watched function entry with a known caller return PC.

Use when the trace depth hook's inferred RTS exit includes later caller state.
The return PC must be the function entry's saved PR and occur once per call.
Both PCs must have full watches and matching per-PC RAM windows.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from collections import defaultdict, deque
from pathlib import Path

NVALS = 37


def read_records(path: Path):
    data = path.read_bytes()
    n = len(data) // 8
    return struct.unpack(f"<{n}Q", data[:n * 8])


def canonical(pc: str) -> int:
    return int(pc, 0) & 0x1FFFFFFF


def read_ram_group(recs, i):
    pc = (recs[i] >> 16) & 0xFFFFFFFF
    nwin = recs[i + 1] & 0xFFFFFFFF
    if nwin > 64:
        raise ValueError(f"invalid RAM window count {nwin} at record {i}")
    j = i + 2
    wins, blobs = [], []
    for _ in range(nwin):
        base = recs[j] & 0xFFFFFFFF
        length = recs[j + 1] & 0xFFFFFFFF
        nwords = length // 4
        words = recs[j + 2:j + 2 + nwords]
        if len(words) != nwords:
            raise ValueError(f"truncated RAM group at record {i}")
        wins.append((base, length))
        blobs.append(struct.pack(f"<{nwords}I", *(w & 0xFFFFFFFF for w in words)))
        j += 2 + nwords
    if j >= len(recs) or (recs[j] & 0xFFFF) != 0xFA51:
        raise ValueError(f"missing FA51 terminator at record {i}")
    return pc, wins, b"".join(blobs), j + 1


def events(path: Path, watched: set[int]):
    recs = read_records(path)
    hits = []
    last_hit = {}
    i = 0
    while i < len(recs):
        marker = recs[i] & 0xFFFF
        if marker == 0xFA30:
            pc = (recs[i] >> 16) & 0xFFFFFFFF
            if pc in watched:
                vals = recs[i + 1:i + 1 + NVALS]
                if len(vals) != NVALS or (recs[i + NVALS + 1] & 0xFFFF) != 0xFA31:
                    raise ValueError(f"malformed snapshot for {pc:08x}")
                hit = {"record": i, "pc": pc,
                       "regs": tuple(v & 0xFFFFFFFF for v in vals),
                       "ram": None}
                hits.append(hit)
                last_hit[pc] = hit
            i += NVALS + 2
            continue
        if marker == 0xFA50:
            pc, wins, blob, i = read_ram_group(recs, i)
            if pc in watched:
                hit = last_hit.get(pc)
                if hit is not None and hit["ram"] is None:
                    hit["ram"] = (wins, blob)
            continue
        i += 1
    return hits


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("trace", nargs="+", help="VF3_FULL trace files")
    ap.add_argument("--entry-pc", required=True)
    ap.add_argument("--return-pc", required=True,
                    help="comma-separated possible saved-PR return PCs")
    ap.add_argument("--scenario", default="capture",
                    help="one name or a comma-separated name per trace")
    ap.add_argument("--out", required=True)
    ap.add_argument("--max-samples", type=int, default=64)
    a = ap.parse_args()

    entry_pc = canonical(a.entry_pc)
    return_pcs = {canonical(pc) for pc in a.return_pc.split(",")}
    scenarios = a.scenario.split(",")
    if len(scenarios) == 1:
        scenarios *= len(a.trace)
    if len(scenarios) != len(a.trace):
        raise SystemExit("--scenario count must be one or match trace count")

    paired = []
    for trace_name, scenario in zip(a.trace, scenarios):
        hits = events(Path(trace_name), return_pcs | {entry_pc})
        pending = defaultdict(deque)
        pairs = []
        for hit in hits:
            if hit["pc"] == entry_pc:
                target = hit["regs"][16] & 0x1FFFFFFF
                if target not in return_pcs:
                    raise SystemExit(f"{trace_name}: un-watched saved PR {target:08x}")
                pending[target].append(hit)
            elif hit["pc"] in return_pcs and pending[hit["pc"]]:
                entry = pending[hit["pc"]].popleft()
                pairs.append((entry, hit))
        if not pairs:
            continue
        ram_pairs = 0
        for entry, ret in pairs:
            if entry["ram"] is None or ret["ram"] is None:
                continue
            if entry["ram"][0] != ret["ram"][0]:
                raise SystemExit(f"{trace_name}: RAM windows differ")
            paired.append({"scenario": scenario, "in": entry["regs"],
                           "out": ret["regs"], "ram_wins": entry["ram"][0],
                           "ram": entry["ram"][1], "xram": ret["ram"][1]})
            ram_pairs += 1
        print(f"{trace_name}: {len(pairs)} matched calls, {ram_pairs} with RAM")

    seen = set()
    unique = []
    for p in paired:
        key = (p["in"], p["out"], p["ram"], p["xram"])
        if key in seen:
            continue
        seen.add(key)
        unique.append(p)
        if len(unique) >= a.max_samples:
            break
    if not unique:
        raise SystemExit("no paired states")

    outdir = Path(a.out)
    outdir.mkdir(parents=True, exist_ok=True)
    name = f"f_{entry_pc:08x}"
    lines = []
    fingerprint = hashlib.sha256()
    for k, p in enumerate(unique):
        rp = f"{name}.ram{k}.bin"
        xp = f"{name}.exitram{k}.bin"
        (outdir / rp).write_bytes(p["ram"])
        (outdir / xp).write_bytes(p["xram"])
        winstr = str(len(p["ram_wins"])) + "".join(
            f" 0x{base:08x} 0x{length:x}" for base, length in p["ram_wins"])
        fingerprint.update(struct.pack(f"<{NVALS * 2}I", *p["in"], *p["out"]))
        fingerprint.update(p["ram"])
        fingerprint.update(p["xram"])
        lines.append(" ".join(f"{v:08x}" for v in (*p["in"], *p["out"]))
                      + f" {rp} {winstr} {xp} {winstr}")
    (outdir / f"{name}.cases").write_text("\n".join(lines) + "\n", encoding="utf-8")
    metadata = {
        "entry_pc": f"0x{entry_pc:08x}",
        "return_pcs": [f"0x{pc:08x}" for pc in sorted(return_pcs)],
        "pairs": len(paired), "unique": len(unique), "unpaired": 0,
        "scenarios": scenarios, "fingerprint": fingerprint.hexdigest()[:16],
        "ram_wins": [f"0x{b:08x} 0x{n:x}" for b, n in unique[0]["ram_wins"]],
    }
    (outdir / f"{name}.return_pair.json").write_text(
        json.dumps(metadata, indent=2) + "\n", encoding="utf-8")
    print(f"{name}: {len(paired)} chronological pairs, {len(unique)} unique; "
          f"return-PCs {','.join(f'{pc:08x}' for pc in sorted(return_pcs))}; "
          f"fp={metadata['fingerprint']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
