"""Report full-body candidates from isolated captures without granting credit."""
import argparse
import csv
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, corpus_pcs, measure
from campaign_io import discover, write_watch


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('inputs', nargs='+', help='case directories or parent directories')
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--merge', type=Path)
    a = ap.parse_args()
    directories = discover(a.inputs)
    spans = body_spans()
    credited = {int(row['entry'], 16) for row in csv.DictReader(
        (ROOT / 'docs/decomp_status.csv').open()) if row['status'].startswith('ported')}
    pcs = corpus_pcs(directories)
    entries = {entry: measure(entry, spans[entry], values[0])[1]
               for entry, values in pcs.items() if entry in spans and entry not in credited
               and not measure(entry, spans[entry], values[0])[2]}
    write_watch(a.out, entries, 'Uncredited whole-body candidates; strict replay still required.')
    report = dict(entries={hex(entry): size for entry, size in sorted(entries.items())},
                  body_bytes=sum(entries.values()), directories=[str(d) for d in directories])
    (ROOT / 'extract/analysis' / (a.out.stem + '_candidates.json')).write_text(
        json.dumps(report, indent=1) + '\n')
    print(f'{len(directories)} corpora; {len(entries)} full-body candidates; '
          f'{sum(entries.values())} raw bytes (no credit)')
    if a.merge and entries:
        from merge_batches import merge
        selected = [d for d in directories if any(
            (d / f'f_{entry:08x}.cases').exists() for entry in entries)]
        merge(selected, a.merge, a.out)
    elif a.merge:
        print('No candidates; no merged corpus written.')


if __name__ == '__main__':
    main()
