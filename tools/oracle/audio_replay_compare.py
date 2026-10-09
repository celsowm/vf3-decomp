"""Strict original/live-C audio comparison; produces advisory enabling evidence.

Matches fresh processes by state hash, named input and repetition. Compares
actual generated bus accesses and all recorded exit effects, never supplies
golden reads or writes to the C implementation.
"""
import argparse
import json
from pathlib import Path
from audio_determinism import compare, sha
from capsules import records


def load_runs(path, execution):
    data = json.loads(Path(path).read_text())
    if data.get('execution') != execution or not data.get('passed'):
        raise ValueError(f'{path}: incomplete or wrong execution backend')
    runs = {}
    for row in data['runs']:
        state_hash = data['provenance'][row['state']]
        key = (state_hash, row['case'], row['repetition'])
        if key in runs or not row['passed'] or row['flags']:
            raise ValueError('duplicate or rejected invocation')
        summary = row.get('summary', {})
        if (row.get('returncode') != 0 or not summary.get('one_shot_done')
                or not summary.get('one_shot')
                or summary.get('started') != 1 or summary.get('completed') != 1
                or summary.get('incomplete') != [] or summary.get('unaccounted') != 0
                or summary.get('restores') != 0):
            raise ValueError('process-owned completion missing or restored')
        for artifact, digest in [(row['capsule'], row['capsule_sha256']),
                                 (row['audio']['path'], row['audio']['sha256']),
                                 (row['log'], row['log_sha256'])]:
            if sha(artifact) != digest:
                raise ValueError(f'changed evidence: {artifact}')
        if execution == 'readable_c_queue' and '[vf3audiobridge] executing C queue with live devices' not in Path(row['log']).read_text(errors='replace'):
            raise ValueError('C execution marker missing')
        capsule = list(records(row['capsule']))
        if len(capsule) != 1:
            raise ValueError('expected one invocation per process')
        sample = capsule[0]
        if (sample['flags'] or sample['entry'] != 0x8c040f1e
                or sample['nstate'] != 63 or not sample['ops']):
            raise ValueError('capsule is rejected or outside the queue scope')
        runs[key] = (row, capsule[0])
    return data, runs


def evaluate(original, c_manifest):
    original_data, left = load_runs(original, 'original_sh4')
    c_data, right = load_runs(c_manifest, 'readable_c_queue')
    if original_data.get('device_control') != c_data.get('device_control'):
        raise ValueError('device input controls differ')
    # Pin emulator, image, recipe and game implementation, not runner mode.
    for path, digest in original_data['provenance'].items():
        if path in c_data['provenance'] and c_data['provenance'][path] != digest:
            raise ValueError(f'provenance differs: {path}')
    if not left or left.keys() != right.keys():
        raise ValueError('original and C invocations do not form the same corpus')
    results = []
    for key, (a, x) in left.items():
        b, y = right[key]
        fields = ['entry', 'exitpc', 'flags', 'before', 'after', 'pages', 'ops', 'device', 'nstate']
        different = [field for field in fields if x[field] != y[field]]
        audio = compare(a['audio']['path'], b['audio']['path'])
        results.append(dict(state_sha256=key[0], case=key[1], repetition=key[2],
            capsule_equal=not different, different_fields=different,
            audio=audio, aica_events=a['aica_events'],
            original_capsule_sha256=a['capsule_sha256'], c_capsule_sha256=b['capsule_sha256']))
    return dict(advisory=True, coverage_credit=False,
        passed=all(r['capsule_equal'] and r['audio']['equal'] for r in results),
        positive_aica_crossings=sum(r['aica_events']>0 for r in results),
        original_manifest=dict(path=str(original), sha256=sha(original)),
        c_manifest=dict(path=str(c_manifest), sha256=sha(c_manifest)), comparisons=results)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('original', type=Path)
    ap.add_argument('c_manifest', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--expect-mismatch', action='store_true', help='explicit negative control')
    a = ap.parse_args()
    result = evaluate(a.original, a.c_manifest)
    result['negative_control'] = a.expect_mismatch
    a.out.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(f"{sum(r['capsule_equal'] and r['audio']['equal'] for r in result['comparisons'])}/{len(result['comparisons'])} strict original/C comparisons match; {result['positive_aica_crossings']} real AICA crossings")
    return int(result['passed'] == a.expect_mismatch)


if __name__ == '__main__':
    raise SystemExit(main())
