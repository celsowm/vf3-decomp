"""Rank shared dependency families by marginal C union and capture evidence.

Missing implementation edges are advisory static leads. Unknown indirect calls
remain explicit costs; neither this report nor SDK identity grants C credit.
"""
import argparse
from bisect import bisect_right
import csv
import io
import json
from pathlib import Path

from campaign_io import attempted_entries, write_watch
from select_next import ROOT, union


def merged_spans(spans):
    """Canonical half-open intervals, ignoring empty seed fragments."""
    merged = []
    for start, end in sorted(spans):
        if end <= start:
            continue
        if merged and start <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(end, merged[-1][1]))
        else:
            merged.append((start, end))
    return merged


def marginal_bytes(spans, covered, covered_ends):
    """Count a canonical candidate against a canonical covered union."""
    total = 0
    for start, end in spans:
        cursor = start
        index = bisect_right(covered_ends, start)
        while index < len(covered) and covered[index][0] < end:
            left, right = covered[index]
            total += max(0, left - cursor)
            cursor = max(cursor, right)
            index += 1
        total += max(0, end - cursor)
    return total


def rank_families(rows, ranges, spans, credited, observed, limit, attempted=None):
    attempted = set() if attempted is None else set(attempted)
    rows = {int(row['entry'], 16): row for row in rows
            if int(row['entry'], 16) not in credited}
    dependencies = {entry: {int(value, 16) for value in row.get('missing_implementations', '').split()}
                    for entry, row in rows.items()}

    def closure(roots):
        members, pending = set(), list(roots)
        while pending:
            entry = pending.pop()
            if entry in members or entry in credited:
                continue
            members.add(entry)
            pending.extend(dependencies.get(entry, set()) - members)
        return members

    groups = {f'root:{entry:#x}': {entry} for entry in rows if entry not in attempted}
    for entry, helpers in dependencies.items():
        if entry in attempted:
            continue
        for helper in helpers:
            if helper not in credited:
                groups.setdefault(f'helper:{helper:#x}', set()).add(entry)
    candidates = []
    for label, roots in groups.items():
        members = closure(roots)
        dynamic = sum(int(rows.get(entry, {}).get('sh4_dyn') or 0) for entry in members)
        unbounded = sorted(members - set(ranges))
        candidates.append(dict(family=label, roots=roots, members=members,
                               dynamic_calls=dynamic, unbounded=unbounded,
                               spans=merged_spans(span for entry in members
                                                  for span in ranges.get(entry, []))))
    selected, covered = [], merged_spans(spans)
    for _ in range(limit):
        covered_ends = [end for _, end in covered]
        ranked = []
        for candidate in candidates:
            members = candidate['members']
            added = candidate['spans']
            gain = marginal_bytes(added, covered, covered_ends)
            if gain == 0:
                continue
            cost = 1 + len(members) + candidate['dynamic_calls'] + len(candidate['unbounded'])
            seen = sum(observed.get(entry, 0) >= 2 for entry in candidate['roots'])
            ranked.append((gain / cost, seen, gain, candidate['family'], candidate, added))
        if not ranked:
            break
        score, seen, gain, _, winner, added = max(ranked, key=lambda item: item[:4])
        covered = merged_spans(covered + added)
        candidates.remove(winner)
        selected.append(dict(family=winner['family'], marginal_bytes=gain,
            score=round(score, 3), observed_roots_in_two_scenarios=seen,
            callers=[hex(entry) for entry in sorted(winner['roots'])],
            members=[hex(entry) for entry in sorted(winner['members'])],
            dynamic_calls=winner['dynamic_calls'],
            missing_body_intervals=[hex(entry) for entry in winner['unbounded']]))
    return selected, union(covered) - union(spans)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--plan', type=Path, required=True)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--survey', type=Path, action='append', default=[])
    parser.add_argument('--limit', type=int, default=20)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--exclude-watch', type=Path, action='append', default=[])
    parser.add_argument('--exclude-progress', type=Path, action='append', default=[])
    args = parser.parse_args()
    baseline = json.loads(args.baseline.read_text())
    credited = {int(row['entry'], 16) for row in csv.DictReader(io.StringIO(
        (ROOT / 'docs/decomp_status.csv').read_text())) if row['status'].startswith('ported')}
    ranges = {}
    for row in csv.DictReader(io.StringIO((ROOT / baseline['body_ranges']).read_text())):
        ranges.setdefault(int(row['entry'], 16), []).append((int(row['start'], 16), int(row['end'], 16)))
    spans = [tuple(span) for span in baseline['baseline_spans']]
    spans.extend(span for entry in credited for span in ranges.get(entry, []))
    observed = {}
    for survey in args.survey:
        for row in json.loads(survey.read_text())['rows']:
            entry = int(row['entry'], 16)
            observed[entry] = max(observed.get(entry, 0), row['scenarios'])
    families, potential = rank_families(list(csv.DictReader(io.StringIO(args.plan.read_text()))),
                                        ranges, spans, credited, observed, args.limit,
                                        attempted_entries(args.exclude_watch, args.exclude_progress))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(dict(advisory=True, baseline_bytes=union(spans),
        potential_unique_bytes=potential, families=families), indent=1) + '\n')
    roots = {int(entry, 16) for family in families for entry in family['callers']}
    write_watch(args.watch, roots, 'Shared dependency family leads; no credit.')
    print(f'{len(families)} families; potential marginal union +{potential} bytes')
    for family in families:
        print(f"{family['family']} +{family['marginal_bytes']} bytes; "
              f"{len(family['members'])} members; {family['dynamic_calls']} unknown dynamic sites")


if __name__ == '__main__':
    main()
