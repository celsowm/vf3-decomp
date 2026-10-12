"""Screen original RAM strip parents; inputs only, with no coverage credit.

The immutable parent tables select their real attribute writers. R12 remains
an inherited RAM stream, and both clipping and winding branches are exercised
through bounded vertex inputs. No code, pools or callback returns are patched.
"""
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {entry: entry+2 for entry in (0x8c0570e0, 0x8c057480,
          0x8c057860, 0x8c057c60, 0x8c057fa0)}


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    name = 'coverage_65_strip_parent_screen_v2'
    count = 192
    memory, registers = {}, {}
    for entry in OWNERS:
        fields = {'0xc055b80': {'values': [0, 1], 'stride': 32},
                  '0xc055b8c': {'values': [0, 1], 'stride': 16},
                  '0xc16b8b8': 0xc460000, '0xc460000': 0xc440000,
                  '0xc16b840': 0, '0xc400000': 0,
                  # One strip followed by its signed vertex count.
                  '0xc400004': [(1 | ((n if i%2 == 0 else -n)&65535)<<16)
                                  for i in range(count)
                                  for n in [1+i//2%5]]}
        stride = 6 if entry in (0x8c057480, 0x8c057c60) else 10 if entry == 0x8c057fa0 else 2
        # The original parent advances over per-index attribute words.
        packed = bytearray(64)
        for index in range(6):
            struct.pack_into('<H', packed, index*stride, index)
            if stride >= 6:
                struct.pack_into('<I', packed, index*stride+2, bits((index+1)/8))
            if stride == 10:
                struct.pack_into('<I', packed, index*stride+6, bits((index+1)/16))
        for offset in range(0, 64, 4):
            fields[hex(0xc400008+offset)] = struct.unpack_from('<I', packed, offset)[0]
        for index in range(8):
            base = 0xc430000+16*index
            fields[hex(base)] = bits([-1, 1, 0, 2, -2, 0, 1, -1][index])
            fields[hex(base+4)] = {'values': [bits(index%3), bits(-(index%3))], 'stride': 8}
            fields[hex(base+8)] = {'values': [bits(v) for v in (0.25, 0.75, 2, -0.25)], 'stride': 2**(index%3), 'phase': index}
            fields[hex(base+12)] = bits(1)
            fields[hex(0xc440000+8*index)] = bits((index+1)/16)
            fields[hex(0xc440004+8*index)] = bits(1)
        memory[hex(entry)] = fields
        registers[hex(entry)] = {'r4': 0xc400000, 'r10': bits(1),
            'r12': 0xc450000, 'r13': 0xc430000, 'fr3': bits(1/256)}
    watch = ROOT/f'tools/oracle/{name}_watch.txt'
    patch = ROOT/f'extract/analysis/{name}.patch'
    paths = [watch, ROOT/f'tools/oracle/{name}_owners.json']
    paths += [ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json' for kind in ('memory', 'registers')]
    assert not any(path.exists() for path in [*paths, patch]), 'refuse to overwrite screening evidence'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    for path, value in zip(paths[1:], ({hex(a): hex(b) for a, b in OWNERS.items()}, memory, registers)):
        path.write_text(json.dumps(value, indent=2)+'\n')
    generate(watch, patch, 0x8c0432e2, count, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
