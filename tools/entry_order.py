#!/usr/bin/env python3
"""entry_order.py - in what order (and from where) does the emulator enter a set of functions, starting from a savestate.

  python tools/entry_order.py 21 0x8c068c58 0x8c0a7f5a 0x8c0a8aca --frames 900

Runs flycast (interpreter) with a `pc` watch per address and prints every entry: sequence number, function, pr (caller return
address) and r4. Entry records are (pc << 16) | 0xFA30, then 37 u64 values (r0-r15 first, pr at index 16), then an extra word.
"""
from __future__ import annotations

import argparse
import os
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
EMU = REPO / 'tools' / 'emu' / 'flycast-build' / 'flycast.exe'
ROM = REPO / 'rom' / 'vf3.gdi'
OUT = REPO / 'extract' / 'analysis'
NVALS = 37


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('state', type=int)
    ap.add_argument('pcs', nargs='+')
    ap.add_argument('--frames', type=int, default=600)
    ap.add_argument('--limit', type=int, default=80)
    ap.add_argument('--timeout', type=int, default=1800)
    a = ap.parse_args()
    pcs = [int(p, 0) for p in a.pcs]
    stem = f'entry_order_vf3_{a.state}'
    watch, trace, log = OUT / f'{stem}.txt', OUT / f'{stem}.bin', OUT / f'{stem}.log'
    watch.write_text(''.join(f'pc 0x{p:X}\n' for p in pcs))
    env = dict(os.environ)
    for k in ('VF3_CAPSULE', 'VF3_HITS', 'VF3_RAM_PATCH', 'VF3_ENTRY_PATCH'):
        env.pop(k, None)
    env.update({'VF3_INTERPRETER': '1', 'VF3_FULL': '1', 'VF3_WATCH': str(watch), 'VF3_TRACE': str(trace),
                'VF3_TRACE_FRAMES': str(a.frames), 'VF3_INSTR': '0',
                'VF3_STATE': str((REPO / 'tools' / 'emu' / 'flycast-build' / 'data' / f'vf3_{a.state}.state').resolve())})
    with open(log, 'w', encoding='utf-8', errors='replace') as lf:
        subprocess.run([str(EMU), str(ROM)], env=env, stdout=lf, stderr=lf, cwd=str(REPO), timeout=a.timeout)
    data = trace.read_bytes() if trace.exists() else b''
    recs = struct.unpack_from(f'<{len(data) // 8}Q', data)
    want = {p & 0x1FFFFFFF for p in pcs}
    n, i, shown = len(recs), 0, 0
    while i < n:
        if (recs[i] & 0xFFFF) == 0xFA30 and (recs[i] >> 16) & 0x1FFFFFFF in want and i + 17 < n:
            v = recs[i + 1:i + 1 + NVALS]
            print(f'#{shown:3d} fn {recs[i] >> 16:08x} pr {v[16] & 0xFFFFFFFF:08x} r4 {v[4] & 0xFFFFFFFF:08x} r5 {v[5] & 0xFFFFFFFF:08x}')
            shown += 1
            if shown >= a.limit:
                break
            i += 1 + NVALS + 1
        else:
            i += 1
    print(f'{shown} entries shown ({n} words, trace {trace})', file=sys.stderr)
    return 0


if __name__ == '__main__':
    sys.exit(main())
