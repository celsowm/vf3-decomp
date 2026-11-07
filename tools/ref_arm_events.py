import struct, sys

PATH='extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
d=open(PATH,'rb').read()
assert d[:8]==b'VF3ARM1\0', d[:8]
n=(len(d)-8)//40
EV=struct.Struct('<QQIIIIII')

def ev(i):
    return EV.unpack_from(d, 8+i*40)

if __name__=='__main__':
    lo=int(sys.argv[1],0) if len(sys.argv)>1 else 0
    hi=int(sys.argv[2],0) if len(sys.argv)>2 else n
    lo=max(0,lo); hi=min(n,hi)
    for i in range(lo,hi):
        seq,cyc,pc,op,addr,data,size,store=ev(i)
        print('%7d cyc=%9d pc=%05x op=%08x %s addr=%07x data=%08x sz=%d store=%d'%(
            i,cyc,pc,op,'W' if store else 'R',addr,data,size,store))
