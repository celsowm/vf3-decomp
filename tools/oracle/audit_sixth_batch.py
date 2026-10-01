#!/usr/bin/env python3
"""Audit sixth-campaign coverage plus immutable development fixture hashes."""
import argparse
import hashlib
import json
from pathlib import Path

from audit_next_batch import main as audit_independent

ROOT = Path(__file__).resolve().parents[2]


def audit(hashes):
    audit_independent(hashes, 'tools/oracle/sixth_batch.json')
    manifest = json.loads((ROOT / 'tools/oracle/sixth_batch.json').read_text())
    bindings = json.loads((ROOT / 'tools/golden_bindings.json').read_text())
    directories = {(ROOT / bindings[entry['binding']]['golden']).parent
                   for entry in manifest['entries'].values()}
    checked = 0
    for directory in directories:
        batch = json.loads((directory / 'batch_manifest.json').read_text())
        for run in batch['runs']:
            patch = run.get('ram_patch')
            if not patch:
                continue
            path = Path(patch)
            assert path.is_file(), path
            assert hashlib.sha256(path.read_bytes()).hexdigest() == run['ram_patch_sha256'], path
            for line in path.read_text().splitlines():
                if not line or line.startswith('#'):
                    continue
                fields = [int(value, 0) for value in line.split()]
                assert len(fields) in (2, 3)
                address, value = fields[-2:]
                assert 0x0c000000 <= address <= 0x0cfffffc and address % 4 == 0
                assert value in (0, 0xffffffff)
            checked += 1
    for directory in ('fifth_leaf_holdout_v6_cases', 'fifth_leaf_fresh_v6_cases',
                      'sixth_loader_holdout_cases', 'sixth_loader_fresh_cases'):
        batch = json.loads((ROOT / 'extract/analysis' / directory / 'batch_manifest.json').read_text())
        assert all(not run.get('ram_patch') for run in batch['runs'])
    print(f'sixth_batch: {checked} immutable development RAM fixtures; untouched loader acceptance - PASS')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes', action='store_true')
    args = parser.parse_args()
    audit(args.hashes)
