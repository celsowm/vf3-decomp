#!/usr/bin/env python3
"""chain_ticks.py - run the reference oracle on K consecutive scheduler ticks of one captured state.

  python tools/recomp/chain_ticks.py <state> <K> [--label NAME] [--code-check]
  CHAIN_RESET=0x0c16ca44:8 python ...   rewind the display-list ring cursors to their tick-1 values every tick
  TICK_QACR0=0x10 python ...            force the store-queue area (the captured QACR can predate the game's own)

Starts from extract/analysis/golden_tickx_vf3_<state>.bin, runs the oracle (refs/dream-recomp build) for tick 1,
feeds its exit RAM in as the entry RAM of tick 2, and so on, with no interrupts or main-loop code between ticks
(the same model as `vf3 --ticks`). Only the last tick is recorded in full. The outputs, named with <NAME>
(default c<state>_<K>), are what tools/recomp/run_state.sh and verify_port.sh read for a state called <NAME>:
  golden_tickx_vf3_<NAME>.bin   entry state of tick K (exit side is a leftover and unused)
  fxr_tick_s<NAME>.bin, _stats.csv, oracle_tick_s<NAME>.bin, devlog_tick_s<NAME>.bin, tick_s<NAME>_pcs.txt: the oracle's records of tick K
Local scaffold: needs the GPL dream-recomp oracle build that is gitignored under refs/."""
import array
import os
import shutil
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
A = REPO / 'extract' / 'analysis'
ORACLE = REPO / 'refs/dream-recomp/build-vf3/games/vf3tb/vf3tb_tick.exe'
RAM_BASE, RAM_LEN, HEADER = 0x0C000000, 0x01000000, 54 * 4


def ram_offset(path):
    """Index (in 64-bit records) of the first entry-RAM word of pair 0 in a tick recording."""
    rec = array.array('Q')
    with open(path, 'rb') as f:
        rec.fromfile(f, os.path.getsize(path) // 8)
    i = 0
    while not ((rec[i] >> 16) != 0 and (rec[i] & 0xFFFF) == 0xFA30):
        i += 1
    i += 38
    while not ((rec[i] >> 16) != 0 and (rec[i] & 0xFFFF) == 0xFA50):
        i += 1
    nwin = rec[i + 1]
    i += 2
    for _ in range(nwin):
        base, length = rec[i], rec[i + 1]
        i += 2
        if base == RAM_BASE and length == RAM_LEN:
            return i
        i += length // 4
    raise SystemExit(f'{path}: no entry RAM window')


CODE_CHECK = False
TEXT_BASE = int(os.environ.get('CHAIN_TEXT_BASE', '0x0C010000'), 0)


TEXT_LEN = int(os.environ.get('CHAIN_TEXT_LEN', '0xF0000'), 0)
MIN_RUN = int(os.environ.get('CHAIN_MIN_RUN', '8'))
_text_ref = []


def code_damage(dump):
    """Words of the program text (TEXT_BASE.., TEXT_LEN bytes) that differ from the text after tick 1."""
    with open(dump, 'rb') as f:
        f.seek(HEADER + (TEXT_BASE - RAM_BASE))
        ram = f.read(TEXT_LEN)
    if not _text_ref:
        _text_ref.append(ram)
        return []
    ref = _text_ref[0]
    changed = [i for i in range(0, TEXT_LEN - 3, 4) if ref[i:i + 4] != ram[i:i + 4]]
    runs, run = [], []
    for i in changed + [None]:
        if run and (i is None or i != run[-1] + 4):
            if len(run) >= MIN_RUN:
                runs.append(run)
            run = []
        if i is not None:
            run.append(i)
    return [(TEXT_BASE + r[0], int.from_bytes(ref[r[0]:r[0] + 4], 'little'), int.from_bytes(ram[r[0]:r[0] + 4], 'little'))
            for r in runs]


def patch(golden, dump, out, offset):
    shutil.copyfile(golden, out)
    words = array.array('I')
    with open(dump, 'rb') as f:
        f.seek(HEADER)
        words.fromfile(f, RAM_LEN // 4)
    wide = array.array('Q', words)
    with open(out, 'r+b') as f:
        f.seek(offset * 8)
        wide.tofile(f)


def frame_reset(path, base, offset):
    """Put the words listed in CHAIN_RESET ("addr:bytes,addr:bytes", RAM addresses) back to their tick-1 values.

    The real main loop rewinds the display-list ring cursors once per frame; chained ticks have no main loop,
    so without this the cursors march up through RAM until they overwrite program text."""
    spec = os.environ.get('CHAIN_RESET', '')
    if not spec:
        return
    with open(base, 'rb') as f:
        for item in spec.split(','):
            addr, length = (int(x, 0) for x in item.split(':'))
            first = offset + (addr - RAM_BASE) // 4
            f.seek(first * 8)
            words = array.array('Q')
            words.fromfile(f, length // 4)
            with open(path, 'r+b') as o:
                o.seek(first * 8)
                words.tofile(o)


def oracle(golden, env_extra):
    env = dict(os.environ, TICK_GBR='0x0c16b880', TICK_INTERP='1', **env_extra)
    r = subprocess.run([str(ORACLE), '0x8c09616a', str(golden), '0'], env=env, capture_output=True, text=True)
    return r.returncode, next((l for l in r.stdout.splitlines() if l.startswith('run: FAULT')), None)


def main(state, k, label):
    base = A / f'golden_tickx_vf3_{state}.bin'
    offset = ram_offset(base)
    cur = base
    tmp_dump = A / f'_chain_dump_{label}.bin'
    tmp_gold = A / f'_chain_gold_{label}.bin'
    for t in range(1, k + 1):
        last = t == k
        env = {'TICK_DUMP': str(tmp_dump)}
        if last:
            env.update(TICK_REC=str(A / f'fxr_tick_s{label}.bin'), TICK_STATS=str(A / f'fxr_tick_s{label}_stats.csv'),
                       TICK_DEVLOG=str(A / f'devlog_tick_s{label}.bin'), TICK_PCS=str(A / f'tick_s{label}_pcs.txt'))
        _, fault = oracle(cur, env)
        if fault:
            print(f'tick {t}: oracle {fault[:160]}', flush=True)
            raise SystemExit(1)
        if not tmp_dump.exists() or tmp_dump.stat().st_size != HEADER + RAM_LEN:
            raise SystemExit(f'tick {t}: the oracle produced no dump')
        if CODE_CHECK:
            bad = code_damage(tmp_dump)
            if bad:
                print(f'tick {t}: program text changed in {len(bad)} runs, first {bad[0][0]:#010x} '
                      f'was {bad[0][1]:#010x} now {bad[0][2]:#010x}', flush=True)
                raise SystemExit(1)
        if last:
            shutil.copyfile(cur, A / f'golden_tickx_vf3_{label}.bin') if cur == base else None
            if cur != base:
                os.replace(cur, A / f'golden_tickx_vf3_{label}.bin')
            os.replace(tmp_dump, A / f'oracle_tick_s{label}.bin')
            print(f'tick {t} recorded as state {label}')
            return
        patch(base, tmp_dump, tmp_gold, offset)
        frame_reset(tmp_gold, base, offset)
        if cur != base:
            os.remove(cur)
        cur = A / f'_chain_cur_{label}.bin'
        os.replace(tmp_gold, cur)
        os.remove(tmp_dump)
        print(f'tick {t} done', flush=True)


if __name__ == '__main__':
    args = sys.argv[1:]
    label = None
    if '--label' in args:
        j = args.index('--label'); label = args[j + 1]; del args[j:j + 2]
    if '--code-check' in args:
        CODE_CHECK = True
        args.remove('--code-check')
    if len(args) != 2:
        raise SystemExit(__doc__)
    main(args[0], int(args[1]), label or f'c{args[0]}_{args[1]}')
