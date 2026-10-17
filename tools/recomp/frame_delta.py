#!/usr/bin/env python3
"""What the real machine changes in RAM during a tick beyond the recompiled tick itself.

  frame_delta.py 4 5 7 9 ...        (state labels; needs oracle_tick_s<N>.bin and flycast_exit_s<N>.bin)
  frame_delta.py --min 3 4 5 7 9    (only words that differ in at least 3 states)

Both images are the RAM after one scheduler tick: the oracle's has only the tick's own effects, the
emulator's also the interrupt handlers and main-loop code that ran in the same frame. Every 32-bit word
whose bytes differ is listed with how many states it differs in and the (hardware - oracle) deltas, so the
words that move by the same amount in every state (frame counters, timers) stand out from stack residue
and per-state data. Words inside the tick's own stack area (0x0C2C0000 and up) are skipped.
"""
import struct
import sys
from collections import defaultdict
from pathlib import Path

A = Path(__file__).resolve().parents[2] / 'extract' / 'analysis'
HDR = 54 * 4
BASE = 0x0C000000
STACK_FLOOR = 0x0C2C0000


def load(n):
    ora = (A / f'oracle_tick_s{n}.bin').read_bytes()
    hw = (A / f'flycast_exit_s{n}.bin').read_bytes()
    if len(ora) == len(hw) + HDR:
        ora = ora[HDR:]
    return ora, hw


def main():
    args = sys.argv[1:]
    least = 1
    if args[:1] == ['--min']:
        least = int(args[1])
        args = args[2:]
    seen = defaultdict(list)
    for n in args:
        ora, hw = load(n)
        for off in range(0, len(ora), 4):
            if ora[off:off + 4] != hw[off:off + 4] and BASE + off < STACK_FLOOR:
                o = struct.unpack_from('<I', ora, off)[0]
                h = struct.unpack_from('<I', hw, off)[0]
                seen[BASE + off].append((n, o, h))
    rows = sorted(seen.items())
    for addr, hits in rows:
        if len(hits) < least:
            continue
        deltas = sorted({(h - o) & 0xFFFFFFFF for _, o, h in hits})
        shown = ' '.join(f'{d:#x}' for d in deltas[:4])
        print(f'{addr:#010x}  states {len(hits):2d}  deltas {shown}{" ..." if len(deltas) > 4 else ""}')
    print(f'{sum(1 for _, h in rows if len(h) >= least)} words differ in at least {least} states')


if __name__ == '__main__':
    main()
