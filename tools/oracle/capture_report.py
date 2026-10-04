"""Rank body gaps and show distinct cases/scenarios per converted capture corpus.

Counts stay per corpus: use merge_batches.py to deduplicate inputs across runs.
Reports are advisory and never grant C coverage credit.
"""
import argparse
import csv
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, corpus_pcs, measure
from campaign_io import discover, read_watch, write_watch


def report(directories, include_credited=False, entries=None):
    spans = body_spans()
    with (ROOT / 'docs/decomp_status.csv').open(newline='') as stream:
        credited = {int(r['entry'], 16) for r in csv.DictReader(stream)
                    if r['status'].startswith('ported')}
    rows = []
    for directory in directories:
        manifest = json.loads((directory / 'capsule_manifest.json').read_text())
        batch = json.loads((directory / 'batch_manifest.json').read_text())
        scenarios = {str(Path(r['capsule']).resolve()): (r.get('state', ''), r.get('play', ''))
                     for r in batch['runs']}
        failed = any(r['returncode'] != 0 or not r.get('frame_complete', False)
                     for r in batch['runs'])
        incomplete = {int(r['entry'], 16) | 0x80000000 for run in manifest['runs']
                      for r in run.get('incomplete', [])}
        quarantined = {int(e, 16) | 0x80000000 for e in manifest.get('nondeterministic_entries', [])}
        pcs = corpus_pcs([directory])
        records_by_entry = {int(key, 16) | 0x80000000: records
                            for key, records in manifest['entries'].items()}
        for entry in sorted(set(records_by_entry) | quarantined | incomplete):
            records = records_by_entry.get(entry, [])
            if (entries is not None and entry not in entries) or (entry in credited and not include_credited):
                continue
            used, unknown = set(), set()
            for record in records:
                for source in record['sources']:
                    path = str(Path(source['source']).resolve())
                    if path in scenarios:
                        used.add(scenarios[path])
                    else:
                        unknown.add(path)
            covered, total, missing = measure(entry, spans.get(entry, []), pcs.get(entry, (set(),))[0])
            reasons = []
            for condition, reason in (
                (failed, 'failed/incomplete capture run'),
                (entry in incomplete, 'incomplete invocation'),
                (entry in quarantined, 'nondeterministic entry'),
                (len(records) < 64, 'fewer than 64 distinct inputs'),
                (len(used) < 2, 'fewer than two scenarios'),
                (bool(unknown), 'unknown source provenance'),
                (entry not in spans, 'missing frozen body'),
                (bool(missing), 'unexecuted body PCs')):
                if condition:
                    reasons.append(reason)
            rows.append(dict(entry=hex(entry), directory=str(directory), distinct_cases=len(records),
                             scenarios=[list(s) for s in sorted(used)], unknown_sources=sorted(unknown),
                             covered_bytes=covered, body_bytes=total,
                             missing_pcs=[hex(pc) for pc in missing], reasons=reasons))
    return sorted(rows, key=lambda r: (bool(r['body_bytes'] == 0), len(r['missing_pcs']),
                                      -r['body_bytes'], r['entry'], r['directory']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('inputs', nargs='+', help='corpus directories, parents, or capsule manifests')
    parser.add_argument('--watch')
    parser.add_argument('--include-credited', action='store_true')
    parser.add_argument('--limit', type=int, default=40, help='printed rows; JSON retains every row')
    parser.add_argument('--out', type=Path, help='optional complete JSON report')
    parser.add_argument('--ready-watch', type=Path,
                        help='write roots passing capture gates; replay and acceptance still required')
    args = parser.parse_args()
    rows = report(discover(args.inputs), args.include_credited, read_watch(args.watch) if args.watch else None)
    if args.ready_watch:
        write_watch(args.ready_watch, {int(row['entry'], 16) for row in rows if not row['reasons']},
                    'Capture gates passed in at least one corpus; strict replay and acceptance required.')
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(dict(advisory=True, entries=rows), indent=1) + '\n')
    for row in rows[:max(0, args.limit)]:
        print(f"{row['entry']} {row['covered_bytes']}/{row['body_bytes']} B "
              f"{row['distinct_cases']} cases {len(row['scenarios'])} scenarios "
              f"missing={','.join(row['missing_pcs'][:8]) or '-'} {Path(row['directory']).name}")
        if row['reasons']:
            print('  ' + '; '.join(row['reasons']))
    print(f'{len(rows)} entry/corpus rows; advisory only; strict replay and independent acceptance required')


if __name__ == '__main__':
    main()
