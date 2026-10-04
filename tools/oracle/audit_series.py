"""Audit a frozen coverage milestone chain, optionally hashing archives in parallel."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import csv
import hashlib
import json
from pathlib import Path
import subprocess
import sys
from select_next import union

ROOT = Path(__file__).resolve().parents[2]


def chain(baseline_path, paths):
    baseline = json.loads(baseline_path.read_text())
    for name in ('inventory', 'body_ranges', 'image'):
        with (ROOT / baseline[name]).open('rb') as stream:
            digest = hashlib.file_digest(stream, 'sha256').hexdigest()
        if digest != baseline[name + '_sha256']:
            raise ValueError(f'Changed frozen {name}')
    spans = list(map(tuple, baseline['baseline_spans']))
    current = union(spans)
    if current != baseline['baseline_bytes']:
        raise ValueError('Frozen baseline spans disagree with byte total')
    ranges = {}
    with (ROOT / baseline['body_ranges']).open(newline='') as stream:
        for row in csv.DictReader(stream):
            ranges.setdefault(int(row['entry'], 16), []).append(
                (int(row['start'], 16), int(row['end'], 16)))
    seen, rows = set(), []
    manifests = [(p, json.loads(p.read_text())) for p in paths]
    manifests.sort(key=lambda item: item[1]['baseline_unique_bytes'])
    if not manifests:
        raise ValueError('No milestone manifests selected')
    for path, manifest in manifests:
        if manifest['baseline_unique_bytes'] != current:
            raise ValueError(f'{path.name}: gap or fork at {current} bytes')
        if manifest['frozen_body_bytes'] != baseline['total_body_bytes']:
            raise ValueError(f'{path.name}: changed denominator')
        entries = {int(e, 16) | 0x80000000 for e, v in manifest['entries'].items() if v['new_credit']}
        if seen & entries:
            raise ValueError(f'{path.name}: duplicate credited entries')
        seen.update(entries)
        gain = manifest['measured_gain']
        if gain < 0:
            raise ValueError(f'{path.name}: negative gain')
        spans.extend(span for entry in entries for span in ranges[entry])
        if union(spans) - current != gain:
            raise ValueError(f'{path.name}: cumulative interval union disagrees with gain')
        rows.append(dict(manifest=str(path), before=current, after=current + gain,
                         gain=gain, entries=len(entries)))
        current += gain
    return dict(baseline_bytes=baseline['baseline_bytes'], total_body_bytes=baseline['total_body_bytes'],
                target_bytes=baseline['target_bytes'], final_bytes=current,
                gain=current - baseline['baseline_bytes'], new_entries=len(seen),
                percentage_points=100 * (current - baseline['baseline_bytes']) / baseline['total_body_bytes'],
                target_met=current >= baseline['target_bytes'], milestones=rows)


def audit_one(row, hashes):
    command = [sys.executable, str(ROOT / 'tools/oracle/audit_matrix_batch.py'),
               '--manifest', row['manifest']]
    if hashes:
        command.append('--hashes')
    result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    return {**row, 'returncode': result.returncode, 'stdout': result.stdout, 'stderr': result.stderr}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, default=ROOT / 'tools/oracle/tenpp_coverage_baseline.json')
    parser.add_argument('--pattern', default='tools/oracle/tenpp_*milestone.json', help='repository-relative glob')
    parser.add_argument('--hashes', action='store_true')
    parser.add_argument('--jobs', type=int, choices=range(1, 5), default=1)
    parser.add_argument('--out', type=Path, help='incremental JSON audit report')
    args = parser.parse_args()
    summary = chain(args.baseline.resolve(), sorted(ROOT.glob(args.pattern)))
    summary.update(hashes=args.hashes, audits=[], complete=False, passed=False)

    def save():
        if args.out:
            args.out.parent.mkdir(parents=True, exist_ok=True)
            args.out.write_text(json.dumps(summary, indent=1) + '\n')

    save()
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [pool.submit(audit_one, row, args.hashes) for row in summary['milestones']]
        for future in as_completed(futures):
            result = future.result()
            summary['audits'].append(result)
            summary['audits'].sort(key=lambda row: row['before'])
            save()
            print(result['stdout'].rstrip(), flush=True)
            if result['stderr']:
                print(result['stderr'].rstrip(), file=sys.stderr, flush=True)
    summary['complete'] = True
    summary['passed'] = all(row['returncode'] == 0 for row in summary['audits'])
    save()
    print(f"{summary['new_entries']} new entries; +{summary['gain']} unique C bytes; "
          f"+{summary['percentage_points']:.6f} percentage points; target_met={summary['target_met']}; "
          f"audits_passed={summary['passed']}")
    return 0 if summary['passed'] else 1


if __name__ == '__main__':
    sys.exit(main())
