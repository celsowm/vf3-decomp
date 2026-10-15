#!/usr/bin/env python3
"""ramdiff.py - native whole-tick RAM vs the captured hardware (flycast) exit RAM.

  python tools/recomp/ramdiff.py native_dump.bin flycast_exit.bin [oracle_dump.bin]

native_dump / oracle_dump use the oracle dump layout (54 x u32 registers, then 16 MiB RAM);
flycast_exit is the raw 16 MiB (TICK_EXITDUMP of tick_oracle).  Prints the differing runs,
labelled by whether the recompiled oracle agrees with the port or with hardware.
"""
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
HDR = 54 * 4


def runs(idx, gap=8):
    out = []
    for i in idx:
        if out and i - out[-1][1] <= gap:
            out[-1][1] = i
        else:
            out.append([i, i])
    return out


def main():
    nat = Path(sys.argv[1]).read_bytes()[HDR:]
    fly = Path(sys.argv[2]).read_bytes()
    orc = Path(sys.argv[3]).read_bytes()[HDR:] if len(sys.argv) > 3 else None
    diff = [i for i in range(len(fly)) if nat[i] != fly[i]]
    print(f'native vs hardware: {len(diff)} bytes in {len(runs(diff))} runs')
    for lo, hi in runs(diff):
        tag = ''
        if orc is not None:
            same = all(orc[i] == nat[i] for i in range(lo, hi + 1))
            tag = '  (oracle agrees with port)' if same else '  (oracle agrees with hardware)' if all(
                orc[i] == fly[i] for i in range(lo, hi + 1)) else ''
        print(f'  {RAM_BASE + lo:08x}..{RAM_BASE + hi:08x}{tag}')


if __name__ == '__main__':
    main()
