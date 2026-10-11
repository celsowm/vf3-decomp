"""Advisory original-image screening; no C coverage is granted by this pilot.

The menu controller records, task descriptors and audio submission queue are
typed RAM inputs. Loaded actors remain at their observed save-state addresses.
Captured outputs are never supplied as fixture values.
"""
import json
from pathlib import Path

from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {
    0x8c0a8370: 0x8c0a8370,
    0x8c0a8f8c: 0x8c0a8f98,
    0x8c09b36c: 0x8c09b37e,
    0x8c09cacc: 0x8c09cada,
    0x8c09bc1c: 0x8c09bc2e,
    0x8c099194: 0x8c0991a2,
    0x8c0993e0: 0x8c0993e8,
    0x8c098c62: 0x8c098c70,
    0x8c099d62: 0x8c099d74,
    0x8c08acc0: 0x8c08acd8,
    0x8c087e04: 0x8c087e1c,
    0x8c08f632: 0x8c08f642,
}


def prepare():
    name = 'coverage_65_batch_screen_dev_v1'
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    memory, registers = {}, {}
    for entry in OWNERS:
        fields = {
            '0xc29bcc0': {'values': [0, 1, 0x80000, 0x80001], 'stride': 8},
            '0xc29bccc': {'values': [0, 0x20000, 0x800, 0x40000000], 'stride': 4},
            '0xc29b870': {'values': [0, 1, 64], 'stride': 4},
            '0xc29ba30': {'values': [0, 1], 'stride': 1},
            '0xc2cf83c': {'values': [0, 16, 32, 64, 128, 4, 2, 8]},
            '0xc2cf844': {'values': [0, 8, 0x400], 'stride': 3},
            '0xc2cf850': {'values': [0, 32, 16], 'stride': 2},
            '0xc2cf858': {'values': [0, 8], 'stride': 2},
            '0xc19e218': 0xc450000, '0xc450000': 0, '0xc450004': 0,
            '0xc29bb94': 0xc1fefe4, '0xc29bb98': 0xc20138c,
        }
        for i, offset in enumerate((12, 24, 28, 48, 52, 56, 60, 64, 80, 84, 116)):
            address = 0xc460000 + i * 0x1000
            fields[hex(0xc29bb84 + offset)] = address
            fields[hex(address)] = {'values': [0, 1, 3], 'stride': 2}
        for offset, values in {
            0x1f0: [0, 1, 2, 3], 0x1f4: [0, 5, 6], 0x1f8: [0, 1],
            0x208: [0, 1, 2, 3, 4, 5], 0x220: [0, 11],
            0x2d4: [0, 1, 30], 0x2d8: [0, 1, 2, 3],
            0x2dc: [0, 1, 171], 0x2e0: [0, 1, 219], 0x2e4: [0, 1, 30],
        }.items():
            fields[hex(0xc29b864 + offset)] = {'values': values, 'stride': 2}
        if entry == 0x8c0a8f8c:
            registers[hex(entry)] = {'r4': 0xc404000, 'r5': 0xc1fefe4}
            fields.update({'0xc404020': 0, '0xc404024': [1, 2, 3],
                           '0xc404004': [0, 0x3f800000, 0xbf800000],
                           '0xc404008': 0, '0xc40400c': 0,
                           '0xc1ff020': 0, '0xc200f9c': [1, 2, 3]})
        else:
            registers[hex(entry)] = {'r4': 0xc400000}
        memory[hex(entry)] = fields
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (ROOT / f'tools/oracle/percentage_inputs/{name}_{suffix}.json').write_text(
            json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, 64,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
