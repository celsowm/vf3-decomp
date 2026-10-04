#!/usr/bin/env python3
"""Credit the initializer family only after strict replay and full body proof."""
import csv
import hashlib
import io
import json
from pathlib import Path

from select_next import ROOT, union


def main():
    an = ROOT / 'extract/analysis'
    baseline = json.loads((ROOT / 'tools/oracle/tenpp_coverage_baseline.json').read_text())
    for key in ('inventory', 'body_ranges', 'image'):
        assert hashlib.sha256((ROOT / baseline[key]).read_bytes()).hexdigest() == baseline[key + '_sha256']
    reports = {name: json.loads((an / name).read_text()) for name in (
        'tenpp_asset_dev_more_replay.json', 'tenpp_asset_final2_replay.json',
        'tenpp_asset_held_replay.json')}
    dev = an / 'tenpp_asset_dev_more_cases'
    manifest = json.loads((dev / 'capsule_manifest.json').read_text())
    batch = json.loads((dev / 'batch_manifest.json').read_text())
    assert all(r['returncode'] == 0 and r['frame_complete'] for r in batch['runs'])
    assert len({(r['state'], r['play']) for r in batch['runs']}) >= 2
    assert not manifest.get('nondeterministic_entries')
    from sys import path
    path.insert(0, str(ROOT / 'tools'))
    from body_cover import body_spans, corpus_pcs, measure
    ranges = body_spans()
    pcs = corpus_pcs([dev])
    sizes = {int(r['entry'], 16): int(r['size']) for r in csv.DictReader(
        (an / 'funcs_1ST_READ.unsc.bin.csv').open())}
    ledger_path = ROOT / 'docs/decomp_status.csv'
    ledger_text = ledger_path.read_text()
    old = {int(r['entry'], 16) for r in csv.DictReader(io.StringIO(ledger_text))
           if r['status'].startswith('ported')}
    bindings_path = ROOT / 'tools/golden_bindings.json'
    bindings = json.loads(bindings_path.read_text())
    entries = {}
    additions = []
    for entry in sorted(reports['tenpp_asset_dev_more_replay.json']):
        e = int(entry, 16)
        assert e not in old, f'already credited: {entry}'
        assert len(manifest['entries'][entry]) >= 64
        assert all(entry in report and report[entry]['pass'] for report in reports.values())
        assert measure(e, ranges[e], pcs[e][0])[:2] == (sizes[e], sizes[e])
        assert all(entry not in {hex(int(r['entry'], 16) | 0x80000000)
                                for r in run.get('incomplete', [])}
                   for run in manifest['runs'])
        case = dev / f'f_{e:08x}.cases'
        artifacts = sorted(p for p in dev.glob(case.stem + '*') if p.is_file())
        archive = hashlib.sha256()
        for artifact in artifacts:
            digest = hashlib.sha256(artifact.read_bytes()).hexdigest()
            archive.update((artifact.relative_to(ROOT).as_posix() + '\\0' + digest + '\\n').encode())
        key = 'tenpp-assets:' + entry
        port = 'src/fight/tenpp_asset_adapters.c'
        bindings[key] = dict(test='build/vf3matrixfamily.exe ' + entry,
            golden=case.relative_to(ROOT).as_posix(), strict=True, port=port,
            source='100% frozen body PCs; >=64 distinct complete development cases; independent relocated descriptor acceptance')
        entries[entry] = dict(new_credit=True, size=sizes[e], binding=key,
            proofs={name: report[entry] for name, report in reports.items()},
            artifacts=dict(count=len(artifacts), sha256=archive.hexdigest()),
            covered_bytes=sizes[e])
        line = io.StringIO()
        csv.writer(line, lineterminator='\n').writerow([entry, 'ported-invocation', port,
            sizes[e], 'static original-image C; complete initializer and helper behavior',
            reports['tenpp_asset_dev_more_replay.json'][entry]['stdout'] +
            '; 100% body PCs; independent descriptor acceptance; docs/re/tenpp_assets.md'])
        additions.append(line.getvalue())
    spans = list(map(tuple, baseline['baseline_spans']))
    gain = union(spans + [s for entry in entries for s in ranges[int(entry, 16)]]) - union(spans)
    proof = dict(baseline_unique_bytes=baseline['baseline_bytes'], baseline_spans=spans,
        frozen_body_bytes=baseline['total_body_bytes'], minimum_gain=1,
        target_gain=baseline['target_gain'], measured_gain=gain,
        target_met=gain >= baseline['target_gain'], minimum_cases=64, minimum_scenarios=2,
        entries=entries, excluded={})
    ledger_path.write_text(ledger_text.rstrip('\n') + '\n' + ''.join(additions))
    bindings_path.write_text(json.dumps(bindings, indent=1) + '\n')
    (ROOT / 'tools/oracle/tenpp_assets_milestone.json').write_text(json.dumps(proof, indent=1) + '\n')
    print(f'{len(entries)} new bodies; +{gain} unique C bytes (+{gain / baseline["total_body_bytes"] * 100:.3f} pp)')


if __name__ == '__main__':
    main()
