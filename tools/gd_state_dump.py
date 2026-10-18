#!/usr/bin/env python3
"""gd_state_dump.py - dump the GDFS/REIOS command state (gd_hle_state) stored in a flycast savestate.

Needs the local flycast fork built with the VF3_GDDUMP hook in core/reios/gdrom_hle.cpp (reios_deserialize). The
emulator is started on the savestate; as soon as the hook has written the text dump the process is stopped.

  python tools/gd_state_dump.py 20 21 22          # states tools/emu/flycast-build/data/vf3_<N>.state
  python tools/gd_state_dump.py --all             # every vf3_<N>.state

Output: extract/analysis/gd_state/vf3_<N>.txt (one "name value" line per field) and gd_state/summary.csv.
"""
from __future__ import annotations

import argparse
import csv
import os
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
EMU = REPO / 'tools' / 'emu' / 'flycast-build' / 'flycast.exe'
DATA = REPO / 'tools' / 'emu' / 'flycast-build' / 'data'
ROM = REPO / 'rom' / 'vf3.gdi'
OUT = REPO / 'extract' / 'analysis' / 'gd_state'
FIELDS = ['last_request_id', 'next_request_id', 'status', 'command', 'params0', 'params1', 'params2', 'params3',
          'result0', 'result1', 'result2', 'result3', 'cur_sector', 'multi_read_sector', 'multi_read_offset',
          'multi_read_count', 'multi_read_total', 'multi_callback', 'multi_callback_arg', 'dma_trans_ended',
          'xfer_end_time']


def dump_one(n: str, timeout: float) -> dict[str, str] | None:
    state = DATA / f'vf3_{n}.state'
    if not state.exists():
        print(f'state {n}: missing {state}')
        return None
    dst = OUT / f'vf3_{n}.txt'
    dst.unlink(missing_ok=True)
    env = dict(os.environ)
    for k in ('VF3_CAPSULE', 'VF3_HITS', 'VF3_RAM_PATCH', 'VF3_ENTRY_PATCH'):
        env.pop(k, None)
    env.update({'VF3_INTERPRETER': '1', 'VF3_STATE': str(state), 'VF3_GDDUMP': str(dst),
                'VF3_TRACE': str(OUT / 'scratch_trace.bin'), 'VF3_TRACE_FRAMES': '1', 'VF3_INSTR': '0'})
    log = OUT / f'vf3_{n}.log'
    with open(log, 'w', encoding='utf-8', errors='replace') as lf:
        p = subprocess.Popen([str(EMU), str(ROM)], env=env, stdout=lf, stderr=lf, cwd=str(REPO))
        t0 = time.time()
        while time.time() - t0 < timeout and not (dst.exists() and dst.stat().st_size > 0) and p.poll() is None:
            time.sleep(0.5)
        time.sleep(0.5)
        if p.poll() is None:
            p.terminate()
            try:
                p.wait(10)
            except subprocess.TimeoutExpired:
                p.kill()
    if not dst.exists():
        print(f'state {n}: no dump (see {log})')
        return None
    row = dict(line.split(None, 1) for line in dst.read_text().splitlines() if line.strip())
    row = {k: v.strip() for k, v in row.items()}
    row['state'] = n
    return row


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('states', nargs='*')
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--timeout', type=float, default=120)
    a = ap.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)
    states = a.states
    if a.all:
        states = sorted((p.stem[4:] for p in DATA.glob('vf3_*.state')), key=lambda s: int(s) if s.isdigit() else 0)
    rows = [r for r in (dump_one(n, a.timeout) for n in states) if r]
    with open(OUT / 'summary.csv', 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=['state'] + FIELDS)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, '') for k in ['state'] + FIELDS})
    for r in rows:
        print(r['state'], 'status', r.get('status'), 'cmd', r.get('command'), 'params', r.get('params0'),
              r.get('params1'), r.get('params2'), r.get('params3'), 'result2', r.get('result2'),
              'multi', r.get('multi_read_count'), '/', r.get('multi_read_total'))
    return 0


if __name__ == '__main__':
    sys.exit(main())
