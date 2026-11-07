#!/usr/bin/env python3
"""Trace guest RAM reads/writes while replaying a saved state.

Legacy use:
  python tools/mem_watch.py 21 0x8C1A0BE8 4 --frames 1500 --writes

Watch multiple fields while replaying controls:
  python tools/mem_watch.py tools/emu/flycast-build/data/vf3_29.state \
      --watch-range 0x0C1FF020:2 --watch-range 0x0C2019E4:2 \
      --play tools/vf3_play_motion_strikes.txt --frames 1800 \
      --emulator tools/emu/flycast-build/flycast_v3.exe --name motion_s29

The trace preserves access order, PC, width, read/write, address and value,
but has no frame timestamp. Each record is four u64s:
``(pc << 16) | 0xFA20, (size << 48) | (isWrite << 47), address, value``
(docs/re/ANALYSIS_STATE.md, M14).
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path

from mem_trace_decode import decode_trace, parse_range

REPO = Path(__file__).resolve().parent.parent
EMU = REPO / 'tools' / 'emu' / 'flycast-build' / 'flycast.exe'
ROM = REPO / 'rom' / 'vf3.gdi'
OUT = REPO / 'extract' / 'analysis'


def resolve_path(path: Path) -> Path:
    return path.resolve() if path.is_absolute() else (REPO / path).resolve()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('state', nargs='?',
                    help='state number (e.g. 21) or savestate path')
    ap.add_argument('addr', nargs='?', help='legacy single watched address')
    ap.add_argument('length', nargs='?', help='legacy watched byte length')
    ap.add_argument('--watch-range', action='append', type=parse_range,
                    help='watched ADDRESS:LENGTH; repeat for multiple ranges')
    ap.add_argument('--decode-trace', type=Path,
                    help='decode a retained memory trace without launching Flycast')
    ap.add_argument('--play', type=Path,
                    help='optional Flycast control script to run after state load')
    ap.add_argument('--emulator', type=Path, default=EMU,
                    help=f'emulator executable (default: {EMU})')
    ap.add_argument('--out-dir', type=Path, default=OUT,
                    help=f'directory for watch, trace and log files (default: {OUT})')
    ap.add_argument('--name', help='output file stem (default derives from state/range)')
    ap.add_argument('--frames', type=int, default=600)
    ap.add_argument('--writes', action='store_true', help='print only writes')
    ap.add_argument('--changes-only', action='store_true',
                    help='print only the first value and changes per address')
    ap.add_argument('--limit', type=int, default=60,
                    help='maximum printed hits; 0 prints all (default: 60)')
    ap.add_argument('--timeout', type=int, default=1800)
    a = ap.parse_args()

    if a.decode_trace is not None:
        if a.state is not None or a.addr is not None or a.length is not None or a.play:
            ap.error('--decode-trace cannot be combined with a state or --play')
        if a.watch_range and (a.addr is not None or a.length is not None):
            ap.error('use --watch-range or positional addr/length, not both')
        if a.addr is not None or a.length is not None:
            ap.error('use --watch-range to filter a retained trace')
        if not a.decode_trace.is_absolute():
            a.decode_trace = resolve_path(a.decode_trace)
        return decode_trace(a.decode_trace, a.watch_range, a.writes,
                            a.changes_only, a.limit)
    if a.state is None:
        ap.error('provide a state, or use --decode-trace TRACE')

    if a.watch_range:
        if a.addr is not None or a.length is not None:
            ap.error('use positional addr/length or --watch-range, not both')
        ranges = a.watch_range
    else:
        if a.addr is None or a.length is None:
            ap.error('provide positional addr and length, or at least one --watch-range')
        ranges = [parse_range(f'{a.addr}:{a.length}')]
    if a.frames <= 0 or a.limit < 0 or a.timeout < 0:
        ap.error('--frames must be positive; --limit and --timeout cannot be negative')

    raw_state = Path(a.state)
    if a.state.isdecimal():
        state = (REPO / 'tools' / 'emu' / 'flycast-build' / 'data' /
                 f'vf3_{a.state}.state').resolve()
        state_label = a.state
    else:
        state = resolve_path(raw_state)
        state_label = state.stem.removeprefix('vf3_')
    emulator = resolve_path(a.emulator)
    play = resolve_path(a.play) if a.play else None
    out_dir = resolve_path(a.out_dir)
    for label, path in (('savestate', state), ('emulator', emulator)):
        if not path.is_file():
            ap.error(f'{label} does not exist: {path}')
    if play is not None and not play.is_file():
        ap.error(f'play script does not exist: {play}')
    if a.name and Path(a.name).name != a.name:
        ap.error('--name must be a file stem without directory components')

    stem = a.name or f'memwatch_vf3_{state_label}_{ranges[0][0]:x}'
    watch, trace, log = (out_dir / f'{stem}.txt', out_dir / f'{stem}.bin',
                         out_dir / f'{stem}.log')
    existing = [path for path in (watch, trace, log) if path.exists()]
    if existing:
        ap.error('refusing to overwrite existing evidence files: ' +
                 ', '.join(str(path) for path in existing))
    out_dir.mkdir(parents=True, exist_ok=True)
    watch.write_text(''.join(f'mem 0x{addr:X} 0x{length:X}\n'
                             for addr, length in ranges), encoding='ascii')

    env = dict(os.environ)
    for key in ('VF3_CAPSULE', 'VF3_HITS', 'VF3_RAM_PATCH', 'VF3_ENTRY_PATCH'):
        env.pop(key, None)
    env.update({'VF3_INTERPRETER': '1', 'VF3_FULL': '1',
                'VF3_WATCH': str(watch), 'VF3_TRACE': str(trace),
                'VF3_TRACE_FRAMES': str(a.frames), 'VF3_INSTR': '0',
                'VF3_STATE': str(state)})
    if play is not None:
        env['VF3_PLAY'] = str(play)
    else:
        env.pop('VF3_PLAY', None)

    try:
        with open(log, 'w', encoding='utf-8', errors='replace') as log_file:
            proc = subprocess.run([str(emulator), str(ROM)], env=env,
                                  stdout=log_file, stderr=log_file,
                                  cwd=str(REPO), timeout=a.timeout)
    except subprocess.TimeoutExpired:
        print(f'mem_watch: emulator timed out after {a.timeout}s; see {log}',
              file=sys.stderr)
        return 2

    decode_result = decode_trace(trace, ranges, a.writes,
                                 a.changes_only, a.limit)
    return proc.returncode if proc.returncode else decode_result


if __name__ == '__main__':
    sys.exit(main())
