"""Translate a batch of roots into one generated adapter module.

`tools/gen_translate.py` prints the translator invocation for a root list; this
runs it directly, so a batch is one command instead of a hand-copied line.
"""
import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def resolve(root):
    """The capture directories that hold f_<root>.ops.json."""
    found = []
    names = {'f_%08x.ops.json' % root, 'f_%08x.ops.json' % (root | 0x80000000)}
    for dirpath, dirs, files in __import__('os').walk(ROOT / 'extract' / 'analysis'):
        for name in files:
            if name in names:
                found.append(str(Path(dirpath).relative_to(ROOT)))
                break
    return found


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--function', required=True)
    ap.add_argument('--reuse', action='append', default=[])
    ap.add_argument('--no-reuse', action='store_true')
    a = ap.parse_args()

    roots = []
    for line in a.watch.read_text().splitlines():
        if line.startswith('pc '):
            roots.append(int(line.split()[1], 16) & 0x1fffffff)
    captures = []
    for root in roots:
        captures.extend(resolve(root))
    captures = sorted(set(captures))
    if not captures:
        print('no capture directories for %d roots' % len(roots), file=sys.stderr)
        return 1
    cmd = [sys.executable, 'tools/oracle/translate_adapters.py'] + captures + [
        '--watch', str(a.watch), '--out', str(a.out), '--function', a.function]
    if not a.no_reuse:
        for pattern in (a.reuse or ['src/fight/*.c']):
            cmd += ['--reuse-adapter', pattern]
    print('translating %d roots from %d capture dirs' % (len(roots), len(captures)), flush=True)
    result = subprocess.run(cmd, cwd=ROOT)
    return result.returncode


if __name__ == '__main__':
    sys.exit(main())
