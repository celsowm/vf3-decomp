"""Freeze advisory marginal bytes for the RAM/clipping implementation pool.

This is a budget check, never promotion. Existing accepted address ranges
are subtracted byte by byte, including the already credited clipping variant.
"""
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans
from coverage_65_batch_clip_inputs import OWNERS

OBSERVED = {0x8c0a8370: 0x8c0a8370, 0x8c0a8f8c: 0x8c0a8f98,
            0x8c087e04: 0x8c087e1c, 0x8c08f632: 0x8c08f642,
            0x8c098b3c: 0x8c098b40, 0x8c099194: 0x8c0991a2,
            0x8c08acc0: 0x8c08acd8}


def main():
    target = ROOT / 'tools/oracle/coverage_65_batch_candidate_budget_v1.json'
    assert not target.exists(), 'refuse to overwrite retained budget evidence'
    coverage_path = ROOT / 'extract/analysis/coverage.json'
    coverage = json.loads(coverage_path.read_text())
    assert coverage['ported_unique_bytes'] == 267230
    accepted = {byte for start, end in coverage['ported_spans'] for byte in range(start, end)}
    spans = body_spans()
    rows = []
    for group, candidates in [('observed_whole_original', OBSERVED), ('pending_clip_screen', OWNERS)]:
        for entry, owner in candidates.items():
            body = {byte for start, end in spans[owner] for byte in range(start, end)}
            rows.append({'group': group, 'entry': hex(entry), 'owner': hex(owner),
                         'body_bytes': len(body), 'current_marginal_bytes': len(body-accepted),
                         'coverage_credit': False, 'caller_proved': False})
    references = []
    for path in [coverage_path, ROOT / 'extract/analysis/function_body_ranges.csv',
                 ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv',
                 ROOT / 'tools/oracle/coverage_65_batch_candidate_budget.py']:
        references.append({'path': str(path.resolve()),
                           'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    totals = {group: sum(row['current_marginal_bytes'] for row in rows if row['group'] == group)
              for group in ('observed_whole_original', 'pending_clip_screen')}
    result = {'advisory': True, 'coverage_credit': False, 'viable_batch_proved': False,
              'baseline_verified_bytes': 267230, 'marginal_bytes': sum(totals.values()),
              'group_totals': totals, 'candidates': rows, 'references': references}
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({key: result[key] for key in ('marginal_bytes', 'group_totals', 'viable_batch_proved')}))


if __name__ == '__main__':
    main()
