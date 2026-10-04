"""Rank unported original bodies by marginal C union bytes and closure cost."""
import argparse
import csv
import json
from pathlib import Path
from select_next import ROOT, union
from campaign_io import read_watch, write_watch


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--plan', type=Path, required=True)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--limit', type=int, default=100)
    parser.add_argument('--max-dynamic', type=int)
    parser.add_argument('--min-dynamic', type=int, default=0)
    parser.add_argument('--minimum-size', type=int, default=16)
    parser.add_argument('--exclude-watch', type=Path, action='append', default=[],
                        help='omit roots already attempted; repeatable')
    parser.add_argument('--exclude-progress', type=Path, action='append', default=[],
                        help='omit entries attempted in isolate_planned progress JSON; repeatable')
    args = parser.parse_args()
    attempted = {entry for watch in args.exclude_watch for entry in read_watch(watch)}
    attempted.update(int(entry, 16) for path in args.exclude_progress
                     for row in json.loads(path.read_text())
                     for entry in row.get('entries', [row['entry']]))
    credited = {int(r['entry'], 16) for r in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if r['status'].startswith('ported')}
    baseline = json.loads(args.baseline.read_text())
    ranges = {}
    for r in csv.DictReader((ROOT / baseline['body_ranges']).open()):
        ranges.setdefault(int(r['entry'], 16), []).append((int(r['start'], 16), int(r['end'], 16)))
    spans = list(map(tuple, baseline['baseline_spans']))
    spans += [span for entry in credited for span in ranges.get(entry, [])]
    before = union(spans)
    candidates = []
    for row in csv.DictReader(args.plan.open()):
        entry = int(row['entry'], 16)
        dynamic = int(row.get('sh4_dyn') or 0)
        if dynamic < args.min_dynamic:
            continue
        if entry in credited or entry in attempted or int(row['size']) < args.minimum_size:
            continue
        if args.max_dynamic is not None and dynamic > args.max_dynamic:
            continue
        gain = union(spans + ranges.get(entry, [])) - before
        if not gain:
            continue
        candidates.append({**row, 'marginal_bytes': gain, 'dynamic_calls': dynamic})
    candidates.sort(key=lambda r: (r['dynamic_calls'], -r['marginal_bytes'], r['entry']))
    selected = candidates[:args.limit]
    potential = union(spans + [span for row in selected for span in ranges[int(row['entry'], 16)]]) - before
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(dict(advisory=True, baseline_bytes=before,
        potential_unique_bytes=potential, candidates=selected), indent=1) + '\n')
    write_watch(args.watch, [int(r['entry'], 16) for r in selected],
                'Unported bodies ranked by closure and marginal C bytes; no credit.',
                preserve_order=True)
    print(f'{len(selected)}/{len(candidates)} candidates; potential union +{potential} B')
    for row in selected[:25]:
        print(f"{row['entry']} +{row['marginal_bytes']} B dyn={row['dynamic_calls']} campaign={row['campaign']}")


if __name__ == '__main__':
    main()
