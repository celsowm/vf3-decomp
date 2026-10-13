"""Locate original BSR and literal-backed JSR callers for specified entries.

Candidates are static leads only; caller captures and opcode proofs are still
required. No candidate receives coverage credit from this listing.
"""
import argparse
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[2]
BASE=0x8c010000

def sites(image,target):
    found=[]
    def word(pc):return struct.unpack_from('<H',image,pc-BASE)[0]
    for offset in range(0,len(image)-2,2):
        pc=BASE+offset;op=word(pc)
        if op>>12==0xb:
            delta=op&4095
            if delta&2048:delta-=4096
            if pc+4+delta*2==target:
                found.append(dict(kind='bsr',call=hex(pc),delay=hex(word(pc+2))))
        if op&0xf0ff==0x400b:
            reg=(op>>8)&15
            for back in range(2,min(66,offset+2),2):
                load=pc-back;w=word(load)
                if w&0xff00==0xd000|(reg<<8):
                    pool=(load+4)&~3;pool+=(w&255)*4
                    if BASE<=pool<=BASE+len(image)-4:
                        value=struct.unpack_from('<I',image,pool-BASE)[0]
                        if value|0x80000000==target:
                            found.append(dict(kind='literal-jsr',load=hex(load),pool=hex(pool),call=hex(pc),delay=hex(word(pc+2))))
                    break
                # Stop at another ordinary write to this register. The
                # remaining window is a lead, never a declaration of proof.
                if w>>12 in (0x6,0xe) and (w>>8)&15==reg:break
    return found

def pointer_sites(image,target):
    return [hex(BASE+i) for i in range(0,len(image)-3,4)
            if struct.unpack_from('<I',image,i)[0]|0x80000000==target]

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('entry',nargs='+',type=lambda s:int(s,0)|0x80000000)
    p.add_argument('--out',type=Path)
    a=p.parse_args();image=(ROOT/'extract/gamedata/1ST_READ.BIN').read_bytes()
    result={hex(e):dict(callers=sites(image,e),pointer_slots=pointer_sites(image,e)) for e in a.entry}
    if a.out:
        if a.out.exists():raise FileExistsError(a.out)
        a.out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result,indent=2))
