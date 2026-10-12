"""Archive the local dependency closure recorded by the matrix replay compiler."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def inputs(build):
    paths = {ROOT/'CMakeLists.txt'}
    dependencies = list((build/'CMakeFiles').rglob('*.obj.d'))
    assert dependencies, 'missing compiler dependencies'
    for dependency in dependencies:
        text = dependency.read_text().replace('\\\n', ' ').replace('\\', '/')
        for name in re.findall(r'[A-Za-z]:/[^\s]+', text):
            path = Path(name).resolve()
            if path.is_relative_to(ROOT) and path.is_file() and path.relative_to(ROOT).parts[0] in ('src', 'tests'):
                paths.add(path)
    return sorted(paths)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, default=ROOT/'build')
    parser.add_argument('--native', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--expected', type=int, required=True)
    parser.add_argument('--supplemental', type=Path,
                        help='retain additional historical inventory paths; report them separately')
    args = parser.parse_args()
    compiler_paths = inputs(args.build)
    supplemental = {ROOT/name for name in json.loads(args.supplemental.read_text())} if args.supplemental else set()
    paths = sorted(set(compiler_paths)|supplemental)
    assert len(paths) == args.expected, f'compiler closure: {len(paths)}, expected {args.expected}'
    assert args.native.is_file() and not args.out.exists()
    args.out.mkdir(parents=True)
    rows = []
    for path in paths:
        name = path.relative_to(ROOT).as_posix()
        destination = args.out/name
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, destination)
        digest = sha(path)
        assert sha(destination) == digest
        rows.append(dict(path=name, sha256=digest))
    manifest = dict(coverage_credit=False, purpose='Complete matrix replay compiler dependency archive',
        native=str(args.native.resolve()), native_sha256=sha(args.native),
        compiler_dependency_files=len(compiler_paths),
        supplemental_files=sorted(p.relative_to(ROOT).as_posix() for p in supplemental-set(compiler_paths)),
        files=rows)
    (args.out/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'Archived {len(rows)} inputs ({len(compiler_paths)} compiler dependencies) and pinned the immutable replay executable')


if __name__ == '__main__':
    main()
