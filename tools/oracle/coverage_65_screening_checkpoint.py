"""Retain excluded screening evidence without changing verified C coverage."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def reference(path):
    path = Path(path).resolve()
    return {'path': str(path), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest()}


def verify(seal):
    assert seal['coverage_credit'] is False
    assert seal['baseline_verified_bytes'] == 267230
    assert seal['target_verified_bytes'] == 282527
    assert seal['remaining_verified_bytes'] == 15297
    for ref in seal['references']:
        assert reference(ref['path']) == ref, f"changed screening evidence: {ref['path']}"
    for path in seal['reports']:
        report = json.loads(Path(path).read_text())
        assert report['coverage_credit'] is False
        assert report['campaign_suitable_for_promotion'] is False
        assert not any(run['unaccounted'] for run in report['runs'])
        for row in report['candidates']:
            assert row['coverage_credit'] is False and row['caller_proved'] is False
            assert row['captured_body_bytes'] <= row['owner_bytes']
    return seal


def seal_reports(reports):
    refs = []
    for path in reports:
        report = json.loads(path.read_text())
        refs.extend(report['references'])
        refs.append(reference(path))
    # Pin the generator, explicit typed inputs and watch lists, including any
    # prepared next pilot. Prepared files are not represented as captures.
    for pattern in ('coverage_65_batch*.py', 'coverage_65_batch*_watch.txt',
                    'coverage_65_batch*_owners.json', 'coverage_65_selection_boundary_inputs.py',
                    'coverage_65_selection_boundary*_watch.txt',
                    'coverage_65_selection_boundary*_owners.json'):
        refs.extend(reference(path) for path in (ROOT / 'tools/oracle').glob(pattern))
    for pattern in ('coverage_65_batch*.json', 'coverage_65_selection_boundary*.json'):
        refs.extend(reference(path) for path in (ROOT / 'tools/oracle/percentage_inputs').glob(pattern))
    for path in (
        'tools/oracle/coverage_65_one_session_queue_v1.json',
        'tools/oracle/replay_callback_v1_manifest.json',
        'tools/oracle/coverage_65_screening_checkpoint.py',
        'tools/oracle/tenpp_probe_plan.py', 'tools/oracle/pointer_seeds.py',
        'tools/oracle/comparison_inputs.py', 'tools/oracle/inspect_capsule.py',
        'tools/oracle/capsules.py', 'tools/golden_batch.py', 'tools/body_cover.py',
        'tools/batch_plan.py', 'tools/callable_body.py',
    ):
        refs.append(reference(ROOT / path))
    unique = {ref['path']: ref for ref in refs}
    return verify({
        'advisory': True, 'coverage_credit': False,
        'baseline_verified_bytes': 267230, 'target_verified_bytes': 282527,
        'remaining_verified_bytes': 15297,
        'reports': [str(path.resolve()) for path in reports],
        'references': list(unique.values()),
    })


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report', type=Path, action='append', default=[])
    parser.add_argument('--write', type=Path)
    parser.add_argument('--manifest', type=Path)
    args = parser.parse_args()
    if args.write:
        assert args.report and not args.write.exists(), 'reports required; retained seals cannot be overwritten'
        result = seal_reports(args.report)
        args.write.write_text(json.dumps(result, indent=2) + '\n')
    else:
        assert args.manifest, 'provide --manifest or --write with --report'
        result = verify(json.loads(args.manifest.read_text()))
    print(f"PASS: {len(result['reports'])} retained pilot reports; zero C credit; gap 15,297 bytes")
