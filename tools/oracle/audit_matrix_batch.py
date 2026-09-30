#!/usr/bin/env python3
"""Check strict evidence bindings and unique byte credit for the matrix batch."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]


def audit(check_hashes=False, manifest_path='tools/oracle/matrix_batch.json'):
    manifest = json.loads((ROOT/manifest_path).read_text())
    bindings = json.loads((ROOT/'tools/golden_bindings.json').read_text())
    ledger = {int(r['entry'], 16): r for r in csv.DictReader((ROOT/'docs/decomp_status.csv').open()) if r['status'].startswith('ported')}
    sizes = {int(r['entry'], 16): int(r['size']) for r in csv.DictReader((ROOT/'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open())}
    ranges = {}
    for r in csv.DictReader((ROOT/'extract/analysis/function_body_ranges.csv').open()):
        ranges.setdefault(int(r['entry'], 16), []).append((int(r['start'], 16), int(r['end'], 16)))
    promoted = set()
    cases = 0
    campaigns = {}
    for entry, evidence in manifest['entries'].items():
        e = int(entry, 16)
        assert entry not in manifest['excluded'], f'Excluded entry promoted: {entry}'
        binding = bindings[evidence['binding']]
        assert binding['strict'] is True
        assert binding['test'] == 'build/vf3matrixfamily.exe '+entry
        assert (ROOT/binding['golden']).is_file()
        for name, proof in evidence['proofs'].items():
            report = json.loads((ROOT/'extract/analysis'/name).read_text())
            assert report[entry] == proof, f'Stale proof: {name} {entry}'
            match = re.fullmatch(r'matrix_family: (\d+)/(\d+) cases match \(0 skipped\) - PASS', proof['stdout'])
            assert proof['pass'] and match and int(match[1]) == int(match[2]) > 0
        chosen = next(p for p in evidence['proofs'].values() if p['cases'].replace('\\','/') == binding['golden'])
        count = int(re.search(r'(\d+)/', chosen['stdout'])[1])
        cases += count
        case = ROOT/binding['golden']
        if case.parent not in campaigns:
            campaign = json.loads((case.parent/'capsule_manifest.json').read_text())
            batch = json.loads((case.parent/'batch_manifest.json').read_text())
            assert all(r['returncode'] == 0 for r in batch['runs'])
            # V4 predates shutdown summaries; its batch exit codes are retained.
            assert 'runs' in campaign or case.parent.name == 'matrix_v4_cases'
            for run in campaign.get('runs', []):
                if not run.get('summary_missing'):
                    assert run['started'] == run['completed']+len(run['incomplete'])
            campaigns[case.parent] = campaign
        campaign=campaigns[case.parent]
        for run in campaign.get('runs', []):
            assert entry not in {hex(int(r['entry'],16)|0x80000000) for r in run.get('incomplete',[])}
        records=campaign['entries'][entry]
        assert len(records) == count
        minimum=evidence.get('minimum_cases',manifest.get('minimum_cases',1))
        assert count>=minimum, f'Insufficient distinct cases: {entry}'
        batch=json.loads((case.parent/'batch_manifest.json').read_text())
        scenario_map={str(Path(run['capsule']).resolve()):(run.get('state',''),run.get('play','')) for run in batch['runs'] if run.get('capsule')}
        scenarios={scenario_map.get(str(Path(source['source']).resolve()),source['source']) for record in records for source in record['sources']}
        assert len(scenarios)>=manifest.get('minimum_scenarios',1), f'Insufficient scenarios: {entry}'
        artifacts = sorted(p for p in case.parent.glob(case.stem+'*') if p.is_file())
        assert len(artifacts) == evidence['artifacts']['count']
        archive_hash = hashlib.sha256()
        for path in artifacts:
            if check_hashes:
                with path.open('rb') as f:
                    digest = hashlib.file_digest(f, 'sha256').hexdigest()
                artifact = path.relative_to(ROOT).as_posix()
                archive_hash.update((artifact+'\\0'+digest+'\\n').encode())
        if check_hashes:
            assert archive_hash.hexdigest() == evidence['artifacts']['sha256'], f'Changed corpus: {entry}'
        if evidence['new_credit']:
            assert e in sizes and int(ledger[e]['size']) == evidence['size'] == sizes[e]
            assert ledger[e]['status'] == 'ported-invocation'
            promoted.add(e)

    def union(spans):
        total = 0
        end = 0
        for a, z in sorted(map(tuple,spans)):
            total += max(0, z-max(a, end))
            end = max(end, z)
        return total

    baseline = manifest['baseline_spans']
    before = union(baseline)
    after = union(baseline+[span for e in promoted for span in ranges[e]])
    assert before == manifest['baseline_unique_bytes']
    assert sum(sizes.values()) == manifest['frozen_body_bytes']
    assert after-before >= manifest['minimum_gain']
    print(f'{Path(manifest_path).stem}: {len(promoted)} new entries, {cases} strict bound cases; unique C bytes {before} -> {after} (+{after-before}) - PASS')
    return before, after


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes', action='store_true', help='also rehash all archived RAM vectors')
    parser.add_argument('--manifest', default='tools/oracle/matrix_batch.json')
    args = parser.parse_args()
    audit(args.hashes, args.manifest)
