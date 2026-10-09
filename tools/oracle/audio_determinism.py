"""Bounded, fresh-process audio diagnostics. Advisory evidence; never credit.

Checkpoint identity is guest instruction ordinal, PC/opcode and emulated time,
not a renderer frame. Raw serializer blocks are tied to the emulator build.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
from contextlib import contextmanager
import gzip

ROOT = Path(__file__).resolve().parents[2]
KINDS = {1: 'architecture', 2: 'physical_ram', 3: 'aica', 4: 'cache',
         5: 'scheduler', 6: 'guest_pcm', 7: 'scheduler_events'}
REGS = ([f'r{i}' for i in range(16)] + ['pr', 'sr', 'fpscr', 'macl', 'mach']
        + [f'fr{i}' for i in range(16)] + [f'xf{i}' for i in range(16)]
        + ['fpul', 'gbr'] + [f'r_bank{i}' for i in range(8)])


def sha(path):
    with Path(path).open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()


@contextmanager
def emulator_lock(emulator):
    """Prevent diagnostic batches racing over Flycast's staged slot 0."""
    with (emulator.resolve().parent/'.vf3_audio.lock').open('a+b') as f:
        if f.tell() == 0:
            f.write(b'0')
            f.flush()
        f.seek(0)
        if os.name == 'nt':
            import msvcrt
            msvcrt.locking(f.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl
            fcntl.flock(f.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        try:
            yield
        finally:
            f.seek(0)
            if os.name == 'nt':
                msvcrt.locking(f.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(f.fileno(), fcntl.LOCK_UN)


def checkpoints(path):
    opener = gzip.open if str(path).endswith('.gz') else open
    with opener(path, 'rb') as f:
        def take(n):
            data = f.read(n)
            if len(data) != n:
                raise ValueError(f'{path}: truncated checkpoint at {f.tell()}')
            return data
        if take(8) != b'VF3AUD1\0':
            raise ValueError('unsupported audio checkpoint format')
        previous = 0
        while raw := f.read(32):
            if len(raw) != 32:
                raise ValueError('truncated checkpoint identity')
            ordinal, cycle, pc, op, budget, next_event = struct.unpack('<QQ4I', raw)
            if ordinal <= previous or op > 65535:
                raise ValueError('invalid checkpoint identity')
            previous = ordinal
            blocks = {}
            for expected in KINDS:
                kind, size = struct.unpack('<2I', take(8))
                if kind != expected or size > 64*1024*1024:
                    raise ValueError('invalid checkpoint block')
                data = take(size)
                if kind == 1 and size != 63*4 or kind == 2 and size != 16*1024*1024:
                    raise ValueError('invalid architectural/RAM block size')
                if kind == 6 and size % 4 or kind == 7 and size % 24:
                    raise ValueError('invalid PCM/event block size')
                blocks[kind] = data
            yield dict(identity=[ordinal, cycle, pc, op, budget, next_event], blocks=blocks)


def compress_checkpoint(path):
    """Archive new, complete evidence and verify reconstruction before unlink."""
    path = Path(path)
    archive = Path(str(path)+'.gz')
    if archive.exists():
        raise FileExistsError(archive)
    raw_hash = sha(path)
    with path.open('rb') as source, archive.open('wb') as dest:
        with gzip.GzipFile(filename='', mode='wb', fileobj=dest, mtime=0) as zipped:
            shutil.copyfileobj(source, zipped)
    with gzip.open(archive, 'rb') as restored:
        if hashlib.file_digest(restored, 'sha256').hexdigest() != raw_hash:
            raise ValueError('audio archive reconstruction hash mismatch')
    path.unlink()
    return archive, raw_hash


def describe(path):
    rows = []
    for row in checkpoints(path):
        rows.append(dict(identity=row['identity'], sections={KINDS[k]: dict(
            bytes=len(data), sha256=hashlib.sha256(data).hexdigest())
            for k, data in row['blocks'].items()}))
    if not rows:
        raise ValueError('empty checkpoint stream')
    return dict(path=str(path), sha256=sha(path), checkpoints=rows)


def first_difference(a, b):
    for start in range(0, min(len(a), len(b)), 4096):
        x, y = a[start:start+4096], b[start:start+4096]
        if x != y:
            for i, (left, right) in enumerate(zip(x, y)):
                if left != right:
                    return start+i
            return start+min(len(x), len(y))
    return min(len(a), len(b))


def compare(left, right):
    from itertools import zip_longest
    for index, (a, b) in enumerate(zip_longest(checkpoints(left), checkpoints(right))):
        if a is None or b is None:
            return dict(equal=False, checkpoint=index, section='checkpoint_count')
        if a['identity'] != b['identity']:
            return dict(equal=False, checkpoint=index, section='identity',
                        left=a['identity'], right=b['identity'])
        for kind in KINDS:
            x, y = a['blocks'][kind], b['blocks'][kind]
            if x != y:
                off = first_difference(x, y)
                result = dict(equal=False, checkpoint=index, identity=a['identity'],
                              section=KINDS[kind], offset=off,
                              left_bytes=len(x), right_bytes=len(y),
                              left=x[off:off+16].hex(), right=y[off:off+16].hex())
                if kind == 1:
                    result['register'] = REGS[off//4]
                if kind == 2:
                    result['address'] = hex(0x0c000000+off)
                return result
    return dict(equal=True)


def run(a):
    out = a.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    watch = out/'watch.txt'
    watch.write_text('pc 8c040f1e\npc 8c0c5d86\n', encoding='ascii')
    points = [int(n, 0) for n in a.points.split(',')]
    if not points or points != sorted(set(points)) or not 1 <= points[0] <= points[-1] <= 1000000000:
        raise ValueError('points must be distinct increasing positive instruction ordinals')
    provenance_paths = [a.emulator, ROOT/'rom/vf3.gdi',
                        ROOT/'extract/gamedata/1ST_READ.BIN',
                        ROOT/'tools/oracle/vf3audio.cpp', ROOT/'tools/oracle/install.py',
                        Path(__file__)]
    manifest = dict(advisory=True, coverage_credit=False, passed=False,
                    scope='aligned audio checkpoints; not full C replay acceptance',
                    points=points, threaded=a.threaded, runs=[], comparisons=[],
                    provenance={str(p): sha(p) for p in provenance_paths})
    target = out/'manifest.json'
    def save():
        target.write_text(json.dumps(manifest, indent=2)+'\n', encoding='utf-8')
    for state in a.state:
        manifest['provenance'][str(state)] = sha(state)
        groups = {'baseline': [], 'observed': []}
        for mode in groups:
            for repetition in range(a.repetitions):
                # Same-state processes must be sequential: Flycast stages slot 0.
                if shutil.disk_usage(out).free < 4*1024**3:
                    raise RuntimeError('4 GiB capture reserve reached')
                stem = f'{state.stem}_{mode}_{repetition+1}'
                capsule = out/f'{stem}.capsule'
                checkpoint = out/f'{stem}.audio'
                log = out/f'{stem}.log'
                env = {k: v for k, v in os.environ.items() if not k.startswith('VF3_')}
                env.update(VF3_INTERPRETER='1', VF3_STATE=str(state.resolve()),
                           VF3_TRACE_FRAMES=str(a.frames), VF3_WATCH=str(watch),
                           VF3_AUDIO_CHECKPOINTS=str(checkpoint), VF3_AUDIO_POINTS=a.points)
                if a.threaded:
                    env['VF3_AUDIO_THREADED'] = '1'
                if mode == 'observed':
                    env.update(VF3_CAPSULE=str(capsule), VF3_CAPSULE_N='128')
                with log.open('wb') as f:
                    try:
                        proc = subprocess.run([str(a.emulator.resolve()), str(ROOT/'rom/vf3.gdi')],
                            cwd=a.emulator.resolve().parent, env=env, stdout=f,
                            stderr=subprocess.STDOUT, timeout=a.timeout)
                        code = proc.returncode
                    except subprocess.TimeoutExpired:
                        code = 'timeout'
                row = dict(state=str(state), mode=mode, repetition=repetition+1,
                           returncode=code, log=str(log), log_sha256=sha(log))
                try:
                    row.update(describe(checkpoint))
                    row['complete'] = code == 0 and [r['identity'][0] for r in row['checkpoints']] == points
                except (ValueError, FileNotFoundError) as e:
                    row.update(complete=False, error=str(e))
                if capsule.exists():
                    row['capsule'] = str(capsule)
                    row['capsule_sha256'] = sha(capsule)
                manifest['runs'].append(row)
                groups[mode].append(row)
                save()
                print(f'{stem}: complete={row["complete"]}', flush=True)
        reference = groups['baseline'][0]
        for row in groups['baseline'][1:] + groups['observed']:
            result = compare(reference['path'], row['path']) if reference['complete'] and row['complete'] else dict(equal=False, section='incomplete_run')
            manifest['comparisons'].append(dict(state=str(state), left=reference.get('path'),
                                                right=row.get('path'), **result))
            print(json.dumps(manifest['comparisons'][-1]), flush=True)
        save()
    manifest['passed'] = bool(manifest['comparisons']) and all(r['equal'] for r in manifest['comparisons']) and all(r['complete'] for r in manifest['runs'])
    save()
    return 0 if manifest['passed'] else 2


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    commands = ap.add_subparsers(dest='command', required=True)
    r = commands.add_parser('run')
    r.add_argument('--state', type=Path, action='append', required=True)
    r.add_argument('--out', type=Path, required=True)
    r.add_argument('--emulator', type=Path, default=ROOT/'tools/emu/flycast-build/flycast.exe')
    r.add_argument('--points', default='1,65536,1048576,4194304')
    r.add_argument('--repetitions', type=int, choices=range(1, 5), default=3)
    r.add_argument('--frames', type=int, default=180)
    r.add_argument('--timeout', type=int, default=60)
    r.add_argument('--threaded', action='store_true', help='diagnose the previous threaded runner')
    c = commands.add_parser('compare')
    c.add_argument('left', type=Path)
    c.add_argument('right', type=Path)
    a = ap.parse_args()
    if a.command == 'run':
        with emulator_lock(a.emulator):
            return run(a)
    result = compare(a.left, a.right)
    print(json.dumps(result, indent=2))
    return 0 if result['equal'] else 2


if __name__ == '__main__':
    raise SystemExit(main())
