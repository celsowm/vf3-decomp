"""Credit supported whole bodies with independent, strict invocation evidence."""
import argparse
import csv
import hashlib
import io
import json
import re
import sys
from pathlib import Path
from select_next import ROOT, union

sys.path.insert(0, str(ROOT / 'tools'))
from body_cover import body_spans, corpus_pcs, measure


def corpus(path):
    manifest = json.loads((path / 'capsule_manifest.json').read_text())
    batch = json.loads((path / 'batch_manifest.json').read_text())
    assert all(r['returncode'] == 0 and r['frame_complete'] for r in batch['runs'])
    assert not manifest.get('nondeterministic_entries')
    sources = {str(Path(r['capsule']).resolve()): (r['state'], r['play']) for r in batch['runs']}
    return manifest, sources


def artifacts(case):
    archive = hashlib.sha256()
    files = sorted(p for p in case.parent.glob(case.stem + '*') if p.is_file())
    for path in files:
        with path.open('rb') as handle:
            digest = hashlib.file_digest(handle, 'sha256').hexdigest()
        archive.update((path.relative_to(ROOT).as_posix() + '\\0' + digest + '\\n').encode())
    return dict(count=len(files), sha256=archive.hexdigest())


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--development', type=Path, required=True)
    ap.add_argument('--development-report', type=Path, required=True)
    ap.add_argument('--acceptance', type=Path, required=True)
    ap.add_argument('--acceptance-report', type=Path, required=True)
    ap.add_argument('--manifest', type=Path, required=True)
    ap.add_argument('--port', required=True)
    ap.add_argument('--label', required=True)
    ap.add_argument('--note', required=True)
    a = ap.parse_args()
    a.development = a.development.resolve()
    a.acceptance = a.acceptance.resolve()
    assert not a.manifest.exists(), 'milestone already recorded'
    frozen = json.loads((ROOT / 'tools/oracle/tenpp_coverage_baseline.json').read_text())
    for key in ('inventory', 'body_ranges', 'image'):
        assert hashlib.sha256((ROOT / frozen[key]).read_bytes()).hexdigest() == frozen[key + '_sha256']
    development, scenarios = corpus(a.development)
    acceptance, _ = corpus(a.acceptance)
    reports = {p.relative_to(ROOT / 'extract/analysis').as_posix(): json.loads(p.read_text())
               for p in (a.development_report.resolve(), a.acceptance_report.resolve())}
    ranges = body_spans()
    pcs = corpus_pcs([a.development])
    sizes = {int(r['entry'], 16): int(r['size']) for r in csv.DictReader(
        (ROOT / frozen['inventory']).open())}
    ledger_path = ROOT / 'docs/decomp_status.csv'
    ledger_text = ledger_path.read_text()
    old = {int(r['entry'], 16) for r in csv.DictReader(io.StringIO(ledger_text))
           if r['status'].startswith('ported')}
    # Keep the frozen off-inventory leaves: they also belong to the baseline
    # C address union, even though the Ghidra body table has no entry for them.
    before_spans = list(map(tuple, frozen['baseline_spans'])) + [
        span for e in old if e in ranges for span in ranges[e]]
    before = union(before_spans)
    bindings_path = ROOT / 'tools/golden_bindings.json'
    bindings = json.loads(bindings_path.read_text())
    entries, excluded, additions = {}, {}, []
    for entry, records in sorted(development['entries'].items()):
        e = int(entry, 16)
        if e in old:
            continue
        try:
            assert e in sizes and e in pcs, 'no frozen body'
            assert len(records) >= 64, 'fewer than 64 distinct development cases'
            used = {scenarios[str(Path(source['source']).resolve())]
                    for record in records for source in record['sources']}
            assert len(used) >= 2, 'fewer than two development scenarios'
            assert measure(e, ranges[e], pcs[e][0])[:2] == (sizes[e], sizes[e]), 'incomplete body execution'
            for campaign in (development, acceptance):
                assert entry in campaign['entries'], 'no independent acceptance'
                assert not any(int(r['entry'], 16) | 0x80000000 == e
                               for run in campaign['runs'] for r in run.get('incomplete', [])), 'incomplete invocation'
            for report in reports.values():
                proof = report.get(entry)
                assert proof and proof['pass'] and re.fullmatch(
                    r'matrix_family: (\d+)/(\d+) cases match \(0 skipped\) - PASS', proof['stdout']), 'strict replay failed'
        except AssertionError as error:
            excluded[entry] = str(error)
            continue
        case = a.development / f'f_{e:08x}.cases'
        key = a.label + ':' + entry
        bindings[key] = dict(test='build/vf3matrixfamily.exe ' + entry,
            golden=case.relative_to(ROOT).as_posix(), strict=True, port=a.port,
            source='100% frozen body; >=64 distinct development inputs in two scenarios; independent acceptance; ' + a.note)
        entries[entry] = dict(new_credit=True, size=sizes[e], binding=key,
            proofs={name: report[entry] for name, report in reports.items()},
            artifacts=artifacts(case), covered_bytes=sizes[e])
        line = io.StringIO()
        csv.writer(line, lineterminator='\n').writerow([entry, 'ported-invocation',
            a.port, sizes[e], 'static original-image C; complete body and helper behavior',
            next(iter(reports.values()))[entry]['stdout'] + '; ' + a.note])
        additions.append(line.getvalue())
    if not entries:
        print(json.dumps(excluded, indent=1))
        raise AssertionError('no candidates passed every gate')
    gain = union(before_spans + [s for entry in entries for s in ranges[int(entry, 16)]]) - before
    remaining = frozen['target_bytes'] - before
    manifest = dict(baseline_unique_bytes=before, baseline_spans=before_spans,
        frozen_body_bytes=frozen['total_body_bytes'], minimum_gain=1,
        target_gain=remaining, measured_gain=gain, target_met=gain >= remaining,
        minimum_cases=64, minimum_scenarios=2, entries=entries, excluded=excluded)
    a.manifest.write_text(json.dumps(manifest, indent=1) + '\n')
    ledger_path.write_text(ledger_text.rstrip('\n') + '\n' + ''.join(additions))
    bindings_path.write_text(json.dumps(bindings, indent=2, sort_keys=True) + '\n')
    print(f'{len(entries)} new functions; +{gain} unique C bytes; total {before + gain}; '
          f'cumulative gain {(before + gain - frozen["baseline_bytes"]) / frozen["total_body_bytes"] * 100:.3f} pp')
    print('Excluded:', excluded)


if __name__ == '__main__':
    main()
