#!/usr/bin/env python3
"""golden_batch.py — batch golden captures from the flycast oracle fork.

Runs the instrumented flycast once per scenario, collecting VF3_FULL traces
(entry/exit snapshots + RAM windows) and optional VF3_EDGES call-edge logs.
Then extracts .cases/.json/.txt goldens for all traces into one directory
with a batch_manifest.json.

Usage:
  python tools/golden_batch.py --name b2 --watch tools/watch/vf3_b2.txt \
      --out extract/analysis/goldens_b2 --frames 240 \
      --run fight:extract/analysis/vf3_fight_keep.state:tools/emu/vf3_play_m26.txt \
      --run boot::tools/emu/vf3_play_boot.txt:4200

Run spec: name:state:play:frames (empty state = boot; empty play = none).
The watch file drives which PCs are captured; "rampc <pc> [<base> <len>]"
lines add RAM dumps with optional per-PC windows.
"""
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
EMU = REPO / "tools" / "emu" / "flycast-build" / "flycast.exe"
ROM = REPO / "rom" / "vf3.gdi"


def parse_run(spec: str):
    parts = spec.split(":")
    if len(parts) < 2:
        raise SystemExit(f"bad --run '{spec}': want name:state:play:frames")
    name = parts[0]
    state = parts[1] if len(parts) > 1 else ""
    play = parts[2] if len(parts) > 2 else ""
    frames = int(parts[3]) if len(parts) > 3 and parts[3] else 0
    return name, state, play, frames


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", required=True, help="batch name (file prefix)")
    ap.add_argument("--watch", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--run", action="append", required=True,
                    help="name:state:play:frames (repeatable)")
    ap.add_argument("--frames", type=int, default=0,
                    help="default frames when the run spec omits them")
    ap.add_argument("--trace-dir", default="extract/analysis")
    ap.add_argument("--ramn", type=int, default=1)
    ap.add_argument("--ramnexit", type=int, default=-1)
    ap.add_argument("--max-samples", type=int, default=64)
    ap.add_argument("--edges", action="store_true", help="also log VF3_EDGES")
    ap.add_argument("--instr", action="store_true",
                    help="keep the full instruction stream (default: "
                         "snapshot-only traces)")
    ap.add_argument("--no-extract", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    watch = (REPO / a.watch) if not Path(a.watch).is_absolute() else Path(a.watch)
    if not watch.exists():
        raise SystemExit(f"watch file missing: {watch}")
    out = REPO / a.out
    trace_dir = REPO / a.trace_dir
    trace_dir.mkdir(parents=True, exist_ok=True)

    runs = []
    for spec in a.run:
        name, state, play, frames = parse_run(spec)
        frames = frames or a.frames
        trace = trace_dir / f"golden_{a.name}_{name}.bin"
        edges = trace_dir / f"edges_{a.name}_{name}.bin"
        log = trace_dir / f"golden_{a.name}_{name}.log"
        env = dict(os.environ)
        env.update({
            "VF3_INTERPRETER": "1",
            "VF3_FULL": "1",
            "VF3_WATCH": str(watch),
            "VF3_TRACE": str(trace),
            "VF3_TRACE_FRAMES": str(frames),
            "VF3_RAMN": str(a.ramn),
            "VF3_INSTR": "1" if a.instr else "0",
        })
        if a.ramnexit >= 0:
            env["VF3_RAMNEXIT"] = str(a.ramnexit)
        else:
            env.pop("VF3_RAMNEXIT", None)
        if a.edges:
            env["VF3_EDGES"] = str(edges)
        else:
            env.pop("VF3_EDGES", None)
        if state:
            env["VF3_STATE"] = str((REPO / state) if not Path(state).is_absolute()
                                   else Path(state))
        else:
            env.pop("VF3_STATE", None)
        if play:
            env["VF3_PLAY"] = str((REPO / play) if not Path(play).is_absolute()
                                  else Path(play))
        else:
            env.pop("VF3_PLAY", None)
        runs.append({"name": name, "state": state, "play": play,
                     "frames": frames, "trace": str(trace),
                     "edges": str(edges) if a.edges else "",
                     "log": str(log)})
        cmd = [str(EMU), str(ROM)]
        print(f"[{name}] frames={frames} state={state or '-'} play={play or '-'}")
        print(f"         trace -> {trace}")
        if a.dry_run:
            continue
        t0 = time.time()
        with open(log, "w", encoding="utf-8", errors="replace") as lf:
            p = subprocess.run(cmd, env=env, stdout=lf, stderr=lf,
                               cwd=str(REPO))
        dt = time.time() - t0
        sz = trace.stat().st_size if trace.exists() else 0
        print(f"         rc={p.returncode} in {dt:.0f}s, trace {sz/1e6:.1f} MB")
        if p.returncode != 0:
            print(f"         WARNING rc={p.returncode}; see {log}")

    manifest = {"name": a.name, "watch": str(watch), "ramn": a.ramn,
                "runs": runs}
    out.mkdir(parents=True, exist_ok=True)
    if not a.dry_run:
        (out / "batch_manifest.json").write_text(
            json.dumps(manifest, indent=1), encoding="utf-8")

    if a.no_extract or a.dry_run:
        return 0
    traces = [r["trace"] for r in runs if Path(r["trace"]).exists()]
    if not traces:
        print("no traces produced")
        return 1
    scen = ",".join(r["name"] for r in runs if Path(r["trace"]).exists())
    cmd = [sys.executable, str(REPO / "tools" / "golden_extract.py"),
           *traces, "--out", str(out), "--scenario", scen,
           "--max-samples", str(a.max_samples)]
    print("extract:", " ".join(cmd[1:]))
    p = subprocess.run(cmd, cwd=str(REPO))
    return p.returncode


if __name__ == "__main__":
    sys.exit(main())