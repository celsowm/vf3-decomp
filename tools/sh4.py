#!/usr/bin/env python3
"""Complete SH-4 (SH7750) decoder — pure python, no capstone.

Why: capstone's SH backend silently drops the whole 0xF FP space
(fmov.s/fipr/ftrv/fmac/fldcx...), and Ghidra's flow listing has holes
inside seed-fragmented fight bodies. This decoder covers the full ISA:
integer, branches, system (ldc/stc/lds/sts incl. FPSCR/FPUL), and all
single-precision FP forms the game uses.

API:
    decode(word, pc) -> (mnemonic, op_str)  or None if illegal
    disasm(data, base, start, n)  -> linear sweep iterator yielding
        dict(addr, word, text, delay, lit_addr, lit_val, branch...)
"""
import struct

REPO = __import__("os").path.dirname(__import__("os").path.dirname(
    __import__("os").path.abspath(__file__)))

GPR = [f"r{i}" for i in range(16)]
FR = [f"fr{i}" for i in range(16)]


def _s8(v):
    return v - 256 if v & 0x80 else v


def _s12(v):
    return v - 4096 if v & 0x800 else v


def decode(w, pc=0):
    """Decode one 16-bit word at address pc. Returns (mnemonic, op_str)."""
    n = (w >> 8) & 0xF
    m = (w >> 4) & 0xF
    d8 = w & 0xFF
    d4 = w & 0xF
    top = (w >> 12) & 0xF

    if top == 0x0:
        if w == 0x0009:
            return "nop", ""
        if w == 0x000B:
            return "rts", ""
        if w == 0x002B:
            return "rte", ""
        if w == 0x0008:
            return "clrt", ""
        if w == 0x0018:
            return "sett", ""
        if w == 0x0028:
            return "clrmac", ""
        if w == 0x0019:
            return "div0u", ""
        if w == 0x001B:
            return "sleep", ""
        if w == 0x00AB:
            return "synco", ""
        if w == 0x00FB:
            return "ldtlb", ""
        if (w & 0xF0FF) == 0x0029:
            return "movt", GPR[n]
        if (w & 0xF0FF) == 0x0002:
            return "stc", f"sr,{GPR[n]}"
        if (w & 0xF0FF) == 0x0012:
            return "stc", f"gbr,{GPR[n]}"
        if (w & 0xF0FF) == 0x0022:
            return "stc", f"vbr,{GPR[n]}"
        if (w & 0xF0FF) == 0x0032:
            return "stc", f"ssr,{GPR[n]}"
        if (w & 0xF0FF) == 0x0042:
            return "stc", f"spc,{GPR[n]}"
        if (w & 0xF0FF) == 0x003A:
            return "stc", f"sgr,{GPR[n]}"
        if (w & 0xF0FF) == 0x000A:
            return "sts", f"mach,{GPR[n]}"
        if (w & 0xF0FF) == 0x001A:
            return "sts", f"macl,{GPR[n]}"
        if (w & 0xF0FF) == 0x002A:
            return "sts", f"pr,{GPR[n]}"
        if (w & 0xF0FF) == 0x005A:
            return "sts", f"fpul,{GPR[n]}"
        if (w & 0xF0FF) == 0x006A:
            return "sts", f"fpscr,{GPR[n]}"
        if (w & 0xF0FF) == 0x0023:
            return "braf", GPR[m]
        if (w & 0xF0FF) == 0x0003:
            return "bsrf", GPR[m]
        if (w & 0xF0FF) == 0x0083:
            return "pref", f"@{GPR[n]}"
        if (w & 0xF0FF) == 0x0093:
            return "ocbi", f"@{GPR[n]}"
        if (w & 0xF0FF) == 0x00A3:
            return "ocbp", f"@{GPR[n]}"
        if (w & 0xF0FF) == 0x00B3:
            return "ocbwb", f"@{GPR[n]}"
        if (w & 0xF0FF) == 0x00E3:
            return "icbi", f"@{GPR[n]}"
        if (w & 0xF08F) == 0x0082:
            bank = (w >> 4) & 7
            return "stc", f"r{bank}_bank,{GPR[n]}"
        if d4 == 0x4:
            return "mov.b", f"{GPR[m]},@(r0,{GPR[n]})"
        if d4 == 0x5:
            return "mov.w", f"{GPR[m]},@(r0,{GPR[n]})"
        if d4 == 0x6:
            return "mov.l", f"{GPR[m]},@(r0,{GPR[n]})"
        if d4 == 0xC:
            return "mov.b", f"@(r0,{GPR[m]}),{GPR[n]}"
        if d4 == 0xD:
            return "mov.w", f"@(r0,{GPR[m]}),{GPR[n]}"
        if d4 == 0xE:
            return "mov.l", f"@(r0,{GPR[m]}),{GPR[n]}"
        if d4 == 0x7:
            return "mul.l", f"{GPR[m]},{GPR[n]}"
        if d4 == 0xF:
            return "mac.l", f"@{GPR[m]}+,@{GPR[n]}+"
        return None

    if top == 0x1:
        return "mov.l", f"{GPR[m]},@({d4*4},{GPR[n]})"

    if top == 0x2:
        tbl = {0x0: ("mov.b", f"{GPR[m]},@{GPR[n]}"),
               0x1: ("mov.w", f"{GPR[m]},@{GPR[n]}"),
               0x2: ("mov.l", f"{GPR[m]},@{GPR[n]}"),
               0x4: ("mov.b", f"{GPR[m]},@-{GPR[n]}"),
               0x5: ("mov.w", f"{GPR[m]},@-{GPR[n]}"),
               0x6: ("mov.l", f"{GPR[m]},@-{GPR[n]}"),
               0x7: ("div0s", f"{GPR[m]},{GPR[n]}"),
               0x8: ("tst", f"{GPR[m]},{GPR[n]}"),
               0x9: ("and", f"{GPR[m]},{GPR[n]}"),
               0xA: ("xor", f"{GPR[m]},{GPR[n]}"),
               0xB: ("or", f"{GPR[m]},{GPR[n]}"),
               0xC: ("cmp/str", f"{GPR[m]},{GPR[n]}"),
               0xD: ("xtrct", f"{GPR[m]},{GPR[n]}"),
               0xE: ("mulu.w", f"{GPR[m]},{GPR[n]}"),
               0xF: ("muls.w", f"{GPR[m]},{GPR[n]}")}
        return tbl.get(d4)

    if top == 0x3:
        tbl = {0x0: "cmp/eq", 0x2: "cmp/hs", 0x3: "cmp/ge", 0x4: "div1",
               0x5: "dmulu.l", 0x6: "cmp/hi", 0x7: "cmp/gt", 0x8: "sub",
               0xA: "subc", 0xB: "subv", 0xC: "add", 0xD: "dmuls.l",
               0xE: "addc", 0xF: "addv"}
        if d4 in tbl:
            return tbl[d4], f"{GPR[m]},{GPR[n]}"
        return None

    if top == 0x4:
        if (w & 0xF0FF) == 0x400B:
            return "jsr", f"@{GPR[m]}"
        if (w & 0xF0FF) == 0x402B:
            return "jmp", f"@{GPR[m]}"
        if (w & 0xF0FF) == 0x400E:
            return "ldc", f"{GPR[m]},sr"
        if (w & 0xF0FF) == 0x401E:
            return "ldc", f"{GPR[m]},gbr"
        if (w & 0xF0FF) == 0x402E:
            return "ldc", f"{GPR[m]},vbr"
        if (w & 0xF0FF) == 0x403E:
            return "ldc", f"{GPR[m]},ssr"
        if (w & 0xF0FF) == 0x404E:
            return "ldc", f"{GPR[m]},spc"
        if (w & 0xF0FF) == 0x403A:
            return "ldc", f"{GPR[m]},sgr"
        if (w & 0xF08F) == 0x408E:
            bank = (w >> 4) & 7
            return "ldc", f"{GPR[m]},r{bank}_bank"
        if (w & 0xF0FF) == 0x4007:
            return "ldc.l", f"@{GPR[m]}+,sr"
        if (w & 0xF0FF) == 0x4017:
            return "ldc.l", f"@{GPR[m]}+,gbr"
        if (w & 0xF0FF) == 0x4027:
            return "ldc.l", f"@{GPR[m]}+,vbr"
        if (w & 0xF0FF) == 0x4037:
            return "ldc.l", f"@{GPR[m]}+,ssr"
        if (w & 0xF0FF) == 0x4047:
            return "ldc.l", f"@{GPR[m]}+,spc"
        if (w & 0xF0FF) == 0x4003:
            return "stc.l", f"sr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4013:
            return "stc.l", f"gbr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4023:
            return "stc.l", f"vbr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4033:
            return "stc.l", f"ssr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4043:
            return "stc.l", f"spc,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4032:
            return "stc.l", f"sgr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x400A:
            return "lds", f"{GPR[m]},mach"
        if (w & 0xF0FF) == 0x401A:
            return "lds", f"{GPR[m]},macl"
        if (w & 0xF0FF) == 0x402A:
            return "lds", f"{GPR[m]},pr"
        if (w & 0xF0FF) == 0x405A:
            return "lds", f"{GPR[m]},fpul"
        if (w & 0xF0FF) == 0x406A:
            return "lds", f"{GPR[m]},fpscr"
        if (w & 0xF0FF) == 0x4006:
            return "lds.l", f"@{GPR[n]}+,mach"
        if (w & 0xF0FF) == 0x4016:
            return "lds.l", f"@{GPR[n]}+,macl"
        if (w & 0xF0FF) == 0x4026:
            return "lds.l", f"@{GPR[n]}+,pr"
        if (w & 0xF0FF) == 0x4056:
            return "lds.l", f"@{GPR[n]}+,fpul"
        if (w & 0xF0FF) == 0x4066:
            return "lds.l", f"@{GPR[n]}+,fpscr"
        if (w & 0xF0FF) == 0x4002:
            return "sts.l", f"mach,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4012:
            return "sts.l", f"macl,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4022:
            return "sts.l", f"pr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4052:
            return "sts.l", f"fpul,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4062:
            return "sts.l", f"fpscr,@-{GPR[n]}"
        if (w & 0xF0FF) == 0x4000:
            return "shll", GPR[n]
        if (w & 0xF0FF) == 0x4001:
            return "shlr", GPR[n]
        if (w & 0xF0FF) == 0x4004:
            return "rotl", GPR[n]
        if (w & 0xF0FF) == 0x4005:
            return "rotr", GPR[n]
        if (w & 0xF0FF) == 0x4008:
            return "shll2", GPR[n]
        if (w & 0xF0FF) == 0x4009:
            return "shlr2", GPR[n]
        if (w & 0xF0FF) == 0x4018:
            return "shll8", GPR[n]
        if (w & 0xF0FF) == 0x4019:
            return "shlr8", GPR[n]
        if (w & 0xF0FF) == 0x4020:
            return "shal", GPR[n]
        if (w & 0xF0FF) == 0x4021:
            return "shar", GPR[n]
        if (w & 0xF0FF) == 0x4024:
            return "rotcl", GPR[n]
        if (w & 0xF0FF) == 0x4025:
            return "rotcr", GPR[n]
        if (w & 0xF0FF) == 0x4028:
            return "shll16", GPR[n]
        if (w & 0xF0FF) == 0x4029:
            return "shlr16", GPR[n]
        if (w & 0xF0FF) == 0x401B:
            return "tas.b", f"@{GPR[n]}"
        if (w & 0xF00F) == 0x400C:
            return "shad", f"{GPR[m]},{GPR[n]}"
        if (w & 0xF00F) == 0x400D:
            return "shld", f"{GPR[m]},{GPR[n]}"
        if (w & 0xF00F) == 0x400F:
            return "mac.w", f"@{GPR[m]}+,@{GPR[n]}+"
        return None

    if top == 0x5:
        return "mov.l", f"@({d4*4},{GPR[m]}),{GPR[n]}"

    if top == 0x6:
        tbl = {0x0: ("mov.b", f"@{GPR[m]},{GPR[n]}"),
               0x1: ("mov.w", f"@{GPR[m]},{GPR[n]}"),
               0x2: ("mov.l", f"@{GPR[m]},{GPR[n]}"),
               0x3: ("mov", f"{GPR[m]},{GPR[n]}"),
               0x4: ("mov.b", f"@{GPR[m]}+,{GPR[n]}"),
               0x5: ("mov.w", f"@{GPR[m]}+,{GPR[n]}"),
               0x6: ("mov.l", f"@{GPR[m]}+,{GPR[n]}"),
               0x7: ("not", f"{GPR[m]},{GPR[n]}"),
               0x8: ("swap.b", f"{GPR[m]},{GPR[n]}"),
               0x9: ("swap.w", f"{GPR[m]},{GPR[n]}"),
               0xA: ("negc", f"{GPR[m]},{GPR[n]}"),
               0xB: ("neg", f"{GPR[m]},{GPR[n]}"),
               0xC: ("extu.b", f"{GPR[m]},{GPR[n]}"),
               0xD: ("extu.w", f"{GPR[m]},{GPR[n]}"),
               0xE: ("exts.b", f"{GPR[m]},{GPR[n]}"),
               0xF: ("exts.w", f"{GPR[m]},{GPR[n]}")}
        return tbl.get(d4)

    if top == 0x7:
        return "add", f"#{_s8(d8)},{GPR[n]}"

    if top == 0x8:
        if (w & 0xFF00) == 0x8800:
            return "cmp/eq", f"#{_s8(d8)},r0"
        if (w & 0xFF00) == 0x8900:
            return "bt", f"0x{pc + 4 + _s8(d8) * 2:08x}"
        if (w & 0xFF00) == 0x8B00:
            return "bf", f"0x{pc + 4 + _s8(d8) * 2:08x}"
        if (w & 0xFF00) == 0x8D00:
            return "bt/s", f"0x{pc + 4 + _s8(d8) * 2:08x}"
        if (w & 0xFF00) == 0x8F00:
            return "bf/s", f"0x{pc + 4 + _s8(d8) * 2:08x}"
        if (w & 0xFF00) == 0x8000:
            return "mov.b", f"r0,@({d4},{GPR[m]})"
        if (w & 0xFF00) == 0x8100:
            return "mov.w", f"r0,@({d4*2},{GPR[m]})"
        if (w & 0xFF00) == 0x8400:
            return "mov.b", f"@({d4},{GPR[m]}),r0"
        if (w & 0xFF00) == 0x8500:
            return "mov.w", f"@({d4*2},{GPR[m]}),r0"
        return None

    if top == 0x9:
        return "mov.w", f"@({d8*2},pc),{GPR[n]}" ,  # lit addr pc+4+d8*2

    if top == 0xA:
        return "bra", f"0x{pc + 4 + _s12(w & 0xFFF) * 2:08x}"

    if top == 0xB:
        return "bsr", f"0x{pc + 4 + _s12(w & 0xFFF) * 2:08x}"

    if top == 0xC:
        if (w & 0xFF00) == 0xC000:
            return "mov.b", f"r0,@({d8},gbr)"
        if (w & 0xFF00) == 0xC100:
            return "mov.w", f"r0,@({d8*2},gbr)"
        if (w & 0xFF00) == 0xC200:
            return "mov.l", f"r0,@({d8*4},gbr)"
        if (w & 0xFF00) == 0xC300:
            return "trapa", f"#{d8}"
        if (w & 0xFF00) == 0xC400:
            return "mov.b", f"@({d8},gbr),r0"
        if (w & 0xFF00) == 0xC500:
            return "mov.w", f"@({d8*2},gbr),r0"
        if (w & 0xFF00) == 0xC600:
            return "mov.l", f"@({d8*4},gbr),r0"
        if (w & 0xFF00) == 0xC700:
            return "mova", f"@({d8*4},pc),r0"
        if (w & 0xFF00) == 0xC800:
            return "tst", f"#{d8},r0"
        if (w & 0xFF00) == 0xC900:
            return "and", f"#{d8},r0"
        if (w & 0xFF00) == 0xCA00:
            return "xor", f"#{d8},r0"
        if (w & 0xFF00) == 0xCB00:
            return "or", f"#{d8},r0"
        if (w & 0xFF00) == 0xCC00:
            return "tst.b", f"#{d8},@(r0,gbr)"
        if (w & 0xFF00) == 0xCD00:
            return "and.b", f"#{d8},@(r0,gbr)"
        if (w & 0xFF00) == 0xCE00:
            return "xor.b", f"#{d8},@(r0,gbr)"
        if (w & 0xFF00) == 0xCF00:
            return "or.b", f"#{d8},@(r0,gbr)"
        return None

    if top == 0xD:
        return "mov.l", f"@({d8*4},pc),{GPR[n]}"  # lit addr (pc&~3)+4+d8*4

    if top == 0xE:
        return "mov", f"#{_s8(d8)},{GPR[n]}"

    if top == 0xF:
        if w == 0xFBFD:
            return "frchg", ""
        if w == 0xF3FD:
            return "fschg", ""
        if (w & 0xF0FF) == 0xF08D:
            return "fldi0", FR[n]
        if (w & 0xF0FF) == 0xF09D:
            return "fldi1", FR[n]
        if (w & 0xF0FF) == 0xF04D:
            return "fneg", FR[n]
        if (w & 0xF0FF) == 0xF05D:
            return "fabs", FR[n]
        if (w & 0xF0FF) == 0xF06D:
            return "fsqrt", FR[n]
        if (w & 0xF0FF) == 0xF02D:
            return "float", f"fpul,{FR[n]}"
        if (w & 0xF0FF) == 0xF03D:
            return "ftrc", f"{FR[n]},fpul"
        if (w & 0xF0FF) == 0xF01D:
            return "flds", f"{FR[n]},fpul"
        if (w & 0xF0FF) == 0xF00D:
            return "fsts", f"fpul,{FR[n]}"
        if (w & 0xF1FF) == 0xF0BD:
            return "fcnvds", f"dr{n & 0xE},fpul"
        if (w & 0xF1FF) == 0xF0AD:
            return "fcnvsd", f"fpul,dr{n & 0xE}"
        if (w & 0xF3FF) == 0xF1FD:
            # ftrv xmtrx,FVn: idx = bits[11:10], group = idx*4
            return "ftrv", f"xmtrx,fv{((w >> 10) & 3) * 4}"
        if (w & 0xF33F) == 0xF0ED:
            # fipr FVm,FVn: idx n=bits[11:10], m=bits[7:6], group = idx*4
            vn = ((w >> 10) & 3) * 4
            vm = ((w >> 6) & 3) * 4
            return "fipr", f"fv{vm},fv{vn}"
        if (w & 0xF00F) == 0xF000:
            return "fadd", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF001:
            return "fsub", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF002:
            return "fmul", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF003:
            return "fdiv", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF004:
            return "fcmp/eq", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF005:
            return "fcmp/gt", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF006:
            return "fmov.s", f"@(r0,{GPR[m]}),{FR[n]}"
        if (w & 0xF00F) == 0xF007:
            return "fmov.s", f"{FR[m]},@(r0,{GPR[n]})"
        if (w & 0xF00F) == 0xF008:
            return "fmov.s", f"@{GPR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF009:
            return "fmov.s", f"@{GPR[m]}+,{FR[n]}"
        if (w & 0xF00F) == 0xF00A:
            return "fmov.s", f"{FR[m]},@{GPR[n]}"
        if (w & 0xF00F) == 0xF00B:
            return "fmov.s", f"{FR[m]},@-{GPR[n]}"
        if (w & 0xF00F) == 0xF00C:
            return "fmov", f"{FR[m]},{FR[n]}"
        if (w & 0xF00F) == 0xF00E:
            return "fmac", f"fr0,{FR[m]},{FR[n]}"
        return None
    return None


BRANCHY = {"bf/s", "bf", "bt", "bt/s", "braf", "bra", "bsr", "bsrf",
           "jmp", "jsr", "rts", "rte"}


def disasm(data, base, start, n):
    """Linear sweep. Yields dict per instruction word."""
    off = start - base
    i = 0
    delay = False
    while i < n and 0 <= off + 1 < len(data):
        w = struct.unpack_from("<H", data, off)[0]
        pc = base + off
        dec = decode(w, pc)
        rec = {"addr": pc, "word": w, "delay": delay}
        if dec:
            mn, ops = dec
            rec["text"] = f"{mn} {ops}".strip()
            # literal annotation
            if mn in ("mov.l", "mov.w") and "pc" in ops:
                if mn == "mov.l":
                    lat = ((pc & ~3) + 4 + (w & 0xFF) * 4)
                    sz = 4
                else:
                    lat = (pc + 4 + (w & 0xFF) * 2)
                    sz = 2
                lo = lat - base
                if 0 <= lo + sz <= len(data):
                    rec["lit_addr"] = lat
                    rec["lit_val"] = struct.unpack_from(
                        "<I" if sz == 4 else "<H", data, lo)[0]
            delay = (not delay) and (mn in BRANCHY)
        else:
            rec["text"] = f".word 0x{w:04x}"
            rec["delay_next"] = False
            delay = False
        off += 2
        i += 1
        yield rec
