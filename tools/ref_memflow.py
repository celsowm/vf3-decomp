import struct, sys

d=open('extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm','rb').read()
n=len(d)//8
def rec(i): return struct.unpack_from('<II',d,i*8)

def is_real(pc,op):
    return 0x1000<=pc<=0x10000 and (pc&3)==0

A=int(sys.argv[1],0) if len(sys.argv)>1 else 101800
B=int(sys.argv[2],0) if len(sys.argv)>2 else 104300

for i in range(A,B):
    pc,op=rec(i)
    if is_real(pc,op):
        dpc,dop=rec(i+1)
        # data record: dpc looks like an addr or literal slot
        print('%8d %05x %08x  -> %06x %08x'%(i,pc,op,dpc,dop))
