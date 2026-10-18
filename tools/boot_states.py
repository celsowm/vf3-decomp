#!/usr/bin/env python3
"""boot_states.py - run the loader-wait boot states natively with build/vf3boot and tabulate the result.

For every state in --states it makes sure the three inputs exist
  extract/analysis/golden_bootV_vf3_<N>.bin     loop-entry capture of 0x8C035CBA (tick_capture.py, needs the emulator fork)
  extract/analysis/gdstate_s<N>_0c0432de.txt    GD command state (converted from extract/analysis/gd_state/vf3_<N>.txt)
and runs the native wait loop plus the game code after it for --cap vblanks:

  python tools/boot_states.py --states 21 30 42 --cap 60
  python tools/boot_states.py --states 22 23 24 25 26 27 28 29 43 44 45 46 --capture --cap 60

The table (one row per state) goes to docs/boot_states.csv: wait result, hops, vblanks reached, unowned calls, failed pc,
GD sectors left. Interrupt-handler entry registers are borrowed from the state-30 captures (they only differ by stack).
"""
from __future__ import annotations

import argparse
import csv
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
A = REPO / 'extract' / 'analysis'
EXE = REPO / 'build' / 'vf3boot.exe'
FIELDS = ['last_request_id', 'next_request_id', 'status', 'command', 'params0', 'params1', 'params2', 'params3',
          'result0', 'result1', 'result2', 'result3', 'cur_sector', 'multi_read_sector', 'multi_read_offset',
          'multi_read_count']


def gdstate(n: int) -> Path | None:
    out = A / f'gdstate_s{n}_0c0432de.txt'
    if out.exists():
        return out
    src = A / 'gd_state' / f'vf3_{n}.txt'
    if not src.exists():
        return None
    vals = dict(line.split()[:2] for line in src.read_text().splitlines() if line.strip())
    out.write_text(' '.join(f'{int(vals[k], 16):08x}' if k != 'status' else f'{int(vals[k], 0):08x}' for k in FIELDS))
    return out


def capture(n: int, free: str = '') -> bool:
    name = 'freeA' if free else 'bootV'
    out = A / f'golden_{name}_vf3_{n}.bin'
    if out.exists():
        return True
    state = REPO / 'tools' / 'emu' / 'flycast-build' / 'data' / f'vf3_{n}.state'
    r = subprocess.run([sys.executable, str(REPO / 'tools' / 'tick_capture.py'), free or '0x8c035cba', '--state', str(state),
                        '--frames', '300', '--pairs', '1', '--exitpc', '0x8c0349a6', '--name', name],
                       capture_output=True, text=True, timeout=900)
    return out.exists()


def run(n: int, cap: int, timeout: int, free: str = '') -> dict:
    row: dict = {'state': n}
    v, g = A / f'golden_{"freeA" if free else "bootV"}_vf3_{n}.bin', gdstate(n)
    if not v.exists() or g is None:
        row['result'] = 'no capture' if not v.exists() else 'no gd state'
        return row
    cmd = [str(EXE), str(v), str(A / 'golden_bootI_vf3_30.bin'), str(A / 'golden_bootS_vf3_30.bin'),
           '--loop-entry', free or '0x8c035cba', '--loop-stop', '0x0c035530', *(['--free', '1'] if free else []), '--irqa', '0x8c063d1e', '--irqb', '0x8c062e94',
           '--cycle-frames', '300', '--first-polls', '531', '--gd-phase', '565440', '--full-loop', '1', '--continue', '4000',
           '--vblank-cap', str(cap), '--aica-word', '88:001e0000', '--gdi', str(REPO / 'rom' / 'vf3.gdi'), '--gd-state', str(g)]
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout, cwd=REPO)
    except subprocess.TimeoutExpired:
        row['result'] = 'timeout'
        return row
    text = p.stdout + p.stderr
    m = re.search(r'the wait function returned (-?\d+) to ([0-9a-f]+) after (\d+) iterations', text)
    row['wait'] = f'{m.group(1)}@{m.group(2)}/{m.group(3)}it' if m else 'no return'
    m = re.search(r'after the wait: ok (\d), pc ([0-9a-f]+), failed ([0-9a-f]+), unowned (\d+) \(first ([0-9a-f]+)\).*?(\d+) vblanks', text)
    if m:
        row.update(ok=m.group(1), pc=m.group(2), failed=m.group(3), unowned=m.group(4), first_unowned=m.group(5), vblanks=m.group(6))
    row['hops'] = len(re.findall(r'^\s+hop \d+', text, re.M))
    m = re.search(r'GD model: status (\d+), (\d+) sectors left, cur ([0-9a-f]+)', text)
    if m:
        row['gd'] = f'st{m.group(1)} left{m.group(2)} cur{m.group(3)}'
    capped = str(row.get('vblanks', '')).isdigit() and int(row['vblanks']) >= cap
    row['result'] = 'ok' if capped or (row.get('ok') == '1' and row.get('unowned') == '0') else ('fail' if m or 'ok' in row else 'no result')
    return row


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument('--states', type=int, nargs='+', required=True)
    ap.add_argument('--cap', type=int, default=60, help='vblanks to run after the wait')
    ap.add_argument('--capture', action='store_true', help='record missing loop captures with the emulator')
    ap.add_argument('--free', default='', help='pc: the states are plain game states, capture and run from this pc (no loader wait)')
    ap.add_argument('--timeout', type=int, default=600)
    ap.add_argument('--csv', default=str(REPO / 'docs' / 'boot_states.csv'))
    args = ap.parse_args()
    cols = ['state', 'result', 'wait', 'hops', 'vblanks', 'ok', 'pc', 'failed', 'unowned', 'first_unowned', 'gd']
    rows = []
    for n in args.states:
        if args.capture:
            capture(n, args.free)
        row = run(n, args.cap, args.timeout, args.free)
        rows.append(row)
        print(' '.join(f'{c}={row.get(c, "")}' for c in cols), flush=True)
    path = Path(args.csv)
    old = {}
    if path.exists():
        for r in csv.DictReader(path.open()):
            old[int(r['state'])] = r
    for r in rows:
        old[r['state']] = {c: r.get(c, '') for c in cols}
    with path.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=cols)
        w.writeheader()
        for n in sorted(old):
            w.writerow(old[n])
    return 0


if __name__ == '__main__':
    sys.exit(main())
