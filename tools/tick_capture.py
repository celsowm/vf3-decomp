#!/usr/bin/env python3
"""tick_capture.py - capture full-RAM entry/exit pairs of one function from a
savestate with the flycast oracle fork (VF3_FULL + `rampc <pc>`).

Each pair is 2 x 16 MiB RAM (64 MiB of trace) + both register files; replay
with build/vf3tick.exe <entry> <trace> [pair]. This is deliberately NOT the
capsule/corpus pipeline: it keeps the whole machine RAM so a whole scheduler
tick (27 task handlers, interrupts included) can be diffed byte for byte.

  python tools/tick_capture.py 0x8c09616a --state tools/emu/flycast-build/data/vf3_7.state \
         --frames 600 --pairs 4 --name tick_s7

Output: extract/analysis/golden_<name>_<state>.bin (+ .log)
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
EMU = REPO / 'tools' / 'emu' / 'flycast-build' / 'flycast.exe'
ROM = REPO / 'rom' / 'vf3.gdi'


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('entry')
    ap.add_argument('--state', required=True)
    ap.add_argument('--frames', type=int, default=240)
    ap.add_argument('--pairs', type=int, default=2)
    ap.add_argument('--name', default='tick')
    ap.add_argument('--play', default='')
    ap.add_argument('--exitsp', default='', help='required (r15 - entry r15) at the exit rts, e.g. -4')
    ap.add_argument('--exitpc', default='', help='address of the exact rts that ends the function (boundary exit)')
    ap.add_argument('--timeout', type=int, default=1800)
    a = ap.parse_args()
    entry = int(a.entry, 16)
    out = REPO / 'extract' / 'analysis'
    stem = Path(a.state).stem
    trace = out / f'golden_{a.name}_{stem}.bin'
    log = out / f'golden_{a.name}_{stem}.log'
    watch = out / f'tickwatch_{a.name}_{stem}.txt'
    wl = f'rampc {entry:x}\nxfpc {entry:x}\n'
    if a.exitpc:
        wl += f'exitpc {entry:x} {int(a.exitpc, 16):x}' + (f' {int(a.exitsp)}' if a.exitsp else '') + '\n'
    watch.write_text(wl)
    env = dict(os.environ)
    for k in ('VF3_CAPSULE', 'VF3_HITS', 'VF3_RAM_PATCH', 'VF3_ENTRY_PATCH'):
        env.pop(k, None)
    env.update({'VF3_INTERPRETER': '1', 'VF3_FULL': '1', 'VF3_WATCH': str(watch),
                'VF3_TRACE': str(trace), 'VF3_TRACE_FRAMES': str(a.frames),
                'VF3_RAMN': str(a.pairs), 'VF3_RAMNEXIT': str(a.pairs),
                'VF3_INSTR': '0', 'VF3_STATE': str(Path(a.state).resolve())})
    if a.play:
        env['VF3_PLAY'] = str(Path(a.play).resolve())
    with open(log, 'w', encoding='utf-8', errors='replace') as lf:
        rc = subprocess.run([str(EMU), str(ROM)], env=env, stdout=lf, stderr=lf,
                            cwd=str(REPO), timeout=a.timeout).returncode
    print(f'rc={rc} trace={trace} ({trace.stat().st_size / 1e6:.0f} MB)')
    return rc


if __name__ == '__main__':
    sys.exit(main())
