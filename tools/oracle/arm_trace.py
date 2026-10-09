"""Read ordered ARM memory evidence. Callback time is coarse SH-4 time.

The trace contains all ARM stores and reads of the low protocol region. A
queue read is a consumption lead, not proof of its command's meaning.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import struct
from audio_determinism import sha


def records(path):
    with Path(path).open('rb') as f:
        if f.read(8)!=b'VF3ARM1\0': raise ValueError('unsupported ARM trace')
        previous=0
        while data:=f.read(40):
            if len(data)!=40: raise ValueError('truncated ARM record')
            seq,cycle,pc,op,addr,value,size,store=struct.unpack('<QQ6I',data)
            if seq!=previous+1 or size not in (1,2,4) or store not in (0,1):
                raise ValueError('invalid ARM record')
            previous=seq
            yield dict(sequence=seq,callback_cycle=cycle,pc=pc,opcode=op,
                       address=addr,value=value,size=size,store=bool(store))


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('trace',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    args=ap.parse_args()
    counts=Counter()
    queue=[]
    voice=[]
    total=0
    for row in records(args.trace):
        total+=1
        addr=row['address']
        counts[(row['store'],f'0x{row["pc"]:08x}')]+=1
        if addr<0x800000 and 0x400<=(addr&0x1fffff)<0x500: queue.append(row)
        if row['store'] and 0x800000<=addr<0x802000: voice.append(row)
    result=dict(coverage_credit=False,source=dict(path=str(args.trace),sha256=sha(args.trace)),
                event_count=total, complete_requires_log_footer=True,
                pc_counts=[dict(store=key[0],pc=key[1],count=count)
                           for key,count in sorted(counts.items())],
                queue_accesses=queue,voice_register_writes=voice)
    args.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f'{total} records; {len(queue)} queue accesses; {len(voice)} voice register writes')


if __name__=='__main__': main()
