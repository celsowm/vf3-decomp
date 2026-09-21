#!/usr/bin/env python3
"""tools/braf_tables.py -- enumerate SH-4 BRAF/@Rn switch tables.

Heuristics ported from refs/DreamcastRecompiled/src/common/function_analysis.cpp
(discover_byte_jump_table / discover_word_jump_table /
discover_absolute_jump_table), implemented over capstone SH-4 disassembly.

Requires: tools/.venv with capstone (SH-4 support).

Usage:
  tools/.venv/Scripts/python tools/braf_tables.py [bin]
Writes extract/analysis/braf_tables.csv + a short summary.
"""
from __future__ import annotations

import csv
import re
import struct
import sys
from pathlib import Path

from capstone import CS_ARCH_SH, CS_MODE_LITTLE_ENDIAN, CS_MODE_SH4, Cs

BASE = 0x8C010000

md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_LITTLE_ENDIAN)


def text_kind(i):
    m = i.mnemonic
    ops = i.op_str
    return m, ops


def parse_reg(s: str):
    s = s.strip()
    if re.fullmatch(r"r\d+", s):
        return int(s[1:])
    return None


class Code:
    def __init__(self, data: bytes):
        self.d = data
        self.cache: dict[int, object] = {}

    def ins(self, addr: int):
        if addr in self.cache:
            return self.cache[addr]
        o = addr - BASE
        if not (0 <= o <= len(self.d) - 2):
            self.cache[addr] = None
            return None
        ins = next(md.disasm(self.d[o:o + 2], addr), None)
        self.cache[addr] = ins
        return ins

    def u16(self, addr):
        o = addr - BASE
        return self.d[o] | (self.d[o + 1] << 8) if 0 <= o < len(self.d) - 1 else 0

    def u32(self, addr):
        o = addr - BASE
        return struct.unpack_from("<I", self.d, o)[0] if 0 <= o <= len(self.d) - 4 else 0


BLOCK_END = {"bra", "bsr", "brf", "braf", "rts", "jmp", "jsr", "rte"}
WRITERS = {"mov", "mov.b", "mov.w", "mov.l", "add", "sub", "xor", "or", "and",
           "shll", "shll2", "shll8", "shll16", "shlr", "shlr2", "shlr8",
           "shlr16", "extu.b", "extu.w", "exts.b", "exts.w", "swap.b",
           "swap.w", "xtrct", "dt", "mova", "lds", "lds.l", "fmov"}


def dst_reg(i):
    """For writers, return destination GPR if simple, else None."""
    ops = [x.strip() for x in i.op_str.split(",")]
    if i.mnemonic in ("mov.l", "mov.w", "mov.b"):
        dst = ops[-1] if i.mnemonic != "mov.l" or True else ops[1]
        # indexed load: mov.l @(r0,rX),rY -> dst = rY
        if len(ops) == 2 and ops[0].startswith("@"):
            return parse_reg(ops[1])
        return parse_reg(ops[-1])
    if i.mnemonic == "mov":
        return parse_reg(ops[1]) if len(ops) == 2 else None
    if i.mnemonic.startswith(("extu", "exts", "swap", "shl", "shr")):
        return parse_reg(ops[1]) if len(ops) == 2 else parse_reg(ops[0])
    if i.mnemonic in ("add", "sub", "xor", "or", "and", "xtrct"):
        return parse_reg(ops[1]) if len(ops) == 2 else parse_reg(ops[0])
    if i.mnemonic in ("dt",):
        return parse_reg(ops[0])
    if i.mnemonic == "mova":
        return 0
    return None


WRITECAPS = ("mov", "add", "sub", "xor", "or", "and", "xtrct", "dt")


def writes_reg(i, r):
    d = dst_reg(i)
    return d == r


def is_capped_blob(d: bytes) -> None:
    pass


def back_scan(code: Code, start: int, stop: int):
    a = start - 2
    while a >= stop:
        i = code.ins(a)
        if i is None:
            a -= 2
            continue
        yield a, i
        a -= 2


def find_bound_reg_feeder(code: Code, block_start: int, bound_reg: int):
    """Backward to find mov #imm,rBound (imm literal)."""
    for a, i in back_scan(code, block_start - block_start and block_start, block_start - 48):
        m, ops = i.mnemonic, i.op_str
        if m == "mov" and f"r{bound_reg}" == ops.split(",")[1].strip():
            first = ops.split(",")[0].strip()
            if first.startswith("#"):
                try:
                    imm = int(first[1:], 10)
                except ValueError:
                    imm = int(first[1:], 16)
                if 0 <= imm < 1024:
                    return imm
            return None
        if writes_reg(i, bound_reg) or m in BLOCK_END:
            return None
    return None


def bra_addr_of(i):
    return int(i.address)


IDX_RE = re.compile(r"@\(r0,\s*(r\d+)\s*\),\s*(r\d+)")


def scan_braf(code: Code, braf):
    """BRAF Rn discovered; try byte-then-word table resolution."""
    addr = braf.address
    rn = None
    m = re.fullmatch(r"r(\d+)", braf.op_str.strip())
    if not m:
        return None
    rn = int(m.group(1))

    # --- find the table-load mov.b/w @(r0,rX),rn feeding the BRAF ----------
    load = None
    load_addr = 0
    kind = None
    zero_ext = False
    stop = max(BASE + 2, addr - 20)
    for a, i in back_scan(code, addr, stop):
        if i.mnemonic == "extu.b":
            ops = [x.strip() for x in i.op_str.split(",")]
            if len(ops) == 2 and ops[0] == f"r{rn}" and ops[1] == f"r{rn}":
                zero_ext = True
                continue
        if i.mnemonic in ("mov.b", "mov.w"):
            mm = IDX_RE.search(i.op_str)
            if mm and mm.group(2) == f"r{rn}":
                load = i
                load_addr = a
                kind = "byte" if i.mnemonic == "mov.b" else "word"
                break
        if i.mnemonic == "add":
            ops = [x.strip() for x in i.op_str.split(",")]
            if len(ops) == 2 and ops[0] == f"r{rn}" and ops[1] == f"r{rn}":
                continue
        if writes_reg(i, rn):
            break
        if i.mnemonic in BLOCK_END:
            return None
    if not load:
        return None

    # --- find the table base (mova -> r0 | mov.l lit,rN -> vaddr) ----------
    mm_idx = IDX_RE.search(load.op_str)
    base_reg = int(mm_idx.group(1)[1:]) if mm_idx else None
    table = None
    stop = max(BASE + 2, load_addr - 32)
    for a, i in back_scan(code, load_addr, stop):
        if i.mnemonic == "mova":
            table = code.u32(a)  # placeholder; patched below via op_str
            mm = re.search(r"(0x[0-9a-fA-F]+)", i.op_str)
            if mm:
                table = int(mm.group(1), 16)
                break
        if i.mnemonic == "mov.l" and "@" not in i.op_str.split(",")[0]:
            # mov.l @(disp,PC),rN literal load -- capstone prints absolute addr
            ops = [x.strip() for x in i.op_str.split(",")]
            if len(ops) == 2:
                src, dst = ops
                lit_addr = None
                mm = re.search(r"(0x[0-9a-fA-F]+)", src)
                if mm:
                    lit_addr = int(mm.group(1), 16)
                if lit_addr:
                    v = code.u32(lit_addr)
                    if BASE <= v < BASE + len(code.d):
                        if base_reg is not None and dst == f"r{base_reg}":
                            table = v
                            break
                        # also accept literal loaded into r0 (base via @(r0,rn))
                        if dst == "r0":
                            table = v
                            break
        if i.mnemonic in BLOCK_END:
            break
    if table is None or not (BASE <= table < BASE + len(code.d)):
        return None

    # --- find count via cmp/hs or cmp/hi with mov #imm,rBound --------------
    # use the index register from the load (r0 indexed with rm)
    idx_reg = base_reg if base_reg is not None else rn
    count = None
    stop = max(BASE + 2, addr - 512)
    for a, i in back_scan(code, addr, stop):
        if i.mnemonic in ("cmp/hs", "cmp/hi"):
            ops = [x.strip() for x in i.op_str.split(",")]
            if len(ops) == 2 and f"r{idx_reg}" in (ops[0], ops[1]):
                other = ops[1] if ops[0] == f"r{idx_reg}" else ops[0]
                bo = parse_reg(other)
                if bo is None:
                    continue
                imm = None
                for a2, i2 in back_scan(code, a, max(BASE + 2, a - 48)):
                    if i2.mnemonic == "mov":
                        ops2 = [x.strip() for x in i2.op_str.split(",")]
                        if len(ops2) == 2 and ops2[1] == f"r{bo}" and ops2[0].startswith("#"):
                            try:
                                imm = int(ops2[0][1:], 10)
                            except ValueError:
                                try:
                                    imm = int(ops2[0][1:], 16)
                                except ValueError:
                                    imm = None
                            break
                    if writes_reg(i2, bo) or i2.mnemonic in BLOCK_END:
                        break
                if imm is not None and 0 <= imm < 1024:
                    count = imm if i.mnemonic == "cmp/hs" else imm + 1
                    break
        if i.mnemonic in ("bra", "bsr", "rts", "jmp", "jsr", "braf"):
            break

    max_count = 128 if kind == "byte" else 4096
    targets = []
    fallback = False
    limit = count if count else 64            # fallback: sentinel-walk
    if not count:
        fallback = True
    for n in range(min(limit, max_count)):
        if kind == "byte":
            o = table - BASE + n
            if not (0 <= o < len(code.d)):
                break
            raw = code.d[o]
            delta = raw if zero_ext else (raw - 256 if raw >= 128 else raw)
        else:
            raw = code.u16(table + n * 2)
            delta = raw - 65536 if raw & 0x8000 else raw
        t = (addr + 4 + delta) & 0xFFFFFFFF
        if t & 1 or not (BASE <= t < BASE + len(code.d)):
            if count:
                continue
            break
        if t not in targets:
            targets.append(t)
        elif not count:
            break
    if fallback:
        count = count or len(targets)
    if not targets:
        return None
    return {"site": f"0x{addr:08X}", "kind": kind + ("?" if fallback else ""),
            "count": count or 0, "table": f"0x{table:08X}",
            "n_targets": len(targets),
            "targets": ";".join(f"0x{t:08X}" for t in targets)}


def scan_jsr_jmp(code: Code, site):
    """jsr/jmp @rN preceded by mov.l @(r0,rN),rN -> dense absolute table."""
    addr = site.address
    rn = parse_reg(site.op_str.replace("@", "").strip())
    if rn is None:
        return None
    stop = max(BASE + 2, addr - 16)
    table_load = None
    for a, i in back_scan(code, addr, stop):
        if i.mnemonic == "mov.l":
            mm = IDX_RE.search(i.op_str)
            if mm and mm.group(2) == f"r{rn}":
                table_load = a
                break
        if writes_reg(i, rn):
            return None
        if i.mnemonic in BLOCK_END:
            return None
    # find table base: mov.l lit,rX with vaddr value
    if table_load is None:
        return None
    table = None
    for a, i in back_scan(code, table_load, max(BASE + 2, table_load - 32)):
        if i.mnemonic == "mov.l" and "@" in (i.op_str.split(",")[0]):
            mm = re.search(r"(0x[0-9a-fA-F]+)", i.op_str)
            if mm:
                v = code.u32(int(mm.group(1), 16))
                if BASE <= v < BASE + len(code.d):
                    table = v
                    break
        if i.mnemonic in BLOCK_END:
            break
    if table is None:
        return None
    targets = []
    p = table
    while p <= table + 0x800:
        v = code.u32(p)
        if BASE <= v < BASE + len(code.d):
            if v not in targets:
                targets.append(v)
                p += 4
                continue
            break
        break
    if len(targets) < 2:
        return None
    return {"site": f"0x{addr:08X}", "kind": "abs32", "count": len(targets),
            "table": f"0x{table:08X}", "n_targets": len(targets),
            "targets": ";".join(f"0x{t:08X}" for t in targets)}


def main() -> int:
    args = [a for a in sys.argv[1:]]
    bin_path = args[0] if args and not args[0].startswith("--") else \
        "extract/exe/1ST_READ.unsc.bin"
    data = Path(bin_path).read_bytes()
    code = Code(data)

    results, jsr_jmp_results = [], []
    n_half = (len(data) - 1) // 2
    for off in range(0, len(data) - 1, 2):
        addr = off + BASE
        i = code.ins(addr)
        if i is None:
            continue
        if i.mnemonic == "braf":
            r = scan_braf(code, i)
            if r:
                results.append(r)
        elif i.mnemonic in ("jsr", "jmp") and i.op_str.strip().startswith("@"):
            r = scan_jsr_jmp(code, i)
            if r:
                jsr_jmp_results.append(r)

    out_csv = Path("extract/analysis/braf_tables.csv")
    out_csv.parent.mkdir(parents=True, exist_ok=True)
    with out_csv.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["site", "kind", "count", "table",
                                          "n_targets", "targets"])
        w.writeheader()
        w.writerows(results + jsr_jmp_results)
    by_kind = {}
    for r in results + jsr_jmp_results:
        by_kind[r["kind"]] = by_kind.get(r["kind"], 0) + 1
    print(f"scanned {n_half:,} halfwords")
    print(f"resolved {len(results)} braf + {len(jsr_jmp_results)} jsr/jmp "
          f"table sites: {by_kind}")
    print(f"wrote {out_csv}")
    for r in (results + jsr_jmp_results)[:12]:
        print(" ", r["site"], r["kind"], "table", r["table"], "n=",
              r["n_targets"])
    return 0


if __name__ == "__main__":
    main()
