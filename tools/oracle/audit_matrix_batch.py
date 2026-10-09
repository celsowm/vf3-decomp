#!/usr/bin/env python3
"""Check strict evidence bindings and unique byte credit for the matrix batch."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from callable_body import validate as validate_callable
from body_cover import corpus_pcs, measure

ROOT = Path(__file__).resolve().parents[2]


def check_proof_archive(case, archive, check_hashes, root=ROOT):
    files = sorted(p for p in case.parent.glob(case.stem+'*') if p.is_file())
    assert len(files) == archive['count'], 'proof artifact count changed'
    if check_hashes:
        digest = hashlib.sha256()
        for path in files:
            with path.open('rb') as stream:
                file_hash = hashlib.file_digest(stream, 'sha256').hexdigest()
            digest.update((path.relative_to(root).as_posix()+'\\0'+file_hash+'\\n').encode())
        assert digest.hexdigest() == archive['sha256'], 'proof corpus changed'


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
        attribution = evidence.get('callable_body')
        invocation = attribution['entry'] if attribution else entry
        assert binding.get('callable_body') == attribution
        assert binding['strict'] is True
        assert binding['test'] == 'build/vf3matrixfamily.exe '+invocation
        assert (ROOT/binding['golden']).is_file()
        for name, proof in evidence['proofs'].items():
            report = json.loads((ROOT/'extract/analysis'/name).read_text())
            assert report[invocation] == proof, f'Stale proof: {name} {entry}'
            if check_hashes and proof.get('executable_sha256'):
                with (ROOT / proof['executable']).open('rb') as stream:
                    digest = hashlib.file_digest(stream, 'sha256').hexdigest()
                assert digest == proof['executable_sha256'], f'Changed proof executable: {name}'
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
            assert invocation not in {hex(int(r['entry'],16)|0x80000000) for r in run.get('incomplete',[])}
        records=campaign['entries'][invocation]
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
        if attribution or evidence.get('proof_artifacts'):
            scenario_sets = []
            for proof_name, proof in evidence['proofs'].items():
                proof_case = ROOT / proof['cases']
                proof_dir = proof_case.parent
                archive = evidence['proof_artifacts'][proof_name]
                check_proof_archive(proof_case, archive, check_hashes)
                if attribution:
                    validate_callable(e, attribution, ranges[e], proof_dir)
                else:
                    proof_pcs = corpus_pcs([proof_dir])
                    assert measure(e, ranges[e], proof_pcs[int(invocation,16)][0])[:2] == (evidence['size'], evidence['size']), 'incomplete proof body execution'
                cm = json.loads((proof_dir/'capsule_manifest.json').read_text())
                bm = json.loads((proof_dir/'batch_manifest.json').read_text())
                assert all(r['returncode'] == 0 and r['frame_complete'] for r in bm['runs'])
                assert not cm.get('nondeterministic_entries')
                assert not any(int(r['entry'],16)|0x80000000 == int(invocation,16) for run in cm['runs'] for r in run.get('incomplete',[]))
                rows = cm['entries'][invocation]
                assert len(rows) == int(re.search(r'(\d+)/', proof['stdout'])[1]) >= manifest['minimum_cases']
                sources = {str(Path(r['capsule']).resolve()):(r['state'],r['play']) for r in bm['runs']}
                used = {sources[str(Path(s['source']).resolve())] for row in rows for s in row['sources']}
                assert len(used) >= manifest['minimum_scenarios']
                scenario_sets.append(used)
            assert len(scenario_sets) == 2 and scenario_sets[0].isdisjoint(scenario_sets[1])
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
    if 'measured_gain' in manifest:
        assert after-before == manifest['measured_gain']
    if 'target_met' in manifest:
        assert manifest['target_met'] == (after-before >= manifest['target_gain'])
    print(f'{Path(manifest_path).stem}: {len(promoted)} new entries, {cases} strict bound cases; unique C bytes {before} -> {after} (+{after-before}) - PASS')
    return before, after


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes', action='store_true', help='also rehash all archived RAM vectors')
    parser.add_argument('--manifest', default='tools/oracle/matrix_batch.json')
    args = parser.parse_args()
    audit(args.hashes, args.manifest)
