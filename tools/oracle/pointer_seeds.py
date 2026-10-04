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
    regs[15] = ('stack', 0)
    stack_values = {}
    assignments = {}
    words = {}
    allocated = {}
    flags = set()
    counts = set()
    next_page = 0x0c420000

    def stack_offset(expr):
        if expr is None:
            return None
        if expr[0] == 'stack':
            return expr[1]
        if expr[0] == 'add':
            offset = stack_offset(expr[1])
            return None if offset is None else offset + expr[2]
        return None

    def load(expr, offset=0):
        stack = stack_offset(expr)
        if stack is not None:
            return stack_values.get(stack + offset)
        address(expr)
        return ('field', expr, offset) if expr is not None else None

    def store(expr, value, offset=0):
        stack = stack_offset(expr)
        if stack is not None:
            stack_values[stack + offset] = value
        else:
            address(expr)

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
        if top == 14:
            value = (op & 255) - (256 if op & 128 else 0)
            regs[n] = ('literal', value)
        elif top in (9, 13):
            pool = pc + 4 + (op & 255) * 2 if top == 9 else ((pc + 4) & ~3) + (op & 255) * 4
            offset = pool - 0x8c010000
            value = struct.unpack_from('<h' if top == 9 else '<I', image, offset)[0] if 0 <= offset <= len(image) - 4 else 0
            regs[n] = ('literal', value)
        elif top == 7:
            immediate = (op & 255) - (256 if op & 128 else 0)
            if regs.get(n) is not None:
                regs[n] = ('add', regs[n], immediate)
        elif top == 6 and low == 3:
            regs[n] = regs.get(m)
        elif top == 8 and n in (0, 1, 4, 5):
            base = regs.get(m)
            offset = low * (2 if n in (1, 5) else 1)
            if n < 4:
                store(base, regs.get(0), offset)
            else:
                address(base)
                regs[0] = None  # byte/word scalar load
        elif top == 0 and low in (4, 5, 6, 12, 13, 14):
            # Indexed data operands use r0 as a byte offset. Seed an initial
            # r0 index at zero while allocating the actual base argument.
            if regs.get(0) == ('arg', 0):
                assignments[0] = 0
            index = regs.get(0)
            global_base = index is not None and index[0] == 'literal' and 0x0c000000 <= index[1] < 0x10000000
            base = None if global_base else regs.get(m if low >= 12 else n)
            if low >= 12:
                regs[n] = load(base) if low == 14 else None
                address(base)
            else:
                store(base, regs.get(m))
        elif top == 5:
            old = regs.get(m)
            regs[n] = load(old, low * 4)
        elif top == 6 and low in (0, 1, 2, 4, 5, 6):
            old = regs.get(m)
            regs[n] = load(old) if low in (2, 6) else None
            address(old)
            if low in (4, 5, 6) and n != m and old is not None:
                regs[m] = ('add', old, 1 << (low - 4))
        elif top == 1:
            store(regs.get(n), regs.get(m), low * 4)
        elif top == 2 and low in (0, 1, 2, 4, 5, 6):
            if low >= 4 and regs.get(n) is not None:
                regs[n] = ('add', regs[n], -(1 << (low - 4)))
            store(regs.get(n), regs.get(m))
        elif top == 4 and op & 255 in (0x02, 0x12, 0x22, 0x52, 0x62, 0x03):
            if regs.get(n) is not None:
                regs[n] = ('add', regs[n], -4)
            store(regs.get(n), None)
        elif top == 4 and op & 255 in (0x06, 0x16, 0x26, 0x56, 0x66):
            if regs.get(n) is not None:
                regs[n] = ('add', regs[n], 4)
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
        elif top == 15 and low in (6, 7, 8, 9, 10, 11):
            if low in (6, 7) and regs.get(0) == ('arg', 0):
                assignments[0] = 0
            address(regs.get(m if low in (6, 8, 9) else n))
    if mode == 'one':
        # One is a bounded scalar/count and supplies a nonempty one-byte
        # string. Preserve inferred pointers and keep a terminal zero word.
        words = {addr: value if value or addr % 4096 == 252 else 1
                 for addr, value in words.items()}
    if mode == 'open':
        scalar_fields = set()
        for expressions, value in ((flags, 0xffffffff), (counts, 1)):
            for expr in expressions:
                parent = address(expr[1])
                if parent is not None and not expr[2] % 4:
                    addr = parent + expr[2]
                    # Pointer and callback fields retain their inferred type.
                    if not words.get(addr) or addr in scalar_fields:
                        words[addr] = value
                        scalar_fields.add(addr)
    words = {addr: value for addr, value in words.items()
             if not addr % 4 and 0x0c400000 <= addr < 0x0c480000}
    return assignments, words
