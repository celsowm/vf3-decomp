"""Attribute resident DTPK assets by complete byte equality, without opcode guesses.

Whole resident files establish bank identity. They do not establish the issuer,
DMA timing, ARM reset semantics, or survival of voices across a transition.
"""
import argparse
import json
from pathlib import Path
from audio_determinism import checkpoints, sha
from audio_state import ARAM_OFFSET, ARAM_BYTES, inspect, digest


def residents(wave, assets):
    found=[]
    for path,data in assets:
        if not data.startswith(b'DTPK') or len(data)>len(wave): continue
        offset=wave.find(data)
        while offset>=0:
            found.append(dict(asset=str(path),aica_offset=offset,**digest(data)))
            offset=wave.find(data,offset+1)
    return found


def map_checkpoint(row,assets):
    block=row['blocks'][3]
    state=inspect(block)
    wave=block[ARAM_OFFSET:ARAM_OFFSET+ARAM_BYTES]
    banks=residents(wave,assets)
    voices=[]
    for voice in state['channels']:
        if not voice['enabled']: continue
        address=int(voice['runtime_sample_address'],0)
        candidates=[dict(asset=b['asset'],file_offset=address-b['aica_offset'],
                         resident_sha256=b['sha256']) for b in banks
                    if b['aica_offset']<=address<b['aica_offset']+b['bytes']]
        voices.append(dict(**voice,resident_assets=candidates))
    return dict(identity=row['identity'],aram=state['aram'],resident_banks=banks,
                enabled_voices=voices)


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('checkpoint',type=Path)
    ap.add_argument('--assets',type=Path,default=Path('extract/gamedata'))
    ap.add_argument('--out',type=Path,required=True)
    args=ap.parse_args()
    assets=[(p,p.read_bytes()) for p in sorted(args.assets.glob('*.BIN'))
            if p.open('rb').read(4)==b'DTPK']
    rows=[map_checkpoint(row,assets) for row in checkpoints(args.checkpoint)]
    result=dict(coverage_credit=False,source=dict(path=str(args.checkpoint),sha256=sha(args.checkpoint)),
                bank_identity_requires_complete_byte_equality=True,checkpoints=rows)
    args.out.write_text(json.dumps(result,indent=2)+'\n')
    for row in rows:
        print(f"{row['identity'][0]}: {len(row['resident_banks'])} complete banks; {len(row['enabled_voices'])} enabled voices")


if __name__=='__main__': main()
