"""Original clipping kernels with typed RAM vertex/output streams.

R12 is the inherited writable output cursor, not an altered literal PVR
address. PREF executes against RAM. This screens RAM behavior only, with
neither device coverage nor SDK-identification credit. Caller proof remains
required. The two extra R10/R9 saves belong to the callable prefixes: their
matching extra pops are present immediately before each original RTS.
"""
import json
import struct
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c05152c: 0x8c05156a, 0x8c051918: 0x8c051956,
          0x8c051c2c: 0x8c051c6a, 0x8c051f50: 0x8c051f8e,
          0x8c05228c: 0x8c0522ca, 0x8c0525c0: 0x8c0525fe,
          0x8c05291c: 0x8c05295a, 0x8c052c34: 0x8c052c72}


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    name = 'coverage_65_batch_clip_dev_v1'
    directory = ROOT / 'tools/oracle/percentage_inputs'
    memory, registers = {}, {}
    count = 64
    for entry in OWNERS:
        fields = {'0xc055b8c': {'values': [0, 1], 'stride': 32}}
        # Packed strip indices, with bounded following texture-coordinate words.
        for index in range(8):
            fields[hex(0xc400000 + index*4)] = (2*index) | ((2*index+1) << 16)
        # Interpolated scalar attributes are indexed at MACL + 8*vertex.
        for index in range(16):
            fields[hex(0xc440000 + index*8)] = bits((index+1)/16)
            fields[hex(0xc440004 + index*8)] = bits(1)
        # Frame +100 is saved R8, the parent's packed strip cursor.
        regs = {'r8': 0xc400000, 'r4': [i % 8 for i in range(count)],
                'r12': 0xc450000, 'macl': 0xc440000, 'fr3': bits(1/256)}
        # Three distinct vertices; vary clip classification independently.
        for vertex in range(3):
            start = 4 + 4*vertex
            regs[f'fr{start}'] = bits([-1, 1, 0][vertex])
            regs[f'fr{start+1}'] = bits([0, 0, 1][vertex])
            regs[f'fr{start+2}'] = [bits(value) for value in
                                      ([0.25+vertex/4, 1+vertex/2, 4+vertex] * 21 + [1])]
            regs[f'fr{start+3}'] = bits(1)
        memory[hex(entry)] = fields
        registers[hex(entry)] = regs
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (directory / f'{name}_{suffix}.json').write_text(json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
