#!/usr/bin/env python3
"""SH-4 clean disassembly of 1ST_READ regions (uses tools/.venv capstone).

Linear-sweep from a start address; every mov.l @(disp,PC) / mov.w @(disp,PC)
gets its literal pool target resolved and the 4-byte value shown inline.
Branches and delayed slots both printed (delay slot line prefixed '_').

Usage (venv python only):
  tools/.venv/Scripts/python tools/sh4dump.py <addr_hex> [n_instructions]
  tools/.venv/Scripts/python tools/sh4dump.py f 8c058e92 200
"""
import os
import re
import struct
import sys

from capstone import CS_ARCH_SH, CS_MODE_SH4, CS_MODE_LITTLE_ENDIAN, Cs

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMG = os.path.join(REPO, "extract", "exe", "1ST_READ.unsc.bin")
BASE = 0x8C010000


def load():
    with open(IMG, "rb") as f:
        return f.read()


BRANCH = re.compile(r"^(bf/s|bf|bt|bt/s|braf|bra|bsr|bsrf|jmp|jsr|rts|rte)")

def descend(data, entry, max_blocks=60):
    """Recursive-sweep disasm: follows bsr/bra/bt/bf; tries to resolve
    jsr/jmp @rN through fresh literal loads in the same block."""
    from collections import deque
    seen_labels = {}          # addr -> label idx
    queue = deque([entry])
    out = {}                  # addr -> decoded line dicts
    def label_for(a):
        if a not in seen_labels:
            seen_labels[a] = len(seen_labels)
        return f"L{seen_labels[a]:03d}"
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)
    literal_regs = {}
    while queue and len(seen_labels) < max_blocks:
        start = queue.popleft()
        if start in out:
            continue
        pc = start
        literal_regs = {}
        delay = False
        visited_start = pc
        while True:
            if pc in out:   # ran into already-emitted block: tail-merge
                break
            if pc - visited_start > 0x400:
                break
            waddr = pc - BASE
            if waddr < 0 or waddr + 2 > len(data):
                break
            chunk = data[waddr:waddr + 2]
            ins = list(md.disasm(chunk, pc))
            if not ins:
                out[pc] = ("data", f".word 0x{int.from_bytes(chunk,'little'):04x}")
                pc += 2
                if not delay:
                    continue
                delay = False
                continue
            i = ins[0]
            txt = f"{i.mnemonic} {i.op_str}".strip()
            note = ""
            # literal-pool annotation (capstone renders absolute)
            m = re.match(r"mov\.([lw])\s+(0x[0-9a-f]+),\s*(r\d+)", txt)
            if m:
                lit = int(m.group(2), 16)
                o = lit - BASE
                if 0 <= o < len(data):
                    if m.group(1) == "l":
                        v = struct.unpack_from("<I", data, o)[0]
                        note = f"   # lit={v:08x}"
                        literal_regs[m.group(3)] = v
                    else:
                        v = struct.unpack_from("<H", data, o)[0]
                        note = f"   # lit.w={v:04x}"
                        literal_regs[m.group(3)] = v
            m2 = re.match(r"(jsr|jmp)\s+@(r\d+)", txt)
            target_label = ""
            if m2:
                tgt = literal_regs.get(m2.group(2))
                if tgt and BASE <= tgt < BASE + len(data):
                    note += f"   # -> {tgt:08x}"
                    if tgt in out or True:
                        lbl = label_for(tgt)
                        note += f" {lbl}?"
                        queue.append(tgt)
            # mark targets of static branches
            b = re.match(r"(bf/s|bf|bt|bt/s|bra|bsr)\s+(0x[0-9a-f]+)", txt)
            if b:
                tgt = int(b.group(2), 16)
                lbl = label_for(tgt)
                note += f"   # -> {lbl}"
                queue.append(tgt)
                if b.group(1) in ("bra",):
                    terminal = "bra"
                elif b.group(1) in ("bsr",):
                    terminal = "call"
                else:
                    terminal = "cond"
            else:
                terminal = None
            delay_prefix = "" if not delay else "_"
            out[pc] = ("insn", f"{delay_prefix}{txt}{note}")
            pc += 2
            if delay:
                delay = False
            elif i.mnemonic in ("rts", "jmp"):
                break
            elif b and b.group(1) in ("bra", "bsr", "bf/s", "bt/s"):
                delay = True
            elif b and b.group(1) in ("bf", "bt"):
                # non-delayed short branches: continue fall-through
                pass
    return out, seen_labels


def main():
    args = sys.argv[1:]
    if args and args[0] == "f":
        args = args[1:]
    if args and args[0] == "c":          # cfg mode
        entry = int(args[1], 16)
        mb = int(args[2]) if len(args) > 2 else 60
        data = load()
        out, labels = descend(data, entry, mb)
        for a in sorted(out):
            if a in labels:
                print(f"{a:08x}:  ; --- L{labels[a]:03d} ---")
            print(f"{a:08x}  {out[a][1]}")
        # label mapping footer
        print("\nlabels:")
        for a, i in labels.items():
            print(f"  L{i:03d} = 0x{a:08x}")
        return
    addr = int(args[0], 16)
    n = int(args[1]) if len(args) > 1 else 60
    data = load()

    md = Cs(CS_ARCH := 0x0, 0)  # placeholder; replaced below
    from capstone import CS_ARCH_SH
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)
    md.detail = False

    code = data[addr - BASE:]
    off = 0
    shown = 0
    delay_next = False
    while shown < n and off + 2 <= len(code):
        chunk = code[off:off + 2]
        insns = list(md.disasm(chunk, addr + off))
        if not insns:
            print(f"{addr + off:08x}  {int.from_bytes(chunk, 'little'):04x}    .word")
            off += 2
            continue
        i = insns[0]
        txt = f"{i.mnemonic} {i.op_str}".strip()
        note = ""
        # capstone renders pc-relative literal loads as absolute addresses
        import re
        m = re.match(r"mov\.([lw])\s+(0x[0-9a-f]+),\s*(r\d+)", txt)
        if m:
            w = m.group(1)
            lit = int(m.group(2), 16)
            offimg = lit - BASE
            if 0 <= offimg < len(data):
                if w == "l":
                    val = struct.unpack_from("<I", data, offimg)[0]
                    note = f"  # lit={val:08x}"
                else:
                    val = struct.unpack_from("<H", data, offimg)[0]
                    note = f"  # lit.w={val:04x}"
        # jsr/bsrf-style resolved targets: annotate name from funcs csv if given
        tag = "_" if delay_next else ""
        print(f"{addr + off:08x}  {int.from_bytes(chunk, 'little'):04x}    {tag}{txt}{note}")
        shown += 1
        off += 2
        # delay slot tracking: branch-class mnemonics take effect next slot
        branchy = i.mnemonic.startswith(("bra", "bsr", "bf", "bt", "jmp", "jsr", "rts", "rte")) or i.mnemonic.endswith("/s")
        delay_next = branchy and not delay_next
        if delay_next and i.mnemonic in ("rts", "jmp", "bra") and shown:
            pass


if __name__ == "__main__":
    main()
