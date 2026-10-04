"""Freeze a new C coverage campaign from the current coverage dashboard."""
import argparse
import csv
import hashlib
import json
from datetime import date
from pathlib import Path
from select_next import ROOT, union


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--previous', type=Path, default=ROOT / 'tools/oracle/tenpp_coverage_baseline.json')
    parser.add_argument('--coverage', type=Path, default=ROOT / 'extract/analysis/coverage.json')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--points', type=int, default=10)
    args = parser.parse_args()
    if args.out.exists():
        raise ValueError('Refusing to overwrite a frozen campaign')
    if not 1 <= args.points <= 100:
        raise ValueError('points must be between 1 and 100')
    previous = json.loads(args.previous.read_text())
    for name in ('inventory', 'body_ranges', 'image'):
        with (ROOT / previous[name]).open('rb') as stream:
            actual = hashlib.file_digest(stream, 'sha256').hexdigest()
        if actual != previous[name + '_sha256']:
            raise ValueError(f'Changed frozen {name}')
    coverage = json.loads(args.coverage.read_text())
    spans = coverage['ported_spans']
    baseline = union(spans)
    ranges = {}
    for row in csv.DictReader((ROOT / previous['body_ranges']).open()):
        ranges.setdefault(int(row['entry'], 16), []).append((int(row['start'], 16), int(row['end'], 16)))
    ledger = ROOT / 'docs/decomp_status.csv'
    entries = {int(row['entry'], 16) for row in csv.DictReader(ledger.open())
               if row['status'].startswith('ported')}
    current = list(map(tuple, previous['baseline_spans'])) + [
        span for entry in entries for span in ranges.get(entry, [])]
    if union(current) != baseline or coverage['ported_unique_bytes'] != baseline:
        raise ValueError('Stale coverage dashboard; run tools/decomp_stats.py first')
    gain = (previous['total_body_bytes'] * args.points + 99) // 100
    frozen = {**previous, 'milestone': f'next {args.points} percentage points of verified readable C',
              'frozen_on': date.today().isoformat(), 'baseline_bytes': baseline,
              'baseline_spans': spans, 'target_gain': gain, 'target_bytes': baseline + gain,
              'starting_ledger_sha256': hashlib.sha256(ledger.read_bytes()).hexdigest()}
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(frozen, indent=1) + '\n')
    print(f'Frozen {baseline} bytes; target {baseline + gain}; gain {gain}')


if __name__ == '__main__':
    main()
