"""Summarize observed ABI inputs and indirect destinations; never award credit.

Use natural VF3CAP6 captures without redirected probes to recover contracts
before constructing synthetic fixtures. A destination is reported only when
both the delay slot and the following executed instruction are present.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
from capsules import records


def canonical(address):
    return (address & 0x1fffffff) | 0x80000000


def indirect_edges(ops):
    edges = Counter()
    for index, (pc, opcode) in enumerate(ops[:-2]):
        if opcode & 0xf0ff not in (0x400b, 0x402b):
            continue
        if canonical(ops[index + 1][0]) != canonical(pc + 2):
            continue
        edges[(canonical(pc), canonical(ops[index + 2][0]))] += 1
    return edges


def observed_word(sample, address):
    address &= 0x1fffffff
    for base, before, _ in sample['pages']:
        if base <= address <= base + len(before) - 4:
            return struct.unpack_from('<I', before, address - base)[0]
    return None


def summarize(paths, words=()):
    entries = {}
    sources = []
    for path in map(Path, paths):
        summary_path = Path(str(path) + '.summary.json')
        summary = json.loads(summary_path.read_text()) if summary_path.exists() else {}
        with path.open('rb') as stream:
            digest = hashlib.file_digest(stream, 'sha256').hexdigest()
        sources.append(dict(path=str(path), sha256=digest,
                            summary_present=summary_path.exists(),
                            incomplete=summary.get('incomplete', []),
                            unaccounted=summary.get('unaccounted')))
        for sample in records(path):
            entry = canonical(sample['entry'])
            row = entries.setdefault(entry, dict(valid=0, rejected=Counter(), sources=set(),
                arguments=defaultdict(set), words=defaultdict(set), edges=Counter(), device_calls=0))
            if sample['flags']:
                row['rejected'][sample['flags']] += 1
                continue
            row['valid'] += 1
            row['sources'].add(str(path))
            state = struct.unpack(f'<{sample["nstate"]}I', sample['before'])
            for name, index in [('r4', 4), ('r5', 5), ('r6', 6), ('r7', 7),
                                ('pr', 16), ('macl', 19), ('mach', 20), ('gbr', 54)]:
                if index < len(state):
                    row['arguments'][name].add(state[index])
            for address in words:
                value = observed_word(sample, address)
                if value is not None:
                    row['words'][address].add(value)
            row['edges'].update(indirect_edges(sample['ops']))
            row['device_calls'] += bool(sample['device'])
    def values(items):
        return dict(distinct=len(items), preview=[hex(value) for value in sorted(items)[:16]])
    output = {}
    for entry, row in sorted(entries.items()):
        output[hex(entry)] = dict(valid_calls=row['valid'], rejected_flags=dict(row['rejected']),
            sources=sorted(row['sources']), device_calls=row['device_calls'],
            arguments={name: values(items) for name, items in row['arguments'].items()},
            words={hex(address): values(items) for address, items in row['words'].items()},
            indirect_edges=[dict(pc=hex(pc), destination=hex(destination), executions=count)
                            for (pc, destination), count in sorted(row['edges'].items())])
    return dict(advisory=True, coverage_credit=False, sources=sources, entries=output)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsules', nargs='+', type=Path)
    parser.add_argument('--word', action='append', type=lambda value: int(value, 0), default=[])
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    result = summarize(args.capsules, args.word)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, indent=1) + '\n')
    for entry, row in result['entries'].items():
        print(f"{entry}: {row['valid_calls']} valid calls, {len(row['indirect_edges'])} indirect edges")


if __name__ == '__main__':
    main()
