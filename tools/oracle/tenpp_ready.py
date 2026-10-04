"""Select complete development proofs for independent acceptance captures."""
import argparse
import csv
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, corpus_pcs, measure


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('development', type=Path)
    ap.add_argument('--replay', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    manifest = json.loads((a.development / 'capsule_manifest.json').read_text())
    batch = json.loads((a.development / 'batch_manifest.json').read_text())
    assert all(r['returncode'] == 0 and r['frame_complete'] for r in batch['runs'])
    replay = json.loads(a.replay.read_text())
    scenarios = {str(Path(r['capsule']).resolve()): (r['state'], r['play'])
                 for r in batch['runs']}
    incomplete = {int(r['entry'], 16) | 0x80000000
                  for run in manifest['runs'] for r in run.get('incomplete', [])}
    credited = {int(r['entry'], 16) for r in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if r['status'].startswith('ported')}
    spans = body_spans()
    pcs = corpus_pcs([a.development])
    ready, excluded = {}, {}
    for entry, records in sorted(manifest['entries'].items()):
        address = int(entry, 16)
        if address in credited:
            continue
        reasons = []
        if len(records) < 64:
            reasons.append('fewer than 64 distinct inputs')
        used = {scenarios[str(Path(source['source']).resolve())]
                for record in records for source in record['sources']}
        if len(used) < 2:
            reasons.append('fewer than two scenarios')
        if address in incomplete:
            reasons.append('incomplete invocation')
        if address not in spans or address not in pcs or measure(address, spans[address], pcs[address][0])[2]:
            reasons.append('incomplete frozen body')
        proof = replay.get(entry, {})
        if not proof.get('pass') or '(0 skipped) - PASS' not in proof.get('stdout', ''):
            reasons.append('strict replay failed')
        if reasons:
            excluded[entry] = reasons
        else:
            ready[entry] = measure(address, spans[address], pcs[address][0])[1]
    a.out.write_text('# Complete strict development proofs; acceptance still required.\n' +
                     ''.join(f'pc {entry}\n' for entry in ready))
    report = dict(ready=ready, excluded=excluded, raw_bytes=sum(ready.values()))
    (ROOT / 'extract/analysis' / (a.out.stem + '_ready.json')).write_text(
        json.dumps(report, indent=1) + '\n')
    print(f'{len(ready)} ready, {sum(ready.values())} raw bytes; {len(excluded)} excluded; no credit')


if __name__ == '__main__':
    main()
