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

Run spec: name:state:play:frames[:ram_patch] (empty state = boot; empty play = none).
The watch file drives which PCs are captured; "rampc <pc> [<base> <len>]"
lines add RAM dumps with optional per-PC windows.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import subprocess
import sys
import time
from pathlib import Path
from oracle.capture_frames import expected_frames, observed_frames

REPO = Path(__file__).resolve().parents[1]
EMU = REPO / "tools" / "emu" / "flycast-build" / "flycast.exe"
ROM = REPO / "rom" / "vf3.gdi"


def parse_run(spec: str):
    parts = spec.split(":")
    if len(parts) < 2:
        raise SystemExit(f"bad --run '{spec}': want name:state:play:frames[:ram_patch]")
    if len(parts) > 5:
        raise SystemExit(f"bad --run '{spec}': too many fields")
    name = parts[0]
    state = parts[1] if len(parts) > 1 else ""
    play = parts[2] if len(parts) > 2 else ""
    frames = int(parts[3]) if len(parts) > 3 and parts[3] else 0
    patch = parts[4] if len(parts) > 4 else ""
    return name, state, play, frames, patch


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", required=True, help="batch name (file prefix)")
    ap.add_argument("--watch", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument('--emulator', type=Path, default=EMU,
                    help='explicit immutable oracle executable; default is the local build')
    ap.add_argument("--entry-patch", default="",
                    help="VF3_ENTRY_PATCH synthetic trigger/target fixture")
    ap.add_argument("--run", action="append", required=True,
                    help="name:state:play:frames[:ram_patch] (repeatable)")
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
    ap.add_argument("--capsule", action="store_true",
                    help="capture touched RAM pages and aligned XF/FPUL state")
    ap.add_argument("--hits", action="store_true",
                    help="count watched entry hits without invocation or RAM capture")
    ap.add_argument("--probe-debug", action="store_true",
                    help="record per-run synthetic-entry probe accounting "
                         "(VF3_ORACLE_DEBUG) next to the capsule log")
    ap.add_argument("--probe-offset", type=int, default=0,
                    help="start the seed sweep at this variant index "
                         "(VF3_PROBE_CURSOR); use to walk a long seed plan "
                         "across successive runs")
    ap.add_argument('--probe-ops', type=int,
                    help='synthetic-call budget, 1..100000; recorded in run provenance')
    ap.add_argument('--rollback-text-control', action='store_true',
                    help='headless original PVR TEXT_CONTROL checkpoint/restore pilot')
    ap.add_argument('--rollback-aica-ram', action='store_true',
                    help='headless canonical sound RAM journal; reject scheduler crossings')
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument('--timeout', type=int, default=0,
                    help='maximum seconds per emulator run; zero disables the limit')
    ap.add_argument('--probe-only', action='store_true',
                    help='capture redirected probes only, without natural watch entries')
    ap.add_argument('--probe-children', action='store_true',
                    help='capture nested watched entries only while a rollback probe is active')
    a = ap.parse_args()
    if a.rollback_text_control and not (a.capsule and a.entry_patch):
        ap.error('--rollback-text-control requires --capsule and --entry-patch')
    if a.rollback_aica_ram and not (a.capsule and a.entry_patch):
        ap.error('--rollback-aica-ram requires --capsule and --entry-patch')
    if a.probe_ops is not None and not 1 <= a.probe_ops <= 100000:
        ap.error('--probe-ops must be 1..100000 (the oracle record limit)')
    if a.hits and (a.capsule or a.instr or a.edges):
        ap.error('--hits cannot be combined with --capsule, --instr or --edges')

    watch = (REPO / a.watch) if not Path(a.watch).is_absolute() else Path(a.watch)
    if not watch.exists():
        raise SystemExit(f"watch file missing: {watch}")
    out = REPO / a.out
    entry_patch = ((REPO / a.entry_patch) if not Path(a.entry_patch).is_absolute()
                   else Path(a.entry_patch)) if a.entry_patch else None
    if entry_patch and not entry_patch.is_file():
        raise SystemExit(f"entry patch missing: {entry_patch}")
    emulator = a.emulator if a.emulator.is_absolute() else REPO / a.emulator
    trace_dir = REPO / a.trace_dir
    trace_dir.mkdir(parents=True, exist_ok=True)

    runs = []
    for spec in a.run:
        name, state, play, frames, patch = parse_run(spec)
        frames = frames or a.frames
        trace = trace_dir / f"golden_{a.name}_{name}.bin"
        edges = trace_dir / f"edges_{a.name}_{name}.bin"
        log = trace_dir / f"golden_{a.name}_{name}.log"
        env = dict(os.environ)
        capsule = trace_dir / f"capsule_{a.name}_{name}.bin"
        hits = trace_dir / f"hits_{a.name}_{name}.csv"
        env.pop("VF3_CAPSULE", None)
        env.pop("VF3_HITS", None)
        env.pop("VF3_RAM_PATCH", None)
        env.pop("VF3_ENTRY_PATCH", None)
        env.pop('VF3_PROBE_ONLY', None)
        env.pop('VF3_PROBE_CHILDREN', None)
        env.pop('VF3_ROLLBACK_TEXT_CONTROL', None)
        env.pop('VF3_ROLLBACK_AICA_RAM', None)
        if a.rollback_aica_ram:
            env['VF3_ROLLBACK_AICA_RAM'] = '1'
        if a.rollback_text_control:
            env['VF3_ROLLBACK_TEXT_CONTROL'] = '1'
        patch_path = ((REPO / patch) if not Path(patch).is_absolute() else Path(patch)) if patch else None
        if patch_path:
            if not patch_path.is_file():
                raise SystemExit(f"RAM patch missing: {patch_path}")
            env["VF3_RAM_PATCH"] = str(patch_path)
        if entry_patch:
            env["VF3_ENTRY_PATCH"] = str(entry_patch)
            if a.probe_ops is not None:
                env['VF3_PROBE_OPS'] = str(a.probe_ops)
            if a.probe_only or a.probe_children:
                env['VF3_PROBE_ONLY'] = '1'
            if a.probe_children:
                env['VF3_PROBE_CHILDREN'] = '1'
        if a.probe_debug and entry_patch and a.capsule:
            probe_debug = trace_dir / f"probe_{a.name}_{name}.json"
            env["VF3_ORACLE_DEBUG"] = str(probe_debug)
        else:
            probe_debug = None
            env.pop("VF3_ORACLE_DEBUG", None)
        if a.probe_offset:
            env["VF3_PROBE_CURSOR"] = str(a.probe_offset)
        else:
            env.pop("VF3_PROBE_CURSOR", None)
        if a.capsule:
            env["VF3_CAPSULE"] = str(capsule)
            env["VF3_CAPSULE_N"] = str(a.max_samples)
        if a.hits:
            env["VF3_HITS"] = str(hits)
        env.update({
            "VF3_INTERPRETER": "1",
            "VF3_FULL": "1",
            "VF3_WATCH": str(watch),
            "VF3_TRACE": str(trace),
            "VF3_TRACE_FRAMES": str(frames),
            "VF3_RAMN": str(a.ramn),
            "VF3_INSTR": "1" if a.instr else "0",
        })
        if (a.capsule and not a.instr) or a.hits:
            # Sparse invocation records replace redundant whole-frame traces.
            env.pop("VF3_TRACE", None)
            env.pop("VF3_FULL", None)
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
        if patch_path:
            runs[-1]["ram_patch"] = str(patch_path)
            runs[-1]["ram_patch_sha256"] = hashlib.sha256(patch_path.read_bytes()).hexdigest()
        if entry_patch:
            runs[-1]["entry_patch"] = str(entry_patch)
            runs[-1]["entry_patch_sha256"] = hashlib.sha256(entry_patch.read_bytes()).hexdigest()
            runs[-1]['probe_ops'] = int(env.get('VF3_PROBE_OPS', '20000'))
            runs[-1]['rollback_text_control'] = a.rollback_text_control
            runs[-1]['rollback_aica_ram'] = a.rollback_aica_ram
            if not a.dry_run:
                runs[-1]['emulator'] = str(emulator)
                with emulator.open('rb') as executable:
                    runs[-1]['emulator_sha256'] = hashlib.file_digest(executable, 'sha256').hexdigest()
                runs[-1]['oracle_source_sha256'] = hashlib.sha256(
                    (REPO / 'tools/oracle/vf3oracle.cpp').read_bytes()).hexdigest()
        if a.capsule:
            runs[-1]["capsule"] = str(capsule)
        if probe_debug:
            runs[-1]["probe_debug"] = str(probe_debug)
        if a.hits:
            runs[-1]["hits"] = str(hits)
        cmd = [str(emulator), str(ROM)]
        print(f"[{name}] frames={frames} state={state or '-'} play={play or '-'}")
        print(f"         trace -> {trace}")
        if a.dry_run:
            continue
        t0 = time.time()
        with open(log, "w", encoding="utf-8", errors="replace") as lf:
            process = subprocess.Popen(cmd, env=env, stdout=lf, stderr=lf,
                                       cwd=str(REPO))
            try:
                returncode = process.wait(timeout=a.timeout or None)
            except subprocess.TimeoutExpired:
                if os.name == 'nt':
                    subprocess.run(['taskkill', '/PID', str(process.pid), '/T', '/F'],
                                   stdout=lf, stderr=lf)
                else:
                    process.kill()
                process.wait()
                returncode = 124
        dt = time.time() - t0
        observed=observed_frames(log)
        expected=expected_frames(frames,(REPO/play) if play and not Path(play).is_absolute() else play)
        complete=observed>=expected>=1
        runs[-1].update(seconds=round(dt,3), returncode=returncode or (0 if complete else 1),
                        emulator_returncode=returncode,ran_frames=observed,expected_frames=expected,
                        frame_complete=complete,
                        capsule_bytes=capsule.stat().st_size if a.capsule and capsule.exists() else 0)
        sz = trace.stat().st_size if trace.exists() and not a.hits else 0
        print(f"         rc={returncode} in {dt:.0f}s, trace {sz/1e6:.1f} MB")
        if returncode != 0 or not complete:
            print(f"         WARNING rc={returncode}, frames={observed}/{expected}; see {log}")
        out.mkdir(parents=True, exist_ok=True)
        (out / 'batch_manifest.json').write_text(json.dumps(dict(
            name=a.name, watch=str(watch), ramn=a.ramn, runs=runs), indent=1))

    manifest = {"name": a.name, "watch": str(watch), "ramn": a.ramn,
                "runs": runs}
    out.mkdir(parents=True, exist_ok=True)
    if not a.dry_run:
        (out / "batch_manifest.json").write_text(
            json.dumps(manifest, indent=1), encoding="utf-8")

    if a.no_extract or a.dry_run or a.hits:
        return int(any(r.get('returncode',0) for r in runs))
    if any(r.get('returncode',0) for r in runs):
        print('capture batch failed; refusing to export goldens')
        return 1
    if a.capsule:
        cmd = [sys.executable, str(REPO / "tools/oracle/capsules.py"),
               *[r["capsule"] for r in runs], "--out", str(out)]
        return subprocess.run(cmd, cwd=REPO).returncode
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
