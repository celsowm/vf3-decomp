import struct

d=open('extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm','rb').read()
n=len(d)//8
def rec(i): return struct.unpack_from('<II',d,i*8)

# melody key-on trace indices; scan a window around them for command words
# at 0x3b5c whose data record carries the command word.
keys=[102043,102333,102893,103183,103718,104108]
lo=keys[0]-3000
hi=keys[-1]+500
cmds=[]
for i in range(max(0,lo),min(n,hi)):
    pc,op=rec(i)
    if pc==0x3b5c:
        dpc,dop=rec(i+1)
        # data record for str r0,[r12,#0xe0] is a literal addr a2e0
        cmds.append((i,dop))
print('command-word events at 0x3b5c:',len(cmds))
for i,v in cmds[:30]:
    print('  %8d  cmd=%08x'%(i,v))
print('...')
for i,v in cmds[-10:]:
    print('  %8d  cmd=%08x'%(i,v))

# Also count distinct command words
from collections import Counter
c=Counter(v for _,v in cmds)
print('distinct cmds:')
for v,k in c.most_common(20):
    print('   %08x  x%d'%(v,k))
