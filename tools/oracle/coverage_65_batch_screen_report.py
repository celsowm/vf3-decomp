"""Hash-pin advisory screening and identify missing original body instructions.

This report is intentionally separate from promotion: even complete body
execution grants zero C coverage and does not prove a callable contract.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, measure
from capsules import records
from coverage_65_batch_screen_inputs import OWNERS


def reference(path):
    path = Path(path).resolve()
    return {'path': str(path), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest()}


def report(corpus, owners=OWNERS, owners_path=None):
    batch_path = corpus / 'batch_manifest.json'
    batch = json.loads(batch_path.read_text())
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    groups, pins, summaries = defaultdict(list), [reference(batch_path)], []
    for run in batch['runs']:
        capsule = Path(run['capsule'])
        summary_path = Path(str(capsule) + '.summary.json')
        summary = json.loads(summary_path.read_text())
        found = list(records(capsule))
        assert summary['completed'] == len(found), 'capture accounting mismatch'
        assert summary['started'] == len(found) + len(summary['incomplete'])
        assert not summary['unaccounted'], 'unaccounted original invocation'
        summaries.append({'scenario': run['name'], **summary})
        for path in (capsule, summary_path, run['log'], run['entry_patch'],
                     ROOT / run['state'], run['emulator']):
            pins.append(reference(path))
        for sample in found:
            assert sample['nstate'] == 63
            for pc, op in sample['ops']:
                offset = (pc | 0x80000000) - 0x8c010000
                # BIOS instructions in failed specimens are outside this image.
                if 0 <= offset <= len(image) - 2:
                    assert struct.unpack_from('<H', image, offset)[0] == op
            groups[sample['entry'] | 0x80000000].append(sample)
    spans = body_spans()
    rows = []
    for entry, owner in owners.items():
        samples = groups[entry]
        valid = [sample for sample in samples if not sample['flags']]
        pcs = {pc | 0x80000000 for sample in valid for pc, _ in sample['ops']}
        got, total, missing = measure(owner, spans[owner], pcs)
        pointers = []
        position = image.find(struct.pack('<I', entry & 0x1fffffff))
        while position >= 0:
            pointers.append(hex(position + 0x8c010000))
            position = image.find(struct.pack('<I', entry & 0x1fffffff), position + 1)
        rows.append({
            'entry': hex(entry), 'owner': hex(owner), 'owner_bytes': total,
            'valid_invocations': len(valid),
            'captured_body_bytes': got, 'missing_pcs': [hex(pc) for pc in missing],
            'rejected_flags': dict(Counter(sample['flags'] for sample in samples if sample['flags'])),
            'rejected_last_pcs': dict(Counter(hex(sample['ops'][-1][0]) for sample in samples if sample['flags'])),
            'immutable_pointer_locations': pointers,
            'caller_proved': False, 'coverage_credit': False,
        })
    pins.extend(reference(ROOT / path) for path in (
        'extract/analysis/funcs_1ST_READ.unsc.bin.csv',
        'extract/analysis/function_body_ranges.csv', 'extract/gamedata/1ST_READ.BIN'))
    for suffix in ('memory', 'registers'):
        pins.append(reference(ROOT / f"tools/oracle/percentage_inputs/{batch['name']}_{suffix}.json"))
    pins.append(reference(batch['watch']))
    if owners_path is not None:
        pins.append(reference(owners_path))
    return {
        'advisory': True, 'coverage_credit': False,
        'incomplete_invocations': sum(len(summary['incomplete']) for summary in summaries),
        'campaign_suitable_for_promotion': False,
        'runs': summaries, 'candidates': rows,
        'references': list({pin['path']: pin for pin in pins}.values()),
    }


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('corpus', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--owners', type=Path)
    args = parser.parse_args()
    assert not args.out.exists(), 'refuse to overwrite retained pilot evidence'
    owners = ({int(entry, 16): int(owner, 16) for entry, owner in
               json.loads(args.owners.read_text()).items()} if args.owners else OWNERS)
    result = report(args.corpus, owners, args.owners)
    args.out.write_text(json.dumps(result, indent=2) + '\n')
    for row in result['candidates']:
        print(row['entry'], f"{row['captured_body_bytes']}/{row['owner_bytes']}",
              'valid', row['valid_invocations'], 'rejected', row['rejected_flags'])
    print('incomplete:', result['incomplete_invocations'], '; C credit: 0')
