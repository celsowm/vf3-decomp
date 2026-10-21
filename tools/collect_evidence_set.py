"""Curate the evidence set that the golden bindings actually depend on.

`tools/golden_bindings.json` maps every promoted entry to the `.cases` file
that replays it.  Those `.cases` rows name the RAM blobs that sit next to
them.  This script collects exactly that closure - the `.cases` files, the
blobs they reference and the manifests beside them - so the evidence can be
handed over without carrying the whole 283 GB capture tree.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def blobs_of(cases_path):
    """Return the RAM blob file names that belong to a .cases file.

    The blobs of a case sit next to it and carry the case's stem
    (`f_0c03a140.ram0.bin`, `f_0c03a140.exitram0.bin`, ...).  Matching on the
    stem is robust against both the v2 and the legacy row format, and it
    cannot miss a blob the row names because every blob of a case shares the
    case's stem.
    """
    stem = cases_path.stem
    return [blob.name for blob in sorted(cases_path.parent.glob(stem + '*.bin'))]


def resolve(golden):
    """Return the path a golden reference points at.

    Most bindings point inside the repository (`extract/analysis/...`), but a
    few corpora were exported outside it (`D:\\vf3-captures\\...` and the
    evidence cache).  Those keep their absolute path so the archive can
    mirror the drive layout.
    """
    path = Path(golden)
    if path.is_absolute():
        return path
    return ROOT / path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bindings', type=Path, default=ROOT / 'tools/golden_bindings.json')
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    bindings = json.loads(args.bindings.read_text(encoding='utf-8'))
    cases = []
    for row in bindings.values():
        golden = row.get('golden')
        if golden and golden not in cases:
            cases.append(golden)
    files = {}
    total = 0
    for golden in cases:
        path = resolve(golden)
        if not path.is_file():
            print(f'MISSING {golden}')
            continue
        key = golden.replace('\\', '/')
        files[key] = path.stat().st_size
        total += path.stat().st_size
        for blob in sorted(path.parent.glob(path.stem + '*.bin')):
            blob_key = str(blob).replace('\\', '/')
            if path.is_relative_to(ROOT):
                blob_key = blob.relative_to(ROOT).as_posix()
            if blob_key not in files:
                files[blob_key] = blob.stat().st_size
                total += blob.stat().st_size
    args.out.write_text(json.dumps(dict(
        bindings=len(bindings),
        cases_files=len(cases),
        total_files=len(files),
        total_bytes=total,
        total_mb=round(total / 1048576, 1),
        files={name: size for name, size in sorted(files.items())}), indent=1) + '\n')
    print(f'{len(bindings)} bindings -> {len(cases)} .cases + {len(files)} files, '
          f'{total / 1048576:.1f} MB')


if __name__ == '__main__':
    main()
