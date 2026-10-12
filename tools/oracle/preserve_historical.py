"""Preserve frozen proof dependencies before subsequent normal-build changes."""
import argparse
import json
from pathlib import Path
import shutil
from ram_clipping_batch_audit import digest, reference

ROOT=Path(__file__).resolve().parents[2]


def preserve(proofs,source_archives,output,manifest):
    output=Path(output).resolve();manifest=Path(manifest)
    if output.exists() or manifest.exists():raise FileExistsError('refusing to replace historical evidence')
    refs={};closures=[]
    def add(row):
        path=str(Path(row['path']).resolve())
        if path in refs and refs[path]['sha256']!=row['sha256']:raise ValueError('conflicting frozen hashes')
        refs[path]=dict(row,path=path)
    for path in proofs:
        add(reference(path))
        for row in json.loads(Path(path).read_text())['references']:add(row)
    for path in source_archives:
        source=json.loads(Path(path).read_text());add(reference(path))
        for row in source['files']:
            archived=Path(path).parent/row['path'];current=ROOT/row['path']
            if digest(archived)!=row['sha256'] or digest(current)!=row['sha256']:
                raise ValueError(f'compiled dependency already changed: {current}')
        native=Path(source['native'])
        if digest(native)!=source['native_sha256']:raise ValueError('frozen executable changed')
        closures.append(dict(manifest=reference(path),archived_files=len(source['files']),native=reference(native)))
    # Validate the whole input set before creating any historical output.
    for row in refs.values():
        if digest(row['path'])!=row['sha256']:raise ValueError(f'proof dependency already changed: {row["path"]}')
    output.mkdir(parents=True);archived=[]
    for row in refs.values():
        path=Path(row['path'])
        if path.is_relative_to(ROOT) and path.relative_to(ROOT).parts[0] in ('tools','docs','build','src'):
            destination=output/path.relative_to(ROOT);destination.parent.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(path,destination)
            if digest(destination)!=row['sha256']:raise ValueError('dependency changed while preserving')
            archived.append(dict(path=str(destination),sha256=row['sha256'],original_path=str(path)))
        else:archived.append(row)
    result=dict(historical_only=True,coverage_credit=False,source_archives=closures,
                proofs=[reference(p) for p in proofs],references=archived)
    manifest.parent.mkdir(parents=True,exist_ok=True);manifest.write_text(json.dumps(result,indent=2)+'\n')
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--proof',type=Path,action='append',required=True)
    parser.add_argument('--source-archive',type=Path,action='append',default=[])
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--manifest',type=Path,required=True)
    args=parser.parse_args()
    result=preserve(args.proof,args.source_archive,args.out,args.manifest)
    print(f'Preserved {len(result["references"])} historical references; no C coverage credit')
