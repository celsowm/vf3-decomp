#!/usr/bin/env python3
"""Credit sixth-campaign bodies only after independent strict invocation replay."""
import csv
import hashlib
import io
import json
from pathlib import Path

from select_next import union

ROOT = Path(__file__).resolve().parents[2]
AN = ROOT / 'extract/analysis'
WORKERS = {0x8c074b0e, 0x8c0750be}
CAMPAIGNS = (
    ('sixth_dev_cases', 'sixth_dev_replay.json',
     'fifth_leaf_holdout_v6_cases', 'sixth_fifth_leaf_holdout_v6_cases_replay.json',
     'fifth_leaf_fresh_v6_cases', 'sixth_fifth_leaf_fresh_v6_cases_replay.json'),
    ('sixth_loader_dev_cases', 'sixth_loader_dev_replay.json',
     'sixth_loader_holdout_cases', 'sixth_loader_holdout_replay.json',
     'sixth_loader_fresh_cases', 'sixth_loader_fresh_replay.json'),
)


def corpus(directory):
    path = AN / directory
    batch = json.loads((path / 'batch_manifest.json').read_text())
    manifest = json.loads((path / 'capsule_manifest.json').read_text())
    assert all(run['returncode'] == 0 and run.get('frame_complete', True) for run in batch['runs'])
    sources = {str(Path(run['capsule']).resolve()): run for run in batch['runs']}
    return path, batch, manifest, sources


def used_runs(records, sources):
    return {sources[str(Path(source['source']).resolve())]['name']
            for record in records for source in record['sources']}


def no_incomplete(entry, manifest):
    return not any((int(item['entry'], 16) | 0x80000000) == int(entry, 16)
                   for run in manifest['runs'] for item in run.get('incomplete', []))


def artifacts_for(path):
    digest = hashlib.sha256()
    files = sorted(q for q in path.parent.glob(path.stem + '*') if q.is_file())
    for item in files:
        with item.open('rb') as handle:
            part = hashlib.file_digest(handle, 'sha256').hexdigest()
        digest.update((item.relative_to(ROOT).as_posix() + '\\0' + part + '\\n').encode())
    return {'count': len(files), 'sha256': digest.hexdigest()}


def main():
    frozen = ROOT / 'tools/oracle/sixth_batch.json'
    coverage = json.loads(frozen.read_text()) if frozen.is_file() else json.loads((AN / 'coverage.json').read_text())
    if 'ported_unique_bytes' not in coverage:
        coverage['ported_unique_bytes'] = coverage['baseline_unique_bytes']
        coverage['bytes_total'] = coverage['frozen_body_bytes']
        coverage['ported_spans'] = coverage['baseline_spans']
    assert coverage['ported_unique_bytes'] == 99760 and coverage['bytes_total'] == 434656
    baseline = list(map(tuple, coverage['ported_spans']))
    assert union(baseline) == 99760
    sizes = {int(row['entry'], 16): int(row['size']) for row in
             csv.DictReader((AN / 'funcs_1ST_READ.unsc.bin.csv').open())}
    ranges = {}
    for row in csv.DictReader((AN / 'function_body_ranges.csv').open()):
        ranges.setdefault(int(row['entry'], 16), []).append(
            (int(row['start'], 16), int(row['end'], 16)))
    ledger_path = ROOT / 'docs/decomp_status.csv'
    lines = ledger_path.read_text().splitlines()
    existing = {int(row['entry'], 16) for row in csv.DictReader(io.StringIO('\n'.join(lines)))
                if row['status'].startswith('ported')}
    bindings_path = ROOT / 'tools/golden_bindings.json'
    bindings = json.loads(bindings_path.read_text())
    selected, excluded, additions, runs = {}, {}, [], set()

    for dev_dir, dev_name, hold_dir, hold_name, fresh_dir, fresh_name in CAMPAIGNS:
        dev_path, dev_batch, dev, dev_sources = corpus(dev_dir)
        hold_path, hold_batch, hold, hold_sources = corpus(hold_dir)
        fresh_path, fresh_batch, fresh, fresh_sources = corpus(fresh_dir)
        reports = {name: json.loads((AN / name).read_text()) for name in
                   (dev_name, hold_name, fresh_name)}
        for batch in (dev_batch, hold_batch, fresh_batch):
            runs.update(str(Path(run['capsule']).resolve()) for run in batch['runs'])
        candidates = WORKERS if dev_dir == 'sixth_dev_cases' else {
            int(line.split()[1], 16) for watch in
            ('vf3_sixth_loader_expanded.txt', 'vf3_sixth_loader_extra.txt')
            for line in (ROOT / 'tools/watch' / watch).read_text().splitlines()
            if line.startswith('pc ')}
        for pc in sorted(candidates):
            entry = f'0x{pc:08x}'
            proof = reports[dev_name].get(entry)
            records = dev['entries'].get(entry, [])
            scenarios = {(dev_sources[str(Path(source['source']).resolve())]['state'],
                          dev_sources[str(Path(source['source']).resolve())]['play'])
                         for record in records for source in record['sources']}
            if not proof or not proof['pass'] or len(records) < 64 or len(scenarios) < 2 or not no_incomplete(entry, dev):
                excluded[entry] = 'Development replay, case, scenario, or completion gate failed'
                continue
            h, f = reports[hold_name].get(entry), reports[fresh_name].get(entry)
            hr, fr = hold['entries'].get(entry, []), fresh['entries'].get(entry, [])
            if not h or not f or not h['pass'] or not f['pass'] or not hr or not fr or \
                    not no_incomplete(entry, hold) or not no_incomplete(entry, fresh):
                excluded[entry] = 'Independent held-out or fresh replay gate failed'
                continue
            hused, fused = used_runs(hr, hold_sources), used_runs(fr, fresh_sources)
            hscenarios = {(r['state'], r['play']) for r in hold_batch['runs'] if r['name'] in hused}
            fscenarios = {(r['state'], r['play']) for r in fresh_batch['runs'] if r['name'] in fused}
            if scenarios & hscenarios or scenarios & fscenarios or hscenarios & fscenarios:
                excluded[entry] = 'Validation scenario overlaps development or other validation'
                continue
            assert pc in sizes and pc in ranges, entry
            if pc in existing:
                assert any(line.lower().startswith(entry + ',ported-invocation,') for line in lines)
            port = ('src/fight/fifth_adapters.c' if pc in WORKERS else
                    'src/fight/sixth_loader_adapters.c' if pc in (0x8c0b38d0, 0x8c0b9700,
                                                                 0x8c0b588e, 0x8c0bbde2) else
                    'src/fight/next_adapters.c')
            case = dev_path / f'f_{pc:08x}.cases'
            key = 'sixth:' + entry
            bindings[key] = {
                'test': 'build/vf3matrixfamily.exe ' + entry,
                'golden': case.relative_to(ROOT).as_posix(), 'strict': True,
                'source': 'Complete invocation registers/banked/XF/FPUL/GBR/return-PC/touched-RAM/device tape; >=64 distinct development inputs in two scenarios; independent holdout and fresh replay',
                'port': port,
            }
            selected[entry] = {
                'new_credit': True, 'size': sizes[pc], 'binding': key,
                'proofs': {dev_name: proof, hold_name: h, fresh_name: f},
                'scenario_count': len(scenarios),
                'validation_groups': {
                    'heldout': {'report': hold_name, 'directory': hold_dir, 'runs': sorted(hused)},
                    'fresh': {'report': fresh_name, 'directory': fresh_dir, 'runs': sorted(fused)}},
                'artifacts': artifacts_for(case),
            }
            row = io.StringIO()
            csv.writer(row, lineterminator='\n').writerow([
                entry, 'ported-invocation', port, sizes[pc],
                'static original-image C control flow; complete invocation replay',
                f'{proof["stdout"]}; independent held-out and fresh strict replay; docs/re/sixth_coverage_batch.md'])
            additions.append(row.getvalue().rstrip('\n'))

    gain = union(baseline + [span for entry in selected for span in ranges[int(entry, 16)]]) - union(baseline)
    assert gain > 0
    for line in additions:
        entry = line.split(',', 1)[0]
        matches = [index for index, old in enumerate(lines) if old.lower().startswith(entry + ',')]
        assert len(matches) <= 1
        if matches:
            lines[matches[0]] = line
        else:
            lines.append(line)
    ledger_path.write_text('\n'.join(lines) + '\n')
    bindings_path.write_text(json.dumps(bindings, indent=1) + '\n')
    manifest = {
        'baseline_unique_bytes': 99760, 'baseline_spans': coverage['ported_spans'],
        'frozen_body_bytes': 434656, 'minimum_gain': 1, 'target_gain': 25000,
        'target_met': gain >= 25000, 'measured_gain': gain,
        'minimum_cases': 64, 'minimum_scenarios': 2,
        'entries': selected, 'excluded': excluded,
        'reports': sorted({name for group in CAMPAIGNS for name in (group[1], group[3], group[5])}),
        'capture_runs': len(runs), 'device_tape_format': 'VF3CAP6',
    }
    (ROOT / 'tools/oracle/sixth_batch.json').write_text(json.dumps(manifest, indent=1) + '\n')
    print(f'Sixth batch: {len(selected)} verified bodies, +{gain} unique C bytes; target_met={gain >= 25000}')
    for entry, reason in excluded.items():
        print(entry, reason)


if __name__ == '__main__':
    main()
