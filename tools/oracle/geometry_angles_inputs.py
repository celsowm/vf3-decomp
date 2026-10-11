"""Typed finite actor geometry; the interpreter supplies every expected result."""
import json
import struct
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
ENTRY = '0x8c0ca8c0'


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    for holdout, label in [(False, 'dev'), (True, 'accept')]:
        actor = 0x0c510000 if holdout else 0x0c410000
        angles = [0, 0x4000, 0x8000, 0xc000, 1, 0x7fff, 0x8001, 0xffff]
        if holdout:
            angles = [0xc000, 0x8000, 0x4000, 0, 2, 0x7ffe, 0x8002, 0xfffe]
        palette = [0.0, 0.00001, 0.5, 1.0, 3.0, -1.0, 10.0, -3.0]
        if holdout:
            palette = [0.0, 0.00002, 0.75, 1.25, 4.0, -1.25, 12.0, -4.0]
        memory = {ENTRY: {
            hex(actor+0x1394): [angles[i % 8] for i in range(64)],
            hex(actor+0x430): [bits(palette[i//8]) for i in range(64)],
            hex(actor+0x438): [bits(palette[(i//8+i) % 8]) for i in range(64)],
        }}
        registers = {ENTRY: {'r4': actor}}
        name = f'coverage_65_geometry_angles_{label}_v1'
        for kind, data in [('memory', memory), ('registers', registers)]:
            (ROOT / f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data, indent=2)+'\n')
        generate(ROOT / 'tools/oracle/coverage_65_geometry_angles_watch_v1.txt',
                 ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, 64,
                 relocation=0x100000 if holdout else 0,
                 fpscr=0x240001 if holdout else 0x40001,
                 bounded_arguments=True, preserve_fields=True, holdout_inputs=holdout,
                 memory_overrides=memory, register_overrides=registers)


if __name__ == '__main__':
    prepare()
