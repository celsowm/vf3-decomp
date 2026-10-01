#!/usr/bin/env python3
"""Audit fourth-batch byte union and independent validation provenance."""
import argparse
import json
from pathlib import Path

from audit_matrix_batch import audit

ROOT=Path(__file__).resolve().parents[2]


def main(check_hashes,manifest_path="tools/oracle/next_batch.json"):
    audit(check_hashes,manifest_path)
    manifest=json.loads((ROOT/manifest_path).read_text())
    campaigns={}
    for entry,evidence in manifest['entries'].items():
        groups=[]
        scenarios=[]
        for name in ('heldout','fresh'):
            group=evidence['validation_groups'][name]
            assert group['report'] in evidence['proofs']
            directory=ROOT/'extract/analysis'/group['directory']
            if directory not in campaigns:
                batch=json.loads((directory/'batch_manifest.json').read_text())
                capsule=json.loads((directory/'capsule_manifest.json').read_text())
                assert all(run['returncode']==0 and run.get('frame_complete',True) for run in batch['runs'])
                sources={str(Path(run['capsule']).resolve()):run['name'] for run in batch['runs']}
                campaigns[directory]=(capsule,sources)
            capsule,sources=campaigns[directory]
            used={sources.get(str(Path(src['source']).resolve()))
                  for record in capsule['entries'][entry] for src in record['sources']}
            assert used.intersection(group['runs']),f'{entry} missing {name} provenance'
            assert all((int(item['entry'],16)|0x80000000)!=int(entry,16)
                       for run in capsule['runs'] for item in run.get('incomplete',[]))
            batch=json.loads((directory/'batch_manifest.json').read_text())
            scenarios.append({(run['state'],run['play']) for run in batch['runs'] if run['name'] in group['runs']})
            groups.append({src['source'] for record in capsule['entries'][entry] for src in record['sources']
                           if sources.get(str(Path(src['source']).resolve())) in group['runs']})
        assert groups[0] and groups[1] and groups[0].isdisjoint(groups[1]),f'{entry} reused validation scenario'
        binding=json.loads((ROOT/'tools/golden_bindings.json').read_text())[evidence['binding']]
        development=json.loads((ROOT/binding['golden']).parent.joinpath('batch_manifest.json').read_text())
        dev_scenarios={(run['state'],run['play']) for run in development['runs']}
        assert scenarios[0].isdisjoint(scenarios[1]),f'{entry} reused validation state/input scenario'
        assert all(group.isdisjoint(dev_scenarios) for group in scenarios),f'{entry} reused development state/input scenario'
    print(f'{Path(manifest_path).stem}: {len(manifest["entries"])} independent held-out/fresh boundaries - PASS')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes',action='store_true')
    parser.add_argument('--manifest',default='tools/oracle/next_batch.json')
    args=parser.parse_args()
    main(args.hashes,args.manifest)
