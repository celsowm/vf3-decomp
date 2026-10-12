"""Merge complete original development campaigns after per-state body audits."""
import argparse
import json
from pathlib import Path
from capsules import convert, records
from evidence_inspect import capture
from ram_clipping_batch_audit import reference


def merge(batches,owners_path,output,proof,image,minimum=64):
    output=Path(output);proof=Path(proof)
    if output.exists() or proof.exists():raise FileExistsError('refusing to replace original development evidence')
    owners=json.loads(Path(owners_path).read_text());assert owners
    inspection=capture(batches,owners,image)
    assert len(inspection['scenarios'])>=2 and not inspection['nondeterministic_entries']
    for run in inspection['runs']:
        assert run['complete_accounting'] and run['frame_complete'] and run['returncode']==0
    for scenario in inspection['scenarios']:
        assert set(scenario['entries'])==set(owners)
        for row in scenario['entries'].values():
            assert row['distinct_inputs']>=minimum and row['missing_body_bytes']==0 and row['device_records']==0
    runs=[];refs=[reference(p) for p in (owners_path,image,Path(__file__))]
    for n,path in enumerate(batches):
        batch=json.loads(Path(path).read_text());refs.append(reference(path))
        for run in batch['runs']:
            assert run['ran_frames']==run['expected_frames']
            raw=Path(run['capsule']);refs.extend(reference(p) for p in (raw,Path(str(raw)+'.summary.json')))
            for sample in records(raw):
                assert sample['nstate']==63 and hex(sample['entry']|0x80000000) in owners
                assert not sample['flags']&~7, 'unclassified excluded specimen'
            runs.append(dict(run,name=f'batch{n}_'+run['name']))
    converted=convert([Path(r['capsule']) for r in runs],output)
    assert not converted['nondeterministic_entries']
    (output/'batch_manifest.json').write_text(json.dumps(dict(development_only=True,coverage_credit=False,runs=runs),indent=2)+'\n')
    refs.extend(reference(output/name) for name in ('capsule_manifest.json','batch_manifest.json'))
    proof.parent.mkdir(parents=True,exist_ok=True)
    proof.write_text(json.dumps(dict(coverage_credit=False,whole_original_development_bodies=True,
        inspection=inspection,references=refs),indent=2)+'\n')
    return converted


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--batch',type=Path,action='append',required=True)
    parser.add_argument('--owners',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--proof',type=Path,required=True)
    parser.add_argument('--image',type=Path,required=True)
    parser.add_argument('--min-cases',type=int,default=64)
    args=parser.parse_args()
    result=merge(args.batch,args.owners,args.out,args.proof,args.image,args.min_cases)
    print(f'{sum(map(len,result["entries"].values()))} distinct complete development cases; no C coverage credit')
