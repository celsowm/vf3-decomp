#!/usr/bin/env python3
"""boot_walk.py - grow the boot module until the disc boot stops hitting
unowned code.

Runs vf3sdl from a boot state (tools/make_boot_state.py), reads the first
unowned PC, adds it to the boot module's watch file, regenerates
src/fight/vf3_boot_adapter.c with the repo's translator, rebuilds and repeats.

  python tools/boot_walk.py extract/analysis/p3/boot.state --entry 0x8c010100
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
WATCH = ROOT / 'extract' / 'analysis' / 'gen_translate_watch.txt'


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or '').split('\n')[0])
    ap.add_argument('state', type=Path)
    ap.add_argument('--entry', default='0x8c004000')
    ap.add_argument('--frames', type=int, default=3)
    ap.add_argument('--rounds', type=int, default=20)
    a = ap.parse_args()
    last = None
    last = None
    for n in range(a.rounds):
        r = run([str(ROOT / 'build' / 'vf3sdl.exe'), '--state', str(a.state), '--entry', a.entry,
                 '--frames', str(a.frames), '--headless'], timeout=300)
        out = r.stdout + r.stderr
        m = re.search(r'first ([0-9a-f]{8})\)', out)
        if not m:
            print(out[-600:])
            print('no unowned call - stopped after', n, 'rounds')
            return 0
        pc = int(m.group(1), 16) | 0x80000000
        if 0x8C004000 <= pc < 0x8C004000 + (0x0C014000 - 0x0C010100):
            pc += 0x0C010100 - 0x0C004000          # the copy: name the source PC
        print(f'round {n}: unowned {pc:08x}')
        lines = WATCH.read_text().splitlines()
        root = f'pc 0x{pc:08x}'
        if root in lines and pc == last:
            print('already a root: the translation does not reach it'); return 1
        last = pc
        if root not in lines:
            WATCH.write_text('\n'.join(lines + [root]) + '\n')
        g = run([sys.executable, 'tools/oracle/translate_adapters.py', 'extract/analysis/_empty_caps',
                 '--watch', str(WATCH), '--out', 'build/boot_raw.c',
                 '--function', 'vf3_boot_adapter'])
        print(g.stdout.strip().splitlines()[-1:] or g.stderr[-300:])
        if g.returncode:
            print(g.stderr[-800:]); return 1
        sys.path.insert(0, str(ROOT / 'tools'))
        import boot_relocate
        (ROOT / 'src/fight/vf3_boot_adapter.c').write_text(
            boot_relocate.relocate((ROOT / 'build/boot_raw.c').read_text()))
        b = run(['cmake', '--build', 'build', '--target', 'vf3sdl'])
        if b.returncode:
            print(b.stdout[-1500:]); return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
