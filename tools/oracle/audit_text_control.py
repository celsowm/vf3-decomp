"""Audit original PVR checkpoint specimens and fail-closed negative controls."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
from capsules import records
from text_control_probe_plan import ENTRY, ROOT


def audit(directory, enabled, offset):
    directory = Path(directory)
    batch = json.loads((directory / 'batch_manifest.json').read_text())
    manifest = json.loads((directory / 'capsule_manifest.json').read_text())
    assert not manifest['nondeterministic_entries'], 'nondeterministic specimens'
    assert len(batch['runs']) >= 2, 'two original scenarios required'
    count = 0
    scenarios = set()
    for run in batch['runs']:
        assert run['returncode'] == 0 and run['frame_complete'], 'incomplete original run'
        assert run['rollback_text_control'] == enabled, 'checkpoint provenance mismatch'
        scenarios.add((run['state'], run['play']))
        capsule = Path(run['capsule'])
        summary = json.loads(Path(str(capsule) + '.summary.json').read_text())
        samples = list(records(capsule))
        assert len(samples) >= 64, 'too few original calls'
        assert summary['started'] == summary['completed'] == summary['armed'] == len(samples)
        assert not summary['incomplete'] and not summary['unaccounted']
        allowed = enabled and offset == 0xe4
        assert summary['text_control_restores'] == (len(samples) if allowed else 0)
        if allowed:
            assert not summary['non_ram'], 'unexpected rejected device access'
        else:
            assert summary['non_ram'] == [dict(entry=hex(ENTRY),
                address=hex(0xa05f8000 + offset), count=len(samples))]
        values = set()
        for sample in samples:
            assert sample['entry'] | 0x80000000 == ENTRY
            before = list(struct.unpack(f'<{sample["nstate"]}I', sample['before']))
            assert before[4] == offset
            values.add(before[5])
            # Loading the original PVR base literal captures its executable
            # RAM page. The helper must leave every captured byte unchanged.
            assert all(initial == final for _, initial, final in sample['pages'])
            if allowed:
                assert sample['flags'] == 0
                assert sample['device'] == [(0x005f8000 + offset, 4, before[5], 1)]
                assert sample['ops'] == [((ENTRY & 0x1fffffff) + delta, op)
                    for delta, op in ((0, 0xd344), (2, 0x343c), (4, 0x2452),
                                      (6, 0x000b), (8, 0xe001))]
                after = list(struct.unpack(f'<{sample["nstate"]}I', sample['after']))
                expected = list(before)
                expected[0], expected[3], expected[4] = 1, 0xa05f8000, 0xa05f8000 + offset
                assert after == expected, 'original leaf architectural result differs'
                assert sample['exitpc'] == before[16]
            else:
                assert sample['flags'] & 2, 'negative control did not reject device access'
                assert not sample['device'], 'rejected control issued a device access'
            count += 1
        assert len(values) >= 64, 'too few distinct input values'
    assert len(scenarios) >= 2
    return dict(directory=str(directory), enabled=enabled, offset=hex(offset),
                original_calls=count, scenarios=len(scenarios), passed=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--development', type=Path, required=True)
    parser.add_argument('--acceptance', type=Path, required=True)
    parser.add_argument('--default-control', type=Path, required=True)
    parser.add_argument('--adjacent-control', type=Path, required=True)
    parser.add_argument('--alias-control', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    rows = [audit(args.development, True, 0xe4), audit(args.acceptance, True, 0xe4),
            audit(args.default_control, False, 0xe4), audit(args.adjacent_control, True, 0xe8),
            audit(args.alias_control, True, 0x400000e4)]
    dev = json.loads((args.development / 'batch_manifest.json').read_text())
    accept = json.loads((args.acceptance / 'batch_manifest.json').read_text())
    assert {r['state'] for r in dev['runs']}.isdisjoint(r['state'] for r in accept['runs'])
    paths = [ROOT / 'tools/oracle/vf3oracle.cpp',
             ROOT / 'tools/emu/flycast-build/flycast.exe',
             ROOT / 'tools/emu/flycast/core/hw/pvr/pvr_regs.cpp',
             ROOT / 'tools/emu/flycast/core/hw/pvr/Renderer_if.cpp']
    assert paths[0].read_bytes() == (ROOT / 'tools/emu/flycast/core/vf3oracle.cpp').read_bytes()
    hashes = {}
    for path in paths:
        with path.open('rb') as stream:
            hashes[path.relative_to(ROOT).as_posix()] = hashlib.file_digest(stream, 'sha256').hexdigest()
    for row in rows:
        if row['enabled']:
            batch = json.loads((Path(row['directory']) / 'batch_manifest.json').read_text())
            for run in batch['runs']:
                assert run['emulator_sha256'] == hashes['tools/emu/flycast-build/flycast.exe']
                assert run['oracle_source_sha256'] == hashes['tools/oracle/vf3oracle.cpp']
    args.out.write_text(json.dumps(dict(passed=True, coverage_credit=0,
        checks=rows, implementation_hashes=hashes), indent=1) + '\n')
    print(f'{sum(r["original_calls"] for r in rows)} original calls; checkpoint and negative controls PASS; no coverage credit')
