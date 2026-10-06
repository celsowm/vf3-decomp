"""Find uncredited complete-body development leads in retained capture reports.

Reports are an advisory index only. Re-run capture_report on their raw corpora
before replay or promotion; this tool never produces proof or ledger credit.
"""
import argparse
import csv
import json
from pathlib import Path

from campaign_io import write_watch
from select_next import ROOT, union


def catalog(reports, baseline, owners=None, single_scenario=False,
            maximum_gap=None, minimum_body=0):
    if maximum_gap is not None and (maximum_gap < 1 or single_scenario):
        raise ValueError('body-gap mode needs a positive gap and two scenarios')
    frozen = json.loads(Path(baseline).read_text())
    with (ROOT / 'docs/decomp_status.csv').open() as ledger:
        credited = {int(row['entry'], 16) for row in csv.DictReader(ledger)
                    if row['status'].startswith('ported')}
    ranges = {}
    with (ROOT / frozen['body_ranges']).open() as body_ranges:
        for row in csv.DictReader(body_ranges):
            ranges.setdefault(int(row['entry'], 16), []).append(
                (int(row['start'], 16), int(row['end'], 16)))
    spans = list(map(tuple, frozen['baseline_spans']))
    spans += [span for entry in credited for span in ranges.get(entry, [])]
    before = union(spans)
    linked = json.loads(Path(owners).read_text()) if owners else {}
    found = {}
    for report in sorted(set(map(Path, reports))):
        if any(word in report.name.lower() for word in ('accept', 'holdout', 'held')):
            continue
        data = json.loads(report.read_text())
        entries = data.get('entries') if isinstance(data, dict) else None
        if not isinstance(entries, list):
            continue
        for row in entries:
            required_reasons = (['unexecuted body PCs'] if maximum_gap is not None else
                                ['fewer than two scenarios'] if single_scenario else [])
            if not isinstance(row, dict) or row.get('reasons') != required_reasons:
                continue
            entry = int(row['entry'], 16)
            directory = Path(row['directory'])
            if (entry in credited or entry not in ranges or not directory.is_dir()
                    or any(word in str(directory).lower() for word in ('accept', 'holdout', 'held'))
                    or row.get('distinct_cases', 0) < 64
                    or len(row.get('scenarios', [])) < (1 if single_scenario else 2)
                    or row.get('body_bytes', 0) < max(1, minimum_body)):
                continue
            gap = row['body_bytes'] - row.get('covered_bytes', 0)
            if maximum_gap is None:
                if gap != 0 or row.get('missing_pcs') != []:
                    continue
            elif not 0 < gap <= maximum_gap or not row.get('missing_pcs'):
                continue
            gain = union(spans + ranges[entry]) - before
            if gain <= 0:
                continue
            item = found.setdefault(entry, dict(entry=f'0x{entry:08x}',
                marginal_bytes=gain, source=linked.get(f'0x{entry:08x}'), corpora=[]))
            evidence = dict(directory=str(directory), report=str(report),
                distinct_cases=row['distinct_cases'], scenarios=row['scenarios'],
                missing_bytes=gap, missing_pcs=row['missing_pcs'])
            if not any(previous['directory'] == evidence['directory'] for previous in item['corpora']):
                item['corpora'].append(evidence)
    rows = sorted(found.values(), key=lambda row: (-row['marginal_bytes'], row['entry']))
    potential = union(spans + [span for entry in found for span in ranges[entry]]) - before
    return dict(advisory=True, single_scenario=single_scenario, maximum_gap=maximum_gap,
                baseline_bytes=before, potential_unique_bytes=potential,
                candidates=rows, note='Retained report leads; fresh raw capture gates required.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--pattern', action='append', required=True,
                        help='repository-relative report glob; repeatable')
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--owners', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--watch', type=Path)
    parser.add_argument('--single-scenario', action='store_true',
                        help='find complete bodies needing a second development scenario')
    parser.add_argument('--maximum-gap', type=int,
                        help='find two-scenario development bodies missing at most this many bytes')
    parser.add_argument('--minimum-body', type=int, default=0)
    args = parser.parse_args()
    reports = [report for pattern in args.pattern for report in ROOT.glob(pattern)]
    data = catalog(reports, args.baseline, args.owners, args.single_scenario,
                   args.maximum_gap, args.minimum_body)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(data, indent=1) + '\n')
    if args.watch:
        write_watch(args.watch, [int(row['entry'], 16) for row in data['candidates']],
                    'Retained complete-body report leads; recheck raw evidence before credit.')
    print(f"{len(reports)} reports: {len(data['candidates'])} uncredited leads, "
          f"potential +{data['potential_unique_bytes']} union bytes")
    for row in data['candidates'][:40]:
        print(row['entry'], row['marginal_bytes'], row['source'], len(row['corpora']), 'corpora')


if __name__ == '__main__':
    main()
