"""Rank uncredited frozen owners without treating the ranking as C evidence."""
import argparse
import bisect
import csv
import json
from collections import Counter
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans
from batch_plan import implementation_graph


def rank(minimum, maximum):
    coverage = json.loads((ROOT / 'extract/analysis/coverage.json').read_text())
    accepted = {pc for a, z in coverage['ported_spans'] for pc in range(a, z)}
    assert len(accepted) == coverage['ported_unique_bytes']
    spans = body_spans()
    inventory = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv').open())}
    entries = sorted(spans)
    heat = Counter()
    for row in csv.DictReader((ROOT / 'extract/analysis/trace_fn_hits.csv').open()):
        pc = int(row['fn'], 16)
        i = bisect.bisect_right(entries, pc) - 1
        if i >= 0 and any(a <= pc < z for a, z in spans[entries[i]]):
            heat[entries[i]] += int(row['hits'])
    blocks = {int(r['owner'], 16) for r in json.loads(
        (ROOT / 'tools/oracle/coverage_65_candidate_blocks.json').read_text())['blocks']}
    rows = []
    resolved = {int(row['site'], 16): int(row['target'], 16) | 0x80000000
                for row in csv.DictReader((ROOT / 'extract/analysis/sh4_resolved.csv').open())
                if row['class'] == 'STATIC'}
    scan = implementation_graph((ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes(), resolved)
    for entry, ranges in spans.items():
        body = {pc for a, z in ranges for pc in range(a, z)}
        margin = len(body - accepted)
        if minimum <= margin <= maximum and entry in inventory and entry not in blocks:
            pcs, calls, unknown = scan(entry)
            rows.append(dict(owner=hex(entry), frozen_bytes=len(body), marginal_bytes=margin,
                             hits=heat[entry], spans=[[hex(a), hex(z)] for a, z in ranges],
                             static_calls=[hex(pc) for pc in sorted(calls)],
                             unresolved_sites=[hex(pc) for pc in sorted(unknown)],
                             reachable_bytes=len(pcs)*2))
    rows.sort(key=lambda r: (-r['hits'], -r['marginal_bytes'], r['owner']))
    return dict(advisory=True, coverage_credit=False, accepted_bytes=len(accepted), candidates=rows)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--min-bytes', type=int, default=40)
    parser.add_argument('--max-bytes', type=int, default=2500)
    parser.add_argument('--top', type=int, default=60)
    parser.add_argument('--leaves', action='store_true')
    parser.add_argument('--callee', type=lambda s: int(s, 0) | 0x80000000)
    parser.add_argument('--max-sites', type=int)
    parser.add_argument('--max-reachable-ratio', type=float)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists():
        raise FileExistsError('refusing to replace retained inventory')
    result = rank(args.min_bytes, args.max_bytes)
    if args.max_sites is not None:
        result['candidates'] = [r for r in result['candidates']
                                if len(r['unresolved_sites']) <= args.max_sites]
    if args.max_reachable_ratio is not None:
        result['candidates'] = [r for r in result['candidates']
                                if r['reachable_bytes'] <= r['frozen_bytes']*args.max_reachable_ratio]
    if args.leaves:
        result['candidates'] = [r for r in result['candidates']
                                if not r['static_calls'] and not r['unresolved_sites']]
    if args.callee is not None:
        result['candidates'] = [r for r in result['candidates']
                                if r['static_calls'] == [hex(args.callee)] and not r['unresolved_sites']]
    args.out.write_text(json.dumps(result, indent=2) + '\n')
    print(f"Accepted {result['accepted_bytes']}; {len(result['candidates'])} advisory owners")
    for row in result['candidates'][:args.top]:
        print(f"{row['owner']} {row['marginal_bytes']:5} B {row['hits']:8} hits "
              f"{len(row['static_calls'])} calls {len(row['unresolved_sites'])} unknown")
