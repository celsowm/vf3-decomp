"""Cross the observed character-selection and controller-menu boundaries.

The first expansion completed in both original states but missed selector,
button, timer and particle-age combinations. All values here are inputs;
original tables, callbacks and expected architectural outputs remain intact.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c09c1de: 0x8c09c1f4, 0x8c0c3210: 0x8c0c321e,
          0x8c08984c: 0x8c089864, 0x8c098b3c: 0x8c098b40}


def prepare():
    name = 'coverage_65_selection_boundary_dev_v1'
    prefix = ROOT / 'tools/oracle/percentage_inputs/coverage_65_batch_expand_dev_v1'
    old = json.loads(Path(str(prefix) + '_memory.json').read_text())
    old_regs = json.loads(Path(str(prefix) + '_registers.json').read_text())
    memory, registers = {}, {}
    count = 256
    buttons = [0, 4, 8, 12, 16, 32, 64, 128, 0x100, 0x200, 0x400, 0x7ff]
    for entry in OWNERS:
        key = hex(entry)
        fields = dict(old[key])
        fields['0xc29bcc0'] = [0 if i % 32 else 0x80001 for i in range(count)]
        fields['0xc29b864'] = 0
        fields['0xc2cf834'] = [0 if i % 32 else 0xfffffffe for i in range(count)]
        fields['0xc2cf848'] = [0 if i % 64 else 0xfffffffe for i in range(count)]
        fields['0xc2cf83c'] = [buttons[i % len(buttons)] for i in range(count)]
        fields['0xc2cf850'] = [buttons[(i + 4) % len(buttons)] for i in range(count)]
        if entry == 0x8c09c1de:
            for player in (0, 1):
                fields[hex(0xc29b864 + 0x234 + player*4)] = {
                    'values': [0, 8, 0x10, 1], 'stride': 48, 'phase': player}
                for offset in (0x23c, 0x244):
                    fields[hex(0xc29b864 + offset + player*4)] = [
                        (i // len(buttons) + player) % 10 for i in range(count)]
                fields[hex(0xc29b864 + 0x24c + player*4)] = [0, 1, 2, 0x7ff] * 64
                for column in range(16):
                    fields[hex(0xc29b864 + 0x254 + player*64 + column*4)] = {
                        'values': [0, 1, 0x400, 0x7ff], 'stride': 24, 'phase': column}
        elif entry == 0x8c0c3210:
            fields['0xc29b8e0'] = {'values': [0, 0x100, 0x200, 0x300], 'stride': 16}
            fields['0xc29b9a0'] = [0, 16, 32, 48] * 64  # mode +0x13c
            fields['0xc29b94c'] = {'values': [0, 3], 'stride': 48}  # mode +0xe8
            fields['0xc29bcf0'] = {'values': [0, 63, 64, 1314, 1315], 'stride': 12}
            fields['0xc29b8fc'] = {'values': [0, 0xffffffff, 0x00400000], 'stride': 24}
            fields['0xc400000'] = 0
            fields['0xc400004'] = {'values': [0, 1], 'stride': 24}
            fields['0xc400030'] = [(buttons[i % len(buttons)] & 255) << 8
                                   for i in range(count)]
            fields['0xc400034'] = [(i // 12 % 6) << 8 for i in range(count)]
            fields['0xc40006c'] = [i // 12 % 7 for i in range(count)]
        elif entry == 0x8c08984c:
            for particle in range(32):
                base = 0xc400018 + particle*40
                fields[hex(base+4)] = {'values': [0, 199, 399, 400], 'stride': 8}
                fields[hex(base+8)] = {'values': [0x01000000, 0x01000001, 0, 2], 'stride': 8}
                fields[hex(base+36)] = [0, 1, 0xffffffff, 2] * 64
                for offset in (24, 28, 32):
                    fields[hex(base+offset)] = [0, 0x3f800000, 0xbf800000] * 85 + [0]
        else:
            fields['0xc29c158'] = [0, 1, 0x101, 0x100] * 64  # scene +0x494/+0x495
            fields['0xc29bcec'] = {'values': [0, 0x300, 0x100], 'stride': 16}
            fields['0xc29bcd8'] = {'values': [0, 63872, 63900, 63935], 'stride': 24}
            fields['0xc29bd54'] = [0, 0x10000, 0x20000] * 85 + [0]  # byte scene +0x92
        memory[key] = fields
        registers[key] = old_regs[key]
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (ROOT / f'tools/oracle/percentage_inputs/{name}_{suffix}.json').write_text(
            json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
