import struct

d=open('extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm','rb').read()
n=len(d)//8
def rec(i): return struct.unpack_from('<II',d,i*8)
def is_real(pc,op):
    return 0x1000<=pc<=0x10000 and (pc&3)==0

A,B=101000,104400
print('=== enqueue (0x245c) into ring buffer, and dispatch (0x3b5c) ===')
last_key=None
for i in range(A,B):
    pc,op=rec(i)
    if pc in (0x245c,0x3b5c,0x264c):
        dpc,dop=rec(i+1)
        tag={0x245c:'ENQ',0x3b5c:'DISP',0x264c:'KEY'}[pc]
        print('%8d %s pc=%05x data=%06x val=%08x'%(i,tag,pc,dpc,dop))
