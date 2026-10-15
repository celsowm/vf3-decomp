#!/usr/bin/env python3
"""unowned_pcs.py - which oracle-executed guest PCs have no generated adapter label?

  python tools/recomp/unowned_pcs.py extract/analysis/tick_s7_pcs.txt [--ops-dir DIR --root 0x8c09616a]

Reads the TICK_PCS dump of tick_oracle (lines `pc <hex>` and `ind <site> <targets...>`),
subtracts every `P_<pc>:` label found under src/, and prints a summary.  With --ops-dir it
writes `f_8c<root>.ops.json` ({pc: opcode}, opcodes read from the identity image) holding the
unowned executed PCs plus a `<name>.indirect.json` for translate_adapters.py --indirect-targets.
"""
import argparse
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x0C010000


def owned_labels(skip=()):
    owned = set()
    pat = re.compile(r'^P_([0-9a-f]{8}):', re.M)
    for p in (ROOT / 'src').rglob('*.c'):
        if p.name in skip:
            continue
        owned.update(int(a, 16) for a in pat.findall(p.read_text(encoding='ascii', errors='ignore')))
    return owned


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('pcs', nargs='+', help='one or more TICK_PCS dumps (union)')
    ap.add_argument('--skip', action='append', default=[], help='source file name whose labels do not count as owned')
    ap.add_argument('--ops-dir', type=Path)
    ap.add_argument('--root', default='0x8c09616a')
    ap.add_argument('--name', default='tick')
    ap.add_argument('--watch', help='watch file to write (default tools/watch/vf3_<name>.txt)')
    a = ap.parse_args()
    executed, ind = set(), {}
    for pcs_file in a.pcs:
        for line in Path(pcs_file).read_text().splitlines():
            f = line.split()
            if not f:
                continue
            if f[0] == 'pc':
                executed.add(int(f[1], 16))
            elif f[0] == 'ind':
                ind.setdefault(int(f[1], 16), []).extend(int(x, 16) for x in f[2:])
    owned = owned_labels(a.skip)
    unowned = sorted(executed - owned)
    print(f'executed {len(executed)}, owned by an adapter label {len(executed & owned)}, unowned {len(unowned)}')
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    inside = [p for p in unowned if BASE <= p < BASE + len(image) - 1]
    print(f'unowned inside the image {len(inside)}, outside (dynamic code) {len(unowned) - len(inside)}')
    # contiguous runs, for orientation
    runs = []
    for p in inside:
        if runs and p - runs[-1][1] <= 2:
            runs[-1][1] = p
        else:
            runs.append([p, p])
    print(f'{len(runs)} runs; largest:')
    for lo, hi in sorted(runs, key=lambda r: r[0] - r[1])[:12]:
        print(f'  {lo:08x}..{hi:08x} ({(hi - lo) // 2 + 1} insns)')
    if a.ops_dir:
        a.ops_dir.mkdir(parents=True, exist_ok=True)
        ops = {f'{p:08x}': f'{struct.unpack_from("<H", image, p - BASE)[0]:04x}' for p in inside}
        root = int(a.root, 16) & 0x1FFFFFFF
        (a.ops_dir / f'f_{0x80000000 | root:08x}.ops.json').write_text(json.dumps(ops))
        indirect = {f'0x{s:08x}': [f'0x{t:08x}' for t in ts] for s, ts in ind.items() if s in executed}
        (a.ops_dir / f'{a.name}.indirect.json').write_text(json.dumps(indirect))
        watch = Path(a.watch) if a.watch else ROOT / 'tools' / 'watch' / f'vf3_{a.name}.txt'
        rows = [f'# {a.name}: executed in the oracle run, no adapter label'] + [f'pc 0x{0x80000000 | lo:08x}' for lo, _ in runs]
        with open(watch, 'w', newline=chr(10)) as out:
            out.write(chr(10).join(rows) + chr(10))
        print(f'wrote {a.ops_dir} and {watch}')


if __name__ == '__main__':
    main()
