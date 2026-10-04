"""Infer bounded pointer fixtures from original integer load/store operands.

This produces inputs, never expected outputs. A successful original interpreter
capture and strict C replay are still required for every candidate.
"""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def fixture(entry, mode='zero', global_fields=False, metadata=False):
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
    narrow_fields = {}
    scalar_reads = set()
    float_reads = set()
    flag_masks = {}
    next_page = 0x0c420000
    data_floor = 0x0c010000 + len(image)

    def writable(addr):
        return 0x0c400000 <= addr < 0x0c480000 or (global_fields and data_floor <= addr < 0x0c400000)

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
        parent = address(expr)
        if parent is not None and writable(parent + offset):
            words.setdefault((parent + offset) & ~3, 0)
            scalar_reads.add((parent + offset) & ~3)
        return ('field', expr, offset) if expr is not None else None

    def narrow(expr, offset, size):
        parent = address(expr)
        if parent is None or not writable(parent + offset):
            return
        addr = parent + offset
        base = addr & ~3
        words.setdefault(base, 0)
        narrow_fields[base] = narrow_fields.get(base, 0) | (1 << ((addr & 3) * 8))

    def flag(expr, mask):
        while expr is not None and expr[0] == 'shift':
            shift = expr[2]
            mask = mask >> shift if shift >= 0 else mask << -shift
            expr = expr[1]
        if expr is None or expr[0] != 'field':
            return
        parent = address(expr[1])
        if parent is not None and writable(parent + expr[2]):
            addr = parent + expr[2]
            words.setdefault(addr & ~3, 0)
            flag_masks.setdefault(addr & ~3, set()).add(mask & 0xffffffff)

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
        elif kind == 'literal':
            # Only infer fields in mutable RAM beyond the loaded image. Keep
            # other live global words intact; rollback restores seeded fields.
            addr = expr[1] & 0x1fffffff
            return addr if global_fields and data_floor <= addr < 0x0c400000 else None
        elif kind == 'add':
            base = address(expr[1])
            return None if base is None else base + expr[2]
        elif kind == 'field':
            parent = address(expr[1])
            if parent is None or not writable(parent + expr[2]):
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
                regs[n] = ('literal', regs[n][1] + immediate) if regs[n][0] == 'literal' else ('add', regs[n], immediate)
        elif top == 3 and low == 12:
            left, right = regs.get(n), regs.get(m)
            if left is not None and right is not None:
                if left[0] == right[0] == 'literal':
                    regs[n] = ('literal', (left[1] + right[1]) & 0xffffffff)
                elif right[0] == 'literal':
                    regs[n] = ('add', left, right[1])
                elif left[0] == 'literal':
                    regs[n] = ('add', right, left[1])
                else:
                    regs[n] = None
            else:
                regs[n] = None
        elif top == 4 and op & 255 in (0, 1, 8, 9, 0x18, 0x19, 0x28, 0x29):
            shifts = {0: 1, 1: -1, 8: 2, 9: -2, 0x18: 8, 0x19: -8, 0x28: 16, 0x29: -16}
            shift = shifts[op & 255]
            value = regs.get(n)
            if value is not None:
                regs[n] = ('literal', ((value[1] << shift) if shift > 0 else ((value[1] & 0xffffffff) >> -shift)) & 0xffffffff) if value[0] == 'literal' else ('shift', value, shift)
        elif top == 6 and low == 3:
            regs[n] = regs.get(m)
        elif top == 8 and n in (0, 1, 4, 5):
            base = regs.get(m)
            offset = low * (2 if n in (1, 5) else 1)
            if n < 4:
                store(base, regs.get(0), offset)
            else:
                address(base)
                narrow(base, offset, 2 if n == 5 else 1)
                regs[0] = None  # byte/word scalar load
        elif top == 0 and low in (4, 5, 6, 12, 13, 14):
            # Indexed data operands use r0 as a byte offset. Seed an initial
            # r0 index at zero while allocating the actual base argument.
            if regs.get(0) == ('arg', 0):
                assignments[0] = 0
            index = regs.get(0)
            global_base = index is not None and index[0] == 'literal' and 0x0c000000 <= index[1] < 0x10000000
            operand = regs.get(m if low >= 12 else n)
            if global_base and operand is not None and operand[0] == 'literal':
                # Indexed operands add both registers. The address literal may
                # be in r0 and the small displacement in the other register.
                base, offset = index, operand[1]
            else:
                base = None if global_base else operand
                offset = index[1] if index is not None and index[0] == 'literal' and not global_base else 0
            if low >= 12:
                regs[n] = load(base, offset) if low == 14 else None
                if low != 14:
                    narrow(base, offset, 1 << (low - 12))
                address(base)
            else:
                store(base, regs.get(m))
        elif top == 5:
            old = regs.get(m)
            regs[n] = load(old, low * 4)
        elif top == 6 and low in (0, 1, 2, 4, 5, 6):
            old = regs.get(m)
            regs[n] = load(old) if low in (2, 6) else None
            if low in (0, 1, 4, 5):
                narrow(old, 0, 1 << (low if low < 4 else low - 4))
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
            if regs.get(n) == regs.get(m) and regs.get(n) is not None and regs[n][0] == 'shift':
                flag(regs[n], 0xffffffff)
            flags.update(expr for expr in (regs.get(n), regs.get(m))
                         if expr is not None and expr[0] == 'field')
            for source, other in ((regs.get(n), regs.get(m)), (regs.get(m), regs.get(n))):
                if other is not None and other[0] == 'literal':
                    flag(source, other[1])
        elif top == 12 and (op >> 8) & 15 == 8:
            expr = regs.get(0)
            if expr is not None and expr[0] == 'field':
                flags.add(expr)
                flag(expr, op & 255)
        elif top == 4 and op & 255 == 0x10:
            expr = regs.get(n)
            if expr is not None and expr[0] == 'field':
                counts.add(expr)
        elif top == 15 and low in (6, 7, 8, 9, 10, 11):
            if low in (6, 7) and regs.get(0) == ('arg', 0):
                assignments[0] = 0
            base = regs.get(m if low in (6, 8, 9) else n)
            parent = address(base)
            index = regs.get(0)
            offset = index[1] if low in (6, 7) and index is not None and index[0] == 'literal' else 0
            if parent is not None and low in (6, 8, 9) and writable(parent + offset):
                words.setdefault((parent + offset) & ~3, 0)
                float_reads.add((parent + offset) & ~3)
            if base is not None and low == 9:
                regs[m] = ('add', base, 4)
            elif base is not None and low == 11:
                regs[n] = ('add', base, -4)
    if mode == 'one':
        # One is a bounded scalar/count and supplies a nonempty one-byte
        # string. Preserve inferred pointers and keep a terminal zero word.
        words = {addr: value if value or addr % 4096 == 252 else narrow_fields.get(addr, 1)
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
             if not addr % 4 and writable(addr)}
    if metadata:
        count_fields = []
        for expr in counts:
            parent = address(expr[1])
            if parent is not None and writable(parent + expr[2]):
                count_fields.append((parent + expr[2]) & ~3)
        return assignments, words, dict(scalars=sorted(scalar_reads),
            narrow=narrow_fields, floats=sorted(float_reads),
            flags={addr: sorted(masks) for addr, masks in flag_masks.items()},
            counts=sorted(count_fields))
    return assignments, words
