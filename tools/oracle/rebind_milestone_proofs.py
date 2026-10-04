"""Refresh a milestone's proof records from strict replays of the same corpora."""
import argparse
import hashlib
import json
from pathlib import Path
import re

from select_next import ROOT


STRICT = re.compile(r'matrix_family: (\d+)/(\d+) cases match \(0 skipped\) - PASS')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('reports', nargs='+', type=Path)
    args = parser.parse_args()
    manifest_path = (ROOT / args.manifest).resolve()
    manifest = json.loads(manifest_path.read_text())
    updates = []
    for report_path in args.reports:
        path = (ROOT / report_path).resolve()
        report = json.loads(path.read_text())
        name = path.name
        for entry, evidence in manifest['entries'].items():
            if entry not in report:
                continue
            previous = evidence['proofs'].get(name)
            if previous is None:
                raise ValueError(f'{manifest_path.name}: no existing proof slot named {name}')
            proof = report[entry]
            match = STRICT.fullmatch(proof.get('stdout', ''))
            if not proof.get('pass') or not match or match[1] != match[2] or int(match[1]) == 0:
                raise ValueError(f'{name} {entry}: report is not a complete strict replay')
            if proof.get('cases', '').replace('\\', '/') != previous.get('cases', '').replace('\\', '/'):
                raise ValueError(f'{name} {entry}: replay corpus differs from recorded proof')
            executable = (ROOT / proof['executable']).resolve()
            with executable.open('rb') as stream:
                digest = hashlib.file_digest(stream, 'sha256').hexdigest()
            if digest != proof.get('executable_sha256'):
                raise ValueError(f'{name} {entry}: executable hash does not match the report')
            updates.append((evidence['proofs'], name, proof))
    if not updates:
        raise ValueError('no existing milestone proofs matched the supplied reports')
    for proofs, name, proof in updates:
        proofs[name] = proof
    manifest_path.write_text(json.dumps(manifest, indent=1) + '\n')
    print(f'{manifest_path.name}: refreshed {len(updates)} strict proof records')


if __name__ == '__main__':
    main()
