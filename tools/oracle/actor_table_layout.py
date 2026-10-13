"""Extract semantic setter lists from four straight-line original wrappers.

This analysis emits constant command/field maps, not opcode execution code.
It fails on any instruction outside the known wrapper grammar.
"""
import argparse
import json
from pathlib import Path
import struct
from actor_table_inputs import OWNERS, EXTRA_OWNERS, ROOT


def layout(entry):
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    def word(pc):
        return struct.unpack_from('<H', image, pc-0x8c010000)[0]
    def signed(v, bits):
        return v-(1<<bits) if v & (1<<(bits-1)) else v
    command = offset = None
    r0 = None
    changed_r0 = False
    targets = {}
    tail_target = tail_register = None
    rows, visited = [], set()
    pc = entry
    def instruction(pc):
        nonlocal command, offset, r0, changed_r0
        w = word(pc)
        visited.add(pc)
        if w & 0xff00 in (0x9400, 0x9000):
            value = signed(word(pc+4+2*(w & 255)), 16)
            if w & 0xff00 == 0x9400:
                command = value
            else:
                r0 = value
                changed_r0 = True
        elif w & 0xff00 in (0xe400, 0xe000):
            value = signed(w & 255, 8)
            if w & 0xff00 == 0xe400:
                command = value
            else:
                r0 = value
                changed_r0 = True
        elif w & 0xfff0 == 0x55e0:
            offset = 4*(w & 15)
        elif w == 0x65e2:
            offset = 0
        elif w == 0x05ee:
            assert changed_r0 and r0 is not None
            offset = r0
        elif w == 0x65e3:
            offset = 0
        elif w & 0xff00 == 0x7500:
            offset += signed(w & 255, 8)
        elif w & 0xff00 in (0xd200, 0xd300):
            pool = ((pc+4) & ~3)+4*(w & 255)
            targets[(w >> 8) & 15] = struct.unpack_from('<I', image, pool-0x8c010000)[0] | 0x80000000
        elif w in (0x6552, 0x2fe6, 0x5e44, 0x4f22, 0x4f26, 0x6ef6, 9):
            pass
        else:
            raise ValueError(f'unsupported wrapper word {pc:#x}: {w:#x}')
    while True:
        assert pc not in visited, 'unexpected loop in table wrapper'
        w = word(pc)
        if w >> 12 in (10, 11) or w & 0xf0ff in (0x400b, 0x402b):
            register = (w >> 8) & 15 if w >> 12 == 4 else None
            target = targets[register] if register is not None else pc+4+signed(w & 4095, 12)*2
            call = w >> 12 == 11 or w & 0xf0ff == 0x400b
            visited.add(pc)
            instruction(pc+2)
            if target == 0x8c0a2e06:
                assert command is not None and offset is not None
                rows.append(dict(command=command, field_offset=offset,
                    r0_value=r0 if changed_r0 else None,
                    return_pc=pc+4 if call else None,
                    helper_register=register))
                changed_r0 = False
                targets.clear()
                if not call:
                    break
                pc += 4
            elif target == 0x8c095178:
                assert not call
                tail_target, tail_register = target, register
                break
            else:
                assert w >> 12 == 10, 'unexpected called dependency'
                pc = target
        else:
            instruction(pc)
            pc += 2
    pointer_refs = []
    for alias in (entry, entry & 0x1fffffff):
        needle = struct.pack('<I', alias)
        start = 0
        while (found := image.find(needle, start)) >= 0:
            if not found % 4:
                pointer_refs.append(hex(0x8c010000 + found))
            start = found+1
    records = []
    for slot in pointer_refs:
        slot = int(slot, 16)
        base = slot - 28
        assert (base - 0x8c10def0) % 36 == 0
        records.append(dict(index=(base-0x8c10def0)//36, address=hex(base),
                            words=[hex(struct.unpack_from('<I', image, base-0x8c010000+4*i)[0])
                                   for i in range(9)]))
    return dict(entry=hex(entry), owner=hex({**OWNERS, **EXTRA_OWNERS}[entry]), pointer_refs=pointer_refs,
                original_resource_records=records,
                tail_target=hex(tail_target) if tail_target else None, tail_register=tail_register,
                wrapper_instructions=len(visited), rows=rows)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--extra', action='store_true')
    args = parser.parse_args()
    if args.out.exists():
        raise FileExistsError(args.out)
    result = [layout(entry) for entry in (EXTRA_OWNERS if args.extra else OWNERS)]
    args.out.write_text(json.dumps(result, indent=2)+'\n')
    for item in result:
        print(item['entry'], len(item['rows']), 'setters', item['wrapper_instructions'], 'wrapper instructions')
        print('  original pointer slots:', ', '.join(item['pointer_refs']))
        print('  resource records:', item['original_resource_records'])
