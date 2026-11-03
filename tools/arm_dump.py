#!/usr/bin/env python3
"""Minimal ARM7TDMI (ARM32) disassembler for the SNDDRV.BIN AICA firmware.

PCs in the ARM trace are byte offsets into SNDDRV.BIN (the firmware blob the
guest uploads to AICA RAM at 0x00800000).  This decoder reads those ranges.
Good enough to read control flow, loads/stores and branches around the
melody scheduler sites (0x0fe4 ADSR pass, 0x0fdc gate, 0x264c key-on,
0x5dac songstep counter).
"""
import sys

COND = ["eq","ne","cs","cc","mi","pl","vs","vc","hi","ls","ge","lt","gt","le","",   "nv"][:16]
DP =  {0:"and",1:"eor",2:"sub",3:"rsb",4:"add",5:"adc",6:"sbc",7:"rsc",
       8:"tst",9:"teq",10:"cmp",11:"cmn",12:"orr",13:"mov",14:"bic",15:"mvn"}
SH = {0:"lsl",1:"lsr",2:"asr",3:"ror"}


def disasm(bits, addr):
    cond = bits >> 28
    conds = CONST_COND[cond] if False else None
    # --- branches ---
    if (bits & 0x0F000000) == 0x0A000000:
        off = bits & 0x00FFFFFF
        if off & 0x800000: off -= 0x1000000
        tgt = addr + 8 + off*4
        op = "bl" if (bits>>24)&1 else "b"
        return f"{op} 0x{tgt:08x}"
    # --- data processing ---
    if (bits & 0x0C000000) == 0x00000000:
        op = DP[(bits>>21)&0xF]
        setf = (bits>>20)&1
        rn = (bits>>16)&0xF
        rd = (bits>>12)&0xF
        s = "s" if setf else ""
        if (bits & 0x02000000):  # immediate
            rot = ((bits>>8)&0xF)*2
            imm = bits & 0xFF
            imm = ((imm >> rot) | (imm << (32-rot))) & 0xFFFFFFFF if rot else imm
            if op in ("mov","mvn"):
                return f"{op}{s} r{rd}, #0x{imm:x}"
            if op in ("tst","teq","cmp","cmn"):
                return f"{op}{s} r{rn}, #0x{imm:x}"
            return f"{op}{s} r{rd}, r{rn}, #0x{imm:x}"
        else:  # register
            rm = bits & 0xF
            if bits & 0x10:  # register shift
                rs = (bits>>8)&0xF
                sh = SH[(bits>>5)&0x3]
                if (bits>>6)&1: sh += "r" if False else ""
                if op in ("mov","mvn"):
                    return f"{op}{s} r{rd}, r{rm}, {sh} r{rs}"
                return f"{op}{s} r{rd}, r{rn}, r{rm}, {sh} r{rs}"
            else:
                shv = (bits>>7)&0x1F
                sh = SH[(bits>>5)&0x3]
                imm5 = f", #{shv}" if shv else ""
                if op in ("mov","mvn"):
                    return f"{op}{s} r{rd}, r{rm}{((', '+sh+str(imm5)) if (bits&0x380) else '')}"
                if op in ("tst","teq","cmp","cmn"):
                    return f"{op}{s} r{rn}, r{rm}"
                return f"{op}{s} r{rd}, r{rn}, r{rm}"
    # --- loads/stores ---
    if (bits & 0x0C000000) == 0x04000000:
        p = (bits>>24)&1; u=(bits>>23)&1; b=(bits>>22)&1; w=(bits>>21)&1; l=(bits>>20)&1
        rn = (bits>>16)&0xF; rd = (bits>>12)&0xF
        addr = "r%d"%rn
        pre = "!" if (p and w) else ""
        if bits & 0x02000000:  # immediate offset
            off = bits & 0xFFF
            if not u: off = -off
            if p:
                mem = f"[r{rn}, #{off}]{pre}" if off else f"[r{rn}]"
            else:
                mem = f"[r{rn}], #{off}"
            if not p and w: mem = f"[r{rn}], #{off}"
        else:  # register offset
            rm = bits & 0xF
            if p:
                mem = f"[r{rn}, r{rm}]"
            else:
                mem = f"[r{rn}], r{rm}"
        t = "b" if b else ""
        m = "ldr%st" % t if l else "str%st" % t
        return f"{m} r{rd}, {mem}"
    # --- LDM/STM ---
    if (bits & 0x0C000000) == 0x08000000:
        p=(bits>>24)&1;u=(bits>>23)&1;s=(bits>>22)&1;w=(bits>>21)&1;l=(bits>>20)&1
        rn=(bits>>16)&0xF; regs=bits&0xFFFF
        lst=[f"r{i}" for i in range(16) if regs&(1<<i)]
        mode = "ia"
        m = "ldm" if l else "stm"
        return f"{m}f{rn}{mode} {{{','.join(lst)}}}"
    # --- multiply ---
    if (bits & 0x0FC000F0) == 0x00000090:
        pass
    # --- misc ---
    return f".word 0x{bits:08x}"

CONST_COND = ["eq","ne","cs","cc","mi","pl","vs","vc","hi","ls","ge","lt","gt","le","al"]


def main():
    data = open("extract/gamedata/SNDDRV.BIN","rb").read()
    for arg in sys.argv[1:]:
        if "-" in arg:
            lo, hi = (int(x,0) for x in arg.split("-"))
        else:
            lo = int(arg,0); hi = lo+0x40
        print(f"=== {lo:#x} .. {hi:#x} ===")
        for a in range(lo, hi, 4):
            if a+4 > len(data): break
            bits = int.from_bytes(data[a:a+4], "little")
            print(f"  {a:08x}: {bits:08x}  {disasm(bits, a)}")


if __name__ == "__main__":
    main()
