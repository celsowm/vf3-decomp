#!/usr/bin/env python3
"""Emit source C ABI adapters around the hand-written matrix algorithms.

This is a source translator, not a runtime interpreter. Each known statement
becomes C; control flow is explicit labels and calls to verified semantic
helpers. Unknown destinations and unsupported instructions fail closed.
The generated source must pass complete-state replay before ledger credit.
"""
import argparse
import csv
import json
from pathlib import Path
import struct
import re
import sys

ROOT=Path(__file__).resolve().parents[2]
MANUAL={0x0c03b450,0x0c03b4b0,0x0c03b530,0x0c03b620,0x0c03b820,0x0c03bd80,
        0x0c03c0e0,0x0c03c4a0,0x0c03c4f0,0x0c03c610,0x0c03c6c0,0x0c03c880,
        0x0c03c940,0x0c03c970,0x0c03cbd0,0x0c03cc60,0x0c03cc90,0x0c03ccb0}
def sx(x,b): return x-(1<<b) if x&(1<<(b-1)) else x
def label(pc): return f"P_{pc:08x}"
def t(expr): return f"r[17]=(r[17]&~1u)|(({expr})!=0);"

def write_source(path, content):
    path = Path(path)
    if not path.exists() or path.read_text(encoding='ascii') != content:
        path.write_text(content, encoding='ascii')

def adapter_pcs(paths):
    """Read emitted labels, excluding comments, routers and inferred seeds."""
    return {int(a,16) for path in paths
            for a in re.findall(r'^P_([0-9a-f]+):',Path(path).read_text(),re.M)}
def emit(pc,w):
    n,m=(w>>8)&15,(w>>4)&15
    rn,rm=f"r[{n}]",f"r[{m}]"
    fn,fm=f"fr[{n}]",f"fr[{m}]"
    top,low=w>>12,w&15
    if w==9: return []
    if w==8: return [t("0")]
    if w==0x18: return [t("1")]
    if w==0x28: return ["r[19]=r[20]=0;"]
    if w==0x19: return ["r[17]&=~0x301u;"]
    if top==0xE: return [f"{rn}=0x{sx(w&255,8)&0xffffffff:08x}u;"]
    if top==7: return [f"{rn}+=0x{sx(w&255,8)&0xffffffff:08x}u;"]
    if top==9: return [f"{rn}=(uint32_t)(int32_t)(int16_t)read(ram,0x{pc+4+(w&255)*2:08x}u,2);"]
    if top==0xD: return [f"{rn}=read(ram,0x{((pc+4)&~3)+(w&255)*4:08x}u,4);"]
    if top==1: return [f"write(ram,{rn}+{(w&15)*4},{rm},4);"]
    if top==5: return [f"{rn}=read(ram,{rm}+{(w&15)*4},4);"]
    if top==2:
        if low<=2: return [f"write(ram,{rn},{rm},{1<<low});"]
        if 4<=low<=6: return [f"tmp={rm}; {rn}-={1<<(low-4)}; write(ram,{rn},tmp,{1<<(low-4)});"]
        if low==7: return [f"r[17]=(r[17]&~0x301u)|(({rn}>>31)<<8)|(({rm}>>31)<<9)|((({rn}^{rm})>>31)&1u);"]
        if low==8: return [t(f"({rn}&{rm})==0")]
        if low in (9,10,11): return [f"{rn}{ {9:'&=',10:'^=',11:'|='}[low]}{rm};"]
        if low==0xC: return [t(f"(({rn}^{rm})&0xffu)==0 || (({rn}^{rm})&0xff00u)==0 || (({rn}^{rm})&0xff0000u)==0 || (({rn}^{rm})&0xff000000u)==0")]
        if low==0xD: return [f"{rn}=({rn}>>16)|({rm}<<16);"]
        if low==0xE: return [f"r[19]=({rn}&65535u)*({rm}&65535u);"]
        if low==0xF: return [f"r[19]=(uint32_t)((int32_t)(int16_t){rn}*(int32_t)(int16_t){rm});"]
    if top==3:
        if low==4: return [f"divide_step(s,{n},{m});"]
        if low in (0,2,3,6,7): return [t({0:f"{rn}=={rm}",2:f"{rn}>={rm}",3:f"(int32_t){rn}>=(int32_t){rm}",6:f"{rn}>{rm}",7:f"(int32_t){rn}>(int32_t){rm}"}[low])]
        if low==8: return [f"{rn}-={rm};"]
        if low==0xC: return [f"{rn}+={rm};"]
        if low==0xA: return [f"wide=(uint64_t){rn}-{rm}-(r[17]&1u); {rn}=(uint32_t)wide;",t("wide>>32")]
        if low==0xE: return [f"wide=(uint64_t){rn}+{rm}+(r[17]&1u); {rn}=(uint32_t)wide;",t("wide>>32")]
        if low in (5,13): return [f"wide={('(uint64_t)((int64_t)(int32_t)'+rn+'*(int64_t)(int32_t)'+rm+')') if low==13 else '(uint64_t)'+rn+'*'+rm}; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);"]
    if top==6:
        if low<=2 or 4<=low<=6:
            k=low if low<=2 else low-4; size=1<<k
            cast={0:"(uint32_t)(int32_t)(int8_t)",1:"(uint32_t)(int32_t)(int16_t)",2:""}[k]
            lines=[f"tmp={cast}read(ram,{rm},{size});"]
            if low>=4 and n!=m: lines.append(f"{rm}+={size};")
            return lines+[f"{rn}=tmp;"]
        if low==3: return [f"{rn}={rm};"]
        if low==7: return [f"{rn}=~{rm};"]
        if low==8: return [f"{rn}=({rm}&0xffff0000u)|(({rm}&255u)<<8)|(({rm}>>8)&255u);"]
        if low==9: return [f"{rn}=({rm}<<16)|({rm}>>16);"]
        if low==0xB: return [f"{rn}=0u-{rm};"]
        if low==0xA: return [f"wide=0ull-(uint64_t){rm}-(r[17]&1u); {rn}=(uint32_t)wide;",t("wide>>32")]
        if low in (0xC,0xD): return [f"{rn}={rm}&{255 if low==0xC else 65535}u;"]
        if low in (0xE,0xF): return [f"{rn}=(uint32_t)(int32_t)({ 'int8_t' if low==0xE else 'int16_t'}){rm};"]
    if top==4:
        k=w&255
        if (w&0xF08F)==0x4083: return ['if(!s->bank_known) goto unsupported;',f'{rn}-=4; write(ram,{rn},s->bank[{(w>>4)&7}],4);']
        if (w&0xF08F)==0x4087: return ['if(!s->bank_known) goto unsupported;',f's->bank[{(w>>4)&7}]=read(ram,{rn},4); {rn}+=4;']
        if (w&0xF08F)==0x408E: return ['if(!s->bank_known) goto unsupported;',f's->bank[{(w>>4)&7}]={rn};']
        if k==0x1b: return [f'tmp=read(ram,{rn},1);',t('tmp==0'),f'write(ram,{rn},tmp|0x80u,1);']
        if k==0x13: return ['if(!s->gbr_known) goto unsupported;',f'{rn}-=4; write(ram,{rn},s->gbr,4);']
        if k==0x17: return [f's->gbr=read(ram,{rn},4); {rn}+=4; s->gbr_known=1;']
        if k==0x1e: return [f's->gbr={rn}; s->gbr_known=1;']
        if k==0x10: return [f"--{rn};",t(f"{rn}==0")]
        if k in (0x11,0x15): return [t(f"(int32_t){rn}{'>=' if k==0x11 else '>'}0")]
        if k in (0,0x20): return [t(f"{rn}>>31"),f"{rn}<<=1;"]
        if k==1: return [t(f"{rn}&1"),f"{rn}>>=1;"]
        if k==0x21: return [t(f"{rn}&1"),f"{rn}=(uint32_t)((int32_t){rn}>>1);"]
        if k in (8,9,0x18,0x19,0x28,0x29): return [f"{rn}{'<<=' if k%2==0 else '>>='}{ {8:2,9:2,0x18:8,0x19:8,0x28:16,0x29:16}[k]};"]
        if low in (0x0C,0x0D): return [f"{rn}=({rm}&0x80000000u)?(({rm}&31u)?{'(uint32_t)((int32_t)'+rn+'>>((-'+rm+')&31u))' if low==0x0C else rn+'>>((-'+rm+')&31u)'}:{'((int32_t)'+rn+'<0?0xffffffffu:0)' if low==0x0C else '0'}):{rn}<<({rm}&31u);"]
        if k==0x24: return [f"tmp={rn}>>31; {rn}=({rn}<<1)|(r[17]&1u);",t("tmp")]
        if k==0x25: return [f"tmp={rn}&1u; {rn}=({rn}>>1)|((r[17]&1u)<<31);",t("tmp")]
        if k==0x05: return [t(f'{rn}&1u'),f'{rn}=({rn}>>1)|({rn}<<31);']
        if k==0x04: return [t(f'{rn}>>31'),f'{rn}=({rn}<<1)|({rn}>>31);']
        dest={0x0A:20,0x1A:19,0x2A:16,0x5A:53,0x6A:18,0x0E:17}.get(k)
        if dest is not None: return [f"r[{dest}]={rn};"]
        dest={0x06:20,0x16:19,0x26:16,0x56:53,0x66:18}.get(k)
        if dest is not None: return [f"r[{dest}]=read(ram,{rn},4); {rn}+=4;"]
        src={0x02:20,0x12:19,0x22:16,0x52:53,0x62:18,0x03:17}.get(k)
        if src is not None: return [f"{rn}-=4; write(ram,{rn},r[{src}],4);"]
    if top==0:
        k=w&255
        if (w&0xF08F)==0x0082: return ['if(!s->bank_known) goto unsupported;',f'{rn}=s->bank[{(w>>4)&7}];']
        if k==0x12: return ['if(!s->gbr_known) goto unsupported;',f'{rn}=s->gbr;']
        if k==0x29: return [f"{rn}=r[17]&1u;"]
        src={0x0A:20,0x1A:19,0x2A:16,0x5A:53,0x6A:18,0x02:17}.get(k)
        if src is not None: return [f"{rn}=r[{src}];"]
        if low in (4,5,6): return [f"write(ram,{rn}+r[0],{rm},{1<<(low-4)});"]
        if low in (0xC,0xD,0xE): return [f"{rn}={ {12:'(uint32_t)(int32_t)(int8_t)',13:'(uint32_t)(int32_t)(int16_t)',14:''}[low]}read(ram,{rm}+r[0],{1<<(low-12)});"]
        if low==7: return [f"r[19]={rn}*{rm};"]
        if k in (0x83,0x93,0xa3,0xb3): return [] # Non-strict emulator cache operations have no architectural result.
        if k==0xc3: return [f'write(ram,{rn},r[0],4);'] # MOVCA.L: interpreter-visible RAM store.
    if top==8:
        k=(w>>8)&15; reg=(w>>4)&15; d=w&15
        if k in (0,1): return [f"write(ram,r[{reg}]+{d*(1<<k)},r[0],{1<<k});"]
        if k in (4,5): return [f"r[0]=(uint32_t)(int32_t)({'int8_t' if k==4 else 'int16_t'})read(ram,r[{reg}]+{d*(1<<(k-4))},{1<<(k-4)});"]
        if k==8: return [t(f"r[0]==0x{sx(w&255,8)&0xffffffff:08x}u")]
    if top==0xC:
        k=(w>>8)&15
        if k in (0,1,2): return ['if(!s->gbr_known) goto unsupported;',f'write(ram,s->gbr+{(w&255)*(1<<k)},r[0],{1<<k});']
        if k in (4,5,6): return ['if(!s->gbr_known) goto unsupported;',f"r[0]={ {4:'(uint32_t)(int32_t)(int8_t)',5:'(uint32_t)(int32_t)(int16_t)',6:''}[k]}read(ram,s->gbr+{(w&255)*(1<<(k-4))},{1<<(k-4)});"]
        if k==7: return [f"r[0]=0x{((pc+4)&~3)+(w&255)*4:08x}u;"]
        if k==8: return [t(f"(r[0]&{w&255}u)==0")]
        if k in (9,10,11): return [f"r[0]{ {9:'&=',10:'^=',11:'|='}[k]}{w&255}u;"]
    if top==0xF:
        if w==0xFBFD: return ["vf3_matrix_swap(s);"]
        if w==0xF3FD: return ["r[18]^=0x100000u;"]
        if (w&0xF1FF)==0xF0FD: return [f"vf3_fpu_fsca(r[53],fr+{n&14});"]
        if (w&0xF0FF)==0xF0ED: return [f"if(!vf3_fpu_fipr(fr+{(n&3)*4},fr+{n&12},r[18],fr+{(n&12)+3})) goto unsupported;"]
        if (w&0xF3FF)==0xF1FD: return [f"if(!vf3_fpu_ftrv(xf,fr+{n&12},r[18],fr+{n&12})) goto unsupported;"]
        if low<=3: return [f"{fn}=vf3_fpu_binary({fn},{fm},r[18],'{'+-*/'[low]}');"]
        if low in (4,5): return [t(f"as_float({fn}){'==' if low==4 else '>'}as_float({fm})")]
        if low in (6,8,9):
            address=f"{rm}+r[0]" if low==6 else rm
            return [f"vf3_matrix_load(s,ram,{n},{address});"]+([f"{rm}+=(r[18]&0x100000u)?8:4;"] if low==9 else [])
        if low in (7,10,11):
            lines=[f"{rn}-=(r[18]&0x100000u)?8:4;"] if low==11 else []
            return lines+[f"vf3_matrix_store(s,ram,{m},{rn+'+r[0]' if low==7 else rn});"]
        if low==12: return [f"vf3_matrix_move(s,{n},{m});"]
        if low==14: return [f"{fn}=vf3_fpu_mac(fr[0],{fm},{fn},r[18]);"]
        if low==13:
            k=w&255
            if k==0x0D: return [f"{fn}=r[53];"]
            if k==0x1D: return [f"r[53]={fn};"]
            if k==0x2D: return [f"{fn}=vf3_fpu_float(r[53],r[18]);"]
            if k==0x3D: return [f"r[53]=truncate_float({fn});"]
            if k==0x4D: return [f"{fn}^=0x80000000u;"]
            if k==0x5D: return [f"{fn}&=0x7fffffffu;"]
            if k==0x6D: return [f"{fn}=vf3_fpu_sqrt({fn},r[18]);"]
            if k==0x7D: return [f"if(!vf3_fpu_fsrra({fn},r[18],&{fn})) goto unsupported;"]
            if k==0x8D: return [f"{fn}=0;"]
            if k==0x9D: return [f"{fn}=0x3f800000u;"]
    raise ValueError(f"unsupported {pc:08x}: {w:04x}")

def generate(directories,out,watch=None,function='vf3_matrix_adapter',reuse_matrix=False,split_size=0,reuse_adapters=()):
    legacy=watch is None
    watch=Path(watch or ROOT/'tools/watch/vf3_matrix_batch.txt')
    roots={int(row.split()[1],16)&0x1fffffff for row in watch.read_text().splitlines() if row.split() and row.split()[0]=='pc'}
    existing=set()
    forced=set()
    if reuse_matrix:
        existing=adapter_pcs([ROOT/'src/fight/matrix_adapters.c'])
    for pattern in reuse_adapters:
        paths=list(ROOT.glob(pattern))
        if not paths: raise ValueError(f'no adapter sources match {pattern}')
        output=Path(out).resolve()
        paths=[p for p in paths if p.resolve()!=output and not
               (p.parent.resolve()==output.parent and
                p.stem.startswith(output.stem+'_'))]
        existing.update(adapter_pcs(paths))
    if reuse_matrix or reuse_adapters:
        for row in csv.DictReader(open(ROOT/'extract/analysis/function_body_ranges.csv')):
            if int(row['entry'],16)&0x1fffffff in roots:
                forced.update(range(int(row['start'],16)&0x1fffffff,int(row['end'],16)&0x1fffffff,2))
    def reused(a): return a in existing and a not in forced
    ops={}
    for directory in directories:
        for p in Path(directory).glob("*.ops.json"):
            if not legacy and (int(p.name.split("_")[1].split(".")[0],16)&0x1fffffff) not in roots:
                continue
            if legacy and p.stem in ("f_8c076c00.ops", "f_8c0782ea.ops"):
                continue
            for a,w in json.loads(p.read_text()).items():
                a=int(a,16)&0x1fffffff; w=int(w,16)
                if a in ops and ops[a]!=w: raise ValueError(f"code identity conflict {a:x}")
                ops[a]=w
    # Hand-written kernels take precedence. Their opcodes are never emitted.
    # Drop capture-only legacy regression workers from this new family.
    ops={a:w for a,w in ops.items() if (not legacy or not 0xc075000<=a<0xc07b000) and not reused(a)}
    image=(ROOT/"extract/exe/1ST_READ.unsc.bin").read_bytes()
    if reuse_matrix or reuse_adapters:
        sys.path.insert(0,str(ROOT))
        from tools.batch_plan import implementation_graph
        # Root adapters must own their whole intraprocedural control flow.
        # A tiny or absent Ghidra seed cannot split a dispatch helper midway.
        root_scan=implementation_graph(image,{})
        for root in roots:
            forced.update(a&0x1fffffff for a in root_scan(root|0x80000000)[0])
        ops={a:w for a,w in ops.items() if not reused(a)}
    foreign={a:w for a,w in ops.items() if not 0xc010000<=a<0xc010000+len(image)-1}
    if not legacy:
        # Dynamically installed code is not an original-image implementation.
        # Preserve it as a blocker; dispatch to these PCs fails at replay.
        ops={a:w for a,w in ops.items() if a not in foreign}
    def word(pc):
        off=(pc|0x80000000)-0x8c010000
        if not 0<=off<len(image)-1: raise ValueError(f"outside image {pc:08x}")
        return struct.unpack_from("<H",image,off)[0]
    for a,w in ops.items():
        if word(a)!=w: raise ValueError(f"executed image mismatch {a:x}")
    # Close statically reachable branches from the original image, including
    # paths absent from development captures. Delay slots do not fall through
    # a return/jump into pools. Dynamic destinations still fail closed.
    resolved={int(r['site'],16)&0x1fffffff:int(r['target'],16)&0x1fffffff
              for r in csv.DictReader(open(ROOT/'extract/analysis/sh4_resolved.csv'))
              if r['class']=='STATIC'}
    delayed=set()
    def delay(w):
        return w>>12 in (0xA,0xB) or w==0xB or (w&0xf0ff) in (0x400b,0x402b,0x0003,0x0023) or (w&0xff00) in (0x8d00,0x8f00)
    for a,w in ops.items():
        if delay(w): delayed.add(a+2)
    todo=[a for a in ops if a not in delayed]
    # Seven-entry flag dispatch table used at B0606, read from the image.
    if legacy: todo.extend(struct.unpack_from('<7I',image,0xc10f6a0-0xc010000))
    # Scene callback and conditional matrix-work entry points.
    if legacy: todo.extend([0xc0a71d4,0xc0a7204,0xc0a721a,0xc03e980,0xc0b10a8,0xc058ea0])
    for row in watch.read_text().splitlines():
        fields=row.split()
        if fields and fields[0]=='pc':
            root=int(fields[1],16)&0x1fffffff
            if not legacy or root not in (0xc076c00,0xc0782ea): todo.append(root)
    followed=set()
    while todo:
        a=todo.pop()
        if a in followed or reused(a) or not 0xc010000<=a<0xc010000+len(image): continue
        followed.add(a); w=word(a); ops[a]=w
        if len(ops)>50000: raise ValueError('CFG expansion exceeded 50000 statements')
        if delay(w):
            ops[a+2]=word(a+2); delayed.add(a+2)
        top=w>>12; k=(w>>8)&15
        if top==0xA: todo.append(a+4+sx(w&4095,12)*2)
        elif top==0xB: todo.extend([a+4,a+4+sx(w&4095,12)*2])
        elif top==8 and k in (9,11,13,15): todo.extend([a+4+sx(w&255,8)*2,a+(4 if k in (13,15) else 2)])
        elif w in (0xB,0x2B): pass
        elif (w&0xf0ff) in (0x402b,0x0023):
            if a in resolved and resolved[a] not in MANUAL: todo.append(resolved[a])
        elif (w&0xf0ff) in (0x400b,0x0003):
            todo.append(a+4)
            if a in resolved and resolved[a] not in MANUAL: todo.append(resolved[a])
        elif a not in delayed: todo.append(a+2)
    lines=['/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.',
           ' * Matrix operations are hand-written in matrix_family.c; unknown code fails.',
           ' * Executed opcodes are checked against the untouched identity image. */',
           '#include "fight/matrix_family.h"','#include "fight/sh4_fpu.h"',
           '#include <math.h>','#include <string.h>',
           '#define read vf3_matrix_read','#define write vf3_matrix_write',
           'static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }',
           'static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }',
           'static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }',
           'static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }',
           f'int {function}(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {{',
           'uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;',
           'dispatch:', 'if(!s->budget--) goto unsupported;',
           'switch(target&0x1fffffffu) {']
    for a in sorted(ops): lines.append(f'case 0x{a:08x}u: goto {label(a)};')
    lines.extend(['default: s->failed_pc=target; return 0;' if legacy else 'default: return vf3_matrix_family(target,s,ram);', '}'])
    unsupported={}; emitted=set()
    def jump(a):
        return f'goto {label(a)};' if a in ops else (f's->failed_pc=0x{a:08x}u; return 0;' if legacy else f'return vf3_matrix_family(0x{a:08x}u,s,ram);')
    def statements(pc):
        try: return emit(pc,word(pc))
        except ValueError as e: unsupported[pc]=str(e); return [f's->failed_pc=0x{pc:08x}u; return 0;']
    for a,w in sorted(ops.items()):
        emitted.add(a)
        lines.append(f'{label(a)}: /* original {w:04x}, guest PC 0x{a:08x} */')
        lines.append(f'if(!s->budget--) {{ s->failed_pc=0x{a:08x}u; return 0; }}')
        top=w>>12; k=(w>>8)&15
        dl=None
        if top in (0xA,0xB):
            dest=a+4+sx(w&4095,12)*2
            if top==0xB:
                lines.append(f'target=0x{dest:08x}u; r[16]=0x{a+4:08x}u;')
                lines.extend(statements(a+2))
                lines.append(f'if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x{a+4:08x}u) {{ target=s->pc; goto dispatch; }}')
                lines.append(jump(a+4))
            else:
                lines.extend(statements(a+2)); lines.append(jump(dest))
        elif top==8 and k in (9,11,13,15):
            lines.append('cond=r[17]&1u;')
            if k in (13,15): lines.extend(statements(a+2))
            lines.append(f"if({'cond' if k in (9,13) else '!cond'}) {{ {jump(a+4+sx(w&255,8)*2)} }}")
            lines.append(jump(a+(4 if k in (13,15) else 2)))
        elif (w&0xF0FF) in (0x400B,0x402B,0x0003,0x0023):
            n=(w>>8)&15
            rel=(w&0xF0FF) in (0x0003,0x0023)
            call=(w&0xF0FF) in (0x400B,0x0003)
            lines.append(f'target=r[{n}]'+(f'+0x{a+4:08x}u;' if rel else ';'))
            if call: lines.append(f'r[16]=0x{a+4:08x}u;')
            lines.extend(statements(a+2))
            if call:
                lines.append(f'if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x{a+4:08x}u) {{ target=s->pc; goto dispatch; }}'); lines.append(jump(a+4))
            else:
                lines.append('switch(target&0x1fffffffu) {')
                for helper in sorted(MANUAL): lines.append(f'case 0x{helper:08x}u: return vf3_matrix_family(target,s,ram);')
                lines.append('default: goto dispatch; }')
        elif w==0xB:
            lines.append('target=r[16];'); lines.extend(statements(a+2)); lines.append('s->pc=target; return ram->oob==0;')
        elif w==0x2B:
            lines.append(f's->failed_pc=0x{a:08x}u; return 0;')
        else:
            lines.extend(statements(a)); lines.append(jump(a+2))
    lines.extend(['unsupported: s->failed_pc=target; return 0;','}'])
    def ownership():
        return ['static const uint32_t owned_pcs[]={',*[''.join(f'0x{a:08x}u,' for a in sorted(ops)[i:i+16]) for i in range(0,len(ops),16)], '};',
          f'int {function}_contains(uint32_t pc) {{',
          'pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);',
          'while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }',
          'return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;', '}']
    if split_size and not legacy:
        starts=[i for i,line in enumerate(lines) if re.match(r'^P_[0-9a-f]+:',line)]
        blocks={int(lines[i][2:10],16):lines[i:(starts[j+1] if j+1<len(starts) else len(lines)-2)] for j,i in enumerate(starts)}
        parts=[]; part=[]
        for pc in sorted(blocks):
            # Prefer a return boundary over splitting the middle of a loop.
            if len(part)>=split_size and word(part[-1]-2)==11:
                parts.append(part); part=[]
            part.append(pc)
        if part: parts.append(part)
        head=next(i for i,line in enumerate(lines) if line.startswith(f'int {function}('))
        prefix=lines[:head]; router=['#include "fight/matrix_family.h"']
        output=Path(out)
        for index,pcs in enumerate(parts):
            name=f'{function}_{index}'; owned=set(pcs)
            body=prefix+[f'int {name}(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {{',
              'uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;',
              'dispatch:', 'if(!s->budget--) goto unsupported;', 'switch(target&0x1fffffffu) {',
              *[f'case 0x{pc:08x}u: goto {label(pc)};' for pc in pcs],
              'default: return vf3_matrix_family(target,s,ram);', '}']
            def transfer(match):
                pc=int(match[1],16)
                return match[0] if pc in owned else f'return vf3_matrix_family(0x{pc:08x}u,s,ram);'
            for pc in pcs:
                body.extend(re.sub(r'goto P_([0-9a-f]+);',transfer,line) for line in blocks[pc])
            body+=['unsupported: s->failed_pc=target; return 0;','}']
            write_source(output.with_name(output.stem+f'_{index}.c'), '\n'.join(body)+'\n')
            router.append(f'int {name}(uint32_t,vf3_matrix_state*,const vf3_ram_map*);')
        router+=ownership()+[f'int {function}(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {{',
          f'if(!{function}_contains(entry)) {{ s->failed_pc=entry; return 0; }}', 'uint32_t pc=entry&0x1fffffffu;']
        for index,pcs in enumerate(parts): router.append(f'if(pc<=0x{pcs[-1]:08x}u) return {function}_{index}(entry,s,ram);')
        router+=['s->failed_pc=entry; return 0;','}']
        write_source(output, '\n'.join(router)+'\n')
        print(f'{len(parts)} bounded source modules')
    else:
        if not legacy: lines.extend(ownership())
        write_source(out, '\n'.join(lines)+'\n')
    report={"statements":len(ops),"unsupported":{f"{k:08x}":v for k,v in unsupported.items()},"inputs":[str(d) for d in directories],"foreign_code":{f'{a:08x}':f'{w:04x}' for a,w in foreign.items()}}
    (ROOT/f"extract/analysis/{'matrix' if legacy else function}_adapter_translation.json").write_text(json.dumps(report,indent=1))
    print(f"{len(ops)} guest statements; {len(unsupported)} unsupported instructions")
    for why in list(unsupported.values())[:15]: print(why)

if __name__=="__main__":
    ap=argparse.ArgumentParser(description=__doc__); ap.add_argument('captures',nargs='+')
    ap.add_argument('--out',default='src/fight/matrix_adapters.c')
    ap.add_argument('--watch',help='explicit roots; enables a separate adapter module')
    ap.add_argument('--function',default='vf3_matrix_adapter')
    ap.add_argument('--reuse-matrix',action='store_true')
    ap.add_argument('--split-size',type=int,default=0)
    ap.add_argument('--reuse-adapter',action='append',default=[],help='existing source glob whose PCs dispatch to their current owner')
    a=ap.parse_args()
    generate(a.captures,a.out,a.watch,a.function,a.reuse_matrix,a.split_size,a.reuse_adapter)
