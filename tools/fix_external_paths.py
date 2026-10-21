"""Point the golden bindings at the mirrored external fixtures.

30 of the 2,250 promoted bindings replay against corpora that were exported
outside the repository (`D:\\vf3-captures\\...` and the local evidence cache).
The evidence bundle carries them under `external_capture_mirror/`, with the
drive letter and the directory structure preserved.  This script rewrites
`tools/golden_bindings.json` in place so those 30 entries resolve inside the
extracted bundle.
"""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BINDINGS = ROOT / 'tools/golden_bindings.json'
MIRROR = 'external_capture_mirror'


def mirrored(golden):
    """Return the in-bundle path of an external golden, or None."""
    parts = golden.replace('\\', '/').split(':', 1)
    if len(parts) != 2:
        return None
    drive, rest = parts
    candidate = f'{MIRROR}/{drive}_drive/{rest.lstrip("/")}'
    if (ROOT / candidate).is_file():
        return candidate
    return None


def main():
    bindings = json.loads(BINDINGS.read_text(encoding='utf-8'))
    changed = 0
    missing = []
    for row in bindings.values():
        golden = row.get('golden')
        if not golden:
            continue
        candidate = mirrored(golden)
        if candidate is None:
            if not (ROOT / golden).is_file() and ':' in golden:
                missing.append(golden)
            continue
        if candidate != golden:
            row['golden'] = candidate
            changed += 1
    if missing:
        print(f'WARNING: {len(missing)} external fixtures are not in the bundle:')
        for golden in missing[:10]:
            print(f'  {golden}')
    BINDINGS.write_text(json.dumps(bindings, indent=1) + '\n', encoding='utf-8')
    print(f'{changed} bindings now point at {MIRROR}/')


if __name__ == '__main__':
    main()
