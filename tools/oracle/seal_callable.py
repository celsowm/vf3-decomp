"""Validate and pin an authored callable contract against original evidence."""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from body_cover import body_spans
from callable_body import validate


def reference(path):
    path=Path(path).resolve()
    with path.open('rb') as stream:
        sha=hashlib.file_digest(stream,'sha256').hexdigest()
    return dict(path=str(path),sha256=sha)


def seal(template, callers, corpora, output, image, reference_key='original_caller_manifests'):
    output=Path(output)
    if output.exists():raise FileExistsError('refusing to replace a callable proof')
    declarations=copy.deepcopy(json.loads(Path(template).read_text()))
    if not declarations or not callers or not corpora:raise ValueError('need authored owners, original callers and corpora')
    references=[reference(path) for path in callers]
    spans=body_spans();rom=Path(image).read_bytes()
    for owner,attribution in declarations.items():
        attribution[reference_key]=references
        for corpus in corpora:validate(int(owner,16),attribution,spans[int(owner,16)],Path(corpus),rom)
    # Detect mutation between validation and sealing; no coverage ledgers change.
    if references != [reference(path) for path in callers]:raise ValueError('caller evidence changed during validation')
    output.parent.mkdir(parents=True,exist_ok=True)
    output.write_text(json.dumps(declarations,indent=2)+'\n')
    return declarations


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--template',type=Path,required=True,help='authored owner-to-contract JSON; no call shape is inferred')
    parser.add_argument('--caller-manifest',type=Path,action='append',required=True)
    parser.add_argument('--corpus',type=Path,action='append',required=True)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--image',type=Path,default=ROOT/'extract/gamedata/1ST_READ.BIN')
    parser.add_argument('--reference-key',choices=('original_caller_manifests','original_dispatch_manifests'),default='original_caller_manifests')
    args=parser.parse_args()
    declarations=seal(args.template,args.caller_manifest,args.corpus,args.out,args.image,args.reference_key)
    print(f'{len(declarations)} callable contracts validated and pinned; no C coverage credit')


if __name__=='__main__':main()
