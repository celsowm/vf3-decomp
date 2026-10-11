"""Original menu resident-kit inputs and independent boundary cases.

Kit IDs are read from the original immutable tables. Only mutable current-kit
state is supplied; the original wrapper and SDK calls still execute. This is
an advisory original-image experiment, with no coverage credit.
"""
import json
import struct
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c09b36c: 0x8c09b37e, 0x8c09cacc: 0x8c09cada,
          0x8c09bc1c: 0x8c09bc2e, 0x8c099194: 0x8c0991a2,
          0x8c08acc0: 0x8c08acd8}


def prepare():
    name = 'coverage_65_batch_resident_dev_v1'
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()

    def word(address):
        return struct.unpack_from('<I', image, address - 0xc010000)[0]

    kits = {}
    for index in range(33):
        kit, request = word(0xc1106a8 + 8*index), word(0xc1106ac + 8*index)
        if not request:
            break
        kits[request] = kit
    prior_dir = ROOT / 'tools/oracle/percentage_inputs'
    original = json.loads((prior_dir / 'coverage_65_batch_screen_dev_v2_memory.json').read_text())
    old_regs = json.loads((prior_dir / 'coverage_65_batch_screen_dev_v2_registers.json').read_text())
    boundary = json.loads((prior_dir / 'coverage_65_batch_boundary_dev_v1_memory.json').read_text())
    count = 384
    memory, registers = {}, {}
    buttons = [0, 16, 32, 64, 128, 4, 2, 8]
    for entry in OWNERS:
        key = hex(entry)
        fields = dict(boundary.get(key, original[key]))
        # Remove old correlated sequences; all varying values have count entries.
        for address, value in list(fields.items()):
            if isinstance(value, list):
                fields[address] = [value[i % len(value)] for i in range(count)]
        fields['0xc29bcc0'] = [0 if i % 47 else 1 for i in range(count)]
        fields['0xc2cf83c'] = [buttons[i % 8] for i in range(count)]
        fields['0xc2cf844'] = [0 if i // 8 % 2 else 8 for i in range(count)]
        if entry == 0x8c09b36c:
            fields['0xc29ba54'] = [i // 8 % 5 for i in range(count)]
            fields['0xc29ba58'] = [[0, 5, 6][i // 40 % 3] for i in range(count)]
            fields['0xc29ba5c'] = [i // 120 % 2 for i in range(count)]
            fields['0xc29ba6c'] = [i // 8 % 6 for i in range(count)]
            fields['0xc29b870'] = [0 if i < 320 else 1 for i in range(count)]
            stages = [0, 2, 48]
            fields['0xc29ba68'] = [stages[i // 40 % 3] for i in range(count)]
            fields['0xc110594'] = [kits[word(0xc10bcbc + 4*stages[i // 40 % 3])]
                                     for i in range(count)]
        elif entry == 0x8c09cacc:
            fields['0xc29bb3c'] = [i // 8 % 5 for i in range(count)]
            limits = [171, 219, 30, 0, 0]
            fields['0xc29bb38'] = [(0 if i < 192 else limits[i // 8 % 5])
                                     for i in range(count)]
            sound_rows = [0, 1, 114, 115, 121, 171]
            voice_rows = [0, 21, 35, 51, 69, 86, 102, 118, 134, 150, 164, 179, 194, 219]
            fields['0xc29bb40'] = [sound_rows[i // 40 % len(sound_rows)] for i in range(count)]
            fields['0xc1105a0'] = [word(0xc10bdf4 + 12*sound_rows[i // 40 % len(sound_rows)] + 8)
                                     for i in range(count)]
            fields['0xc29bb44'] = [voice_rows[i // 8 % len(voice_rows)] for i in range(count)]
            fields['0xc29bb48'] = [i // 40 % 31 for i in range(count)]
            fields['0xc110594'] = [kits.get(word(0xc10c604 + 8*(i // 40 % 31)), 0)
                                     for i in range(count)]
        elif entry == 0x8c09bc1c:
            fields['0xc29ba84'] = [i // 8 % 12 for i in range(count)]
            limits = [5, 3, 3, 400, 400, 1, 2, 1, 0, 0, 0, 0]
            fields['0xc29ba80'] = [0 if i < 192 else limits[i // 8 % 12] for i in range(count)]
            fields['0xc29bccc'] = 0
            base = word(0xc11e510) & 0xffff
            fields['0xc11e510'] = [base | ((i // 96 % 2) << 16) for i in range(count)]
        elif entry == 0x8c099194:
            fields['0xc468010'] = [0, 1, 319, 320] * 96
            phases = [0, 1, 3]
            flags = [0, 4, 0x20000, 0x40000000, 0x40000004, 0x800]
            fields['0xc29bcec'] = [(1 if i // 18 % 2 else 9) << 24 |
                                     phases[i % 3] << 8 for i in range(count)]
            fields['0xc29bccc'] = [flags[i // 3 % 6] for i in range(count)]
            fields['0xc29bcdc'] = [0 if i // 36 % 2 else 0x202 for i in range(count)]
            base = word(0xc11e514) & 0x00ffffff
            fields['0xc11e514'] = [base | ((i // 72 % 2) << 24) for i in range(count)]
        else:
            fields['0xc29b868'] = [0 if i // 8 % 3 else 0xc0030000 for i in range(count)]
            fields['0xc400010'] = [([0, 0x22e, 0x22f, 0x230, 0x705, 0x706, 0x707, 0x7ff][i % 8] << 16)
                                      | [0, 539, 1999, 2000][i // 8 % 4] for i in range(count)]
            fields['0xc29b880'] = [0 if i // 32 % 2 else 16 for i in range(count)]
        memory[key] = fields
        registers[key] = old_regs[key]
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (prior_dir / f'{name}_{suffix}.json').write_text(json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
