"""Verify the complete resident sound-ID map against the original image table."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from audio_determinism import sha
from capsules import records


def inspect(manifest,image):
    batch=json.loads(manifest.read_text())
    assert batch['passed'] and batch['execution']=='original_sh4'
    address=0x0c1025f0;size=477*4
    initial=image.read_bytes()[address-0x0c010000:address-0x0c010000+size]
    assert len(initial)==size
    initial_words=struct.unpack('<477I',initial)
    states={}
    for row in batch['runs']:
        sample=next(records(row['capsule']))
        page=next(((base,before,after) for base,before,after in sample['pages']
                   if base<=address and address+size<=base+len(before)),None)
        if page is None:continue
        base,before,after=page;offset=address-base
        resident=before[offset:offset+size]
        assert resident==after[offset:offset+size], 'submission modified the resident map'
        words=struct.unpack('<477I',resident)
        state=row['state']
        report=dict(resident_sha256=hashlib.sha256(resident).hexdigest(),
                    image_differs=resident!=initial,
                    changed_ids=[i for i,(a,b) in enumerate(zip(initial_words,words)) if a!=b],
                    nonnegative_ids=sum(v<0x80000000 for v in words),
                    capsule=dict(path=row['capsule'],sha256=sha(row['capsule'])),
                    sample_values={str(i):f'0x{words[i]:08x}' for i in (0,1,4,10,35,225,476)})
        if state in states:assert states[state]['resident_sha256']==report['resident_sha256']
        else:states[state]=report
    assert len(states)>=2 and all(not row['image_differs'] for row in states.values())
    return dict(passed=True,coverage_credit=False,address=hex(address),bytes=size,
                interpretation='both observed resident maps equal the complete original image table; submissions preserve it',
                issuer_attribution=False,command_names_attributed=False,
                source={str(path):sha(path) for path in (manifest,image)},states=states)


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('manifest',type=Path);ap.add_argument('image',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();result=inspect(a.manifest,a.image)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f'{len(result["states"])} complete resident maps match the original image table')
