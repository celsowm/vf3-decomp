"""Find unported helper entries executed inside complete parent captures."""
import argparse
import csv
import json
import sys
from pathlib import Path
from campaign_io import write_watch
from select_next import ROOT, union

sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, corpus_pcs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('corpora', nargs='+', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    credited = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if row['status'].startswith('ported')}
    spans = body_spans()
    pcs = corpus_pcs(args.corpora)
    parents = {entry: {pc | 0x80000000 for pc in values[0]} for entry, values in pcs.items()}
    candidates = {entry: [hex(parent) for parent, executed in parents.items() if entry in executed]
                  for entry in spans if entry not in credited}
    candidates = {entry: sources for entry, sources in candidates.items() if sources}
    baseline = list(map(tuple, json.loads((ROOT / 'extract/analysis/coverage.json').read_text())['ported_spans']))
    potential = union(baseline + [s for entry in candidates for s in spans[entry]]) - union(baseline)
    write_watch(args.out, candidates, 'Executed helper entries; nested paired capture and strict proof required.')
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(dict(advisory=True, potential_unique_bytes=potential,
        entries={hex(entry): sources for entry, sources in candidates.items()}), indent=1) + '\n')
    print(f'{len(candidates)} unported executed entries; potential union +{potential} B')


if __name__ == '__main__':
    main()
