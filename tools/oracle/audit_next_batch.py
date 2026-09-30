#!/usr/bin/env python3
"""Audit fourth-batch byte union and independent validation provenance."""
import argparse
import json
from pathlib import Path

from audit_matrix_batch import audit

ROOT=Path(__file__).resolve().parents[2]


def main(check_hashes):
    audit(check_hashes,'tools/oracle/next_batch.json')
    manifest=json.loads((ROOT/'tools/oracle/next_batch.json').read_text())
    campaigns={}
    for entry,evidence in manifest['entries'].items():
        groups=[]
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
            groups.append({src['source'] for record in capsule['entries'][entry] for src in record['sources']
                           if sources.get(str(Path(src['source']).resolve())) in group['runs']})
        assert groups[0] and groups[1] and groups[0].isdisjoint(groups[1]),f'{entry} reused validation scenario'
    print(f'next_batch: {len(manifest["entries"])} independent held-out/fresh boundaries - PASS')


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes',action='store_true')
    args=parser.parse_args()
    main(args.hashes)
