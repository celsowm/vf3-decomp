"""Infer bounded pointer fixtures from original integer load/store operands.

This produces inputs, never expected outputs. A successful original interpreter
capture and strict C replay are still required for every candidate.
"""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def fixture(entry, mode='zero'):
    from sys import path
    path.insert(0, str(ROOT / 'tools'))
    from batch_plan import implementation_graph
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    pcs, _, _ = implementation_graph(image, {})(entry)
    regs = {n: ('arg', n) for n in range(15)}
    assignments = {}
    words = {}
    allocated = {}
    flags = set()
    counts = set()
    next_page = 0x0c420000

    def address(expr):
        nonlocal next_page
        if expr is None:
            return None
        kind = expr[0]
        if kind == 'arg':
            n = expr[1]
            addr = 0x0c400000 + n * 4096
            assignments[n] = addr
        elif kind == 'add':
            base = address(expr[1])
            return None if base is None else base + expr[2]
        elif kind == 'field':
            parent = address(expr[1])
            if parent is None or not 0x0c400000 <= parent + expr[2] < 0x0c480000:
                return None
            if expr not in allocated:
                if next_page >= 0x0c480000:
                    return None
                allocated[expr] = next_page
                next_page += 4096
            addr = allocated[expr]
            words[parent + expr[2]] = addr
        else:
            return None
        for off in range(0, 256, 4):
            words.setdefault(addr + off, 0)
        return addr

    def callback(expr):
        if expr is None:
            return
        if expr[0] == 'arg':
            assignments[expr[1]] = 0x0c0671aa  # existing verified RTS/NOP leaf
        elif expr[0] == 'field':
            parent = address(expr[1])
            if parent is not None and not expr[2] % 4:
                words[parent + expr[2]] = 0x0c0671aa

    for pc in sorted(pcs):
        if not 0x8c010000 <= pc < 0x8c010000 + len(image) - 1:
            continue
        op = struct.unpack_from('<H', image, pc - 0x8c010000)[0]
        n, m, top, low = (op >> 8) & 15, (op >> 4) & 15, op >> 12, op & 15
        if top == 14 or top in (9, 13):
            regs[n] = None
        elif top == 7:
            immediate = (op & 255) - (256 if op & 128 else 0)
            if regs.get(n) is not None:
                regs[n] = ('add', regs[n], immediate)
        elif top == 6 and low == 3:
            regs[n] = regs.get(m)
        elif top == 5:
            old = regs.get(m)
            address(old)
            regs[n] = ('field', old, low * 4) if old is not None else None
        elif top == 6 and low in (0, 1, 2, 4, 5, 6):
            old = regs.get(m)
            address(old)
            regs[n] = ('field', old, 0) if old is not None and low in (2, 6) else None
            if low in (4, 5, 6) and n != m and old is not None:
                regs[m] = ('add', old, 1 << (low - 4))
        elif top == 1:
            address(regs.get(n))
        elif top == 2 and low in (0, 1, 2, 4, 5, 6):
            address(regs.get(n))
        elif op & 0xf0ff in (0x400b, 0x402b):
            callback(regs.get(n))
        elif top == 2 and low == 8:
            flags.update(expr for expr in (regs.get(n), regs.get(m))
                         if expr is not None and expr[0] == 'field')
        elif top == 12 and (op >> 8) & 15 == 8:
            expr = regs.get(0)
            if expr is not None and expr[0] == 'field':
                flags.add(expr)
        elif top == 4 and op & 255 == 0x10:
            expr = regs.get(n)
            if expr is not None and expr[0] == 'field':
                counts.add(expr)
        elif top == 15 and low in (8, 9, 10, 11):
            address(regs.get(m if low in (8, 9) else n))
    if mode == 'open':
        for expressions, value in ((flags, 0xffffffff), (counts, 1)):
            for expr in expressions:
                parent = address(expr[1])
                if parent is not None and not expr[2] % 4:
                    addr = parent + expr[2]
                    # Pointer and callback fields retain their inferred type.
                    if not words.get(addr):
                        words[addr] = value
    words = {addr: value for addr, value in words.items()
             if not addr % 4 and 0x0c400000 <= addr < 0x0c480000}
    return assignments, words
