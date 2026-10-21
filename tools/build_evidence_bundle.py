"""Build the hand-over evidence bundle.

The capture tree under `extract/analysis` is 4.66 million files and 283 GB,
almost all of it raw RAM capsules.  The friend only needs the closure that
the promoted bindings actually replay against, the analysis reports, and the
oracle revision.  This script stages exactly that set into a single tree and
writes the list file for 7-Zip.

The staging tree uses hard links for the in-repository files (same volume, so
no data is copied and the source tree is untouched) and real copies only for
the fixtures that live outside the repository.
"""
import argparse
import json
import os
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STAGE = Path('E:/vf3-evidencias-stage')
BUNDLE = 'vf3tb-evidencias'

# Trees that are tools or SDK payloads rather than evidence.
SKIP_TOOLS = {'emu', 'katana', 'katana_raw', '_katana_pkg', '_sdk_src', 'kamui',
              'ghidra_12.1.3_PUBLIC', '.venv', '__pycache__'}

REPORT_SUFFIXES = ('.csv', '.json', '.md', '.txt')


def link_or_copy(source, target):
    target.parent.mkdir(parents=True, exist_ok=True)
    if target.exists():
        return 'skip'
    try:
        os.link(source, target)
        return 'link'
    except OSError:
        shutil.copy2(source, target)
        return 'copy'


def walk(root):
    """Yield the files under root, never descending into a skipped subtree."""
    for path in sorted(root.iterdir()):
        if path.is_dir():
            if path.name in SKIP_TOOLS or path.name == '__pycache__':
                continue
            yield from walk(path)
        elif path.is_file():
            yield path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--evidence-set', type=Path,
                        default=ROOT / 'extract/analysis/evidence_set.json')
    parser.add_argument('--stage', type=Path, default=STAGE)
    args = parser.parse_args()
    bundle = args.stage / BUNDLE
    bundle.mkdir(parents=True, exist_ok=True)
    stats = {'link': 0, 'copy': 0, 'skip': 0}

    def place(source: Path, relative: str):
        stats[link_or_copy(source, bundle / relative)] += 1

    # 1. the fixture closure the golden bindings replay against
    evidence = json.loads(args.evidence_set.read_text(encoding='utf-8'))
    external = []
    for relative, size in evidence['files'].items():
        source = Path(relative)
        if not source.is_absolute():
            place(ROOT / relative, relative)
        else:
            external.append((source, relative))
    # fixtures that live outside the repository get mirrored under the bundle
    for source, relative in external:
        parts = relative.split(':', 1)
        if len(parts) == 2:
            mirror = f'external_capture_mirror/{parts[0]}_drive/{parts[1].lstrip("/")}'
        else:
            mirror = 'external_capture_mirror/' + relative.lstrip('/')
        place(source, mirror)

    # 2. the analysis reports (CSV/JSON/MD/TXT) that sit next to the corpora
    analysis = ROOT / 'extract/analysis'
    for path in analysis.rglob('*'):
        if not path.is_file() or path.suffix.lower() not in REPORT_SUFFIXES:
            continue
        if '__pycache__' in path.parts:
            continue
        relative = path.relative_to(ROOT).as_posix()
        if relative in evidence['files']:
            continue
        place(path, relative)

    # 3. the ledger, the RE notes and the C port itself
    for relative in ('docs', 'src', 'tests', 'CMakeLists.txt'):
        source = ROOT / relative
        if source.is_file():
            place(source, relative)
            continue
        for path in source.rglob('*'):
            if not path.is_file() or '__pycache__' in path.parts:
                continue
            place(path, path.relative_to(ROOT).as_posix())

    # 4. the RE tooling (but not the SDK payloads and the emulator tree)
    tools = ROOT / 'tools'
    for path in walk(tools):
        parts = path.relative_to(tools).parts
        if parts[0] in SKIP_TOOLS or '__pycache__' in parts:
            continue
        place(path, path.relative_to(ROOT).as_posix())

    # 5. the oracle revision (already inside extract/analysis, but its
    #    .cpp/.patch files are not reports, so stage them explicitly)
    revision = analysis / 'oracle_revision'
    for path in revision.rglob('*'):
        if path.is_file():
            place(path, path.relative_to(ROOT).as_posix())

    manifest = {
        'bundle': BUNDLE,
        'bindings': evidence['bindings'],
        'fixture_files': evidence['total_files'],
        'fixture_bytes': evidence['total_bytes'],
        'external_fixture_files': len(external),
        'staged_links': stats['link'],
        'staged_copies': stats['copy'],
        'already_present': stats['skip'],
    }
    (bundle / 'evidence_manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps(manifest, indent=2))
    print(f'staging tree: {bundle}')


if __name__ == '__main__':
    main()
