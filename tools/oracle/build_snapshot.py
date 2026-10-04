"""Build an immutable strict matrix replay executable without replacing live tests."""
import argparse
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--build', type=Path, default=ROOT / 'build')
    parser.add_argument('--jobs', type=int, default=4, choices=range(1, 5))
    args = parser.parse_args()
    output, build = args.out.resolve(), args.build.resolve()
    if output.exists():
        raise FileExistsError(f'refusing to overwrite proof executable: {output}')
    cache = (build / 'CMakeCache.txt').read_text()
    compiler = re.search(r'^CMAKE_C_COMPILER:[^=]+=(.+)$', cache, re.M)
    if not compiler:
        raise ValueError('configured C compiler missing')
    compiler = Path(compiler[1].strip())
    if compiler.stem not in ('gcc', 'clang', 'cc'):
        raise ValueError('snapshot linker currently supports GCC and Clang builds')
    subprocess.run(['cmake', '--build', str(build), '--target', 'vf3core',
                    '--parallel', str(args.jobs)], cwd=ROOT, check=True)
    output.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([str(compiler), '-O3', '-DNDEBUG', '-std=c99',
                    '-I' + str(ROOT / 'src'), '-I' + str(ROOT / 'tests'),
                    str(ROOT / 'tests/matrix_family_replay.c'),
                    str(build / 'libvf3core.a'), '-lm', '-o', str(output)],
                   cwd=ROOT, check=True)
    print(f'Immutable replay executable: {output}')


if __name__ == '__main__':
    main()
