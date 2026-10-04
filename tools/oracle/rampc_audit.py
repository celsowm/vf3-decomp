"""Summarize windowed RAM snapshots embedded in Flycast VF3 trace files."""
import argparse
import json
import mmap
from pathlib import Path
import struct

OPEN = 0xFA50
CLOSE = 0xFA51


def dumps(path):
    with Path(path).open('rb') as stream:
        if stream.seek(0, 2) == 0:
            return
        stream.seek(0)
        with mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
            if len(data) % 8:
                raise ValueError(f'{path}: trace size is not a multiple of eight bytes')
            count_records = len(data) // 8
            index = 0
            while index < count_records:
                marker, = struct.unpack_from('<Q', data, index * 8)
                pc, tag = (marker >> 16) & 0xffffffff, marker & 0xffff
                if tag != OPEN:
                    index += 1
                    continue
                if index + 1 >= count_records:
                    raise ValueError(f'{path}: truncated RAM-window header at record {index}')
                count, = struct.unpack_from('<Q', data, (index + 1) * 8)
                if not 1 <= count <= 8:
                    index += 1
                    continue
                cursor, windows = index + 2, []
                try:
                    for _ in range(count):
                        base, size = struct.unpack_from('<2Q', data, cursor * 8)
                        cursor += 2
                        if base % 4 or not 0x0c000000 <= base < 0x0d000000:
                            raise ValueError('invalid RAM window base')
                        if not size or size % 4 or size > 0x01000000 or base + size > 0x0d000000:
                            raise ValueError('invalid RAM window size')
                        nwords = size // 4
                        if cursor + nwords > count_records:
                            raise ValueError('truncated RAM window')
                        raw = struct.unpack_from(f'<{nwords}Q', data, cursor * 8)
                        cursor += nwords
                        words = tuple(word & 0xffffffff for word in raw)
                        windows.append((base, size, words))
                    close, = struct.unpack_from('<Q', data, cursor * 8)
                    if close & 0xffff != CLOSE or (close >> 16) & 0xffffffff != pc:
                        raise ValueError('RAM dump has no matching closing marker')
                except (IndexError, struct.error, ValueError):
                    index += 1
                    continue
                yield pc, tuple(windows)
                index = cursor + 1


def summarize(paths):
    samples = {}
    for path in paths:
        for pc, windows in dumps(path):
            for base, size, words in windows:
                key = (pc, base, size)
                sample = samples.get(key)
                if sample is None:
                    samples[key] = dict(first=words, first_sample=str(path),
                                        count=1, changed=set(), varying=set())
                    continue
                first = sample['first']
                for i, value in enumerate(words):
                    if value != first[i]:
                        sample['changed'].add(i)
                        sample['varying'].add(i)
                sample['count'] += 1
    rows = []
    for (pc, base, size), sample in sorted(samples.items()):
        first = sample['first']
        varying = sample['varying']
        rows.append(dict(pc=f'0x{pc:08x}', base=f'0x{base:08x}', size=size,
                         samples=sample['count'], changed_words=len(sample['changed']),
                         varying_words=len(varying),
                         first_nonzero_words=sum(value != 0 for value in first),
                         first_word=f'0x{first[0]:08x}',
                         first_sample=sample['first_sample'],
                         varying_offsets=[f'0x{i * 4:04x}' for i in sorted(varying)]))
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('traces', nargs='+', type=Path)
    parser.add_argument('--out', type=Path)
    args = parser.parse_args()
    rows = summarize(args.traces)
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(dict(advisory=True, windows=rows), indent=1) + '\n')
    for row in rows:
        print(f"{row['pc']} RAM {row['base']}+0x{row['size']:x}: "
              f"{row['samples']} samples; first={row['first_word']} "
              f"first_nonzero={row['first_nonzero_words']} words; "
              f"changed={row['changed_words']} words; varying={row['varying_words']}")
    print(f'{len(rows)} PC/window groups; snapshot evidence only, no allocation or coverage credit')


if __name__ == '__main__':
    main()
