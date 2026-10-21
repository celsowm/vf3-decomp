#!/usr/bin/env python3
"""Derive the pinned observer's P1 data view without mutating capture originals.

This is a P1, privileged data-read projection, not a device/cache replacement.
P2 reads always use the raw RAM. Instruction-cache behavior is kept separately.
"""
import argparse
import json
from pathlib import Path
import struct

def project(metadata, raw, cache):
    if len(raw)!=0x1000000 or len(cache)!=30744:
        raise ValueError('unexpected pinned Dreamcast RAM/cache layout')
    version,ram_size=struct.unpack_from('<II',cache)
    if version!=854 or version!=metadata['cache_serializer_version'] or ram_size!=len(raw):
        raise ValueError('serializer header does not match the snapshot')
    result=bytearray(raw); ccr=metadata['ccr']; rows=[]
    # Pinned ARM64/x64 ABI: I-cache 256*40, O-cache 512*40, two u64 timings.
    for index in range(512):
        offset=8+256*40+index*40
        valid,dirty,tag=struct.unpack_from('<BB2xI',cache,offset)
        if valid not in (0,1) or dirty not in (0,1):
            raise ValueError('invalid cache flags; unsupported ABI')
        if not valid: continue
        physical=(tag<<10)|((index&0x1f)<<5)
        if not 0x0c000000<=physical<0x0d000000: continue
        address=physical|0x80000000
        ora=bool(ccr&0x20); oix=bool(ccr&0x80)
        expected=(((address>>17)&0x100)|((address>>5)&(0x7f if ora else 0xff))) if oix else ((address>>5)&(0x17f if ora else 0x1ff))
        applied=bool(ccr&1) and expected==index
        start=physical-0x0c000000
        data=cache[offset+8:offset+40]
        changed=sum(a!=b for a,b in zip(raw[start:start+32],data))
        if applied: result[start:start+32]=data
        rows.append(dict(index=index,physical=hex(physical),dirty=bool(dirty),applied=applied,bytes_different=changed))
    return bytes(result),dict(view='privileged P1 data',ccr=hex(ccr),mmucr=hex(metadata['mmucr']),
        rows=rows,changed_bytes=sum(a!=b for a,b in zip(raw,result)),
        note='All valid matching operand lines overlay RAM, including clean stale lines. P2 uses raw RAM; MMU/P0 and instruction-cache views are not modeled.')

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('snapshot',type=Path)
    a=parser.parse_args(); source=a.snapshot
    raw=source.with_suffix('.ram.bin'); cache=source.with_suffix('.cache.bin')
    output=source.with_suffix('.p1-ram.bin'); report=source.with_suffix('.p1-ram.json')
    if output.exists() or report.exists(): parser.error('derived output already exists; refusing overwrite')
    data,result=project(json.loads(source.read_text()),raw.read_bytes(),cache.read_bytes())
    output.write_bytes(data); report.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(output=str(output),changed_bytes=result['changed_bytes'])))

if __name__=='__main__': main()
