"""Export only successfully terminated capture runs, retaining rejected provenance."""
import argparse
import json
from pathlib import Path
from capsules import convert


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('batch', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    batch = json.loads((a.batch / 'batch_manifest.json').read_text())
    accepted = [r for r in batch['runs'] if r['returncode'] == 0 and r['frame_complete']
                and Path(r['capsule'] + '.summary.json').exists()]
    rejected = [r for r in batch['runs'] if r not in accepted]
    assert accepted, 'no successful runs'
    convert([r['capsule'] for r in accepted], a.out)
    (a.out / 'batch_manifest.json').write_text(json.dumps(dict(
        name=a.out.name, watch=batch['watch'], runs=accepted,
        rejected_runs=rejected, source_batch=str(a.batch.resolve())), indent=1) + '\n')
    print(f'{len(accepted)} successful runs; {len(rejected)} failed runs excluded')


if __name__ == '__main__':
    main()
