"""Audit sound-RAM checkpoint leaves, rejected controls and scheduler rejection."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
from capsules import records
from aica_ram_probe_plan import ADDRESSES, ENTRY, ROOT


def audit_leaf(directory, mode):
    batch = json.loads((Path(directory)/'batch_manifest.json').read_text())
    enabled = mode != 'disabled'
    allowed = mode in ('development', 'acceptance')
    address = ADDRESSES[mode]
    scenarios = set()
    count = 0
    for run in batch['runs']:
        assert run['returncode'] == 0 and run['frame_complete'], 'incomplete original run'
        assert run['rollback_aica_ram'] == enabled, 'checkpoint provenance mismatch'
        scenarios.add((run['state'], run['play']))
        capsule = Path(run['capsule'])
        summary = json.loads(Path(str(capsule)+'.summary.json').read_text())
        samples = list(records(capsule))
        assert len(samples) >= 64
        assert summary['started'] == summary['completed'] == summary['armed'] == len(samples)
        assert not summary['incomplete'] and not summary['unaccounted']
        assert summary['aica_timeslice_aborts'] <= sum(bool(s['flags'] & 4) for s in samples)
        assert summary['aica_page_restores'] == (len(samples) if allowed else 0)
        assert summary['non_ram'] == ([] if allowed else [dict(
            entry=hex(ENTRY), address=hex(address), count=len(samples))])
        values = set()
        valid = 0
        for sample in samples:
            before = struct.unpack(f'<{sample["nstate"]}I', sample['before'])
            assert sample['entry'] | 0x80000000 == ENTRY
            assert (before[4]+0xa05f8000) & 0xffffffff == address
            assert all(initial == final for _, initial, final in sample['pages'])
            values.add(before[5])
            if allowed:
                assert sample['device'] == [(address & 0x1fffffff, 4, before[5], 1)]
                if sample['flags']:
                    assert sample['flags'] == 4, 'unexpected leaf rejection'
                    continue
                valid += 1
                after = struct.unpack(f'<{sample["nstate"]}I', sample['after'])
                expected = list(before)
                expected[0], expected[3], expected[4] = 1, 0xa05f8000, address
                assert after == tuple(expected)
                assert sample['exitpc'] == before[16]
            else:
                assert sample['flags'] & 2 and not sample['device']
        assert len(values) >= 64
        if allowed:
            assert valid >= 64, 'too few valid leaves after scheduler rejection'
        count += valid if allowed else len(samples)
    assert len(scenarios) >= 2
    return dict(mode=mode, calls=count, scenarios=len(scenarios), passed=True)


def audit_timeslice(directory):
    batch = json.loads((Path(directory)/'batch_manifest.json').read_text())
    count = 0
    for run in batch['runs']:
        assert run['returncode'] == 0 and run['frame_complete']
        assert run['rollback_aica_ram']
        capsule = Path(run['capsule'])
        summary = json.loads(Path(str(capsule)+'.summary.json').read_text())
        assert summary['started'] == summary['completed'] == summary['armed']
        assert not summary['incomplete'] and not summary['unaccounted']
        assert not summary['non_ram'], 'unexpected forbidden device access'
        aborted = sum(bool(sample['flags'] & 4) for sample in records(capsule))
        assert aborted == summary['aica_timeslice_aborts'] and aborted >= 64
        count += aborted
    return dict(mode='scheduler crossing', rejected_calls=count, passed=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for mode in ADDRESSES:
        parser.add_argument('--'+mode, type=Path, required=True)
    parser.add_argument('--timeslice-control', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    results = [audit_leaf(getattr(args,mode),mode) for mode in ADDRESSES]
    results.append(audit_timeslice(args.timeslice_control))
    dev = json.loads((args.development/'batch_manifest.json').read_text())
    accept = json.loads((args.acceptance/'batch_manifest.json').read_text())
    assert {r['state'] for r in dev['runs']}.isdisjoint(r['state'] for r in accept['runs'])
    hashes = {}
    for name in ['tools/oracle/vf3oracle.cpp','tools/emu/flycast-build/flycast.exe',
                 'tools/emu/flycast/core/hw/sh4/interpr/sh4_interpreter.cpp',
                 'tools/emu/flycast/core/hw/aica/aica.cpp']:
        with (ROOT/name).open('rb') as stream:
            hashes[name] = hashlib.file_digest(stream,'sha256').hexdigest()
    assert (ROOT/'tools/oracle/vf3oracle.cpp').read_bytes() == (
        ROOT/'tools/emu/flycast/core/vf3oracle.cpp').read_bytes()
    for mode in ADDRESSES:
        if mode == 'disabled':
            continue
        batch = json.loads((getattr(args,mode)/'batch_manifest.json').read_text())
        for run in batch['runs']:
            assert run['emulator_sha256'] == hashes['tools/emu/flycast-build/flycast.exe']
            assert run['oracle_source_sha256'] == hashes['tools/oracle/vf3oracle.cpp']
    batch = json.loads((args.timeslice_control/'batch_manifest.json').read_text())
    for run in batch['runs']:
        assert run['emulator_sha256'] == hashes['tools/emu/flycast-build/flycast.exe']
        assert run['oracle_source_sha256'] == hashes['tools/oracle/vf3oracle.cpp']
    args.out.write_text(json.dumps(dict(passed=True, coverage_credit=0,
        checks=results, implementation_hashes=hashes),indent=1)+'\n')
    print('AICA RAM checkpoint, independent leaves and rejection controls PASS; no coverage credit')
