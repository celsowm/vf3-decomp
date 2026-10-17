#!/usr/bin/env python3
"""scene_survey.py - find the per-frame scene function of a savestate from a VF3_EDGES call-edge log.

  python tools/scene_survey.py 2 [--frames 120]        # runs the emulator on tools/emu/flycast-build/data/vf3_2.state
  python tools/scene_survey.py --edges extract/analysis/p4/e2.bin

The function holding the most call edges at the shallowest depth is the scene's frame function; its most common
rts (the return edge inside it) gives the exit pc. Prints the tick_capture.py command line to capture it.
"""
import argparse
import bisect
import collections
import csv
import os
import struct
import subprocess
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
A = REPO / 'extract' / 'analysis'
EMU = REPO / 'tools' / 'emu' / 'flycast-build' / 'flycast.exe'
ROM = REPO / 'rom' / 'vf3.gdi'


def load_funcs():
    starts = []
    for r in csv.reader(open(A / 'funcs_1ST_READ.unsc.bin.csv')):
        try:
            starts.append(int(r[0], 16))
        except ValueError:
            pass
    starts.sort()
    return starts


def containing(starts, pc):
    i = bisect.bisect_right(starts, pc | 0x80000000) - 1
    return starts[i] if i >= 0 else 0


def run_edges(state, frames):
    out = A / 'p4'
    out.mkdir(exist_ok=True)
    watch = out / 'w.txt'
    watch.write_text('pc 0x8C096136\n')
    edges = out / f'e{state}.bin'
    env = dict(os.environ)
    env.update({'VF3_FULL': '1', 'VF3_INTERPRETER': '1', 'VF3_WATCH': str(watch), 'VF3_EDGES': str(edges),
                'VF3_TRACE': str(out / f't{state}.bin'), 'VF3_TRACE_FRAMES': str(frames), 'VF3_INSTR': '0',
                'VF3_STATE': str(EMU.parent / 'data' / f'vf3_{state}.state')})
    with open(out / f'l{state}.log', 'w') as lf:
        subprocess.run([str(EMU), str(ROM)], env=env, stdout=lf, stderr=lf, cwd=str(REPO), timeout=900)
    (out / f't{state}.bin').unlink(missing_ok=True)
    return edges


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('state', nargs='?')
    ap.add_argument('--edges')
    ap.add_argument('--frames', type=int, default=120)
    a = ap.parse_args()
    edges = Path(a.edges) if a.edges else run_edges(a.state, a.frames)
    d = edges.read_bytes()
    recs = [struct.unpack_from('<4I', d, 16 * i) for i in range(len(d) // 16)]
    calls = [r for r in recs if r[0] == 0]
    if not calls:
        print('no call edges')
        return 1
    dmin = min(r[3] for r in calls)
    starts = load_funcs()
    per = collections.Counter(containing(starts, r[1]) for r in calls if r[3] == dmin)
    fn, n = per.most_common(1)[0]
    rets = collections.Counter(r[1] | 0x80000000 for r in recs if r[0] == 1 and r[3] == dmin - 1
                               and containing(starts, r[1]) == fn)
    exitpc = rets.most_common(1)[0][0] if rets else None
    print(f'min depth {dmin}: frame function 0x{fn:08x} ({n} edges at that depth, {len(per)} candidates)')
    print('top candidates:', ', '.join(f'0x{f:08x}x{c}' for f, c in per.most_common(4)))
    if exitpc:
        print(f'python tools/tick_capture.py 0x{fn:08x} --state tools/emu/flycast-build/data/vf3_{a.state}.state '
              f'--frames 300 --pairs 1 --name p4scene --exitpc 0x{exitpc:08x}')
    else:
        print('no return edge seen for that function (it does not return inside the window)')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
