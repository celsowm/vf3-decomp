"""Pin a complete strict replay failure and all campaign files without filtering."""
import argparse
import json
from pathlib import Path
from ram_clipping_batch_audit import digest, reference


def pin(directory, report_path, output):
    assert not output.exists(), 'refuse to replace failed evidence'
    manifest = json.loads((directory / 'capsule_manifest.json').read_text())
    batch = json.loads((directory / 'batch_manifest.json').read_text())
    report = json.loads(report_path.read_text())
    assert set(report) == set(manifest['entries']), 'replay report omits entries'
    assert any(not row['pass'] for row in report.values()), 'no failed replay to preserve'
    paths = [report_path, Path(__file__)] + [path for path in directory.iterdir() if path.is_file()]
    for entry, row in report.items():
        assert Path(row['cases']).resolve() == (directory / f'f_{int(entry,16):08x}.cases').resolve()
        executable = Path(row['executable'])
        assert digest(executable) == row['executable_sha256']
        paths.append(executable)
    for run in batch['runs']:
        raw = Path(run['capsule'])
        paths += [raw, Path(str(raw)+'.summary.json'), Path(run['entry_patch']), Path(run['log'])]
        assert digest(run['entry_patch']) == run['entry_patch_sha256']
    refs = list({row['path']: row for row in map(reference, paths)}.values())
    output.write_text(json.dumps(dict(coverage_credit=False, acceptance_failed=True,
        reason='The complete strict report has failed specimens. All entries, runs and case artifacts are retained; no passing subset qualifies this campaign.',
        reports=report, references=refs), indent=2)+'\n')
    print(f'Pinned {len(refs)} failed-campaign dependencies; no coverage credit')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--report', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    pin(args.directory, args.report, args.out)
