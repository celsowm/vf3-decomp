#!/usr/bin/env python3
"""mem_watch.py - who writes (or reads) a guest address range, in the emulator, from a savestate.

  python tools/mem_watch.py 21 0x8C1A0BE8 4 --frames 1500 --writes

Runs flycast (interpreter) from tools/emu/flycast-build/data/vf3_<N>.state with a `mem ADDR LEN` watch and prints the
hits: frame-less order, pc, size, read/write, address, value. Records are four u64 each:
(pc << 16) | 0xFA20, (size << 48) | (isWrite << 47), address, value (docs/re/ANALYSIS_STATE.md, M14).
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


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('state', type=int)
    ap.add_argument('addr')
    ap.add_argument('length')
    ap.add_argument('--frames', type=int, default=600)
    ap.add_argument('--writes', action='store_true', help='print only writes')
    ap.add_argument('--limit', type=int, default=60)
    ap.add_argument('--timeout', type=int, default=1800)
    a = ap.parse_args()
    addr, length = int(a.addr, 0), int(a.length, 0)
    stem = f'memwatch_vf3_{a.state}_{addr:x}'
    watch, trace, log = OUT / f'{stem}.txt', OUT / f'{stem}.bin', OUT / f'{stem}.log'
    watch.write_text(f'mem 0x{addr:X} 0x{length:X}\n')
    env = dict(os.environ)
    for k in ('VF3_CAPSULE', 'VF3_HITS', 'VF3_RAM_PATCH', 'VF3_ENTRY_PATCH'):
        env.pop(k, None)
    env.update({'VF3_INTERPRETER': '1', 'VF3_FULL': '1', 'VF3_WATCH': str(watch), 'VF3_TRACE': str(trace),
                'VF3_TRACE_FRAMES': str(a.frames), 'VF3_INSTR': '0',
                'VF3_STATE': str((REPO / 'tools' / 'emu' / 'flycast-build' / 'data' / f'vf3_{a.state}.state').resolve())})
    with open(log, 'w', encoding='utf-8', errors='replace') as lf:
        subprocess.run([str(EMU), str(ROM)], env=env, stdout=lf, stderr=lf, cwd=str(REPO), timeout=a.timeout)
    data = trace.read_bytes() if trace.exists() else b''
    shown = 0
    for i in range(0, len(data) - 31, 32):
        w0, w1, ad, val = struct.unpack_from('<QQQQ', data, i)
        if (w0 & 0xFFFF) != 0xFA20:
            continue
        is_w = (w1 >> 47) & 1
        if a.writes and not is_w:
            continue
        print(f'pc {w0 >> 16:08x} {"W" if is_w else "R"}{w1 >> 48} [{ad:08x}] = {val:08x}')
        shown += 1
        if shown >= a.limit:
            break
    print(f'{shown} hits shown ({len(data) // 32} records, trace {trace})', file=sys.stderr)
    return 0


if __name__ == '__main__':
    sys.exit(main())
