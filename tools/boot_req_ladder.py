#!/usr/bin/env python3
"""boot_req_ladder.py - check a native boot run against the GD request ladder.

The emulator savestates 21-29 each hold one GD read in flight, so their gdstate
files name the read the boot sequence had reached. If a native run issues the
same reads, in the same order, it follows the emulator's boot path. This is the
check used to validate the state-21 run after the FAD and AICA fixes.

  VF3_GDTRACE=1 build/vf3boot.exe ... 2> native_s21.log
  python tools/boot_req_ladder.py native_s21.log

Trace lines (src/fight/native_tick.c) look like:

    req cmd 17 params 00082282 00000056 0caae800 00000000

The triple compared is (params[0], params[1], params[2]) = FAD, sector count,
destination. FADs are resolved to file names through docs/files.md (the GD LBA
is the FAD minus the 150-sector pregap).

The first state's read is already in flight when the capture starts; a native
run that starts from that capture does not issue it again. It is reported as
"inherited" and skipped.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / 'extract' / 'analysis'
REQ = re.compile(r'req cmd\s+(\d+)\s+params\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)')
MANIFEST = re.compile(r'\| ([^|]+) \| (\d+) \| (\d+) \|')


def files_by_lba() -> list[tuple[str, int, int]]:
    out = []
    p = REPO / 'docs' / 'files.md'
    if not p.exists():
        return out
    for line in p.read_text(errors='replace').splitlines():
        m = MANIFEST.match(line)
        if m:
            out.append((m.group(1).strip(), int(m.group(2)), int(m.group(3))))
    return out


def file_at(fad: int, files) -> str:
    lba = fad - 150
    for name, start, size in files:
        if start <= lba < start + (size + 2047) // 2048:
            return name
    return '?'


def gdstate(n: int) -> list[int] | None:
    p = AN / f'gdstate_s{n}_0c0432de.txt'
    if not p.exists():
        return None
    return [int(v, 16) for v in p.read_text().split()]


def parse_trace(path: Path) -> list[tuple[int, int, int, int]]:
    """(command, fad, count, destination) for every REQ_CMD in the log."""
    out = []
    for line in path.read_text(errors='replace').splitlines():
        m = REQ.search(line)
        if m:
            out.append((int(m.group(1)), int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16)))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('trace', help='native stderr log captured with VF3_GDTRACE=1')
    ap.add_argument('--states', type=int, nargs='+', default=list(range(21, 30)))
    a = ap.parse_args()

    reqs = parse_trace(Path(a.trace))
    files = files_by_lba()
    print(f'{len(reqs)} REQ_CMD call(s) in {a.trace}')
    for i, (cmd, fad, count, dest) in enumerate(reqs):
        print(f'  #{i:<2} cmd {cmd:02x} fad {fad:08x} ({file_at(fad, files)}) '
              f'count {count:04x} dest {dest:08x}')

    pos = 0
    gap = None
    for n in a.states:
        st = gdstate(n)
        if st is None:
            print(f'state {n}: no gdstate file')
            continue
        fad, count, dest = st[4], st[5], st[6]
        name = file_at(fad, files)
        hit = next((i for i in range(pos, len(reqs)) if reqs[i][1:] == (fad, count, dest)), None)
        if n == a.states[0] and hit is None:
            print(f'state {n}: inherited  {name:<14} fad {fad:08x} count {count:04x} dest {dest:08x} '
                  f'(in flight when the capture starts)')
            continue
        if hit is None:
            print(f'state {n}: MISS       {name:<14} fad {fad:08x} count {count:04x} dest {dest:08x}')
            gap = n
            break
        print(f'state {n}: match #{hit:<2}  {name:<14} fad {fad:08x} count {count:04x} dest {dest:08x}')
        pos = hit + 1
    if gap:
        print(f'first gap: state {gap} (read not issued within this run)')
        return 1
    print('every ladder state reached in order')
    return 0


if __name__ == '__main__':
    sys.exit(main())
