"""Screen remaining scene and UI candidates in loaded original states.

True prefixes are taken from the original register-save prologues. Writable
descriptors and control state are inputs; nested helper returns are untouched.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c097aa4: 0x8c097abc, 0x8c096342: 0x8c09635a,
          0x8c096afc: 0x8c096b0a, 0x8c0972c4: 0x8c0972d2,
          0x8c08230c: 0x8c08231c, 0x8c0831ea: 0x8c0831f8,
          0x8c0a1642: 0x8c0a1658}


def prepare():
    name = 'coverage_65_batch_expand_dev_v2'
    directory = ROOT / 'tools/oracle/percentage_inputs'
    prior = json.loads((directory / 'coverage_65_batch_screen_dev_v2_memory.json').read_text())
    base = prior['0x8c0a8370']
    memory, registers = {}, {}
    count = 64
    for entry in OWNERS:
        fields = dict(base)
        fields.update({
            '0xc29b864': {'values': [0, 0x10000000, 0x30000000, 0xc0000000], 'stride': 16},
            '0xc29b868': {'values': [0, 0x100000, 0x700000], 'stride': 8},
            '0xc29bcc0': [0, 1, 0x20000, 0x20001],
            '0xc29bccc': {'values': [0, 0x20000, 0x800, 0x40000000], 'stride': 8},
            '0xc2cf83c': [0, 4, 8, 16, 32, 64, 128, 0x400],
            '0xc2cf850': [0x400, 128, 64, 32, 16, 8, 4, 0],
            '0xc2cf844': [0, 0x606, 8, 0x60e],
            '0xc2cf858': [0x60e, 8, 0x606, 0],
            '0xc2cf834': {'values': [0, 0x7ff, 0xf06fe], 'stride': 8},
            '0xc2cf848': {'values': [0xf06fe, 0x7ff, 0], 'stride': 8},
            '0xc29c158': [0, 1, 2, 255],
            '0xc29bb80': {'values': [0, 0x100], 'stride': 16},  # mode +0x31d
            '0xc29ba60': [0, 1, 9, 12], '0xc29ba64': [12, 9, 1, 0],
            '0xc29ba00': [0, 1, 2, 3], '0xc29ba04': [0, 1, 2, 3],
            '0xc29ba08': [0, 1, 2, 3],
        })
        # Extra original task-table fields used by the pause/scene routines.
        for index, offset in enumerate((32, 36, 40, 44, 72, 92)):
            address = 0xc480000 + index*0x1000
            fields[hex(0xc29bb84 + offset)] = address
            fields[hex(address)] = [0, 1, 3, 8]
            fields[hex(address + 12)] = 0
        memory[hex(entry)] = fields
        registers[hex(entry)] = {'r4': 0xc400000, 'r5': 0xc404000}
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
