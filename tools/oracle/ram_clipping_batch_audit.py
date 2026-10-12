"""Audit the complete RAM/clipping evidence without changing coverage ledgers."""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
from task_completion_audit import freeze
from capsules import records
from audio_corpus import validate_batch
from regression_status import summarize

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
sys.path.insert(0, str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate as validate_callable
from callable_geometry import original_pools
from portcheck import TESTS


def digest(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def reference(path):
    return {'path': str(Path(path).resolve()), 'sha256': digest(path)}


def native_suite_files(suites):
    assert len(suites) == len(TESTS) and {row['test'] for row in suites} == set(TESTS), 'wrong native suite inventory'
    files = []
    for row in suites:
        executable = Path(row.get('executable', ROOT/'build'/f'{row["test"]}.exe'))
        assert row['status'] == 'PASS' and digest(executable) == row['sha256'], 'native suite executable changed or failed'
        files.append(reference(executable))
    return files


def caller_files(attributions):
    files = []
    paths = {row['path']: row['sha256'] for attribution in attributions.values()
             for row in attribution['original_caller_manifests']}
    for name, expected in paths.items():
        path = Path(name)
        assert digest(path) == expected, 'changed original caller manifest'
        files.append(reference(path))
        manifest = json.loads(path.read_text())
        for name, expected in manifest['provenance'].items():
            assert digest(name) == expected, 'changed original caller provenance'
            files.append(reference(name))
        for run in manifest['runs']:
            for name, expected in ((run['log'], run['log_sha256']),
                    (Path(run['log']).with_suffix('.patch'), run['patch_sha256']),
                    (run['capsule'], run['capsule_sha256']),
                    (run['audio']['path'], run['audio']['sha256'])):
                assert digest(name) == expected, 'changed original caller artifact'
                files.append(reference(name))
            files.append(reference(str(run['capsule'])+'.summary.json'))
            files.append(reference(ROOT/run['state']))
    return files


def campaign(directory, report_path, owners, native, image, quarantined=()):
    directory = Path(directory)
    manifest = json.loads((directory/'capsule_manifest.json').read_text())
    batch = json.loads((directory/'batch_manifest.json').read_text())
    validate_batch(batch, True)
    quarantined=set(quarantined)
    assert (len(batch['runs']) == 2 or batch.get('mode') == 'original_ram_supplemented') and set(manifest['nondeterministic_entries'])<=quarantined, 'need two complete deterministic scenarios'
    report = json.loads(Path(report_path).read_text())
    spans = body_spans()
    states, fingerprints, proofs, files = set(), set(), [], []
    native_hash = digest(native)
    scenarios = {}
    for run in batch['runs']:
        raw = Path(run['capsule'])
        summary_path = Path(str(raw)+'.summary.json')
        summary = json.loads(summary_path.read_text())
        assert summary['started'] == summary['completed'] and not summary['incomplete'] and not summary['unaccounted'], 'incomplete original campaign'
        assert run['emulator_sha256'] == digest(CACHE/'flycast_task_return_boundary_v1.exe'), 'changed original observer'
        state = ROOT/run['state']
        state_hash = digest(state)
        states.add(state_hash)
        seen, inputs, invalid = scenarios.setdefault(state_hash, (defaultdict(set), defaultdict(set), Counter()))
        counted = 0
        for sample in records(raw):
            counted += 1
            if sample['flags']:
                assert sample['flags'] in (1, 4, 5, 6), 'unsupported exclusion flag'
                invalid[sample['flags']] += 1
                continue
            assert sample['nstate'] == 63 and not sample['device'], 'batch scope requires complete architectural/RAM specimens'
            original_pools(sample, image, sample['ops'])
            entry = hex(sample['entry']|0x80000000)
            assert entry in owners or entry in quarantined, 'unexpected batch entry'
            if entry in quarantined:
                for pc,opcode in sample['ops']:
                    offset=(pc&0x1fffffff)-0x0c010000
                    assert 0<=offset<=len(image)-2 and struct.unpack_from('<H',image,offset)[0]==opcode, 'nonoriginal quarantined instruction'
                continue
            fingerprint = hashlib.sha256(sample['before']+b''.join(struct.pack('<I', base)+before for base, before, _ in sample['pages'])).hexdigest()
            fingerprints.add(fingerprint); inputs[entry].add(fingerprint)
            for pc, opcode in sample['ops']:
                offset = (pc&0x1fffffff)-0x0c010000
                assert 0 <= offset <= len(image)-2 and struct.unpack_from('<H', image, offset)[0] == opcode, 'nonoriginal batch instruction'
                seen[entry].add(pc|0x80000000)
        assert counted == summary['completed'], 'capsule accounting mismatch'
        files.extend(reference(path) for path in (raw, summary_path, state, Path(run['log']), Path(run['entry_patch'])))
        assert digest(run['entry_patch']) == run['entry_patch_sha256'], 'changed capture patch'
    assert len(states) == 2, 'duplicate original scenario states'
    for state_hash, (seen, inputs, invalid) in scenarios.items():
        for entry, owner in owners.items():
            required = {pc for start, end in spans[int(owner, 16)] for pc in range(start, end, 2)}
            assert required <= seen[entry], f'incomplete independent scenario body: {entry}'
            assert len(inputs[entry]) >= 64, f'insufficient distinct independent scenario inputs: {entry}'
        proofs.append({'state_sha256': state_hash, 'distinct_valid': {entry: len(inputs[entry]) for entry in owners}, 'excluded': dict(invalid), 'complete_owners': len(owners)})
    for entry in owners:
        count = len(manifest['entries'][entry])
        row = report[entry]
        assert count >= 64 and row['pass'] and row['stdout'] == f'matrix_family: {count}/{count} cases match (0 skipped) - PASS', 'strict native batch replay failed'
        assert row['executable_sha256'] == native_hash, 'replay used another executable'
        assert Path(row['cases']).resolve() == (directory/f'f_{int(entry,16):08x}.cases').resolve(), 'replay used another case corpus'
        for path in sorted(directory.glob(f'f_{int(entry,16):08x}*')):
            if path.is_file(): files.append(reference(path))
    files.extend(reference(path) for path in (directory/'capsule_manifest.json', directory/'batch_manifest.json', report_path))
    return states, fingerprints, proofs, files


def audit(args):
    native = freeze(args.source_freeze, native=True)
    assert len(json.loads(args.source_freeze.read_text())['files']) == 398, 'incomplete compiled source closure'
    freeze(CACHE/'task_return_boundary_v1_linked_sources/manifest.json')
    source_frozen = json.loads(args.development_freeze.read_text())
    assert source_frozen['qualified_development_only'] and source_frozen['compiled_inputs'] == 398
    for ref in source_frozen['references']:
        assert digest(ref['path']) == ref['sha256'], 'changed development freeze dependency'
    owners = json.loads(args.owners.read_text())
    assert len(owners) == 15 and owners.get('0x8c051f50') == '0x8c051f8e', 'wrong complete batch/control inventory'
    quarantine_refs=[];quarantined=set()
    if getattr(args,'quarantine',None):
        from ram_observable_nondeterminism import validate as validate_quarantine
        quarantine=validate_quarantine(args.quarantine)
        entry=quarantine['quarantined_entry']
        assert entry=='0x8c0a8f8c' and owners[entry]==quarantine['quarantined_owner'], 'wrong quarantined owner'
        quarantined={entry};owners={entry:owner for entry,owner in owners.items() if entry not in quarantined}
        quarantine_refs=list(quarantine['references'].values())+[reference(args.quarantine),reference(Path(__file__).with_name('ram_observable_nondeterminism.py'))]
    image_path = ROOT/'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()
    dev_states, dev_inputs, dev, dev_files = campaign(args.development, args.development_report, owners, native, image, quarantined)
    held_states, held_inputs, held, held_files = campaign(args.acceptance, args.acceptance_report, owners, native, image, quarantined)
    assert dev_states.isdisjoint(held_states) and dev_inputs.isdisjoint(held_inputs), 'development/acceptance reuse'
    holdout_inputs = json.loads(args.holdout_inputs.read_text())
    frozen_ref = holdout_inputs['development_freeze']
    assert Path(frozen_ref['path']).resolve() == args.development_freeze.resolve() and frozen_ref['sha256'] == digest(args.development_freeze), 'holdout used another source freeze'
    assert args.holdout_inputs.stat().st_mtime_ns >= args.development_freeze.stat().st_mtime_ns, 'holdout inputs precede source freeze'
    for ref in holdout_inputs['files']:
        assert digest(ref['path']) == ref['sha256'], 'changed held input artifact'
    held_batch = json.loads((args.acceptance/'batch_manifest.json').read_text())
    if quarantined:
        held_primary=held_batch.get('original_frame_campaign',reference(args.acceptance/'batch_manifest.json'))
        assert held_primary==quarantine['references']['frame_manifest'], 'quarantine witness is from another held campaign'
    supplement_refs = []
    if held_batch.get('mode') == 'original_ram_supplemented':
        from ram_holdout_supplement import checked, evidence_references
        recipe_path = checked(held_batch['supplement_inputs'])
        recipe = json.loads(recipe_path.read_text())
        assert recipe['development_freeze'] == frozen_ref, 'supplement used another C freeze'
        assert recipe_path.stat().st_mtime_ns >= args.development_freeze.stat().st_mtime_ns, 'supplement inputs precede C freeze'
        supplement_refs = evidence_references(held_batch)
        supplement_refs += [reference(Path(__file__).with_name('ram_holdout_supplement.py')), reference(Path(__file__).with_name('audio_corpus.py'))]
    attributions = json.loads(args.callable_map.read_text())
    expected = set(owners.values())-{'0x8c051f8e'}
    assert set(attributions)==expected|({'0x8c0a8f98'} if quarantined else set()), 'missing batch caller attribution'
    attributions={owner:row for owner,row in attributions.items() if owner in expected}
    assert len(expected)==14-len(quarantined), 'wrong selected owner inventory'
    spans = body_spans()
    for owner, attribution in attributions.items():
        for directory in (args.development, args.acceptance):
            validate_callable(int(owner,16), attribution, spans[int(owner,16)], directory, image)
    bindings = json.loads((ROOT/'tools/golden_bindings.json').read_text())
    status = summarize(args.full_regression.read_text(encoding='utf-8-sig', errors='replace'), bindings)
    assert status['passed'], 'full current binding inventory has not passed'
    suites = json.loads(args.native_suites.read_text())
    suite_files = native_suite_files(suites)
    original_caller_files = caller_files(attributions)
    tests = args.tool_tests.read_text()
    assert re.search(r'Ran \d+ tests', tests) and '\nOK\n' in tests and '\nFAILED' not in tests, 'oracle tool tests failed'
    baseline = json.loads(args.baseline.read_text())
    assert baseline['baseline_bytes'] == 267230 and baseline['total_body_bytes'] == 434656 and baseline['target_bytes'] == 282527
    for key in ('inventory', 'body_ranges', 'image'):
        assert digest(ROOT/baseline[key]) == baseline[key+'_sha256'], 'changed frozen body/image inventory'
    accepted = {byte for start, end in baseline['baseline_spans'] for byte in range(start, end)}
    body = {byte for owner in expected for start, end in spans[int(owner,16)] for byte in range(start, end)}
    gain = len(body-accepted)
    assert gain == 6076-158*len(quarantined), 'changed batch marginal address union'
    assert not args.out.exists(), 'refuse to overwrite qualification evidence'
    files = dev_files+held_files+suite_files+original_caller_files+supplement_refs+quarantine_refs+[reference(path) for path in (args.source_freeze, args.development_freeze, native, image_path, args.owners, args.callable_map, args.holdout_inputs, args.baseline, args.full_regression, args.native_suites, args.tool_tests, Path(__file__))]
    args.out.write_text(json.dumps({'coverage_credit': False, 'ready_for_promotion': True, 'marginal_bytes': gain, 'quarantined_entries':sorted(quarantined),'frozen_body_bytes': 434656, 'development': dev, 'acceptance': held, 'full_regression': status, 'references': list({ref['path']: ref for ref in files}.values())}, indent=2)+'\n')
    print(f'Selected batch audit PASS; {gain} marginal bytes ready for ledger promotion; {len(quarantined)} owners remain uncredited')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('source-freeze', 'development-freeze', 'development', 'development-report', 'acceptance', 'acceptance-report', 'owners', 'callable-map', 'holdout-inputs', 'baseline', 'full-regression', 'native-suites', 'tool-tests', 'out'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--quarantine',type=Path,help='verified original observable-input disagreement; excludes the entire owner from credit')
    audit(parser.parse_args())
