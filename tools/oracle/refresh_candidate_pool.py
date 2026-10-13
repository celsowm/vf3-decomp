"""Refresh a reserve's current margins while removing recorded whole-owner blocks."""
import argparse
import json
from pathlib import Path
from candidate_margin import measure
from ram_clipping_batch_audit import reference

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prior', type=Path, required=True)
    parser.add_argument('--blocks', type=Path, default=ROOT/'tools/oracle/coverage_65_candidate_blocks.json')
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists():
        raise FileExistsError('refuse to replace a reserve snapshot')
    prior = json.loads(args.prior.read_text())
    block_rows = json.loads(args.blocks.read_text())['blocks']
    blocks = {}
    for row in block_rows:
        owner = int(row['owner'],0)
        if owner in blocks:
            raise ValueError('duplicate blocked owner')
        if not row['reason'] or not (ROOT/row['evidence']).is_file():
            raise ValueError('block lacks a reason or evidence file')
        blocks[owner] = row
    owners = {int(row['owner'],0) for row in prior['candidates']}
    result = measure(sorted(owners-set(blocks)),ROOT/'extract/analysis/coverage.json',282527)
    result['excluded_candidates'] = [blocks[owner] for owner in sorted(owners & set(blocks))]
    result['references'] += [reference(args.prior),reference(args.blocks)]
    result['references'] += [reference(ROOT/blocks[owner]['evidence']) for owner in sorted(owners & set(blocks))]
    # Already accepted dependencies no longer consume the implementation queue.
    result['already_accepted_owners'] = [row['owner'] for row in result['candidates'] if not row['marginal_bytes']]
    result['candidates'] = [row for row in result['candidates'] if row['marginal_bytes']]
    args.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f"Gap {result['remaining_verified_bytes']}; {len(result['candidates'])} eligible advisory owners; "
          f"potential {result['potential_unique_bytes']} bytes; {len(result['excluded_candidates'])} recorded blocks")
    print('Potential bytes are not qualified yield or coverage credit')


if __name__ == '__main__':
    main()
